#include "CrookDatabase.h"

#include <algorithm>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"

std::vector<Item*> CrookDatabase::crookDatabase;

void CrookDatabase::registerCrook(Item* crook) {
	crookDatabase.emplace_back(crook);
}

bool CrookDatabase::isCrook(ItemInstance* item) {
	return std::find(std::begin(crookDatabase), std::end(crookDatabase), item->item) != std::end(crookDatabase);
}