#pragma once


//Honestly I lost track of which ones are needed...
#include "mcpe/item/Item.h"
#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/BlockShape.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/Vec3.h"
#include "mcpe/util/Color.h"
#include "mcpe/level/BlockSource.h"

#include "mcpe/entity/Entity.h"

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
	
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	
	static Item* mCrookWood;
	static Item* mCrookBone;

	static Item* mHammerWood;
	static Item* mHammerStone;
	static Item* mHammerIron;
	static Item* mHammerGold;
	static Item* mHammerDiamond;
	
	static Item* mWorm;
	static Item* mWormCooked;
	
	static Block* mOakBarrel;
	static Block* mUnfiredCrucible;
	static Block* mCrucible;
	static Block* mSilkLeaves;
	static Block* mDust;
};

