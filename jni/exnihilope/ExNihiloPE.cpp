#include "ExNihiloPE.h"

//#include "items/Crook.h"
//#include "items/Hammer.h"

Item* ExNihiloPE::mCrookWood;
Item* ExNihiloPE::mCrookBone;

Item* ExNihiloPE::mHammerWood;
Item* ExNihiloPE::mHammerStone;
Item* ExNihiloPE::mHammerIron;
Item* ExNihiloPE::mHammerGold;
Item* ExNihiloPE::mHammerDiamond;

Block* ExNihiloPE::mOakBarrel;
Block* ExNihiloPE::mUnfiredCrucible;
Block* ExNihiloPE::mCrucible;

void ExNihiloPE::initItems()
{

//Crooks
	Item::mItems[3814] = mCrookWood = (new Item("crookWood", 3814 - 256))->setIcon("crook_wood", 0)->setCategory(CreativeItemCategory::Tools);

   Item::mItems[3815] = mCrookBone = (new Item("crookBone", 3815 - 256))->setIcon("crook_bone", 0)->setCategory(CreativeItemCategory::Tools);

//Hammers

Item::mItems[3816] = mHammerWood = (new Item("hammerWood", 3816 - 256))->setIcon("hammer_wood", 0)->setCategory(CreativeItemCategory::Tools);

Item::mItems[3817] = mHammerStone = (new Item("hammerStone", 3817 - 256))->setIcon("hammer_stone", 0)->setCategory(CreativeItemCategory::Tools);

Item::mItems[3818] = mHammerIron = (new Item("hammerIron", 3818 - 256))->setIcon("hammer_iron", 0)->setCategory(CreativeItemCategory::Tools);

Item::mItems[3819] = mHammerGold = (new Item("hammerGold", 3819 - 256))->setIcon("hammer_gold", 0)->setCategory(CreativeItemCategory::Tools);

Item::mItems[3820] = mHammerDiamond = (new Item("hammerDiamond", 3820 - 256))->setIcon("hammer_diamond", 0)->setCategory(CreativeItemCategory::Tools);
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
    for(int i = 0; i <= 6; i += 1) {
	Item::addCreativeItem(3814+i, 0);
	}
}

void ExNihiloPE::initCreativeBlocks()
{
	Item::addCreativeItem(230, 0);
	Item::addCreativeItem(231, 0);
}

