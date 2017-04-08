#include "CrookBase.h"

#include "../ENItems.h"

#include "database/CrookDatabase.h"
#include "../../registries/CrookRegistry.h"

CrookBase::CrookBase(const std::string& name, int maxUses)
	: ToolItem(name, ENItems::getNextItemId() - 0x100, 0.0F, Item::Tier::WOOD, {}) {

	setMaxDamage(maxUses);
	Item::mItems[itemId] = this;
	CrookDatabase::registerCrook(this);
}

float CrookBase::getDestroySpeed(ItemInstance* item, const Block* block) {
	return CrookRegistry::registered(block) ? efficiencyOnProperMaterial : 1.0F;
}
