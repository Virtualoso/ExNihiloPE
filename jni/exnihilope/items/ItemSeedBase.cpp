#include "ItemSeedBase.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/block/Block.h"
#include "mcpe/level/BlockPos.h"

ItemSeedBase::ItemSeedBase(const std::string& name, int id, Block* plant, unsigned char _plantData)
	: Item(name, id) {
	
	setCategory(CreativeItemCategory::ITEMS);
	plantId = plant->blockId;
	plantData = _plantData;
}

bool ItemSeedBase::_useOn(ItemInstance& item, Entity& player, BlockPos pos, signed char side, float hitX, float hitY, float hitZ) const {
	if(side == 1) {
		if(Block::mBlocks[plantId]->mayPlace(*player.getRegion(), {pos.x, pos.y + 1, pos.z}) && Block::mBlocks[plantId]->mayPlaceOn(*player.getRegion()->getBlock(pos)) && player.getRegion()->isEmptyBlock({pos.x, pos.y + 1, pos.z})) {
			if(player.getRegion()->setBlockAndData({pos.x, pos.y + 1, pos.z}, FullBlock(BlockID(plantId), plantData), 3, &player)) {
				item.count--;
				return true;
			}
		}
	}

	return false;
}