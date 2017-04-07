#include "ENBlocks.h"

#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/BlockShape.h"

#include "BlockBaseFalling.h"

Block* ENBlocks::dust;
Block* ENBlocks::netherrackCrushed;
Block* ENBlocks::endstoneCrushed;
Block* ENBlocks::barrelWood;
Block* ENBlocks::crucible;

void ENBlocks::init() {
	Block::mBlocks[252] = dust = new BlockBaseFalling("blockDust", 252);
	dust->setCategory(CreativeItemCategory::BLOCKS);
	dust->setDestroyTime(0.7F);

	Block::mBlocks[253] = netherrackCrushed = new BlockBaseFalling("blockNetherrackCrushed", 253);
	netherrackCrushed->setCategory(CreativeItemCategory::BLOCKS);
	netherrackCrushed->setDestroyTime(0.7F);

	Block::mBlocks[254] = endstoneCrushed = new BlockBaseFalling("blockEndstoneCrushed", 254);
	endstoneCrushed->setCategory(CreativeItemCategory::BLOCKS);
	endstoneCrushed->setDestroyTime(0.7F);

	Block::mBlocks[230] = barrelWood = new Block("blockBarrel0", 230, Material::getMaterial(MaterialType::WOOD));
	barrelWood->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood->setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	Block::mBlocks[242] = crucible = new Block("blockCrucible", 242, Material::getMaterial(MaterialType::STONE));
	crucible->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood->setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	initBlockItems();
}

void ENBlocks::initBlockItems() {
	Item::mItems[252] = new BlockItem(dust->getDescriptionId(), 252 - 256);
	Item::mItems[253] = new BlockItem(netherrackCrushed->getDescriptionId(), 253 - 256);
	Item::mItems[254] = new BlockItem(endstoneCrushed->getDescriptionId(), 254 - 256);
	Item::mItems[230] = new BlockItem(barrelWood->getDescriptionId(), 230 - 256);
	Item::mItems[242] = new BlockItem(crucible->getDescriptionId(), 242 - 256);
}

void ENBlocks::initGraphics() {
	BlockGraphics::mBlocks[252] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[252]->setTextureItem("blockDust");
	BlockGraphics::mBlocks[252]->setSoundType(BlockSoundType::WOOL);
	
	BlockGraphics::mBlocks[253] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[253]->setTextureItem("blockNetherrackCrushed");
	BlockGraphics::mBlocks[253]->setSoundType(BlockSoundType::DIRT);
	
	BlockGraphics::mBlocks[254] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[254]->setTextureItem("blockEndstoneCrushed");
	BlockGraphics::mBlocks[254]->setSoundType(BlockSoundType::DIRT);

	BlockGraphics::mBlocks[230] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::WOOD);

	BlockGraphics::mBlocks[242] = new BlockGraphics("stone");
    BlockGraphics::mBlocks[242]->setBlockShape(BlockShape::CAULDRON);
	BlockGraphics::mBlocks[242]->setTextureItem("blockCrucible");
	BlockGraphics::mBlocks[242]->setSoundType(BlockSoundType::STONE);
}

void ENBlocks::initCreativeBlocks() {
	Item::addCreativeItem(252, 0);
	Item::addCreativeItem(253, 0);
	Item::addCreativeItem(254, 0);
	Item::addCreativeItem(230, 0);
	Item::addCreativeItem(242, 0);
}

