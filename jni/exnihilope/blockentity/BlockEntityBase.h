#pragma once

#include "mcpe\block\EntityBlock.h"

class BlockEntityBase : public EntityBlock {
public:
	BlockEntityBase(const std::string& descriptionId, int id, const Material& material);

	virtual ~BlockEntityBase();
	virtual std::unique_ptr<BlockEntity> createBlockEntity(const BlockPos& pos) = 0;
};