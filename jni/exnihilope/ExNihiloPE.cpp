#include "ExNihiloPE.h"

#include "tessellator/BarrelTessellator.h"

Item* ExNihiloPE::mCrookWood;
Item* ExNihiloPE::mCrookBone;

Item* ExNihiloPE::mHammerWood;
Item* ExNihiloPE::mHammerStone;
Item* ExNihiloPE::mHammerIron;
Item* ExNihiloPE::mHammerGold;
Item* ExNihiloPE::mHammerDiamond;

Item* ExNihiloPE::mWorm;
Item* ExNihiloPE::mWormCooked;

Block* ExNihiloPE::mOakBarrel;
Block* ExNihiloPE::mUnfiredCrucible;
Block* ExNihiloPE::mCrucible;
Block* ExNihiloPE::mSilkLeaves;
Block* ExNihiloPE::mDust;

void ExNihiloPE::initItems(){
	//Crooks
	Item::mItems[3814] = mCrookWood = (new Item("crookWood", 3814 - 256))->setIcon("crook_wood", 0)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3815] = mCrookBone = (new Item("crookBone", 3815 - 256))->setIcon("crook_bone", 0)->setCategory(CreativeItemCategory::TOOLS);

	//Hammers
	Item::mItems[3816] = mHammerWood = (new Item("hammerWood", 3816 - 256))->setIcon("hammer_wood", 0)->setMaxStackSize(1)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3817] = mHammerStone = (new Item("hammerStone", 3817 - 256))->setIcon("hammer_stone", 0)->setMaxStackSize(1)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3818] = mHammerIron = (new Item("hammerIron", 3818 - 256))->setIcon("hammer_iron", 0)->setMaxStackSize(1)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3819] = mHammerGold = (new Item("hammerGold", 3819 - 256))->setIcon("hammer_gold", 0)->setMaxStackSize(1)->setCategory(CreativeItemCategory::TOOLS);
	Item::mItems[3820] = mHammerDiamond = (new Item("hammerDiamond", 3820 - 256))->setIcon("hammer_diamond", 0)->setMaxStackSize(1)->setCategory(CreativeItemCategory::TOOLS);

	//Ect
	Item::mItems[3821] = mWorm = (new Item("worm", 3821 - 256))->setIcon("silkworm", 0)->setCategory(CreativeItemCategory::ITEMS);
	Item::mItems[3822] = mWormCooked = (new Item("wormCooked", 3822 - 256))->setIcon("silkworm_cooked", 0)->setCategory(CreativeItemCategory::ITEMS);
}

bool ExNihiloPE::useOn(ItemInstance& item, Entity& player, int x, int y, int z, signed char side, float xx, float yy, float zz){
	if(item == ItemInstance(ExNihiloPE::mWorm)){
		//Remove silk worm
		player->getRegion()->setBlock(x, y, z, ExNihiloPE::mSilkLeaves, 0);
	}
}

void ExNihiloPE::mineBlock(ItemInstance* item, BlockID blockId, int x, int y, int z, Entity* player);
	Block* block = player->getRegion().getBlock({x,y,z});
	
	if((item == ItemInstance(ExNihiloPE::mCrookWood) || item == ItemInstance(mCrookBone)) && (block->blockId == Block::mLeaves || block->blockId == Block::mLeaves2)){
		//MORE DROPS!!!
	}
	
	if(block->blockId == Block::mCobblestone){
		if(item == ItemInstance(ExNihiloPE::mHammerWood) || item == ItemInstance(ExNihiloPE::mHammerStone) || item == ItemInstance(ExNihiloPE::mHammerIron) || item == ItemInstance(ExNihiloPE::mHammerGold) || item == ItemInstance(ExNihiloPE::mHammerDiamond)){
			Block::mCobblestone::getResource(Random& rand, int data, int idk) = Block::mGravel;
		}else{
			int Block::mCobblestone::getResource(Random& rand, int data, int idk) = Block::mCobblestone;
		}
	}
	if(block->blockId == Block::mGravel){
		if(item == ItemInstance(ExNihiloPE::mHammerWood) || item == ItemInstance(ExNihiloPE::mHammerStone) || item == ItemInstance(ExNihiloPE::mHammerIron) || item == ItemInstance(ExNihiloPE::mHammerGold) || item == ItemInstance(ExNihiloPE::mHammerDiamond)){
			Block::mCobblestone::getResource(Random& rand, int data, int idk) = Block::mSand;
		}else{
			int Block::mCobblestone::getResource(Random& rand, int data, int idk) = Block::mGravel;
		}
	}
	if(block->blockId == Block::mSand){
		if(item == ItemInstance(ExNihiloPE::mHammerWood) || item == ItemInstance(ExNihiloPE::mHammerStone) || item == ItemInstance(ExNihiloPE::mHammerIron) || item == ItemInstance(ExNihiloPE::mHammerGold) || item == ItemInstance(ExNihiloPE::mHammerDiamond)){
			Block::mCobblestone::getResource(Random& rand, int data, int idk) = ExNihiloPE::mDust;
		}else{
			int Block::mCobblestone::getResource(Random& rand, int data, int idk) = Block::mSand;
		}
	}
}

void ExNihiloPE::initBlocks()
{
	Block::mBlocks[230] = mOakBarrel = new Block("barrel", 230, Material::getMaterial(MaterialType::WOOD));
	mOakBarrel->setCategory(CreativeItemCategory::BLOCKS);
	//mOakBarrel>setDestroyTime(1.4f);
	//mOakBarrel->setExplodeable(5.0f);

	Block::mBlocks[231] = mCrucible = new Block("crucible", 231, Material::getMaterial(MaterialType::STONE));
	mCrucible->setCategory(CreativeItemCategory::BLOCKS);
	//mOakBarrel>setDestroyTime(1.4f);
	//mOakBarrel->setExplodeable(5.0f);
	
	Block::mBlocks[232] = mSilkLeaves = new Block("silkLeaves",232,Material::getMaterial(MaterialType::PLANT));
	mSilkLeaves->setCategory(CreativeItemCategory::DECORATIONS);
	
	Block::mBlocks[233] = mDust = new Block("block_dust", 233, Material::getMaterial(MaterialType::SAND));
	mDust->setCategory(CreativeItemCategory::BLOCKS);
}

void ExNihiloPE::initBlockItems(){
	Item::mItems[230] = new BlockItem(mOakBarrel->getDescriptionId(), 230 - 256);
	Item::mItems[231] = new BlockItem(mOakBarrel->getDescriptionId(), 231 - 256);
	Item::mItems[232] = new BlockItem(mOakBarrel->getDescriptionId(), 232 - 256);
	Item::mItems[233] = new BlockItem(mOakBarrel->getDescriptionId(), 232 - 256);
}

void ExNihiloPE::initBlockGraphics(){
	BlockGraphics::mBlocks[230] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[230]->setTextureItem("planks");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::WOOD);

	BlockGraphics::mBlocks[231] = new BlockGraphics("stone");
    BlockGraphics::mBlocks[231]->setBlockShape(BlockShape::CAULDRON);
	BlockGraphics::mBlocks[231]->setTextureItem("crucible");
	BlockGraphics::mBlocks[231]->setSoundType(BlockSoundType::STONE);
	
	BlockGraphics::mBlocks[232] = new BlockGraphics("leaves");
	BlockGraphics::mBlocks[232]->setTextureItem("leaves");
	BlockGraphics::mBlocks[232]->setSoundType(BlockSoundType::GRASS);
	BlockGraphics::mBlocks[232]->setMapColor(Color::WHITE);
	
	BlockGraphics::mBlocks[230] = new BlockGraphics("sand"); //What is supposted to go in the params of this?
	BlockGraphics::mBlocks[230]->setTextureItem("block_dust");
	BlockGraphics::mBlocks[230]->setSoundType(BlockSoundType::GRASS);//I couldnt find sand or any related sounds
}

bool ExNihiloPE:: initBlockTessellator(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf) {
	if(&block==mOakBarrel)
		return ((BarrelTessellator*)tessellator)->tessellate(block,pos,aux,wtf);

}

void ExNihiloPE::initCreativeItems(){
    for(int i = 0; i <= 8; i += 1) {
		Item::addCreativeItem(3814+i, 0);
	}
}

void ExNihiloPE::initCreativeBlocks(){
	Item::addCreativeItem(230, 0);
	Item::addCreativeItem(231, 0);
	Item::addCreativeItem(232, 0);
	Item::addCreativeItem(233, 0);
}

