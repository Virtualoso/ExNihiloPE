#include "HandlerCrook.h"

#include <vector>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "mcpe/player/Player.h"
#include "mcpe/level/Level.h"
#include "mcpe/item/enchant/EnchantUtils.h"
#include "mcpe/block/Block.h"

#include "../items/tools/database/CrookDatabase.h"
#include "../registries/CrookRegistry.h"
#include "../registries/types/CrookReward.h"

bool HandlerCrook::crook(Block* block, int meta, const BlockPos& pos, Player* harvester) {
	if (harvester->getLevel()->isClientSide() || harvester == NULL) // isRemote, valid Player
		return false;

	ItemInstance* held = harvester->getSelectedItem();
		
	if (held == NULL || held->item == NULL || EnchantUtils::hasEnchant(16, *held) || !CrookDatabase::isCrook(held)) // is item invalid, is silktouching, is not crook
		return false;

	int fortune = EnchantUtils::getEnchantLevel(18, *held);

	std::vector<CrookReward*> rewards = CrookRegistry::getRewards(block, meta);
	if (rewards.size() > 0) {
		for(CrookReward* reward : rewards) {
			if (harvester->getLevel()->getRandom()->nextFloat() <= reward->getChance() + (reward->getFortuneChance() * fortune)) {
				block->popResource(*(harvester->getRegion()), pos, reward->getStack()->clone());
			}
		}
	}
	if (block == Block::mLeaves || block == Block::mLeaves2) { //Simulate vanilla drops
		for (int i = 0 ; i < 4; i++) { // todo config
			block->spawnResources(*(harvester->getRegion()), pos, meta, 1.0F, fortune);
		}
	}
	else {
		return false;
	}

	harvester->causeFoodExhaustion(0.025F);

	return true;
}