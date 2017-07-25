#include "BlockEntityRegistry.h"

#include "BlockEntityBase.h"

#include "mcpe/block/entity/BlockEntityType.h"
#include "mcpe/block/entity/BlockEntity.h"

std::vector<BlockEntityBase*> BlockEntityRegistry::owners;

void BlockEntityRegistry::registerBlockEntity(BlockEntityBase* owner, const std::string& id) {
	if(owner == NULL || owner->blockEntityType == BlockEntityType::None || id.empty())
		return;

	BlockEntity::setId(owner->blockEntityType, id);
	owners.push_back(owner);
}