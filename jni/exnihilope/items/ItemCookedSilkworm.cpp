#include "ItemCookedSilkworm.h"

#include "ENItems.h"

#include "mcpe/item/FoodItemComponent.h"

ItemCookedSilkworm::ItemCookedSilkworm() : Item("silkwormCooked", ENItems::getNextItemId() - 0x100) {
	setCategory(CreativeItemCategory::ITEMS);
	setUseAnimation(UseAnimation::EAT);
	setMaxUseDuration(1);
	_foodDetails = std::unique_ptr<FoodItemComponent>(new FoodItemComponent(*this));
	_foodDetails->healAmount = 2;
	_foodDetails->saturation = 0.6F;
	_foodDetails->isMeat = false;
	Item::mItems[itemId] = this;
}