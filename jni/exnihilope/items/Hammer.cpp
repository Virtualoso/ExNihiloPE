#include "Hammer.h"

#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/item/ItemInstance.h"

Hammer::Hammer(short itemId, int type) : Item("hammer", itemID - 256) {
	Item::mItems[itemId] = this;
	creativeCategory = CreativeCategory::TOOLS;
	setMaxStackSize(1);
	handEquipped = true;
	
	switch(type){
	case 0:
		setIcon("hammer_wood", 0);
		name = "hammerWood";
		setMaxUseDuration(64);
		break;
	case 1:
		setIcon("hammer_stone", 0);
		name = "hammerStone";
		setMaxUseDuration(128);
		break;
	case 2:
		setIcon("hammer_iron", 0);
		name = "hammerIron";
		setMaxUseDuration(512);
		break;
	case 3:
		setIcon("hammer_gold", 0);
		name = "hammerGold";
		setMaxUseDuration(64);
		break;
	case 4:
		setIcon("hammer_diamond", 0);
		name = "hammerDiamond";
		setMaxUseDuration(4096);
		break;
	}
}

void Hammer::mineBlock(ItemInstance* item_, BlockID blockId_, int x, int y, int z, Entity* player){
	Block* block = player->getRegion().getBlock({x,y,z});
	
	if(block == Block::mCobblestone){
		block::getResource(Random& rand, int data, int idk) = Block::mGravel;
	}else{
		block::getResource(Random& rand, int data, int idk) = Block::mCobblestone;
	}
	if(block == Block::mGravel){
		block::getResource(Random& rand, int data, int idk) = Block::mSand;
	}else{
		block::getResource(Random& rand, int data, int idk) = Block::mGravel;
	}
	if(block == Block::mSand){
		block::getResource(Random& rand, int data, int idk) = ExNihiloPE::mDust;
	}else{
		block::getResource(Random& rand, int data, int idk) = Block::mSand;
	}
}

float Hammer::getDestroySpeed(ItemInstance* item_, Block const* block_){
	switch(block_){
	case Block::mCobblestone:
		return 0.5f;
	case Block::mGravel:
		return 0.5f;
	case Block::mSand:
		return 0.5f;
	case Block::mDust:
		return 0.5f;
	default:
		return 1.0f;
	}
}