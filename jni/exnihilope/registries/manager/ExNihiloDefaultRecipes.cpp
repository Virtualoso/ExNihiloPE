#include "ExNihiloDefaultRecipes.h"

#include "RegistryManager.h"
#include "../HammerRegistry.h"
#include "../CrookRegistry.h"
#include "../../blocks/ENBlocks.h"
#include "../../util/BlockInfo.h"
#include "../../items/ItemResource.h"

#include "mcpe/block/Block.h"
#include "mcpe/item/ItemInstance.h"

ExNihiloDefaultRecipes::ExNihiloDefaultRecipes() {
	RegistryManager::registerSieveDefaultRecipeHandler(this);
	RegistryManager::registerHammerDefaultRecipeHandler(this);
	RegistryManager::registerCompostDefaultRecipeHandler(this);
	RegistryManager::registerCrookDefaultRecipeHandler(this);
	RegistryManager::registerCrucibleDefaultRecipeHandler(this);
	RegistryManager::registerFluidBlockDefaultRecipeHandler(this);
	RegistryManager::registerFluidTransformDefaultRecipeHandler(this);
	RegistryManager::registerFluidOnTopDefaultRecipeHandler(this);
	RegistryManager::registerHeatDefaultRecipeHandler(this);
	RegistryManager::registerOreDefaultRecipeHandler(this);
}

void ExNihiloDefaultRecipes::registerSieveRecipeDefaults() {
	// todo when adding sieves
}

void ExNihiloDefaultRecipes::registerHammerRecipeDefaults() {
	HammerRegistry::registerRecipe(Block::mCobblestone, 0, new ItemInstance(*Block::mGravel, 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(Block::mGravel, 0, new ItemInstance(*Block::mSand, 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(Block::mSand, 0, new ItemInstance(*ENBlocks::dust, 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(Block::mNetherrack, 0, new ItemInstance(*ENBlocks::netherrackCrushed, 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(Block::mEndStone, 0, new ItemInstance(*ENBlocks::endstoneCrushed, 1), 0, 1.0F, 0.0F);
}

void ExNihiloDefaultRecipes::registerCompostRecipeDefaults() {
	// todo when adding compost
}

void ExNihiloDefaultRecipes::registerCrookRecipeDefaults () {
	CrookRegistry::registerRecipe(new BlockInfo(Block::mLeaves, -1), ItemResource::getResourceStack(ItemResource::SILKWORM), 0.1F, 0.0F);
	CrookRegistry::registerRecipe(new BlockInfo(Block::mLeaves2, -1), ItemResource::getResourceStack(ItemResource::SILKWORM), 0.1F, 0.0F);
}

void ExNihiloDefaultRecipes::registerCrucibleRecipeDefaults () {
	// todo when adding crucibles
}

void ExNihiloDefaultRecipes::registerFluidBlockRecipeDefaults () {
	// todo when adding fluid blocks
}

void ExNihiloDefaultRecipes::registerFluidTransformRecipeDefaults () {
	// todo when adding fluid transform
}

void ExNihiloDefaultRecipes::registerFluidOnTopRecipeDefaults () {
	// todo when adding fluid on top
}

void ExNihiloDefaultRecipes::registerHeatRecipeDefaults () {
	// todo when adding heat
}

void ExNihiloDefaultRecipes::registerOreRecipeDefaults () {
	// todo when adding ore
}