#include "BlockEntityInfestedLeaves.h"

#include <utility>

#include "mcpe/nbt/CompoundTag.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/util/Util.h"

GuiData* BlockEntityInfestedLeaves::guiData;

BlockEntityInfestedLeaves::BlockEntityInfestedLeaves(const BlockPos& pos) : BlockEntity(BlockEntityType::InfestedLeaves, pos, "leaves") {
	counter = 0;
}

BlockEntityInfestedLeaves::~BlockEntityInfestedLeaves() {}

void BlockEntityInfestedLeaves::load(CompoundTag const& tag) {
	BlockEntity::load(tag);
	if(tag.contains("counter")) {
		counter = tag.getInt("counter");
	}
}

bool BlockEntityInfestedLeaves::save(CompoundTag& tag) const {
	if(BlockEntity::save(tag)) {
		tag.putInt("counter", counter);
		return true;
	}
	return false;
}

void BlockEntityInfestedLeaves::upCounter() {
	counter++;
	guiData->displayClientMessage(Util::toNiceString(counter));
	setChanged();
}