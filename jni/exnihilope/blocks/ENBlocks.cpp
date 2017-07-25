#include "ENBlocks.h"

#include "mcpe/item/BlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/client/renderer/block/BlockGraphics.h"
#include "mcpe/client/renderer/block/BlockShape.h"

#include "BlockBaseFalling.h"
#include "BlockInfestedLeaves.h"

Block* ENBlocks::dust;
Block* ENBlocks::netherrackCrushed;
Block* ENBlocks::endstoneCrushed;
Block* ENBlocks::barrelWood;
Block* ENBlocks::infestedLeaves;
Block* ENBlocks::crucible;

void ENBlocks::init() {
	dust = &registerBlock<BlockBaseFalling>("blockDust", 252);
	dust->setCategory(CreativeItemCategory::BLOCKS);
	dust->setDestroyTime(0.7F);

	netherrackCrushed = &registerBlock<BlockBaseFalling>("blockNetherrackCrushed", 253);
	netherrackCrushed->setCategory(CreativeItemCategory::BLOCKS);
	netherrackCrushed->setDestroyTime(0.7F);

	endstoneCrushed = &registerBlock<BlockBaseFalling>("blockEndstoneCrushed", 254);
	endstoneCrushed->setCategory(CreativeItemCategory::BLOCKS);
	endstoneCrushed->setDestroyTime(0.7F);

	barrelWood = &registerBlock<Block>("blockBarrel0", 230, Material::getMaterial(MaterialType::WOOD));
	barrelWood->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood->setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	infestedLeaves = &registerBlock<BlockInfestedLeaves>("blockInfestedLeaves", 176);
	infestedLeaves->setCategory(CreativeItemCategory::DECORATIONS);

	crucible = &registerBlock<Block>("blockCrucible", 242, Material::getMaterial(MaterialType::STONE));
	crucible->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood->setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	initBlockItems();
}

void ENBlocks::initBlockItems() {
	registerItem<BlockItem>(dust->getDescriptionId(), 252 - 256);
	registerItem<BlockItem>(netherrackCrushed->getDescriptionId(), 253 - 256);
	registerItem<BlockItem>(endstoneCrushed->getDescriptionId(), 254 - 256);
	registerItem<BlockItem>(barrelWood->getDescriptionId(), 230 - 256);
	registerItem<BlockItem>(infestedLeaves->getDescriptionId(), 176 - 256);
	registerItem<BlockItem>(crucible->getDescriptionId(), 242 - 256);
}

void ENBlocks::initGraphics() {
	BlockGraphics::mBlocks[252] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[252]->setTextureItem("blockDust");
	BlockGraphics::mBlocks[252]->setSoundType(BlockSoundType::CLOTH);
	
	BlockGraphics::mBlocks[253] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[253]->setTextureItem("blockNetherrackCrushed");
	BlockGraphics::mBlocks[253]->setSoundType(BlockSoundType::GRAVEL);
	
	BlockGraphics::mBlocks[254] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[254]->setTextureItem("blockEndstoneCrushed");
	BlockGraphics::mBlocks[254]->setSoundType(BlockSoundType::GRAVEL);

	BlockGraphics::mBlocks[230] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::GRAVEL);
	
	BlockGraphics::mBlocks[176] = new BlockGraphics("leaves");
	BlockGraphics::mBlocks[176]->setTextureItem("leaves");
	BlockGraphics::mBlocks[176]->setCarriedTextureItem("leaves_carried");
	BlockGraphics::mBlocks[176]->brightnessGamma = 0.80F;
	BlockGraphics::mBlocks[176]->setSoundType(BlockSoundType::GRASS);

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
	Item::addCreativeItem(176, 0);
	Item::addCreativeItem(242, 0);
}