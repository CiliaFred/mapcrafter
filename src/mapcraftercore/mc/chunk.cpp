/*
 * Copyright 2012-2016 Moritz Hilscher
 *
 * This file is part of Mapcrafter.
 *
 * Mapcrafter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mapcrafter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mapcrafter.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "chunk.h"

#include "blockstate.h"

#include <cmath>
#include <iostream>

namespace mapcrafter {
namespace mc {

static const std::unordered_map<std::string, uint32_t> biome_resource_ids = {
    {"minecraft:ocean", 0},
    {"minecraft:plains", 1},
    {"minecraft:desert", 2},
    {"minecraft:windswept_hills", 3},
    {"minecraft:forest", 4},
    {"minecraft:taiga", 5},
    {"minecraft:swamp", 6},
    {"minecraft:river", 7},
    {"minecraft:nether_wastes", 8},
    {"minecraft:the_end", 9},
    {"minecraft:frozen_ocean", 10},
    {"minecraft:frozen_river", 11},
    {"minecraft:snowy_plains", 12},
    {"minecraft:mushroom_fields", 14},
    {"minecraft:beach", 16},
    {"minecraft:jungle", 21},
    {"minecraft:sparse_jungle", 23},
    {"minecraft:deep_ocean", 24},
    {"minecraft:stony_shore", 25},
    {"minecraft:snowy_beach", 26},
    {"minecraft:birch_forest", 27},
    {"minecraft:dark_forest", 29},
    {"minecraft:snowy_taiga", 30},
    {"minecraft:old_growth_pine_taiga", 32},
    {"minecraft:windswept_forest", 34},
    {"minecraft:savanna", 35},
    {"minecraft:savanna_plateau", 36},
    {"minecraft:badlands", 37},
    {"minecraft:wooded_badlands", 38},
    {"minecraft:small_end_islands", 40},
    {"minecraft:end_midlands", 41},
    {"minecraft:end_highlands", 42},
    {"minecraft:end_barrens", 43},
    {"minecraft:warm_ocean", 44},
    {"minecraft:lukewarm_ocean", 45},
    {"minecraft:cold_ocean", 46},
    {"minecraft:deep_lukewarm_ocean", 48},
    {"minecraft:deep_cold_ocean", 49},
    {"minecraft:deep_frozen_ocean", 50},
    {"minecraft:the_void", 127},
    {"minecraft:sunflower_plains", 129},
    {"minecraft:windswept_gravelly_hills", 131},
    {"minecraft:flower_forest", 132},
    {"minecraft:ice_spikes", 140},
    {"minecraft:old_growth_birch_forest", 155},
    {"minecraft:old_growth_spruce_taiga", 160},
    {"minecraft:windswept_savanna", 163},
    {"minecraft:eroded_badlands", 165},
    {"minecraft:bamboo_jungle", 168},
    {"minecraft:soul_sand_valley", 170},
    {"minecraft:crimson_forest", 171},
    {"minecraft:warped_forest", 172},
    {"minecraft:basalt_deltas", 173},
    {"minecraft:dripstone_caves", 174},
    {"minecraft:lush_caves", 175},
    {"minecraft:meadow", 177},
    {"minecraft:grove", 178},
    {"minecraft:snowy_slopes", 179},
    {"minecraft:frozen_peaks", 180},
    {"minecraft:jagged_peaks", 181},
    {"minecraft:stony_peaks", 182},
    {"minecraft:mangrove_swamp", 183},
};

namespace {

void readPackedShorts(const std::vector<int64_t> &data, std::array<uint16_t, 4096> &palette) {
    // this is basically taken from Minecraft Overviewer
    // https://github.com/gmcnew/Minecraft-Overviewer/blob/minecraft113/overviewer_core/world.py#L809
    // maybe we can keep this, or maybe we could do something with unions for speed-up?
    const uint8_t *b = reinterpret_cast<const uint8_t *>(&data.front());
    int bits_per_entry = data.size() * 64 / (16 * 16 * 16);

    unsigned int i = 0, j = 0;
    while (i < data.size() * sizeof(int64_t)) {
        if (bits_per_entry == 4) {
            for (int k = 0; k < 4; k++) {
                palette[j++] = b[i + k] & 0x0f;
                palette[j++] = (b[i + k] & 0xf0) >> 4;
            }
            i += 4;
        }
        if (bits_per_entry == 5) {
            palette[j++] = b[i] & 0x1f;
            palette[j++] = ((b[i + 1] & 0x03) << 3) | ((b[i] & 0xe0) >> 5);
            palette[j++] = (b[i + 1] & 0x7c) >> 2;
            palette[j++] = ((b[i + 2] & 0x0f) << 1) | ((b[i + 1] & 0x80) >> 7);
            palette[j++] = ((b[i + 3] & 0x01) << 4) | ((b[i + 2] & 0xf0) >> 4);
            palette[j++] = (b[i + 3] & 0x3e) >> 1;
            palette[j++] = ((b[i + 4] & 0x07) << 2) | ((b[i + 3] & 0xc0) >> 6);
            palette[j++] = (b[i + 4] & 0xf8) >> 3;
            i += 5;
        }
        if (bits_per_entry == 6) {
            palette[j++] = b[i] & 0x3f;
            palette[j++] = ((b[i + 1] & 0x0f) << 2) | ((b[i] & 0xc0) >> 6);
            palette[j++] = ((b[i + 2] & 0x03) << 4) | ((b[i + 1] & 0xf0) >> 4);
            palette[j++] = (b[i + 2] & 0xfc) >> 2;
            i += 3;
        }
        if (bits_per_entry == 7) {
            palette[j++] = b[i] & 0x7f;
            palette[j++] = ((b[i + 1] & 0x3f) << 1) | ((b[i] & 0x80) >> 7);
            palette[j++] = ((b[i + 2] & 0x1f) << 2) | ((b[i + 1] & 0xc0) >> 6);
            palette[j++] = ((b[i + 3] & 0x0f) << 3) | ((b[i + 2] & 0xe0) >> 5);
            palette[j++] = ((b[i + 4] & 0x07) << 4) | ((b[i + 3] & 0xf0) >> 4);
            palette[j++] = ((b[i + 5] & 0x03) << 5) | ((b[i + 4] & 0xf8) >> 3);
            palette[j++] = ((b[i + 6] & 0x01) << 6) | ((b[i + 5] & 0xfc) >> 2);
            palette[j++] = (b[i + 6] & 0xfe) >> 1;
            i += 7;
        }
        if (bits_per_entry == 8) {
            palette[j++] = b[i];
            i += 1;
        }
        if (bits_per_entry == 9) {
            palette[j++] = ((b[i + 1] & 0x01) << 8) | b[0];
            palette[j++] = ((b[i + 2] & 0x03) << 7) | ((b[i + 1] & 0xfe) >> 1);
            palette[j++] = ((b[i + 3] & 0x07) << 6) | ((b[i + 2] & 0xfc) >> 2);
            palette[j++] = ((b[i + 4] & 0x0f) << 5) | ((b[i + 3] & 0xf8) >> 3);
            palette[j++] = ((b[i + 5] & 0x1f) << 4) | ((b[i + 4] & 0xf0) >> 4);
            palette[j++] = ((b[i + 6] & 0x3f) << 3) | ((b[i + 5] & 0xe0) >> 5);
            palette[j++] = ((b[i + 7] & 0x7f) << 2) | ((b[i + 6] & 0xc0) >> 6);
            palette[j++] = (b[i + 8] << 1) | ((b[i + 7] & 0x80) >> 7);
            i += 9;
        }
        if (bits_per_entry == 10) {
            palette[j++] = ((b[i + 1] & 0x03) << 8) | b[0];
            palette[j++] = ((b[i + 2] & 0x0f) << 6) | ((b[i + 1] & 0xfc) >> 2);
            palette[j++] = ((b[i + 3] & 0x3f) << 4) | ((b[i + 2] & 0xf0) >> 4);
            palette[j++] = (b[i + 4] << 2) | ((b[i + 3] & 0xc0) >> 6);
            i += 5;
        }
        if (bits_per_entry == 11) {
            palette[j++] = ((b[i + 1] & 0x07) << 8) | b[0];
            palette[j++] = ((b[i + 2] & 0x3f) << 5) | ((b[i + 1] & 0xf8) >> 3);
            palette[j++] = ((b[i + 4] & 0x01) << 10) | (b[i + 3] << 2) | ((b[i + 2] & 0xc0) >> 6);
            palette[j++] = ((b[i + 5] & 0x0f) << 7) | ((b[i + 4] & 0xfe) >> 1);
            palette[j++] = ((b[i + 6] & 0x7f) << 4) | ((b[i + 5] & 0xf0) >> 4);
            palette[j++] = ((b[i + 8] & 0x03) << 9) | (b[i + 7] << 1) | ((b[i + 6] & 0x80) >> 7);
            palette[j++] = ((b[i + 9] & 0x1f) << 2) | ((b[i + 8] & 0xfc) >> 2);
            palette[j++] = (b[i + 10] << 3) | ((b[i + 9] & 0xe0) >> 5);
            i += 11;
        }
        if (bits_per_entry == 12) {
            palette[j++] = ((b[i + 1] & 0x0f) << 8) | b[0];
            palette[j++] = (b[i + 2] << 4) | ((b[i + 1] & 0xf0) >> 4);
            i += 3;
        }
    }
    assert(j == 16 * 16 * 16);
}

template <std::size_t PALETTE_SIZE = 4096>
void readPackedShorts_v116(const std::vector<int64_t> &data,
                           std::array<uint16_t, PALETTE_SIZE> &palette) {
    uint32_t shorts_per_long = (PALETTE_SIZE + data.size() - 1) / data.size();
    uint32_t bits_per_value = 64 / shorts_per_long;
    palette.fill(0);
    uint16_t mask = (1 << bits_per_value) - 1;

    for (uint32_t i = 0; i < shorts_per_long; i++) {
        uint32_t j = 0;
        for (uint32_t k = i; k < PALETTE_SIZE; k += shorts_per_long) {
            assert(j < data.size());
            palette[k] = (uint16_t)(data[j] >> (bits_per_value * i)) & mask;
            j++;
        }
        assert(j <= data.size());
    }
}

} // namespace

Chunk::Chunk() : chunkpos(42, 42), rotation(0), air_id(0) { clear(); }

Chunk::~Chunk() {}

void Chunk::setRotation(int rotation) { this->rotation = rotation; }

void Chunk::setWorldCrop(const WorldCrop &world_crop) { this->world_crop = world_crop; }

int Chunk::positionToKey(int x, int z, int y) const { return y + 256 * (x + 16 * z); }

bool Chunk::readNBT117(mc::BlockStateRegistry &block_registry, const nbt::NBTFile &nbt) {
    int data_version = nbt.findTag<nbt::TagInt>("DataVersion").payload;

    // find "level" tag
    if (!nbt.hasTag<nbt::TagCompound>("Level")) {
        LOG(ERROR) << "Corrupt chunk: No level tag found!";
        return false;
    }
    const nbt::TagCompound &level = nbt.findTag<nbt::TagCompound>("Level");

    // then find x/z pos of the chunk
    if (!level.hasTag<nbt::TagInt>("xPos") || !level.hasTag<nbt::TagInt>("zPos")) {
        LOG(ERROR) << "Corrupt chunk: No x/z position found!";
        return false;
    }
    chunkpos_original = ChunkPos(level.findTag<nbt::TagInt>("xPos").payload,
                                 level.findTag<nbt::TagInt>("zPos").payload);
    chunkpos = chunkpos_original;
    if (rotation)
        chunkpos.rotate(rotation);

    // now we have the original chunk position:
    // check whether this chunk is completely contained within the cropped world
    chunk_completely_contained = world_crop.isChunkCompletelyContained(chunkpos_original);

    if (level.hasTag<nbt::TagString>("Status")) {
        const nbt::TagString &tag = level.findTag<nbt::TagString>("Status");
        // completely generated chunks in fresh 1.13 worlds usually have status 'fullchunk' or
        // 'postprocessed' however, chunks of converted <1.13 worlds don't use these, but the state
        // 'mobs_spawned'
        if (!(tag.payload == "fullchunk" || tag.payload == "full" ||
              tag.payload == "postprocessed" || tag.payload == "mobs_spawned")) {
            return true;
        }
    }

    if (level.hasArray<nbt::TagByteArray>("Biomes", BIOMES_ARRAY_SIZE)) {
        const nbt::TagByteArray &biomes_tag = level.findTag<nbt::TagByteArray>("Biomes");
        std::copy(biomes_tag.payload.begin(), biomes_tag.payload.end(), biomes);
    } else if (level.hasArray<nbt::TagIntArray>("Biomes", BIOMES_ARRAY_SIZE)) {
        const nbt::TagIntArray &biomes_tag = level.findTag<nbt::TagIntArray>("Biomes");
        std::copy(biomes_tag.payload.begin(), biomes_tag.payload.end(), biomes);
    } else if (level.hasArray<nbt::TagIntArray>("Biomes", 1024)) {
        const nbt::TagIntArray &biomes_tag = level.findTag<nbt::TagIntArray>("Biomes");
        std::copy(biomes_tag.payload.begin(), biomes_tag.payload.end(), biomes);
    } else if (level.hasArray<nbt::TagByteArray>("Biomes", 0) ||
               level.hasArray<nbt::TagLongArray>("Biomes", 0)) {
        std::fill(biomes, biomes + BIOMES_ARRAY_SIZE, 0);
    } else if (level.hasArray<nbt::TagByteArray>("Biomes", 256) ||
               level.hasArray<nbt::TagIntArray>("Biomes", 256)) {
        LOG(WARNING) << "Out dated chunk " << chunkpos << ": Old biome data found!";
    } else {
        LOG(WARNING) << "Corrupt chunk " << chunkpos << ": No biome data found!";
        // level.dump(std::cout);
    }

    // find sections list
    // ignore it if section list does not exist, can happen sometimes with the empty
    // chunks of the end
    if (!level.hasList<nbt::TagCompound>("Sections"))
        return true;

    const nbt::TagList &sections_tag = level.findTag<nbt::TagList>("Sections");
    if (sections_tag.tag_type != nbt::TagCompound::TAG_TYPE)
        return true;

    // go through all sections
    for (auto it = sections_tag.payload.begin(); it != sections_tag.payload.end(); ++it) {
        const nbt::TagCompound &section_tag = (*it)->cast<nbt::TagCompound>();

        // make sure section is valid
        if (!section_tag.hasTag<nbt::TagByte>("Y")
            //		|| !section_tag.hasArray<nbt::TagByteArray>("Blocks", 4096)
            //		|| !section_tag.hasArray<nbt::TagByteArray>("Data", 2048)
            || !section_tag.hasArray<nbt::TagLongArray>("BlockStates") ||
            !section_tag.hasTag<nbt::TagList>("Palette"))
            continue;

        const nbt::TagByte &y = section_tag.findTag<nbt::TagByte>("Y");
        if (y.payload < CHUNK_LOW || y.payload >= CHUNK_TOP)
            continue;
        // const nbt::TagByteArray& blocks = section_tag.findTag<nbt::TagByteArray>("Blocks");
        // const nbt::TagByteArray& data = section_tag.findTag<nbt::TagByteArray>("Data");

        const nbt::TagLongArray &blockstates =
            section_tag.findTag<nbt::TagLongArray>("BlockStates");

        const nbt::TagList &palette = section_tag.findTag<nbt::TagList>("Palette");
        std::vector<mc::BlockState> palette_blockstates(palette.payload.size());
        std::vector<uint16_t> palette_lookup(palette.payload.size());

        size_t i = 0;
        for (auto it2 = palette.payload.begin(); it2 != palette.payload.end(); ++it2, ++i) {
            const nbt::TagCompound &entry = (*it2)->cast<nbt::TagCompound>();
            const nbt::TagString &name = entry.findTag<nbt::TagString>("Name");

            mc::BlockState block(name.payload);
            if (entry.hasTag<nbt::TagCompound>("Properties")) {
                const nbt::TagCompound &properties = entry.findTag<nbt::TagCompound>("Properties");
                for (auto it3 = properties.payload.begin(); it3 != properties.payload.end();
                     ++it3) {
                    std::string key = it3->first;
                    std::string value = it3->second->cast<nbt::TagString>().payload;
                    if (block_registry.isKnownProperty(block.getName(), key)) {
                        block.setProperty(key, value);
                    }
                }
            }
            palette_blockstates[i] = block;
            palette_lookup[i] = block_registry.getBlockID(block);
        }

        // create a ChunkSection-object
        ChunkSection section;
        section.y = y.payload;

        if (data_version >= 2529) {
            readPackedShorts_v116(blockstates.payload, section.block_ids);
        } else {
            readPackedShorts(blockstates.payload, section.block_ids);
        }

        int bits_per_entry = blockstates.payload.size() * 64 / (16 * 16 * 16);
        bool ok = true;
        for (size_t i = 0; i < 16 * 16 * 16; i++) {
            if (section.block_ids[i] >= palette_blockstates.size()) {
                LOG(ERROR) << "Incorrectly parsed palette ID " << section.block_ids[i]
                           << " at index " << i << " (max is " << palette_blockstates.size() - 1
                           << " with " << bits_per_entry << " bits per entry)";
                ok = false;
                break;
            }
            section.block_ids[i] = palette_lookup[section.block_ids[i]];
        }
        if (!ok) {
            continue;
        }

        if (section_tag.hasArray<nbt::TagByteArray>("BlockLight", 2048)) {
            const nbt::TagByteArray &block_light =
                section_tag.findTag<nbt::TagByteArray>("BlockLight");
            std::copy(block_light.payload.begin(), block_light.payload.end(), section.block_light);
        } else {
            std::fill(&section.block_light[0], &section.block_light[2048], 0);
        }
        if (section_tag.hasArray<nbt::TagByteArray>("SkyLight", 2048)) {
            const nbt::TagByteArray &sky_light = section_tag.findTag<nbt::TagByteArray>("SkyLight");
            std::copy(sky_light.payload.begin(), sky_light.payload.end(), section.sky_light);
        } else {
            std::fill(&section.sky_light[0], &section.sky_light[2048], 0);
        }

        // add this section to the section list
        section_offsets[section.y - CHUNK_LOW] = sections.size();
        sections.push_back(section);
    }

    return true;
}

bool Chunk::simulateSunLight() const { return (this->chunk_status != "full"); }

bool Chunk::readNBT118(mc::BlockStateRegistry &block_registry, const nbt::NBTFile &nbt) {
    int data_version = nbt.findTag<nbt::TagInt>("DataVersion").payload;
    if (data_version < 2860) {
        throw new std::logic_error("readNBT118 needs data version >= 2860");
    }

    // then find x/z pos of the chunk
    if (!nbt.hasTag<nbt::TagInt>("xPos") || !nbt.hasTag<nbt::TagInt>("zPos")) {
        LOG(ERROR) << "Corrupt chunk: No x/z position found!";
        return false;
    }
    chunkpos_original = ChunkPos(nbt.findTag<nbt::TagInt>("xPos").payload,
                                 nbt.findTag<nbt::TagInt>("zPos").payload);
    chunkpos = chunkpos_original;
    if (rotation)
        chunkpos.rotate(rotation);

    // now we have the original chunk position:
    // check whether this chunk is completely contained within the cropped world
    chunk_completely_contained = world_crop.isChunkCompletelyContained(chunkpos_original);

    if (!nbt.hasTag<nbt::TagString>("Status")) {
        return true;
    }

    chunk_status = nbt.findTag<nbt::TagString>("Status").payload;

    // find sections list
    // ignore it if section list does not exist, can happen sometimes with the empty
    // chunks of the end
    if (!nbt.hasList<nbt::TagCompound>("sections"))
        return true;

    const nbt::TagList &sections_tag = nbt.findTag<nbt::TagList>("sections");
    if (sections_tag.tag_type != nbt::TagCompound::TAG_TYPE)
        return true;

    for (auto it = sections_tag.payload.begin(); it != sections_tag.payload.end(); ++it) {
        const nbt::TagCompound &section_tag = (*it)->cast<nbt::TagCompound>();

        // make sure section is valid
        if (!section_tag.hasTag<nbt::TagByte>("Y"))
            continue;

        const nbt::TagByte &y = section_tag.findTag<nbt::TagByte>("Y");
        if (y.payload < CHUNK_LOW || y.payload >= CHUNK_TOP)
            continue;

        if (!section_tag.hasTag<nbt::TagCompound>("block_states"))
            continue;

        if (section_tag.hasTag<nbt::TagCompound>("biomes")) {
            const auto &biomes_tag = section_tag.findTag<nbt::TagCompound>("biomes");
            const nbt::TagList &palette = biomes_tag.findTag<nbt::TagList>("palette");
            const int biomes_per_section = 64; // 4 * 4 * 4
            int biomes_base_index = (y.payload - CHUNK_LOW) * biomes_per_section;

            if (biomes_tag.hasTag<nbt::TagLongArray>("data")) {
                const auto &biomes_data = biomes_tag.findTag<nbt::TagLongArray>("data");
                // std::cout << "biomes data for section x=" << chunkpos.x << " z=" << chunkpos.z
                //           << " y=" << (int)y.payload << ":\n";
                // for (const auto &value : biomes_data.payload) {
                //     std::cout << "    " << value << "\n";
                // }
                std::array<uint16_t, biomes_per_section> biome_palette;
                readPackedShorts_v116(biomes_data.payload, biome_palette);
                // for (auto v : section_biomes) {
                //     std::cout << "  decoded value: " << v << "\n";
                // }
                for (int i = 0; i < biomes_per_section; i++) {
                    uint16_t palette_index = biome_palette.at(i);
                    if (palette_index >= palette.payload.size()) {
                        // still no clue how this happens, let's ignore for now
                        // std::cout << "x=" << chunkpos.x << " z=" << chunkpos.z
                        //           << " y=" << (int)y.payload << "\n";
                        continue;
                    }
                    // std::cout << "palette_index: " << palette_index << " "
                    //           << "palette_size: " << palette.payload.size() << "\n";

                    std::string biome_name =
                        palette.payload.at(palette_index)->cast<nbt::TagString>().payload;
                    auto it = biome_resource_ids.find(biome_name);
                    uint32_t biome_id = 1; // minecraft:plains
                    if (it != biome_resource_ids.end())
                        biome_id = it->second;
                    biomes[biomes_base_index + i] = biome_id;
                }
            } else {
                std::string biome_name = palette.payload.at(0)->cast<nbt::TagString>().payload;
                uint32_t biome_id = 1; // minecraft:plains
                auto it = biome_resource_ids.find(biome_name);
                if (it != biome_resource_ids.end())
                    biome_id = it->second;
                std::fill(biomes + biomes_base_index,
                          biomes + biomes_base_index + biomes_per_section, biome_id);
            }
        }

        const auto &block_states = section_tag.findTag<nbt::TagCompound>("block_states");

        const nbt::TagList &palette = block_states.findTag<nbt::TagList>("palette");
        std::vector<mc::BlockState> palette_blockstates(palette.payload.size());
        std::vector<uint16_t> palette_lookup(palette.payload.size());

        size_t i = 0;
        for (auto it2 = palette.payload.begin(); it2 != palette.payload.end(); ++it2, ++i) {
            const nbt::TagCompound &entry = (*it2)->cast<nbt::TagCompound>();
            const nbt::TagString &name = entry.findTag<nbt::TagString>("Name");

            mc::BlockState block(name.payload);
            if (entry.hasTag<nbt::TagCompound>("Properties")) {
                const nbt::TagCompound &properties = entry.findTag<nbt::TagCompound>("Properties");
                for (auto it3 = properties.payload.begin(); it3 != properties.payload.end();
                     ++it3) {
                    std::string key = it3->first;
                    std::string value = it3->second->cast<nbt::TagString>().payload;
                    if (block_registry.isKnownProperty(block.getName(), key)) {
                        block.setProperty(key, value);
                    }
                }
            }
            palette_blockstates[i] = block;
            palette_lookup[i] = block_registry.getBlockID(block);
        }

        // create a ChunkSection-object
        ChunkSection section;
        section.y = y.payload;
        if (block_states.hasArray<nbt::TagLongArray>("data")) {
            const nbt::TagLongArray &block_states_data =
                block_states.findTag<nbt::TagLongArray>("data");

            readPackedShorts_v116(block_states_data.payload, section.block_ids);

            int bits_per_entry = block_states_data.payload.size() * 64 / (16 * 16 * 16);
            bool ok = true;
            for (size_t i = 0; i < 16 * 16 * 16; i++) {
                if (section.block_ids[i] >= palette_blockstates.size()) {
                    LOG(ERROR) << "Incorrectly parsed palette ID " << section.block_ids[i]
                               << " at index " << i << " (max is " << palette_blockstates.size() - 1
                               << " with " << bits_per_entry << " bits per entry)";
                    ok = false;
                    break;
                }
                section.block_ids[i] = palette_lookup[section.block_ids[i]];
            }
            if (!ok) {
                continue;
            }
        } else {
            if (palette_lookup[0] == air_id)
                continue;
            section.block_ids.fill(palette_lookup[0]);
        }

        if (section_tag.hasArray<nbt::TagByteArray>("BlockLight", 2048)) {
            const nbt::TagByteArray &block_light =
                section_tag.findTag<nbt::TagByteArray>("BlockLight");
            std::copy(block_light.payload.begin(), block_light.payload.end(), section.block_light);
        } else {
            std::fill(&section.block_light[0], &section.block_light[2048], 0);
        }
        if (section_tag.hasArray<nbt::TagByteArray>("SkyLight", 2048)) {
            const nbt::TagByteArray &sky_light = section_tag.findTag<nbt::TagByteArray>("SkyLight");
            std::copy(sky_light.payload.begin(), sky_light.payload.end(), section.sky_light);
        } else {
            std::fill(&section.sky_light[0], &section.sky_light[2048], 0);
        }

        // add this section to the section list
        section_offsets[section.y - CHUNK_LOW] = sections.size();
        sections.push_back(section);
    }

    return true;
}

bool Chunk::readNBT(mc::BlockStateRegistry &block_registry, const char *data, size_t len,
                    nbt::Compression compression) {
    clear();

    air_id = block_registry.getBlockID(mc::BlockState("minecraft:air"));

    nbt::NBTFile nbt;
    nbt.readNBT(data, len, compression);

    // Make sure we know which data format this chunk is built of
    if (!nbt.hasTag<nbt::TagInt>("DataVersion")) {
        LOG(ERROR) << "Corrupt chunk: No version tag found!";
        return false;
    }
    int data_version = nbt.findTag<nbt::TagInt>("DataVersion").payload;

    // nbt.dump(std::cout);

    // 1.18 chunk format
    if (data_version >= 2860)
        return readNBT118(block_registry, nbt);
    // the previous code
    return readNBT117(block_registry, nbt);
}

void Chunk::clear() {
    sections.clear();
    for (size_t i = 0; i < sizeof(section_offsets) / sizeof(section_offsets[0]); i++)
        section_offsets[i] = -1;
    std::fill(biomes, biomes + 256, 21 /* DEFAULT_BIOME */);
}

bool Chunk::hasSection(int section) const {
    return section >= CHUNK_LOW && section < CHUNK_TOP &&
           section_offsets[section - CHUNK_LOW] != -1;
}

void rotateBlockPos(int &x, int &z, int rotation) {
    int nx = x, nz = z;
    for (int i = 0; i < rotation; i++) {
        nx = z;
        nz = 15 - x;
        x = nx;
        z = nz;
    }
}

uint16_t Chunk::getBlockID(const LocalBlockPos &pos, bool force) const {
    // at first find out the section and check if it's valid and contained
    int section = pos.y >> 4;
    if (section < CHUNK_LOW || section >= CHUNK_TOP || section_offsets[section - CHUNK_LOW] == -1)
        return air_id;
    // FIXME sometimes this happens, fix this
    // if (sections.size() > 16 || sections.size() <= (unsigned) section_offsets[section-CHUNK_LOW])
    // { 	return 0;
    //}

    // if rotated: rotate position to position with original rotation
    int x = pos.x;
    int z = pos.z;
    if (rotation)
        rotateBlockPos(x, z, rotation);

    // check whether this block is really rendered
    if (!checkBlockWorldCrop(x, z, pos.y))
        return air_id;

    // calculate the offset and get the block ID
    // and don't forget the add data
    int offset = ((pos.y & 15) * 16 + z) * 16 + x;
    uint16_t id = sections[section_offsets[section - CHUNK_LOW]].block_ids[offset];
    if (!force && world_crop.hasBlockMask()) {
        const BlockMask *mask = world_crop.getBlockMask();
        BlockMask::BlockState block_state = mask->getBlockState(id);
        if (block_state == BlockMask::BlockState::COMPLETELY_HIDDEN)
            return air_id;
        else if (block_state == BlockMask::BlockState::COMPLETELY_SHOWN)
            return id;
        if (mask->isHidden(id, 0 /*getBlockData(pos, true)*/))
            return air_id;
    }
    return id;
}

bool Chunk::checkBlockWorldCrop(int x, int z, int y) const {
    // now about the actual world cropping:
    // get the global position of the block, with the original world rotation
    BlockPos global_pos = LocalBlockPos(x, z, y).toGlobalPos(chunkpos_original);
    // check whether the block is contained in the y-bounds.
    if (!world_crop.isBlockContainedY(global_pos))
        return false;
    // only check x/z-bounds if the chunk is not completely contained
    if (!chunk_completely_contained && !world_crop.isBlockContainedXZ(global_pos))
        return false;
    return true;
}

uint8_t Chunk::getData(const LocalBlockPos &pos, int array, bool force) const {
    // at first find out the section and check if it's valid and contained
    int section = pos.y >> 4;
    if (section < CHUNK_LOW || section >= CHUNK_TOP || section_offsets[section - CHUNK_LOW] == -1) {
        // not existing sections should always have skylight
        return array == 1 ? 15 : 0;
    }

    // if rotated: rotate position to position with original rotation
    int x = pos.x;
    int z = pos.z;
    if (rotation)
        rotateBlockPos(x, z, rotation);

    // check whether this block is really rendered
    if (!checkBlockWorldCrop(x, z, pos.y)) {
        return array == 1 ? 15 : 0;
    }

    uint8_t data = 0;
    // calculate the offset and get the block data
    int offset = ((pos.y & 15) * 16 + z) * 16 + x;
    // handle bottom/top nibble
    if ((offset % 2) == 0)
        data = sections[section_offsets[section - CHUNK_LOW]].getArray(array)[offset / 2] & 0xf;
    else
        data = (sections[section_offsets[section - CHUNK_LOW]].getArray(array)[offset / 2] >> 4) &
               0x0f;
    if (!force && world_crop.hasBlockMask()) {
        const BlockMask *mask = world_crop.getBlockMask();
        if (mask->isHidden(getBlockID(pos, true), data)) {
            return array == 1 ? 15 : 0;
        }
    }
    return data;
}

uint8_t Chunk::getBlockLight(const LocalBlockPos &pos) const { return getData(pos, 0); }

uint8_t Chunk::getSkyLight(const LocalBlockPos &pos) const { return getData(pos, 1); }

uint8_t Chunk::getBiomeAt(const LocalBlockPos &pos) const {
    int x = pos.x / 4;
    int z = pos.z / 4;
    int y = (pos.y - CHUNK_LOW * 16) / 4;
    assert(y >= 0 && y < (CHUNK_TOP - CHUNK_LOW) * 16 / 4);

    if (rotation)
        rotateBlockPos(x, z, rotation);

    return biomes[(y * 16 + (z * 4 + x))];
}

const ChunkPos &Chunk::getPos() const { return chunkpos; }

} // namespace mc
} // namespace mapcrafter
