#include "HammerBase.h"

#include "../ENItems.h"

HammerBase::HammerBase(const std::string& name, int maxUses, Item::Tier material)
	: ToolItem(name, ENItems::getNextItemId() - 0x100, 0.0F, material, {}) {

	setMaxDamage(maxUses);
	miningLevel = material.harvestLevel;
	Item::mItems[itemId] = this;
}

bool HammerBase::isHammer(const ItemInstance& item) {
	return true;
}

int HammerBase::getMiningLevel(const ItemInstance& item) {
	return miningLevel;
}

float HammerBase::getDestroySpeed(ItemInstance* item, const Block* block) {
	//return HammerRegistry::registered(block) ? efficiencyOnProperMaterial : 1.0F;
	return 1.0F;
}

bool HammerBase::canDestroySpecial(Block const* block) const {
	return false; //HammerRegistry::registered(block);
}
