#pragma once

#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/BlockShape.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/Vec3.h"

class ExNihiloDefaultRecipes;

class ExNihiloPE
{
public:
	static void initBlocks();
	static void initBlockItems();
	static void initBlockGraphics();
	static bool initBlockTessellator(BlockTessellator*,const Block&, const BlockPos&, uchar, bool);
	static void initCreativeBlocks();
	
	static Block* mOakBarrel;
	static Block* mUnfiredCrucible;
	static Block* mCrucible;

	static ExNihiloDefaultRecipes* defaultRecipes;
};

