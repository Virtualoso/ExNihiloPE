#include "ExNihiloPE.h"

//#include "items/Crook.h"

Item* ExNihiloPE::mWoodenCrook;
Item* ExNihiloPE::mBoneCrook;

Block* ExNihiloPE::mOakBarrel;
Block* ExNihiloPE::mUnfiredCrucible;
Block* ExNihiloPE::mCrucible;

void ExNihiloPE::initItems()
{
	Item::mItems[3814] = mWoodenCrook = (new Item("woodenCrook", 3814 - 256))->setIcon("crook_wood", 0)->setCategory(CreativeItemCategory::Tools);
   Item::mItems[3815] = mBoneCrook = (new Item("boneCrook", 3815 - 256))->setIcon("crook_bone", 0)->setCategory(CreativeItemCategory::Tools);
}

void ExNihiloPE::initBlocks()
{
	Block::mBlocks[230] = mOakBarrel = new Block("barrel", 230, Material::getMaterial(MaterialType::WOOD));
	mOakBarrel->setCategory(CreativeItemCategory::Blocks);
	//mOakBarrel>setDestroyTime(1.4f);
	//mOakBarrel->setExplodeable(5.0f);

   Block::mBlocks[231] = mOakBarrel = new Block("crucible", 231, Material::getMaterial(MaterialType::WOOD));
	mOakBarrel->setCategory(CreativeItemCategory::Blocks);
	//mOakBarrel>setDestroyTime(1.4f);
	//mOakBarrel->setExplodeable(5.0f);
}

void ExNihiloPE::initBlockItems()
{
	Item::mItems[230] = new BlockItem(mOakBarrel->getDescriptionId(), 230 - 256);

	Item::mItems[231] = new BlockItem(mOakBarrel->getDescriptionId(), 231 - 256);
}

void ExNihiloPE::initBlockGraphics()
{
	BlockGraphics::mBlocks[230] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::WOOD);

	BlockGraphics::mBlocks[231] = new BlockGraphics("stone");
	BlockGraphics::mBlocks[231]->setTextureItem("unfired_crucible");
	BlockGraphics::mBlocks[231]->setSoundType(BlockSoundType::STONE);
	
}

void ExNihiloPE::initCreativeItems()
{
	Item::addCreativeItem(3814, 0);
	Item::addCreativeItem(3815, 0);
}

void ExNihiloPE::initCreativeBlocks()
{
	Item::addCreativeItem(230, 0);
	Item::addCreativeItem(231, 0);
}

