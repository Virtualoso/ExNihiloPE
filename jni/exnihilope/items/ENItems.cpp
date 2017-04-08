#include "ENItems.h"

#include "tools/HammerBase.h"
#include "tools/CrookBase.h"

HammerBase* ENItems::hammerWood;
HammerBase* ENItems::hammerStone;
HammerBase* ENItems::hammerIron;
HammerBase* ENItems::hammerDiamond;
HammerBase* ENItems::hammerGold;

CrookBase* ENItems::crookWood;
CrookBase* ENItems::crookBone;

void ENItems::init() {
	registerItemIds();
	
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

	crookWood = new CrookBase("crookWood", 64);
	crookWood->setCategory(CreativeItemCategory::TOOLS);
		
	crookBone = new CrookBase("crookBone", 256);
	crookBone->setCategory(CreativeItemCategory::TOOLS);
}

void ENItems::initCreativeItems() {
	Item::addCreativeItem(hammerWood, 0);
	Item::addCreativeItem(hammerStone, 0);
	Item::addCreativeItem(hammerIron, 0);
	Item::addCreativeItem(hammerDiamond, 0);
	Item::addCreativeItem(hammerGold, 0);
	Item::addCreativeItem(crookWood, 0);
	Item::addCreativeItem(crookBone, 0);
}

void ENItems::loadResources() {
	hammerWood->setIcon("hammerWood", 0);
	hammerStone->setIcon("hammerStone", 0);
	hammerIron->setIcon("hammerIron", 0);
	hammerDiamond->setIcon("hammerDiamond", 0);
	hammerGold->setIcon("hammerGold", 0);
	crookWood->setIcon("crookWood", 0);
	crookBone->setIcon("crookBone", 0);
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