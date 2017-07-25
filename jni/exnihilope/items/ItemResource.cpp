#include "ItemResource.h"

#include "ENItems.h"

#include "mcpe/entity/Entity.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/block/Block.h"
#include "mcpe/level/BlockPos.h"
#include "mcpe/locale/I18n.h"
#include "mcpe/item/ItemInstance.h"

const std::string ItemResource::PORCELAIN_CLAY = "porcelain_clay";
const std::string ItemResource::SILKWORM = "silkworm";
const std::string ItemResource::ANCIENT_SPORES = "ancient_spores";
const std::string ItemResource::GRASS_SEEDS = "grass_seeds";
const std::string ItemResource::DOLL_BASE = "doll";

std::string ItemResource::names[6];
std::string ItemResource::textures[6];

ItemResource::ItemResource(const std::string& name, int id) : Item(name, id) {
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);

	names[0] = "removed";
	names[1] = PORCELAIN_CLAY;
	names[2] = SILKWORM;
	names[3] = ANCIENT_SPORES;
	names[4] = GRASS_SEEDS;
	names[5] = DOLL_BASE;
	
	textures[0] = "itemPebble";
	textures[1] = "porcelainClay";
	textures[2] = "silkworm";
	textures[3] = "ancientSpores";
	textures[4] = "grassSeeds";
	textures[5] = "doll";
}

std::string ItemResource::buildDescriptionName(ItemInstance const& stack) const {
	return I18n::get(name + "." + names[stack.data] + ".name");
}

bool ItemResource::_useOn(ItemInstance& stack, Entity& player, BlockPos pos, signed char side, float hitX, float hitY, float hitZ) const {
	if (names[stack.data] == SILKWORM) {
		Block* block = player.getRegion()->getBlock(pos);
		if (block != NULL && (block == Block::mLeaves || block == Block::mLeaves2)) {
		    //BlockInfestedLeaves::infestLeafBlock(player.getRegion(), pos);
			stack.count--;
			return true;
		}
	}
	if (names[stack.data] == ANCIENT_SPORES || names[stack.data] == GRASS_SEEDS) {
		Block* block = player.getRegion()->getBlock(pos);
		if (block != NULL && block == Block::mDirt) {
			Block* transformTo = names[stack.data] == ANCIENT_SPORES ? Block::mMycelium : Block::mGrass;
			player.getRegion()->setBlockAndData(pos.x, pos.y, pos.z, FullBlock(BlockID(transformTo->blockId), 0), 3);
			stack.count--;
			return true;
		}
	}
		
	return false;
}

TextureUVCoordinateSet const& ItemResource::getIcon(int meta, int i2, bool b) const {
	if (meta < 6)
		((Item*) this)->setIcon(textures[meta], 0);
	else
		((Item*) this)->setIcon(textures[0], 0);
	
	return Item::getIcon(meta, i2, b);
}

ItemInstance* ItemResource::getResourceStack(const std::string& name) {
	return getResourceStack(name, 1);
}

ItemInstance* ItemResource::getResourceStack(const std::string& name, int quantity) {
	for (int i = 0; i < 6; i++) {
		if(names[i] == name)
			return new ItemInstance(*ENItems::resources, quantity, i);
	}
}