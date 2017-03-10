#include "ExNihiloPE.h"

//#include "items/Crook.h"
//#include "items/Hammer.h"

#include "tessellator/BarrelTessellator.h"

Item* ExNihiloPE::mCrookWood;
Item* ExNihiloPE::mCrookBone;
Item* ExNihiloPE::mHammerWood;
Item* ExNihiloPE::mHammerStone;
Item* ExNihiloPE::mHammerIron;
Item* ExNihiloPE::mHammerGold;
Item* ExNihiloPE::mHammerDiamond;
Item* ExNihiloPE::mAncientSpores;
Item* ExNihiloPE::mDoll;
Item* ExNihiloPE::mDollBlaze;
Item* ExNihiloPE::mDollEnder;
Item* ExNihiloPE::mGrassSeeds;
Item* ExNihiloPE::mPebble;
Item* ExNihiloPE::mPorcelainClay;
Item* ExNihiloPE::mAcaciaSeed;
Item* ExNihiloPE::mBirchSeed;
Item* ExNihiloPE::mCactusSeed;
Item* ExNihiloPE::mCarrotSeed;
Item* ExNihiloPE::mDarkoakSeed;
Item* ExNihiloPE::mJungleSeed;
Item* ExNihiloPE::mOakSeed;
Item* ExNihiloPE::mPotatoSeed;
Item* ExNihiloPE::mSpruceSeed;
Item* ExNihiloPE::mSugarcaneSeed;
Item* ExNihiloPE::mSilkWorm;
Item* ExNihiloPE::mCookedSilkWorm;

Block* ExNihiloPE::mOakBarrel;
Block* ExNihiloPE::mUnfiredCrucible;
Block* ExNihiloPE::mCrucible;
Block* ExNihiloPE::mSilkLeaves;
Block* ExNihiloPE::mDust;
Block* ExNihiloPE::mEndstoneCrushed;
Block* ExNihiloPE::mNetherrackCrushed;
Block* ExNihiloPE::mBirchBarrel;
Block* ExNihiloPE::mSpruceBarrel;
Block* ExNihiloPE::mDarkoakBarrel;
Block* ExNihiloPE::mAcaciaBarrel;
Block* ExNihiloPE::mJungleBarrel;
Block* ExNihiloPE::mOakSieve;
Block* ExNihiloPE::mBirchSieve;
Block* ExNihiloPE::mSpruceSieve;
Block* ExNihiloPE::mDarkoakSieve;
Block* ExNihiloPE::mAcaciaSieve;
Block* ExNihiloPE::mJungleSieve;

void ExNihiloPE::initItems()
{
	Item::mItems[3814] = mCrookWood = (new Item("crookWood", 3814 - 256))->setIcon("crook_wood", 0)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3815] = mCrookBone = (new Item("crookBone", 3815 - 256))->setIcon("crook_bone", 0)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3816] = mHammerWood = new Hammer(3816,0);
	Item::mItems[3817] = mHammerStone = new Hammer(3817,1);
	Item::mItems[3818] = mHammerIron = new Hammer(3818,2);
	Item::mItems[3819] = mHammerGold = new Hammer(3819,3);
	Item::mItems[3820] = mHammerDiamond = new Hammer(3820,4);
}

void ExNihiloPE::initBlocks()
{
	Block::mBlocks[230] = mOakBarrel = new Block("barrel", 230, Material::getMaterial(MaterialType::WOOD));
	mOakBarrel->setCategory(CreativeItemCategory::BLOCKS);

	Block::mBlocks[231] = mCrucible = new Block("crucible", 231, Material::getMaterial(MaterialType::STONE));
	mCrucible->setCategory(CreativeItemCategory::BLOCKS);
	
	Block::mBlocks[232] = mSilkLeaves = new Block("silkLeaves", 232, Material::getMaterial(MaterialType::PLANT));
	mSilkLeaves->setCategory(CreativeItemCategory::DECORATIONS);
}

void ExNihiloPE::initBlockItems()
{
	Item::mItems[230] = new BlockItem(mOakBarrel->getDescriptionId(), 230 - 256);
	Item::mItems[231] = new BlockItem(mOakBarrel->getDescriptionId(), 231 - 256);
	Item::mItems[232] = new BlockItem(mOakBarrel->getDescriptionId(), 232 - 256);
}

void ExNihiloPE::initBlockGraphics()
{
	BlockGraphics::mBlocks[230] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::WOOD);

	BlockGraphics::mBlocks[231] = new BlockGraphics("stone");
    BlockGraphics::mBlocks[231]->setBlockShape(BlockShape::CAULDRON);
	BlockGraphics::mBlocks[231]->setTextureItem("crucible");
	BlockGraphics::mBlocks[231]->setSoundType(BlockSoundType::STONE);
	
	BlockGraphics::mBlocks[232] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[232]->setTextureItem("leaves");
	BlockGraphics::mBlocks[232]->setSoundType(BlockSoundType::GRASS);
	BlockGraphics::mBlocks[232]->setMapColor(Color::WHITE);
}

bool ExNihiloPE:: initBlockTessellator(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf) {
	if(&block==mOakBarrel)
		return ((BarrelTessellator*)tessellator)->tessellate(block,pos,aux,wtf);

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
	Item::addCreativeItem(232, 0);
}

