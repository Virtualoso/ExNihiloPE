#pragma once

#include "mcpe/block/EntityBlock.h"

class BlockInfestedLeaves : public EntityBlock {
public:
	BlockInfestedLeaves(int);
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual void playerDestroy(Player*, const BlockPos&, int) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual int getVariant(int) const;
	virtual int getColor(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;

	static void infestLeafBlock(BlockSource&, const BlockPos&);
};