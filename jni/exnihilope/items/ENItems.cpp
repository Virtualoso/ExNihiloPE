#include "ENItems.h"

#include "tools/HammerBase.h"
#include "tools/CrookBase.h"
#include "ItemResource.h"
#include "ItemCookedSilkworm.h"
#include "ItemSeedBase.h"

#include "mcpe/block/Block.h"

HammerBase* ENItems::hammerWood;
HammerBase* ENItems::hammerStone;
HammerBase* ENItems::hammerIron;
HammerBase* ENItems::hammerDiamond;
HammerBase* ENItems::hammerGold;

CrookBase* ENItems::crookWood;
CrookBase* ENItems::crookBone;

ItemResource* ENItems::resources;
ItemCookedSilkworm* ENItems::cookedSilkworm;

std::vector<ItemSeedBase*> ENItems::itemSeeds;

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
		
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedOak", getNextItemId(), Block::mSapling, 0));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedSpruce", getNextItemId(), Block::mSapling, 1));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedBirch", getNextItemId(), Block::mSapling, 2));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedJungle", getNextItemId(), Block::mSapling, 3));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedAcacia", getNextItemId(), Block::mSapling, 4));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedDarkOak", getNextItemId(), Block::mSapling, 5));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedCactus", getNextItemId(), Block::mCactus, 0));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedSugarcane", getNextItemId(), Block::mReeds, 0));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedCarrot", getNextItemId(), Block::mCarrotCrop, 0));
	itemSeeds.emplace_back(&registerItem<ItemSeedBase>("itemSeedPotato", getNextItemId(), Block::mPotatoCrop, 0));
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

	for (Item* seed : itemSeeds)
		Item::addCreativeItem(seed, 0);
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
	itemSeeds[0]->setIcon("seedOak", 0);
	itemSeeds[1]->setIcon("seedSpruce", 0);
	itemSeeds[2]->setIcon("seedBirch", 0);
	itemSeeds[3]->setIcon("seedJungle", 0);
	itemSeeds[4]->setIcon("seedAcacia", 0);
	itemSeeds[5]->setIcon("seedDarkOak", 0);
	itemSeeds[6]->setIcon("seedCactus", 0);
	itemSeeds[7]->setIcon("seedSugarcane", 0);
	itemSeeds[8]->setIcon("seedCarrot", 0);
	itemSeeds[9]->setIcon("seedPotato", 0);
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