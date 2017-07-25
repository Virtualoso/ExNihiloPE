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
	dust = &registerBlock<BlockBaseFalling>("blockDust", getNextBlockId());
	dust->setCategory(CreativeItemCategory::BLOCKS);
	dust->setDestroyTime(0.7F);

	netherrackCrushed = &registerBlock<BlockBaseFalling>("blockNetherrackCrushed", getNextBlockId());
	netherrackCrushed->setCategory(CreativeItemCategory::BLOCKS);
	netherrackCrushed->setDestroyTime(0.7F);

	endstoneCrushed = &registerBlock<BlockBaseFalling>("blockEndstoneCrushed", getNextBlockId());
	endstoneCrushed->setCategory(CreativeItemCategory::BLOCKS);
	endstoneCrushed->setDestroyTime(0.7F);

	barrelWood = &registerBlock<Block>("blockBarrel0", getNextBlockId(), Material::getMaterial(MaterialType::WOOD));
	barrelWood->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood->setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	infestedLeaves = &registerBlock<BlockInfestedLeaves>("blockInfestedLeaves", getNextBlockId());
	infestedLeaves->setCategory(CreativeItemCategory::DECORATIONS);

	crucible = &registerBlock<Block>("blockCrucible", getNextBlockId(), Material::getMaterial(MaterialType::STONE));
	crucible->setCategory(CreativeItemCategory::BLOCKS);
	//barrelWood->setDestroyTime(1.4f);
	//barrelWood->setExplodeable(5.0f);

	initBlockItems();
}

void ENBlocks::initBlockItems() {
	registerItem<BlockItem>(dust->getDescriptionId(), dust->blockId - 256);
	registerItem<BlockItem>(netherrackCrushed->getDescriptionId(), netherrackCrushed->blockId - 256);
	registerItem<BlockItem>(endstoneCrushed->getDescriptionId(), endstoneCrushed->blockId - 256);
	registerItem<BlockItem>(barrelWood->getDescriptionId(), barrelWood->blockId - 256);
	registerItem<BlockItem>(infestedLeaves->getDescriptionId(), infestedLeaves->blockId - 256);
	registerItem<BlockItem>(crucible->getDescriptionId(), crucible->blockId - 256);
}

void ENBlocks::initGraphics() {
	BlockGraphics::mBlocks[dust->blockId] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[dust->blockId]->setTextureItem("blockDust");
	BlockGraphics::mBlocks[dust->blockId]->setSoundType(BlockSoundType::CLOTH);
	
	BlockGraphics::mBlocks[netherrackCrushed->blockId] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[netherrackCrushed->blockId]->setTextureItem("blockNetherrackCrushed");
	BlockGraphics::mBlocks[netherrackCrushed->blockId]->setSoundType(BlockSoundType::GRAVEL);
	
	BlockGraphics::mBlocks[endstoneCrushed->blockId] = new BlockGraphics("sand");
	BlockGraphics::mBlocks[endstoneCrushed->blockId]->setTextureItem("blockEndstoneCrushed");
	BlockGraphics::mBlocks[endstoneCrushed->blockId]->setSoundType(BlockSoundType::GRAVEL);

	BlockGraphics::mBlocks[barrelWood->blockId] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[barrelWood->blockId]->setTextureItem("planks");
	BlockGraphics::mBlocks[barrelWood->blockId]->setSoundType(BlockSoundType::GRAVEL);
	
	BlockGraphics::mBlocks[infestedLeaves->blockId] = new BlockGraphics("leaves");
	BlockGraphics::mBlocks[infestedLeaves->blockId]->setTextureItem("leaves");
	BlockGraphics::mBlocks[infestedLeaves->blockId]->setCarriedTextureItem("leaves_carried");
	BlockGraphics::mBlocks[infestedLeaves->blockId]->brightnessGamma = 0.80F;
	BlockGraphics::mBlocks[infestedLeaves->blockId]->setSoundType(BlockSoundType::GRASS);

	BlockGraphics::mBlocks[crucible->blockId] = new BlockGraphics("stone");
    BlockGraphics::mBlocks[crucible->blockId]->setBlockShape(BlockShape::CAULDRON);
	BlockGraphics::mBlocks[crucible->blockId]->setTextureItem("blockCrucible");
	BlockGraphics::mBlocks[crucible->blockId]->setSoundType(BlockSoundType::STONE);
}

void ENBlocks::initCreativeBlocks() {
	Item::addCreativeItem(dust, 0);
	Item::addCreativeItem(netherrackCrushed, 0);
	Item::addCreativeItem(endstoneCrushed, 0);
	Item::addCreativeItem(barrelWood, 0);
	Item::addCreativeItem(infestedLeaves, 0);
	Item::addCreativeItem(crucible, 0);
}

int ENBlocks::getNextBlockId() {
	for(int counter = 0; counter < 254; counter++) {
		std::stringstream ss;
		ss << counter;
		std::string blockName = ss.str();
		if(Block::mBlocks[counter]->nameId == blockName)
			return counter;
	}
	return 255;
}
