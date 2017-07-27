#include "BlockInfestedLeaves.h"

#include "../blockentity/BlockEntityInfestedLeaves.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/level/BlockPos.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/item/Item.h"
#include "mcpe/player/Player.h"
#include "mcpe/player/LocalPlayer.h"
#include "mcpe/client/ClientInstance.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/level/Level.h"
#include "mcpe/block/Block.h"

BlockInfestedLeaves::BlockInfestedLeaves(const std::string& name, int id) : BlockEntityBase(name, id, Material::getMaterial(MaterialType::PLANT)) {
	setSolid(false);
	setPushesOutItems(true);
	renderLayer = (BlockRenderLayer) 5;
	unknown2 = 0.8F;
	properties |= 0x2000020;
	blockEntityType = BlockEntityType::InfestedLeaves;
}

void BlockInfestedLeaves::onRemove(BlockSource& world, const BlockPos& pos) const {
	if(world.getBlockEntity(pos)->getType() == BlockEntityType::InfestedLeaves)
		world.removeBlockEntity(pos);
	Block::onRemove(world, pos);
}

void BlockInfestedLeaves::infestLeafBlock(BlockSource& world, const BlockPos& pos) {
	/*IBlockState block = world.getBlockState(pos);

	if (block.getBlock().isLeaves(block, world, pos) && !block.getBlock().equals(ENBlocks.infestedLeaves)) {
		world.setBlockState(pos, ENBlocks.infestedLeaves.getDefaultState());

		TileInfestedLeaves tile = (TileInfestedLeaves) world.getTileEntity(pos);

		if (tile != null) {
			tile.setLeafBlock(block);
		}
	}*/
}

int BlockInfestedLeaves::getVariant(int meta) const {
	return 0;
}

ItemInstance BlockInfestedLeaves::asItemInstance(BlockSource& region, const BlockPos& pos, int meta) const {
	return ItemInstance(*this, 1, 0);
}

Color BlockInfestedLeaves::getMapColor(BlockSource& region, const BlockPos& pos) const {
	return Color::WHITE; // todo
}

unsigned int BlockInfestedLeaves::getColor(BlockSource& region, const BlockPos& pos, unsigned char meta) const {
	return 0xFFFFFF; // todo
}

bool BlockInfestedLeaves::isSeasonTinted(BlockSource& region, const BlockPos& pos) const {
	return true;
}

void BlockInfestedLeaves::playerDestroy(Player* harvester, const BlockPos& pos, int aux) const {
	if(!(harvester->getLevel()->isClientSide())) {
		ItemInstance* selected = harvester->getSelectedItem();
		if(selected != NULL && Item::mShears != NULL && selected->item == Item::mShears)
			popResource(*(harvester->getRegion()), pos, ItemInstance(*this, 1, 0));
		
		//block entity stuff here eventually
	}
}

bool BlockInfestedLeaves::use(Player& player, const BlockPos& pos) const {
	Block::use(player, pos);
	((BlockEntityInfestedLeaves*) player.getRegion()->getBlockEntity(pos))->upCounter();
}

std::unique_ptr<BlockEntity> BlockInfestedLeaves::createBlockEntity(const BlockPos& pos) {
	return std::unique_ptr<BlockEntity>(new BlockEntityInfestedLeaves(pos));
}