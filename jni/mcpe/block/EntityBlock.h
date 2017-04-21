#pragma once

#include <memory>

#include "Block.h"

class BlockEntity;

class EntityBlock : public Block {
public:
    EntityBlock(std::string const&, int, Material const&);

    virtual ~EntityBlock() {}
    virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&) const;
    virtual void triggerEvent(BlockSource&, BlockPos const&, int, int) const;

    std::unique_ptr<BlockEntity> newBlockEntity(BlockPos const&, BlockID) const;
};