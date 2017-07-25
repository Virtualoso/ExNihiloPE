#include "ItemCookedSilkworm.h"

#include "ENItems.h"

#include "mcpe/item/FoodItemComponent.h"

ItemCookedSilkworm::ItemCookedSilkworm(const std::string& name, int id) : Item(name, id) {
	setCategory(CreativeItemCategory::ITEMS);
	setUseAnimation(UseAnimation::EAT);
	setMaxUseDuration(1);
	foodComponent = std::unique_ptr<FoodItemComponent>(new FoodItemComponent(*this));
	foodComponent->nutrition = 2;
	foodComponent->saturationModifier = 0.6F;
	foodComponent->isMeat = false;
}