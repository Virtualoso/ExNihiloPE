#pragma once

#include <map>
#include <vector>
#include <string>

class ItemInfo;
class HammerReward;
class Block;
class ItemInstance;
class Random;

class HammerRegistry {
private:
	static std::map<ItemInfo*, std::vector<HammerReward*>> registry;

public:
	static void loadJson(const std::string&);
	static void saveJson(const std::string&);
	static void addHammerRecipe(Block*, int, ItemInstance*, int, float, float);
	static void registerRecipe(Block*, int, ItemInstance*, int, float, float);
	static void registerRecipe(Block*, int, ItemInstance*, int, float, float, bool);
	static std::vector<ItemInstance*> getRewardDrops(Random&, Block*, int, int, int);
	static std::vector<HammerReward*> getRewards(Block*, int);
	static bool registered(const Block*);
	static void registerDefaults();
	static std::vector<HammerReward*> getRewards(Block*, int, int);
	static std::vector<HammerReward*> getRegistryValue(ItemInfo*);
};