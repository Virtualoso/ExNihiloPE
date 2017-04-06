#include "ExNihiloDefaultRecipes.h"

#include "RegistryManager.h"
#include "../HammerRegistry.h"

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
	HammerRegistry::registerRecipe(Block::mCobblestone, 0, new ItemInstance(Block::mGravel, 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(Block::mGravel, 0, new ItemInstance(Block::mSand, 1), 0, 1.0F, 0.0F);
	/*HammerRegistry::register(Block::SAND.getDefaultState(), new ItemStack(ENBlock::dust, 1), 0, 1.0F, 0.0F);
	HammerRegistry::register(Block::NETHERRACK.getDefaultState(), new ItemStack(ENBlock::netherrackCrushed, 1), 0, 1.0F, 0.0F);
	HammerRegistry::register(Block::END_STONE.getDefaultState(), new ItemStack(ENBlock::endstoneCrushed, 1), 0, 1.0F, 0.0F);*/
	// todo when adding new items and blocks
}

void ExNihiloDefaultRecipes::registerCompostRecipeDefaults() {
	// todo when adding compost
}

void ExNihiloDefaultRecipes::registerCrookRecipeDefaults () {
	// todo when adding crooks
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