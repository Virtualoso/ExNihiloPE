#include "HandlerHammer.h"

#include <vector>
#include <sstream>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/Level.h"
#include "mcpe/item/enchant/EnchantUtils.h"
#include "mcpe/block/Block.h"

#include "../items/tools/HammerBase.h"
#include "../items/tools/database/HammerDatabase.h"
#include "../registries/HammerRegistry.h"

bool HandlerHammer::hammer(Block* block, int meta, const BlockPos& pos, Player* harvester) {
	if (harvester->getLevel().isClientSide() || harvester == NULL || EnchantUtils::hasEnchant(16, *(harvester->getSelectedItem()))) // isRemote, valid Player, is silk touching
		return false;

	ItemInstance* held = harvester->getSelectedItem();
		
	if (held == NULL || held->item == NULL || !HammerDatabase::isHammer(held))
		return false;

	std::vector<ItemInstance*> rewards = HammerRegistry::getRewardDrops(harvester->getLevel().getRandom(), block, meta, ((HammerBase*) held->item)->getMiningLevel(*held), EnchantUtils::getEnchantLevel(18, *(harvester->getSelectedItem())));
		
	if (rewards.size() > 0) {
		for(ItemInstance* item : rewards) {
			block->popResource(harvester->getRegion(), pos, *item);
		}
	}
	else {
		return false;
	}

	harvester->causeFoodExhaustion(0.025F);

	return true;
}