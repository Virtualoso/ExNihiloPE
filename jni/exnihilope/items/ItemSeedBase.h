#pragma once

#include "mcpe/item/Item.h"

class ItemSeedBase : public Item {
private:
	unsigned char plantId;
	unsigned char plantData;
public:
	ItemSeedBase(const std::string&, int, Block*, unsigned char);

	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
};