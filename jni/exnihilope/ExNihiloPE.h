#pragma once

#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/item/BlockItem.h"
#include "minecraftpe/world/level/block/Block.h"
#include "minecraftpe/world/level/block/BlockGraphics.h"

class ExNihiloPE
{
public:
	static void initItems();
	static void initBlocks();
	static void initBlockItems();
	static void initBlockGraphics();
	static void initCreativeItems();
	static void initCreativeBlocks();
	
	static Item* mCrookWood;
	static Item* mCrookBone;

	static Item* mHammerWood;
	static Item* mHammerStone;
	static Item* mHammerIron;
	static Item* mHammerGold;
	static Item* mHammerDiamond;
	
	static Block* mOakBarrel;
	static Block* mUnfiredCrucible;
	static Block* mCrucible;
};

