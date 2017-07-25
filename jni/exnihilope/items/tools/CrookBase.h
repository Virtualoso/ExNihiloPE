#pragma once

#include "mcpe/item/ToolItem.h"

class CrookBase : public ToolItem {
public:
	CrookBase(const std::string&, int, int);

	virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
};