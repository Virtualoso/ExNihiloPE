#pragma once

#include "mcpe/item/Item.h"

class Hammer : public Item{
public:
	Hammer(short itemId, int type);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual float getDestroySpeed(ItemInstance*, Block const*);
};