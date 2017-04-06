#pragma once

#include <vector>

class Item;
class ItemInstance;

class HammerDatabase {
private:
	static std::vector<Item*> hammerDatabase;
public:
	static void registerHammer(Item*);
	static bool isHammer(ItemInstance*);
};