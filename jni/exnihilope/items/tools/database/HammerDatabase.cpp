#include "HammerDatabase.h"

#include <algorithm>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"

std::vector<Item*> HammerDatabase::hammerDatabase;

void HammerDatabase::registerHammer(Item* hammer) {
	hammerDatabase.emplace_back(hammer);
}

bool HammerDatabase::isHammer(ItemInstance* item) {
	return std::find(std::begin(hammerDatabase), std::end(hammerDatabase), item->item) != std::end(hammerDatabase);
}