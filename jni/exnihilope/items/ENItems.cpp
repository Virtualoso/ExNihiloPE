#include "ENItems.h"

#include "tools/HammerBase.h"

HammerBase* ENItems::hammerWood;
HammerBase* ENItems::hammerStone;
HammerBase* ENItems::hammerIron;
HammerBase* ENItems::hammerDiamond;
HammerBase* ENItems::hammerGold;

void ENItems::init() {
	hammerWood = new HammerBase("hammerWood", 64, Item::Tier::WOOD);
	hammerWood->setCategory(CreativeItemCategory::TOOLS);
	
	hammerStone = new HammerBase("hammerStone", 128, Item::Tier::STONE);
	hammerStone->setCategory(CreativeItemCategory::TOOLS);
	
	hammerIron = new HammerBase("hammerIron", 512, Item::Tier::IRON);
	hammerIron->setCategory(CreativeItemCategory::TOOLS);
	
	hammerDiamond = new HammerBase("hammerDiamond", 4096, Item::Tier::DIAMOND);
	hammerDiamond->setCategory(CreativeItemCategory::TOOLS);
	
	hammerGold = new HammerBase("hammerGold", 64, Item::Tier::GOLD);
	hammerGold->setCategory(CreativeItemCategory::TOOLS);
}

void ENItems::initCreativeItems() {
	Item::addCreativeItem(hammerDiamond, 0);
	Item::addCreativeItem(hammerStone, 0);
	Item::addCreativeItem(hammerIron, 0);
	Item::addCreativeItem(hammerDiamond, 0);
	Item::addCreativeItem(hammerGold, 0);
}


int ENItems::index;
std::vector<int> ENItems::freeIds;

void ENItems::registerItemIds() {
	for(int counter = 256; counter < 4096; counter++) {
		if(Item::mItems[counter] == NULL)
			freeIds.emplace_back(counter);
	}
}

int ENItems::getNextItemId() {	
	int id = freeIds[index];
	index++;
	return id;
}