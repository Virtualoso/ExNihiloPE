#pragma once

#include "../blockentity/BlockEntityBase.h"

class BlockInfestedLeaves : public BlockEntityBase {
public:
	BlockInfestedLeaves(const std::string&, int);
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual void playerDestroy(Player*, const BlockPos&, int) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual int getVariant(int) const;
	virtual unsigned int getColor(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual std::unique_ptr<BlockEntity> createBlockEntity(const BlockPos&);

	static void infestLeafBlock(BlockSource&, const BlockPos&);
};