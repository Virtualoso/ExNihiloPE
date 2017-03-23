#pragma once

#include <vector>

class HammerBase;

class ENItems {
public:
	static HammerBase* hammerWood;
	static HammerBase* hammerStone;
	static HammerBase* hammerIron;
	static HammerBase* hammerDiamond;
	static HammerBase* hammerGold;

	static void init();
	static void initCreativeItems();

	static int index;
	static std::vector<int> freeIds;
	static void registerItemIds();
	static int getNextItemId();
};