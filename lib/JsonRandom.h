/*
 * JsonRandom.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

#include "GameConstants.h"
#include "ResourceSet.h"

VCMI_LIB_NAMESPACE_BEGIN

class JsonNode;
using JsonVector = std::vector<JsonNode>;
class CRandomGenerator;

struct Bonus;
struct Component;
class CStackBasicDescriptor;

namespace JsonRandom
{
	using Variables = std::map<std::string, int>;

	struct DLL_LINKAGE RandomStackInfo
	{
		std::vector<const CCreature *> allowedCreatures;
		si32 minAmount;
		si32 maxAmount;
	};

	DLL_LINKAGE si32 loadValue(const JsonNode & value, CRandomGenerator & rng, const Variables & variables, si32 defaultValue = 0);

	DLL_LINKAGE TResources loadResources(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE TResources loadResource(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE std::vector<si32> loadPrimary(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE SecondarySkill loadSecondary(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE std::map<SecondarySkill, si32> loadSecondaries(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);

	DLL_LINKAGE ArtifactID loadArtifact(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE std::vector<ArtifactID> loadArtifacts(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);

	DLL_LINKAGE SpellID loadSpell(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE std::vector<SpellID> loadSpells(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);

	DLL_LINKAGE CStackBasicDescriptor loadCreature(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE std::vector<CStackBasicDescriptor> loadCreatures(const JsonNode & value, CRandomGenerator & rng, const Variables & variables);
	DLL_LINKAGE std::vector<RandomStackInfo> evaluateCreatures(const JsonNode & value, const Variables & variables);

	DLL_LINKAGE std::vector<PlayerColor> loadColors(const JsonNode & value, CRandomGenerator & rng);
	DLL_LINKAGE std::vector<HeroTypeID> loadHeroes(const JsonNode & value, CRandomGenerator & rng);
	DLL_LINKAGE std::vector<HeroClassID> loadHeroClasses(const JsonNode & value, CRandomGenerator & rng);

	DLL_LINKAGE std::vector<Bonus> loadBonuses(const JsonNode & value);
}

VCMI_LIB_NAMESPACE_END
