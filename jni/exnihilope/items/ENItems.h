#pragma once

#include <vector>

class HammerBase;
class CrookBase;
class ItemResource;
class ItemCookedSilkworm;
class ItemSeedBase;

class ENItems {
public:
	static HammerBase* hammerWood;
	static HammerBase* hammerStone;
	static HammerBase* hammerIron;
	static HammerBase* hammerDiamond;
	static HammerBase* hammerGold;

	static CrookBase* crookWood;
	static CrookBase* crookBone;

	static ItemResource* resources;
	static ItemCookedSilkworm* cookedSilkworm;

	static std::vector<ItemSeedBase*> itemSeeds;

	static void init();
	static void initCreativeItems();
	static void loadResources();

	static int index;
	static std::vector<int> freeIds;
	static void registerItemIds();
	static int getNextItemId();
};