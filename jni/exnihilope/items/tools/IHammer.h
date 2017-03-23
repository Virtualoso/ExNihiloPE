#pragma once

class ItemInstance;

class IHammer {
public:
	virtual bool isHammer(const ItemInstance&) = 0;
	virtual int getMiningLevel(const ItemInstance&) = 0;
};
