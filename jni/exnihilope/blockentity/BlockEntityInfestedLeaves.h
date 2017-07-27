#pragma once

#include "mcpe/block/entity/BlockEntity.h"

class GuiData;

class BlockEntityInfestedLeaves : public BlockEntity {
private:
	int counter;
public:
	static GuiData* guiData;
	BlockEntityInfestedLeaves(const BlockPos&);
	
	virtual ~BlockEntityInfestedLeaves();
	virtual void load(CompoundTag const&);
	virtual bool save(CompoundTag&) const;

	void upCounter();
};