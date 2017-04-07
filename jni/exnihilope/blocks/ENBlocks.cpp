#include "ENBlocks.h"

#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/BlockShape.h"

Block* ENBlocks::barrelWood;
Block* ENBlocks::crucible;

void ENBlocks::init() {
	Block::mBlocks[230] = barrelWood = new Block("barrel", 230, Material::getMaterial(MaterialType::WOOD));
	barrelWood->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood>setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	Block::mBlocks[231] = crucible = new Block("crucible", 231, Material::getMaterial(MaterialType::STONE));
	crucible->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood>setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	initBlockItems();
}

void ENBlocks::initBlockItems() {
	Item::mItems[230] = new BlockItem(barrelWood->getDescriptionId(), 230 - 256);
	Item::mItems[231] = new BlockItem(barrelWood->getDescriptionId(), 231 - 256);
}

void ENBlocks::initGraphics() {
	BlockGraphics::mBlocks[230] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::WOOD);

	BlockGraphics::mBlocks[231] = new BlockGraphics("stone");
    BlockGraphics::mBlocks[231]->setBlockShape(BlockShape::CAULDRON);
	BlockGraphics::mBlocks[231]->setTextureItem("crucible");
	BlockGraphics::mBlocks[231]->setSoundType(BlockSoundType::STONE);
}

void ENBlocks::initCreativeBlocks() {
	Item::addCreativeItem(230, 0);
	Item::addCreativeItem(231, 0);
}

