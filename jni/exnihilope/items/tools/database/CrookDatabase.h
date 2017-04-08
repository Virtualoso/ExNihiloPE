#pragma once

#include <vector>

class Item;
class ItemInstance;

class CrookDatabase {
private:
	static std::vector<Item*> crookDatabase;
public:
	static void registerCrook(Item*);
	static bool isCrook(ItemInstance*);
};