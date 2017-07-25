#include "HammerBase.h"

#include "../ENItems.h"

#include "database/HammerDatabase.h"
#include "../../registries/HammerRegistry.h"

HammerBase::HammerBase(const std::string& name, int id, int maxUses, Item::Tier material)
	: ToolItem(name, id, 0.0F, material, {}) {

	setMaxDamage(maxUses);
	miningLevel = material.harvestLevel;
	HammerDatabase::registerHammer(this);
}

int HammerBase::getMiningLevel(const ItemInstance& item) {
	return miningLevel;
}

float HammerBase::getDestroySpeed(const ItemInstance& item, const Block& block) const {
	return HammerRegistry::registered(&block) ? efficiencyOnProperMaterial : 1.0F;
}

bool HammerBase::canDestroySpecial(Block const& block) const {
	return HammerRegistry::registered(&block);
}
