#pragma once

#include <string>

class Item;
class Block;
class FullBlock;
class CompoundTag;
class ItemInstance;

class ItemInfo {
private:
	Item* item;
	int meta;

public:
	static ItemInfo* getItemInfoFromStack(ItemInstance*);
	
	ItemInfo(ItemInstance*);
	ItemInfo(Block*, int);
	ItemInfo(const std::string&);
	ItemInfo(const FullBlock&);
	
	std::string toString();
	ItemInstance* getItemStack();
	CompoundTag* writeToNBT(CompoundTag*);
	
	static ItemInfo* readFromNBT(CompoundTag*);

	int hashCode();
	bool equals(ItemInfo*);

	Item* getItem() { return item; }
	int getMeta() { return meta; }
	void setMeta(int newMeta) { meta = newMeta; }
};