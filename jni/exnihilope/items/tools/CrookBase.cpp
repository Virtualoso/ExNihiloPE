#include "CrookBase.h"

#include "../ENItems.h"

#include "database/CrookDatabase.h"
#include "../../registries/CrookRegistry.h"

CrookBase::CrookBase(const std::string& name, int id, int maxUses)
	: ToolItem(name, id, 0.0F, Item::Tier::WOOD, {}) {

	setMaxDamage(maxUses);
	CrookDatabase::registerCrook(this);
}

float CrookBase::getDestroySpeed(const ItemInstance& item, const Block& block) const {
	return CrookRegistry::registered(&block) ? efficiencyOnProperMaterial : 1.0F;
}
