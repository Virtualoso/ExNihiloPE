#pragma once

#include "mcpe/item/ToolItem.h"

class CrookBase : public ToolItem {
public:
	CrookBase(const std::string&, int);

	virtual float getDestroySpeed(ItemInstance*, const Block*);
};