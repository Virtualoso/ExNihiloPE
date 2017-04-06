#pragma once

class ItemInstance;

class IHammer {
public:
	virtual int getMiningLevel(const ItemInstance&) = 0;
};
