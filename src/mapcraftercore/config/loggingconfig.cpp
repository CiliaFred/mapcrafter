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

#include "loggingconfig.h"

#include "configparser.h"
#include "iniconfig.h"

namespace mapcrafter {
namespace config {

LoggingConfig::LoggingConfig() {
}

LoggingConfig::~LoggingConfig() {
}

ValidationMap LoggingConfig::parse(const std::string& filename) {
	ValidationMap validation;

	INIConfig config;
	try {
		config.loadFile(filename);
	} catch (INIConfigError& exception) {
		validation.section("Configuration file").error(exception.what());
		return validation;
	}

	ConfigParser parser(config);

	// use an empty root section to also get warnings for unknown entries here
	ConfigSection root_section;
	parser.parseRootSection(root_section);

	fs::path config_dir = BOOST_FS_ABSOLUTE1(fs::path(filename)).parent_path();
	parser.parseSections(log_sections, "log", ConfigDirSectionFactory<LogSection>(config_dir));

	parser.validate();
	return parser.getValidation();
}

const std::vector<LogSection>& LoggingConfig::getLogSections() {
	return log_sections;
}

const std::vector<LogSection> &LoggingConfig::getLogSections() { return log_sections; }

		LOG(WARNING) << "Unable to find a global logging configuration file!";
		return;
	}

	LoggingConfig config;

	if (!validation.isEmpty()) {
    ValidationMap validation = config.parse(logging_config.string());
    if (!validation.isEmpty()) {
        if (validation.isCritical())
            LOG(FATAL) << "Unable to parse global logging configuration file:";
		validation.log();
	}
	if (validation.isCritical())
		return;

	auto log_sections = config.getLogSections();
	for (auto it = log_sections.begin(); it != log_sections.end(); ++it)
		it->configureLogging();
}

} /* namespace config */
} /* namespace mapcrafter */
