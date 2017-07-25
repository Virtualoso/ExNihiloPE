#include "ENItems.h"

#include "tools/HammerBase.h"
#include "tools/CrookBase.h"
#include "ItemResource.h"
#include "ItemCookedSilkworm.h"

HammerBase* ENItems::hammerWood;
HammerBase* ENItems::hammerStone;
HammerBase* ENItems::hammerIron;
HammerBase* ENItems::hammerDiamond;
HammerBase* ENItems::hammerGold;

CrookBase* ENItems::crookWood;
CrookBase* ENItems::crookBone;

ItemResource* ENItems::resources;
ItemCookedSilkworm* ENItems::cookedSilkworm;

void ENItems::init() {
	registerItemIds();
	
	hammerWood = &registerItem<HammerBase>("hammerWood", getNextItemId(), 64, Item::Tier::WOOD);
	hammerWood->setCategory(CreativeItemCategory::TOOLS);
	
	hammerStone = &registerItem<HammerBase>("hammerStone", getNextItemId(), 128, Item::Tier::STONE);
	hammerStone->setCategory(CreativeItemCategory::TOOLS);
	
	hammerIron = &registerItem<HammerBase>("hammerIron", getNextItemId(), 512, Item::Tier::IRON);
	hammerIron->setCategory(CreativeItemCategory::TOOLS);
	
	hammerDiamond = &registerItem<HammerBase>("hammerDiamond", getNextItemId(), 4096, Item::Tier::DIAMOND);
	hammerDiamond->setCategory(CreativeItemCategory::TOOLS);
	
	hammerGold = &registerItem<HammerBase>("hammerGold", getNextItemId(), 64, Item::Tier::GOLD);
	hammerGold->setCategory(CreativeItemCategory::TOOLS);

	crookWood = &registerItem<CrookBase>("crookWood", getNextItemId(), 64);
	crookWood->setCategory(CreativeItemCategory::TOOLS);
		
	crookBone = &registerItem<CrookBase>("crookBone", getNextItemId(), 256);
	crookBone->setCategory(CreativeItemCategory::TOOLS);

	resources = &registerItem<ItemResource>("itemMaterial", getNextItemId());
	
	cookedSilkworm = &registerItem<ItemCookedSilkworm>("silkwormCooked", getNextItemId());
}

void ENItems::initCreativeItems() {
	Item::addCreativeItem(hammerWood, 0);
	Item::addCreativeItem(hammerStone, 0);
	Item::addCreativeItem(hammerIron, 0);
	Item::addCreativeItem(hammerDiamond, 0);
	Item::addCreativeItem(hammerGold, 0);
	Item::addCreativeItem(crookWood, 0);
	Item::addCreativeItem(crookBone, 0);

	for (int i = 1; i < 6; i++)
		Item::addCreativeItem(resources, i);
		
	Item::addCreativeItem(cookedSilkworm, 0);
}

void ENItems::loadResources() {
	hammerWood->setIcon("hammerWood", 0);
	hammerStone->setIcon("hammerStone", 0);
	hammerIron->setIcon("hammerIron", 0);
	hammerDiamond->setIcon("hammerDiamond", 0);
	hammerGold->setIcon("hammerGold", 0);
	crookWood->setIcon("crookWood", 0);
	crookBone->setIcon("crookBone", 0);
	resources->setIcon("itemPebble", 0);
	cookedSilkworm->setIcon("silkwormCooked", 0);
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
	return id - 0x100;
}