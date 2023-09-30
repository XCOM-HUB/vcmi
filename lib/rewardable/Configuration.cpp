/*
 * Configuration.cpp, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */

#include "StdInc.h"
#include "Configuration.h"
#include "../serializer/JsonSerializeFormat.h"

VCMI_LIB_NAMESPACE_BEGIN

Rewardable::EVisitMode Rewardable::Configuration::getVisitMode() const
{
	return static_cast<EVisitMode>(visitMode);
}

ui16 Rewardable::Configuration::getResetDuration() const
{
	return resetParameters.period;
}

std::optional<int> Rewardable::Configuration::getVariable(const std::string & category, const std::string & name) const
{
	std::string variableID = category + '@' + name;

	if (variables.values.count(variableID))
		return variables.values.at(variableID);

	return std::nullopt;
}

JsonNode Rewardable::Configuration::getPresetVariable(const std::string & category, const std::string & name) const
{
	std::string variableID = category + '@' + name;

	if (variables.values.count(variableID))
		return variables.preset.at(variableID);
	else
		return JsonNode();
}

void Rewardable::Configuration::presetVariable(const std::string & category, const std::string & name, const JsonNode & value)
{
	std::string variableID = category + '@' + name;
	variables.preset[variableID] = value;
}

void Rewardable::Configuration::initVariable(const std::string & category, const std::string & name, int value)
{
	std::string variableID = category + '@' + name;
	variables.values[variableID] = value;
}

void Rewardable::ResetInfo::serializeJson(JsonSerializeFormat & handler)
{
	handler.serializeInt("period", period);
	handler.serializeBool("visitors", visitors);
	handler.serializeBool("rewards", rewards);
}

void Rewardable::VisitInfo::serializeJson(JsonSerializeFormat & handler)
{
	handler.serializeStruct("limiter", limiter);
	handler.serializeStruct("reward", reward);
	handler.serializeStruct("message", message);
	handler.serializeInt("visitType", visitType);
}

void Rewardable::Variables::serializeJson(JsonSerializeFormat & handler)
{
	// TODO
}

void Rewardable::Configuration::serializeJson(JsonSerializeFormat & handler)
{
	handler.serializeStruct("onSelect", onSelect);
	handler.enterArray("info").serializeStruct(info);
	handler.serializeEnum("selectMode", selectMode, std::vector<std::string>{SelectModeString.begin(), SelectModeString.end()});
	handler.serializeEnum("visitMode", visitMode, std::vector<std::string>{VisitModeString.begin(), VisitModeString.end()});
	handler.serializeStruct("resetParameters", resetParameters);
	handler.serializeBool("canRefuse", canRefuse);
	handler.serializeInt("infoWindowType", infoWindowType);
}

VCMI_LIB_NAMESPACE_END
