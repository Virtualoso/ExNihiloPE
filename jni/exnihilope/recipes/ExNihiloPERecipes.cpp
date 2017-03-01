#include "ExNihiloPERecipes.h"

#include "../ExNihiloPE.h"

Recipes* ExNihiloPERecipes::_Instance;
std::vector<Recipes::Type> ExNihiloPERecipes::_ingredients;

void ExNihiloPERecipes::initRecipes(Recipes *recipes)
{	
	_Instance = recipes;
	
	// Crook
	pushIngredient(Item::mStick, 'n');
	addRecipe(ExNihiloPE::mWoodenCrook->itemId, 1, 0, {"nn ", " n ", " n "});

	pushIngredient(Item::mBone, 'n');
	addRecipe(ExNihiloPE::mBoneCrook->itemId, 1, 0, {"nn ", " n ", " n "});
	
	/* BLOCKS */
	// Barrel
	pushIngredient(Block::mWoodPlanks, 'n');
	pushIngredient(Block::mWoodenSlab, 'm');
	addRecipe(ExNihiloPE::mOakBarrel->blockId, 1, 0, {"n n", "n n", "nmn"});

}

void ExNihiloPERecipes::initFurnaceRecipes(FurnaceRecipes *recipes)
{

}

void ExNihiloPERecipes::pushIngredient(Item *item, char letter)
{
	pushIngredient(item->itemId, 0, letter);
}

void ExNihiloPERecipes::pushIngredient(Block *block, char letter)
{
	pushIngredient(block->blockId, 0, letter);
}

void ExNihiloPERecipes::pushIngredient(short id, short data, char letter)
{
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void ExNihiloPERecipes::addRecipe(short outputId, short outputCount, short outputData, const std::vector<std::string> &shape)
{
	_Instance->addShapedRecipe(ItemInstance(outputId, outputCount, outputData), shape, _ingredients);	
	_ingredients.clear();
}

