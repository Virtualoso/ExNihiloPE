#include "ExNihiloPE.h"

#include "blocks/ENBlocks.h"
#include "items/ENItems.h"
#include "registries/manager/ExNihiloDefaultRecipes.h"
#include "registries/HammerRegistry.h"
#include "registries/CrookRegistry.h"
#include "tessellator/BarrelTessellator.h"

ExNihiloDefaultRecipes* ExNihiloPE::defaultRecipes;

void ExNihiloPE::init() {
	ENBlocks::init();
	ENItems::init();

	defaultRecipes = new ExNihiloDefaultRecipes();

	HammerRegistry::loadJson("HammerRegistry.json");
	CrookRegistry::loadJson("CrookRegistry.json");
}

void ExNihiloPE::initCreative() {
	ENItems::initCreativeItems();
	ENBlocks::initCreativeBlocks();
}

bool ExNihiloPE::initBlockTessellator(BlockTessellator* tessellator, Block const& block, BlockPos const& pos, uchar aux, bool wtf) {
	if(&block == ENBlocks::barrelWood)
		return ((BarrelTessellator*)tessellator)->tessellate(block, pos, aux, wtf);
}