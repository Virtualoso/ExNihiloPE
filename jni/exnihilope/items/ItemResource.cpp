#include "ItemResource.h"

#include "ENItems.h"

#include "mcpe/entity/Entity.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/block/Block.h"
#include "mcpe/client/resources/I18n.h"

const std::string ItemResource::PORCELAIN_CLAY = "porcelain_clay";
const std::string ItemResource::SILKWORM = "silkworm";
const std::string ItemResource::ANCIENT_SPORES = "ancient_spores";
const std::string ItemResource::GRASS_SEEDS = "grass_seeds";
const std::string ItemResource::DOLL_BASE = "doll";

std::string ItemResource::names[6];
std::string ItemResource::textures[6];

ItemResource::ItemResource() : Item("itemMaterial", ENItems::getNextItemId() - 0x100) {
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	Item::mItems[itemId] = this;

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
	return I18n::get(name + "." + names[stack.aux] + ".name");
}

bool ItemResource::useOn(ItemInstance& stack, Entity& player, int x, int y, int z, signed char side, float hitX, float hitY, float hitZ) {
	if (names[stack.aux] == SILKWORM) {
		Block* block = player.getRegion().getBlock(x, y, z);
		if (block != NULL && (block == Block::mLeaves || block == Block::mLeaves2)) {
		    //BlockInfestedLeaves::infestLeafBlock(player.getRegion(), {x, y, z});
			stack.count--;
			return true;
		}
	}
	if (names[stack.aux] == ANCIENT_SPORES || names[stack.aux] == GRASS_SEEDS) {
		Block* block = player.getRegion().getBlock(x, y, z);
		if (block != NULL && block == Block::mDirt) {
			Block* transformTo = names[stack.aux] == ANCIENT_SPORES ? Block::mMycelium : Block::mGrass;
			player.getRegion().setBlockAndData(x, y, z, FullBlock(BlockID(transformTo->blockId), 0), 3);
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
			return new ItemInstance(ENItems::resources, quantity, i);
	}
}