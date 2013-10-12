#ifndef BLOCKTEXTURES_H_
#define BLOCKTEXTURES_H_

#include "textureimage.h"

#include <string>
#include <vector>

namespace mapcrafter {
namespace renderer {

/**
 * Collection of Minecraft block textures.
 */
class BlockTextures {
  public:
    BlockTextures();
    ~BlockTextures();

    bool load(const std::string &block_dir, int size, int blur, double water_opacity);

	TextureImage
		ACACIA_DOOR_BOTTOM,
		ACACIA_DOOR_TOP,
		ACACIA_LEAVES,
		ACACIA_LOG,
		ACACIA_LOG_TOP,
		ACACIA_PLANKS,
		ACACIA_SAPLING,
		ACACIA_TRAPDOOR,
		ACTIVATOR_RAIL,
		ACTIVATOR_RAIL_ON,
		ALLIUM,
		AMETHYST_BLOCK,
		AMETHYST_CLUSTER,
		ANCIENT_DEBRIS_SIDE,
		ANCIENT_DEBRIS_TOP,
		ANDESITE,
		ANVIL,
		ANVIL_TOP,
		ATTACHED_MELON_STEM,
		ATTACHED_PUMPKIN_STEM,
		AZALEA_LEAVES,
		AZALEA_PLANT,
		AZALEA_SIDE,
		AZALEA_TOP,
		AZURE_BLUET,
		BAMBOO_LARGE_LEAVES,
		BAMBOO_SINGLELEAF,
		BAMBOO_SMALL_LEAVES,
		BAMBOO_STAGE0,
		BAMBOO_STALK,
		BARREL_BOTTOM,
		BARREL_SIDE,
		BARREL_TOP,
		BARREL_TOP_OPEN,
		BASALT_SIDE,
		BASALT_TOP,
		BEACON,
		BEDROCK,
		BEE_NEST_BOTTOM,
		BEE_NEST_FRONT,
		BEE_NEST_FRONT_HONEY,
		BEE_NEST_SIDE,
		BEE_NEST_TOP,
		BEEHIVE_END,
		BEEHIVE_FRONT,
		BEEHIVE_FRONT_HONEY,
		BEEHIVE_SIDE,
		BEETROOTS_STAGE0,
		BEETROOTS_STAGE1,
		BEETROOTS_STAGE2,
		BEETROOTS_STAGE3,
		BELL_BOTTOM,
		BELL_SIDE,
		BELL_TOP,
		BIG_DRIPLEAF_SIDE,
		BIG_DRIPLEAF_STEM,
		BIG_DRIPLEAF_TIP,
		BIG_DRIPLEAF_TOP,
		BIRCH_DOOR_BOTTOM,
		BIRCH_DOOR_TOP,
		BIRCH_LEAVES,
		BIRCH_LOG,
		BIRCH_LOG_TOP,
		BIRCH_PLANKS,
		BIRCH_SAPLING,
		BIRCH_TRAPDOOR,
		BLACK_CANDLE,
		BLACK_CANDLE_LIT,
		BLACK_CONCRETE,
		BLACK_CONCRETE_POWDER,
		BLACK_GLAZED_TERRACOTTA,
		BLACK_SHULKER_BOX,
		BLACK_STAINED_GLASS,
		BLACK_STAINED_GLASS_PANE_TOP,
		BLACK_TERRACOTTA,
		BLACK_WOOL,
		BLACKSTONE,
		BLACKSTONE_TOP,
		BLAST_FURNACE_FRONT,
		BLAST_FURNACE_FRONT_ON,
		BLAST_FURNACE_SIDE,
		BLAST_FURNACE_TOP,
		BLUE_CANDLE,
		BLUE_CANDLE_LIT,
		BLUE_CONCRETE,
		BLUE_CONCRETE_POWDER,
		BLUE_GLAZED_TERRACOTTA,
		BLUE_ICE,
		BLUE_ORCHID,
		BLUE_SHULKER_BOX,
		BLUE_STAINED_GLASS,
		BLUE_STAINED_GLASS_PANE_TOP,
		BLUE_TERRACOTTA,
		BLUE_WOOL,
		BONE_BLOCK_SIDE,
		BONE_BLOCK_TOP,
		BOOKSHELF,
		BRAIN_CORAL,
		BRAIN_CORAL_BLOCK,
		BRAIN_CORAL_FAN,
		BREWING_STAND,
		BREWING_STAND_BASE,
		BRICKS,
		BROWN_CANDLE,
		BROWN_CANDLE_LIT,
		BROWN_CONCRETE,
		BROWN_CONCRETE_POWDER,
		BROWN_GLAZED_TERRACOTTA,
		BROWN_MUSHROOM,
		BROWN_MUSHROOM_BLOCK,
		BROWN_SHULKER_BOX,
		BROWN_STAINED_GLASS,
		BROWN_STAINED_GLASS_PANE_TOP,
		BROWN_TERRACOTTA,
		BROWN_WOOL,
		BUBBLE_CORAL,
		BUBBLE_CORAL_BLOCK,
		BUBBLE_CORAL_FAN,
		BUDDING_AMETHYST,
		CACTUS_BOTTOM,
		CACTUS_SIDE,
		CACTUS_TOP,
		CAKE_BOTTOM,
		CAKE_INNER,
		CAKE_SIDE,
		CAKE_TOP,
		CALCITE,
		CAMPFIRE_FIRE,
		CAMPFIRE_LOG,
		CAMPFIRE_LOG_LIT,
		CANDLE,
		CANDLE_LIT,
		CARROTS_STAGE0,
		CARROTS_STAGE1,
		CARROTS_STAGE2,
		CARROTS_STAGE3,
		CARTOGRAPHY_TABLE_SIDE1,
		CARTOGRAPHY_TABLE_SIDE2,
		CARTOGRAPHY_TABLE_SIDE3,
		CARTOGRAPHY_TABLE_TOP,
		CARVED_PUMPKIN,
		CAULDRON_BOTTOM,
		CAULDRON_INNER,
		CAULDRON_SIDE,
		CAULDRON_TOP,
		CAVE_VINES,
		CAVE_VINES_LIT,
		CAVE_VINES_PLANT,
		CAVE_VINES_PLANT_LIT,
		CHAIN,
		CHAIN_COMMAND_BLOCK_BACK,
		CHAIN_COMMAND_BLOCK_CONDITIONAL,
		CHAIN_COMMAND_BLOCK_FRONT,
		CHAIN_COMMAND_BLOCK_SIDE,
		CHIPPED_ANVIL_TOP,
		CHISELED_DEEPSLATE,
		CHISELED_NETHER_BRICKS,
		CHISELED_POLISHED_BLACKSTONE,
		CHISELED_QUARTZ_BLOCK,
		CHISELED_QUARTZ_BLOCK_TOP,
		CHISELED_RED_SANDSTONE,
		CHISELED_SANDSTONE,
		CHISELED_STONE_BRICKS,
		CHORUS_FLOWER,
		CHORUS_FLOWER_DEAD,
		CHORUS_PLANT,
		CLAY,
		COAL_BLOCK,
		COAL_ORE,
		COARSE_DIRT,
		COBBLED_DEEPSLATE,
		COBBLESTONE,
		COBWEB,
		COCOA_STAGE0,
		COCOA_STAGE1,
		COCOA_STAGE2,
		COMMAND_BLOCK_BACK,
		COMMAND_BLOCK_CONDITIONAL,
		COMMAND_BLOCK_FRONT,
		COMMAND_BLOCK_SIDE,
		COMPARATOR,
		COMPARATOR_ON,
		COMPOSTER_BOTTOM,
		COMPOSTER_COMPOST,
		COMPOSTER_READY,
		COMPOSTER_SIDE,
		COMPOSTER_TOP,
		CONDUIT,
		COPPER_BLOCK,
		COPPER_ORE,
		CORNFLOWER,
		CRACKED_DEEPSLATE_BRICKS,
		CRACKED_DEEPSLATE_TILES,
		CRACKED_NETHER_BRICKS,
		CRACKED_POLISHED_BLACKSTONE_BRICKS,
		CRACKED_STONE_BRICKS,
		CRAFTING_TABLE_FRONT,
		CRAFTING_TABLE_SIDE,
		CRAFTING_TABLE_TOP,
		CRIMSON_DOOR_BOTTOM,
		CRIMSON_DOOR_TOP,
		CRIMSON_FUNGUS,
		CRIMSON_NYLIUM,
		CRIMSON_NYLIUM_SIDE,
		CRIMSON_PLANKS,
		CRIMSON_ROOTS,
		CRIMSON_ROOTS_POT,
		CRIMSON_STEM,
		CRIMSON_STEM_TOP,
		CRIMSON_TRAPDOOR,
		CRYING_OBSIDIAN,
		CUT_COPPER,
		CUT_RED_SANDSTONE,
		CUT_SANDSTONE,
		CYAN_CANDLE,
		CYAN_CANDLE_LIT,
		CYAN_CONCRETE,
		CYAN_CONCRETE_POWDER,
		CYAN_GLAZED_TERRACOTTA,
		CYAN_SHULKER_BOX,
		CYAN_STAINED_GLASS,
		CYAN_STAINED_GLASS_PANE_TOP,
		CYAN_TERRACOTTA,
		CYAN_WOOL,
		DAMAGED_ANVIL_TOP,
		DANDELION,
		DARK_OAK_DOOR_BOTTOM,
		DARK_OAK_DOOR_TOP,
		DARK_OAK_LEAVES,
		DARK_OAK_LOG,
		DARK_OAK_LOG_TOP,
		DARK_OAK_PLANKS,
		DARK_OAK_SAPLING,
		DARK_OAK_TRAPDOOR,
		DARK_PRISMARINE,
		DAYLIGHT_DETECTOR_INVERTED_TOP,
		DAYLIGHT_DETECTOR_SIDE,
		DAYLIGHT_DETECTOR_TOP,
		DEAD_BRAIN_CORAL,
		DEAD_BRAIN_CORAL_BLOCK,
		DEAD_BRAIN_CORAL_FAN,
		DEAD_BUBBLE_CORAL,
		DEAD_BUBBLE_CORAL_BLOCK,
		DEAD_BUBBLE_CORAL_FAN,
		DEAD_BUSH,
		DEAD_FIRE_CORAL,
		DEAD_FIRE_CORAL_BLOCK,
		DEAD_FIRE_CORAL_FAN,
		DEAD_HORN_CORAL,
		DEAD_HORN_CORAL_BLOCK,
		DEAD_HORN_CORAL_FAN,
		DEAD_TUBE_CORAL,
		DEAD_TUBE_CORAL_BLOCK,
		DEAD_TUBE_CORAL_FAN,
		DEBUG,
		DEBUG2,
		DEEPSLATE,
		DEEPSLATE_BRICKS,
		DEEPSLATE_COAL_ORE,
		DEEPSLATE_COPPER_ORE,
		DEEPSLATE_DIAMOND_ORE,
		DEEPSLATE_EMERALD_ORE,
		DEEPSLATE_GOLD_ORE,
		DEEPSLATE_IRON_ORE,
		DEEPSLATE_LAPIS_ORE,
		DEEPSLATE_REDSTONE_ORE,
		DEEPSLATE_TILES,
		DEEPSLATE_TOP,
		DESTROY_STAGE_0,
		DESTROY_STAGE_1,
		DESTROY_STAGE_2,
		DESTROY_STAGE_3,
		DESTROY_STAGE_4,
		DESTROY_STAGE_5,
		DESTROY_STAGE_6,
		DESTROY_STAGE_7,
		DESTROY_STAGE_8,
		DESTROY_STAGE_9,
		DETECTOR_RAIL,
		DETECTOR_RAIL_ON,
		DIAMOND_BLOCK,
		DIAMOND_ORE,
		DIORITE,
		DIRT,
		DIRT_PATH_SIDE,
		DIRT_PATH_TOP,
		DISPENSER_FRONT,
		DISPENSER_FRONT_VERTICAL,
		DRAGON_EGG,
		DRIED_KELP_BOTTOM,
		DRIED_KELP_SIDE,
		DRIED_KELP_TOP,
		DRIPSTONE_BLOCK,
		DROPPER_FRONT,
		DROPPER_FRONT_VERTICAL,
		EMERALD_BLOCK,
		EMERALD_ORE,
		ENCHANTING_TABLE_BOTTOM,
		ENCHANTING_TABLE_SIDE,
		ENCHANTING_TABLE_TOP,
		END_PORTAL_FRAME_EYE,
		END_PORTAL_FRAME_SIDE,
		END_PORTAL_FRAME_TOP,
		END_ROD,
		END_STONE,
		END_STONE_BRICKS,
		EXPOSED_COPPER,
		EXPOSED_CUT_COPPER,
		FARMLAND,
		FARMLAND_MOIST,
		FERN,
		FIRE_0,
		FIRE_1,
		FIRE_CORAL,
		FIRE_CORAL_BLOCK,
		FIRE_CORAL_FAN,
		FLETCHING_TABLE_FRONT,
		FLETCHING_TABLE_SIDE,
		FLETCHING_TABLE_TOP,
		FLOWER_POT,
		FLOWERING_AZALEA_LEAVES,
		FLOWERING_AZALEA_SIDE,
		FLOWERING_AZALEA_TOP,
		FROGSPAWN,
		FROSTED_ICE_0,
		FROSTED_ICE_1,
		FROSTED_ICE_2,
		FROSTED_ICE_3,
		FURNACE_FRONT,
		FURNACE_FRONT_ON,
		FURNACE_SIDE,
		FURNACE_TOP,
		GILDED_BLACKSTONE,
		GLASS,
		GLASS_PANE_TOP,
		GLOW_ITEM_FRAME,
		GLOW_LICHEN,
		GLOWSTONE,
		GOLD_BLOCK,
		GOLD_ORE,
		GRANITE,
		GRASS,
		GRASS_BLOCK_SIDE,
		GRASS_BLOCK_SIDE_OVERLAY,
		GRASS_BLOCK_SNOW,
		GRASS_BLOCK_TOP,
		GRASS_PATH_SIDE,
		GRASS_PATH_TOP,
		GRAVEL,
		GRAY_CANDLE,
		GRAY_CANDLE_LIT,
		GRAY_CONCRETE,
		GRAY_CONCRETE_POWDER,
		GRAY_GLAZED_TERRACOTTA,
		GRAY_SHULKER_BOX,
		GRAY_STAINED_GLASS,
		GRAY_STAINED_GLASS_PANE_TOP,
		GRAY_TERRACOTTA,
		GRAY_WOOL,
		GREEN_CANDLE,
		GREEN_CANDLE_LIT,
		GREEN_CONCRETE,
		GREEN_CONCRETE_POWDER,
		GREEN_GLAZED_TERRACOTTA,
		GREEN_SHULKER_BOX,
		GREEN_STAINED_GLASS,
		GREEN_STAINED_GLASS_PANE_TOP,
		GREEN_TERRACOTTA,
		GREEN_WOOL,
		GRINDSTONE_PIVOT,
		GRINDSTONE_ROUND,
		GRINDSTONE_SIDE,
		HANGING_ROOTS,
		HAY_BLOCK_SIDE,
		HAY_BLOCK_TOP,
		HONEY_BLOCK_BOTTOM,
		HONEY_BLOCK_SIDE,
		HONEY_BLOCK_TOP,
		HONEYCOMB_BLOCK,
		HOPPER_INSIDE,
		HOPPER_OUTSIDE,
		HOPPER_TOP,
		HORN_CORAL,
		HORN_CORAL_BLOCK,
		HORN_CORAL_FAN,
		ICE,
		IRON_BARS,
		IRON_BLOCK,
		IRON_DOOR_BOTTOM,
		IRON_DOOR_TOP,
		IRON_ORE,
		IRON_TRAPDOOR,
		ITEM_FRAME,
		JACK_O_LANTERN,
		JIGSAW_BOTTOM,
		JIGSAW_LOCK,
		JIGSAW_SIDE,
		JIGSAW_TOP,
		JUKEBOX_SIDE,
		JUKEBOX_TOP,
		JUNGLE_DOOR_BOTTOM,
		JUNGLE_DOOR_TOP,
		JUNGLE_LEAVES,
		JUNGLE_LOG,
		JUNGLE_LOG_TOP,
		JUNGLE_PLANKS,
		JUNGLE_SAPLING,
		JUNGLE_TRAPDOOR,
		KELP,
		KELP_PLANT,
		LADDER,
		LANTERN,
		LAPIS_BLOCK,
		LAPIS_ORE,
		LARGE_AMETHYST_BUD,
		LARGE_FERN_BOTTOM,
		LARGE_FERN_TOP,
		LAVA_FLOW,
		LAVA_STILL,
		LECTERN_BASE,
		LECTERN_FRONT,
		LECTERN_SIDES,
		LECTERN_TOP,
		LEVER,
		LIGHT_BLUE_CANDLE,
		LIGHT_BLUE_CANDLE_LIT,
		LIGHT_BLUE_CONCRETE,
		LIGHT_BLUE_CONCRETE_POWDER,
		LIGHT_BLUE_GLAZED_TERRACOTTA,
		LIGHT_BLUE_SHULKER_BOX,
		LIGHT_BLUE_STAINED_GLASS,
		LIGHT_BLUE_STAINED_GLASS_PANE_TOP,
		LIGHT_BLUE_TERRACOTTA,
		LIGHT_BLUE_WOOL,
		LIGHT_GRAY_CANDLE,
		LIGHT_GRAY_CANDLE_LIT,
		LIGHT_GRAY_CONCRETE,
		LIGHT_GRAY_CONCRETE_POWDER,
		LIGHT_GRAY_GLAZED_TERRACOTTA,
		LIGHT_GRAY_SHULKER_BOX,
		LIGHT_GRAY_STAINED_GLASS,
		LIGHT_GRAY_STAINED_GLASS_PANE_TOP,
		LIGHT_GRAY_TERRACOTTA,
		LIGHT_GRAY_WOOL,
		LIGHTNING_ROD,
		LIGHTNING_ROD_ON,
		LILAC_BOTTOM,
		LILAC_TOP,
		LILY_OF_THE_VALLEY,
		LILY_PAD,
		LIME_CANDLE,
		LIME_CANDLE_LIT,
		LIME_CONCRETE,
		LIME_CONCRETE_POWDER,
		LIME_GLAZED_TERRACOTTA,
		LIME_SHULKER_BOX,
		LIME_STAINED_GLASS,
		LIME_STAINED_GLASS_PANE_TOP,
		LIME_TERRACOTTA,
		LIME_WOOL,
		LODESTONE_SIDE,
		LODESTONE_TOP,
		LOOM_BOTTOM,
		LOOM_FRONT,
		LOOM_SIDE,
		LOOM_TOP,
		MAGENTA_CANDLE,
		MAGENTA_CANDLE_LIT,
		MAGENTA_CONCRETE,
		MAGENTA_CONCRETE_POWDER,
		MAGENTA_GLAZED_TERRACOTTA,
		MAGENTA_SHULKER_BOX,
		MAGENTA_STAINED_GLASS,
		MAGENTA_STAINED_GLASS_PANE_TOP,
		MAGENTA_TERRACOTTA,
		MAGENTA_WOOL,
		MAGMA,
		MANGROVE_DOOR_BOTTOM,
		MANGROVE_DOOR_TOP,
		MANGROVE_LEAVES,
		MANGROVE_LOG,
		MANGROVE_LOG_TOP,
		MANGROVE_PLANKS,
		MANGROVE_PROPAGULE,
		MANGROVE_PROPAGULE_HANGING,
		MANGROVE_ROOTS_SIDE,
		MANGROVE_ROOTS_TOP,
		MANGROVE_TRAPDOOR,
		MEDIUM_AMETHYST_BUD,
		MELON_SIDE,
		MELON_STEM,
		MELON_TOP,
		MOSS_BLOCK,
		MOSSY_COBBLESTONE,
		MOSSY_STONE_BRICKS,
		MUD,
		MUD_BRICKS,
		MUDDY_MANGROVE_ROOTS_SIDE,
		MUDDY_MANGROVE_ROOTS_TOP,
		MUSHROOM_BLOCK_INSIDE,
		MUSHROOM_STEM,
		MYCELIUM_SIDE,
		MYCELIUM_TOP,
		NETHER_BRICKS,
		NETHER_GOLD_ORE,
		NETHER_PORTAL,
		NETHER_QUARTZ_ORE,
		NETHER_SPROUTS,
		NETHER_WART_BLOCK,
		NETHER_WART_STAGE0,
		NETHER_WART_STAGE1,
		NETHER_WART_STAGE2,
		NETHERITE_BLOCK,
		NETHERRACK,
		NOTE_BLOCK,
		OAK_DOOR_BOTTOM,
		OAK_DOOR_TOP,
		OAK_LEAVES,
		OAK_LOG,
		OAK_LOG_TOP,
		OAK_PLANKS,
		OAK_SAPLING,
		OAK_TRAPDOOR,
		OBSERVER_BACK,
		OBSERVER_BACK_ON,
		OBSERVER_FRONT,
		OBSERVER_SIDE,
		OBSERVER_TOP,
		OBSIDIAN,
		OCHRE_FROGLIGHT_SIDE,
		OCHRE_FROGLIGHT_TOP,
		ORANGE_CANDLE,
		ORANGE_CANDLE_LIT,
		ORANGE_CONCRETE,
		ORANGE_CONCRETE_POWDER,
		ORANGE_GLAZED_TERRACOTTA,
		ORANGE_SHULKER_BOX,
		ORANGE_STAINED_GLASS,
		ORANGE_STAINED_GLASS_PANE_TOP,
		ORANGE_TERRACOTTA,
		ORANGE_TULIP,
		ORANGE_WOOL,
		OXEYE_DAISY,
		OXIDIZED_COPPER,
		OXIDIZED_CUT_COPPER,
		PACKED_ICE,
		PACKED_MUD,
		PEARLESCENT_FROGLIGHT_SIDE,
		PEARLESCENT_FROGLIGHT_TOP,
		PEONY_BOTTOM,
		PEONY_TOP,
		PINK_CANDLE,
		PINK_CANDLE_LIT,
		PINK_CONCRETE,
		PINK_CONCRETE_POWDER,
		PINK_GLAZED_TERRACOTTA,
		PINK_SHULKER_BOX,
		PINK_STAINED_GLASS,
		PINK_STAINED_GLASS_PANE_TOP,
		PINK_TERRACOTTA,
		PINK_TULIP,
		PINK_WOOL,
		PISTON_BOTTOM,
		PISTON_INNER,
		PISTON_SIDE,
		PISTON_TOP,
		PISTON_TOP_STICKY,
		PODZOL_SIDE,
		PODZOL_TOP,
		POINTED_DRIPSTONE_DOWN_BASE,
		POINTED_DRIPSTONE_DOWN_FRUSTUM,
		POINTED_DRIPSTONE_DOWN_MIDDLE,
		POINTED_DRIPSTONE_DOWN_TIP,
		POINTED_DRIPSTONE_DOWN_TIP_MERGE,
		POINTED_DRIPSTONE_UP_BASE,
		POINTED_DRIPSTONE_UP_FRUSTUM,
		POINTED_DRIPSTONE_UP_MIDDLE,
		POINTED_DRIPSTONE_UP_TIP,
		POINTED_DRIPSTONE_UP_TIP_MERGE,
		POLISHED_ANDESITE,
		POLISHED_BASALT_SIDE,
		POLISHED_BASALT_TOP,
		POLISHED_BLACKSTONE,
		POLISHED_BLACKSTONE_BRICKS,
		POLISHED_DEEPSLATE,
		POLISHED_DIORITE,
		POLISHED_GRANITE,
		POPPY,
		POTATOES_STAGE0,
		POTATOES_STAGE1,
		POTATOES_STAGE2,
		POTATOES_STAGE3,
		POTTED_AZALEA_BUSH_PLANT,
		POTTED_AZALEA_BUSH_SIDE,
		POTTED_AZALEA_BUSH_TOP,
		POTTED_FLOWERING_AZALEA_BUSH_PLANT,
		POTTED_FLOWERING_AZALEA_BUSH_SIDE,
		POTTED_FLOWERING_AZALEA_BUSH_TOP,
		POWDER_SNOW,
		POWERED_RAIL,
		POWERED_RAIL_ON,
		PRISMARINE,
		PRISMARINE_BRICKS,
		PUMPKIN_SIDE,
		PUMPKIN_STEM,
		PUMPKIN_TOP,
		PURPLE_CANDLE,
		PURPLE_CANDLE_LIT,
		PURPLE_CONCRETE,
		PURPLE_CONCRETE_POWDER,
		PURPLE_GLAZED_TERRACOTTA,
		PURPLE_SHULKER_BOX,
		PURPLE_STAINED_GLASS,
		PURPLE_STAINED_GLASS_PANE_TOP,
		PURPLE_TERRACOTTA,
		PURPLE_WOOL,
		PURPUR_BLOCK,
		PURPUR_PILLAR,
		PURPUR_PILLAR_TOP,
		QUARTZ_BLOCK_BOTTOM,
		QUARTZ_BLOCK_SIDE,
		QUARTZ_BLOCK_TOP,
		QUARTZ_BRICKS,
		QUARTZ_PILLAR,
		QUARTZ_PILLAR_TOP,
		RAIL,
		RAIL_CORNER,
		RAW_COPPER_BLOCK,
		RAW_GOLD_BLOCK,
		RAW_IRON_BLOCK,
		RED_CANDLE,
		RED_CANDLE_LIT,
		RED_CONCRETE,
		RED_CONCRETE_POWDER,
		RED_GLAZED_TERRACOTTA,
		RED_MUSHROOM,
		RED_MUSHROOM_BLOCK,
		RED_NETHER_BRICKS,
		RED_SAND,
		RED_SANDSTONE,
		RED_SANDSTONE_BOTTOM,
		RED_SANDSTONE_TOP,
		RED_SHULKER_BOX,
		RED_STAINED_GLASS,
		RED_STAINED_GLASS_PANE_TOP,
		RED_TERRACOTTA,
		RED_TULIP,
		RED_WOOL,
		REDSTONE_BLOCK,
		REDSTONE_DUST_DOT,
		REDSTONE_DUST_LINE0,
		REDSTONE_DUST_LINE1,
		REDSTONE_DUST_OVERLAY,
		REDSTONE_LAMP,
		REDSTONE_LAMP_ON,
		REDSTONE_ORE,
		REDSTONE_TORCH,
		REDSTONE_TORCH_OFF,
		REINFORCED_DEEPSLATE_BOTTOM,
		REINFORCED_DEEPSLATE_SIDE,
		REINFORCED_DEEPSLATE_TOP,
		REPEATER,
		REPEATER_ON,
		REPEATING_COMMAND_BLOCK_BACK,
		REPEATING_COMMAND_BLOCK_CONDITIONAL,
		REPEATING_COMMAND_BLOCK_FRONT,
		REPEATING_COMMAND_BLOCK_SIDE,
		RESPAWN_ANCHOR_BOTTOM,
		RESPAWN_ANCHOR_SIDE0,
		RESPAWN_ANCHOR_SIDE1,
		RESPAWN_ANCHOR_SIDE2,
		RESPAWN_ANCHOR_SIDE3,
		RESPAWN_ANCHOR_SIDE4,
		RESPAWN_ANCHOR_TOP,
		RESPAWN_ANCHOR_TOP_OFF,
		ROOTED_DIRT,
		ROSE_BUSH_BOTTOM,
		ROSE_BUSH_TOP,
		SAND,
		SANDSTONE,
		SANDSTONE_BOTTOM,
		SANDSTONE_TOP,
		SCAFFOLDING_BOTTOM,
		SCAFFOLDING_SIDE,
		SCAFFOLDING_TOP,
		SCULK,
		SCULK_CATALYST_BOTTOM,
		SCULK_CATALYST_SIDE,
		SCULK_CATALYST_SIDE_BLOOM,
		SCULK_CATALYST_TOP,
		SCULK_CATALYST_TOP_BLOOM,
		SCULK_SENSOR_BOTTOM,
		SCULK_SENSOR_SIDE,
		SCULK_SENSOR_TENDRIL_ACTIVE,
		SCULK_SENSOR_TENDRIL_INACTIVE,
		SCULK_SENSOR_TOP,
		SCULK_SHRIEKER_BOTTOM,
		SCULK_SHRIEKER_CAN_SUMMON_INNER_TOP,
		SCULK_SHRIEKER_INNER_TOP,
		SCULK_SHRIEKER_SIDE,
		SCULK_SHRIEKER_TOP,
		SCULK_VEIN,
		SEA_LANTERN,
		SEA_PICKLE,
		SEAGRASS,
		SHROOMLIGHT,
		SHULKER_BOX,
		SLIME_BLOCK,
		SMALL_AMETHYST_BUD,
		SMALL_DRIPLEAF_SIDE,
		SMALL_DRIPLEAF_STEM_BOTTOM,
		SMALL_DRIPLEAF_STEM_TOP,
		SMALL_DRIPLEAF_TOP,
		SMITHING_TABLE_BOTTOM,
		SMITHING_TABLE_FRONT,
		SMITHING_TABLE_SIDE,
		SMITHING_TABLE_TOP,
		SMOKER_BOTTOM,
		SMOKER_FRONT,
		SMOKER_FRONT_ON,
		SMOKER_SIDE,
		SMOKER_TOP,
		SMOOTH_BASALT,
		SMOOTH_STONE,
		SMOOTH_STONE_SLAB_SIDE,
		SNOW,
		SOUL_CAMPFIRE_FIRE,
		SOUL_CAMPFIRE_LOG_LIT,
		SOUL_FIRE_0,
		SOUL_FIRE_1,
		SOUL_LANTERN,
		SOUL_SAND,
		SOUL_SOIL,
		SOUL_TORCH,
		SPAWNER,
		SPONGE,
		SPORE_BLOSSOM,
		SPORE_BLOSSOM_BASE,
		SPRUCE_DOOR_BOTTOM,
		SPRUCE_DOOR_TOP,
		SPRUCE_LEAVES,
		SPRUCE_LOG,
		SPRUCE_LOG_TOP,
		SPRUCE_PLANKS,
		SPRUCE_SAPLING,
		SPRUCE_TRAPDOOR,
		STONE,
		STONE_BRICKS,
		STONECUTTER_BOTTOM,
		STONECUTTER_SAW,
		STONECUTTER_SIDE,
		STONECUTTER_TOP,
		STRIPPED_ACACIA_LOG,
		STRIPPED_ACACIA_LOG_TOP,
		STRIPPED_BIRCH_LOG,
		STRIPPED_BIRCH_LOG_TOP,
		STRIPPED_CRIMSON_STEM,
		STRIPPED_CRIMSON_STEM_TOP,
		STRIPPED_DARK_OAK_LOG,
		STRIPPED_DARK_OAK_LOG_TOP,
		STRIPPED_JUNGLE_LOG,
		STRIPPED_JUNGLE_LOG_TOP,
		STRIPPED_MANGROVE_LOG,
		STRIPPED_MANGROVE_LOG_TOP,
		STRIPPED_OAK_LOG,
		STRIPPED_OAK_LOG_TOP,
		STRIPPED_SPRUCE_LOG,
		STRIPPED_SPRUCE_LOG_TOP,
		STRIPPED_WARPED_STEM,
		STRIPPED_WARPED_STEM_TOP,
		STRUCTURE_BLOCK,
		STRUCTURE_BLOCK_CORNER,
		STRUCTURE_BLOCK_DATA,
		STRUCTURE_BLOCK_LOAD,
		STRUCTURE_BLOCK_SAVE,
		SUGAR_CANE,
		SUNFLOWER_BACK,
		SUNFLOWER_BOTTOM,
		SUNFLOWER_FRONT,
		SUNFLOWER_TOP,
		SWEET_BERRY_BUSH_STAGE0,
		SWEET_BERRY_BUSH_STAGE1,
		SWEET_BERRY_BUSH_STAGE2,
		SWEET_BERRY_BUSH_STAGE3,
		TALL_GRASS_BOTTOM,
		TALL_GRASS_TOP,
		TALL_SEAGRASS_BOTTOM,
		TALL_SEAGRASS_TOP,
		TARGET_SIDE,
		TARGET_TOP,
		TERRACOTTA,
		TINTED_GLASS,
		TNT_BOTTOM,
		TNT_SIDE,
		TNT_TOP,
		TORCH,
		TRIPWIRE,
		TRIPWIRE_HOOK,
		TUBE_CORAL,
		TUBE_CORAL_BLOCK,
		TUBE_CORAL_FAN,
		TUFF,
		TURTLE_EGG,
		TURTLE_EGG_SLIGHTLY_CRACKED,
		TURTLE_EGG_VERY_CRACKED,
		TWISTING_VINES,
		TWISTING_VINES_PLANT,
		VERDANT_FROGLIGHT_SIDE,
		VERDANT_FROGLIGHT_TOP,
		VINE,
		WARPED_DOOR_BOTTOM,
		WARPED_DOOR_TOP,
		WARPED_FUNGUS,
		WARPED_NYLIUM,
		WARPED_NYLIUM_SIDE,
		WARPED_PLANKS,
		WARPED_ROOTS,
		WARPED_ROOTS_POT,
		WARPED_STEM,
		WARPED_STEM_TOP,
		WARPED_TRAPDOOR,
		WARPED_WART_BLOCK,
		WATER_FLOW,
		WATER_OVERLAY,
		WATER_STILL,
		WEATHERED_COPPER,
		WEATHERED_CUT_COPPER,
		WEEPING_VINES,
		WEEPING_VINES_PLANT,
		WET_SPONGE,
		WHEAT_STAGE0,
		WHEAT_STAGE1,
		WHEAT_STAGE2,
		WHEAT_STAGE3,
		WHEAT_STAGE4,
		WHEAT_STAGE5,
		WHEAT_STAGE6,
		WHEAT_STAGE7,
		WHITE_CANDLE,
		WHITE_CANDLE_LIT,
		WHITE_CONCRETE,
		WHITE_CONCRETE_POWDER,
		WHITE_GLAZED_TERRACOTTA,
		WHITE_SHULKER_BOX,
		WHITE_STAINED_GLASS,
		WHITE_STAINED_GLASS_PANE_TOP,
		WHITE_TERRACOTTA,
		WHITE_TULIP,
		WHITE_WOOL,
		WITHER_ROSE,
		YELLOW_CANDLE,
		YELLOW_CANDLE_LIT,
		YELLOW_CONCRETE,
		YELLOW_CONCRETE_POWDER,
		YELLOW_GLAZED_TERRACOTTA,
		YELLOW_SHULKER_BOX,
		YELLOW_STAINED_GLASS,
		YELLOW_STAINED_GLASS_PANE_TOP,
		YELLOW_TERRACOTTA,
		YELLOW_WOOL;
	std::vector<TextureImage*> textures;
};

} // namespace renderer
} // namespace mapcrafter

#endif /* BLOCKTEXTURES_H_ */
