#include "ExNihiloPE.h"

#include "tessellator/BarrelTessellator.h"

Block* ExNihiloPE::mOakBarrel;
Block* ExNihiloPE::mUnfiredCrucible;
Block* ExNihiloPE::mCrucible;

void ExNihiloPE::initBlocks() {
	Block::mBlocks[230] = mOakBarrel = new Block("barrel", 230, Material::getMaterial(MaterialType::WOOD));
	mOakBarrel->setCategory(CreativeItemCategory::BLOCKS);
	//mOakBarrel>setDestroyTime(1.4f);
	//mOakBarrel->setExplodeable(5.0f);

   Block::mBlocks[231] = mCrucible = new Block("crucible", 231, Material::getMaterial(MaterialType::STONE));
	mCrucible->setCategory(CreativeItemCategory::BLOCKS);
	//mOakBarrel>setDestroyTime(1.4f);
	//mOakBarrel->setExplodeable(5.0f);
}

void ExNihiloPE::initBlockItems() {
	Item::mItems[230] = new BlockItem(mOakBarrel->getDescriptionId(), 230 - 256);

	Item::mItems[231] = new BlockItem(mOakBarrel->getDescriptionId(), 231 - 256);
}

void ExNihiloPE::initBlockGraphics() {
	BlockGraphics::mBlocks[230] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::WOOD);

	BlockGraphics::mBlocks[231] = new BlockGraphics("stone");
    BlockGraphics::mBlocks[231]->setBlockShape(BlockShape::CAULDRON);
	BlockGraphics::mBlocks[231]->setTextureItem("crucible");
	BlockGraphics::mBlocks[231]->setSoundType(BlockSoundType::STONE);
}

bool ExNihiloPE::initBlockTessellator(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf) {

if(&block==mOakBarrel)
		return ((BarrelTessellator*)tessellator)->tessellate(block,pos,aux,wtf);

}

void ExNihiloPE::initCreativeBlocks() {
	Item::addCreativeItem(230, 0);
	Item::addCreativeItem(231, 0);
}

