#pragma once

#include "mcpe/item/Item.h"
#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/BlockShape.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/Vec3.h"
#include "mcpe/util/Color.h"

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
	
	static Item* mAncientSpores;
	static Item* mDoll;
	static Item* mDollBlaze;
	static Item* mDollEnder;
	static Item* mGrassSeeds;
	static Item* mPebble;
	static Item* mPorcelainClay;
	static Item* mAcaciaSeed;
	static Item* mBirchSeed;
	static Item* mCactusSeed;
	static Item* mCarrotSeed;
	static Item* mDarkoakSeed;
	static Item* mJungleSeed;
	static Item* mOakSeed;
	static Item* mPotatoSeed;
	static Item* mSpruceSeed;
	static Item* mSugarcaneSeed;
	static Item* mCrookWood;
	static Item* mCrookBone;
	static Item* mHammerWood;
	static Item* mHammerStone;
	static Item* mHammerIron;
	static Item* mHammerGold;
	static Item* mHammerDiamond;
	static Item* mSilkWorm;
	static Item* mCookedSilkWorm;
	
	static Block* mDust;
	static Block* mEndstoneCrushed;
	static Block* mNetherrackCrushed;
	static Block* mOakBarrel;
	static Block* mBirchBarrel;
	static Block* mSpruceBarrel;
	static Block* mDarkoakBarrel;
	static Block* mAcaciaBarrel;
	static Block* mJungleBarrel
	static Block* mOakSieve;
	static Block* mBirchSieve;
	static Block* mSpruceSieve;
	static Block* mDarkoakSieve;
	static Block* mAcaciaSieve;
	static Block* mJungleSieve;
	static Block* mUnfiredCrucible;
	static Block* mCrucible;
	static Block* mSilkLeaves;
};

