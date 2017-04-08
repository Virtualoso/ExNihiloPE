#pragma once

#include <map>
#include <vector>
#include <string>

class BlockInfo;
class CrookReward;
class Block;
class ItemInstance;
class Random;

class CrookRegistry {
private:
	static std::map<BlockInfo*, std::vector<CrookReward*>> registry;
	static std::map<BlockInfo*, std::vector<CrookReward*>> externalRegistry;

	static void registerInternal(BlockInfo*, ItemInstance*, float, float);

public:
	static void loadJson(const std::string&);
	static void saveJson(const std::string&);
	static void addCrookRecipe(BlockInfo*, ItemInstance*, float, float);
	static void registerRecipe(BlockInfo*, ItemInstance*, float, float);
	static std::vector<CrookReward*> getRewards(Block*, int);
	static bool registered(const Block*);
	static void registerDefaults();
	static std::vector<CrookReward*> getRegistryValue(BlockInfo*);
	static std::vector<CrookReward*> getExternalRegistryValue(BlockInfo*);
};