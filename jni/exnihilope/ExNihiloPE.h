#pragma once

#include "mcpe/item/Item.h"
#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/BlockShape.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/Vec3.h"

class ExNihiloPE
{
public:
	static void initItems();
	static void initBlocks();
	static void initBlockItems();
	static void initBlockGraphics();
	static bool initBlockTessellator(BlockTessellator*,const Block&, const BlockPos&, uchar, bool);
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

