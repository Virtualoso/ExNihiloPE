#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/world/item/recipes/FurnaceRecipes.h"
#include "minecraftpe/world/entity/player/Player.h"
#include "minecraftpe/world/level/BlockSource.h"

#include "exnihilope/ExNihiloPE.h"
#include "exnihilope/recipes/ExNihiloPERecipes.h"

#define LOG_TAG "ExNihilo-PE"
#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

void (*_initClientData)();
void initClientData()
{
	_initClientData();
	
	LOG("Init Items");
	ExNihiloPE::initItems();
	LOG("Items Initiated");
	
	LOG("Init BlockItems");
	ExNihiloPE::initBlockItems();
	LOG("BlockItems Initiated");
}

void (*_initCreativeItems)();
void initCreativeItems()
{
	_initCreativeItems();
	
	LOG("Add Items to Creative Inventory");
	ExNihiloPE::initCreativeItems();
	LOG("Items added to Creative Inventory");
	
	LOG("Add Blocks to Creative Inventory");
	ExNihiloPE::initCreativeBlocks();
	LOG("Blocks added to Creative Inventory");
}

void (*_initBlocks)();
void initBlocks()
{
	_initBlocks();

	LOG("Init Blocks");
	ExNihiloPE::initBlocks();
	LOG("Blocks Initiated");
}

void (*_initBlockGraphics)();
void initBlockGraphics()
{
	_initBlockGraphics();

	LOG("Init Block Graphics");
	ExNihiloPE::initBlockGraphics();
	LOG("Block Graphics Initiated");
}

void (*_initRecipes)(Recipes*);
void initRecipes(Recipes *self)
{
	_initRecipes(self);

	ExNihiloPERecipes::initRecipes(self);
	LOG("Recipes Initiated");
}

void (*_initFurnaceRecipes)(FurnaceRecipes*);
void initFurnaceRecipes(FurnaceRecipes *recipes)
{
	_initFurnaceRecipes(recipes);
	
	ExNihiloPERecipes::initFurnaceRecipes(recipes);
	LOG("Furnace Recipes Initiated");
}

bool (*_Player$onLadder)(Player*, bool);
bool Player$onLadder(Player *self, bool idk)
{
	if (self->getRegion().getBlockID(self->getPos().x, self->getPos().y, self->getPos().z) == 237)
		return true;
	return _Player$onLadder(self, idk);
}

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" )
		_Localization$_load(self, "exnihilope/" + langCode);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	LOG("Function Hooking Started");
	
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	//MSHookFunction((void*) &Player::onLadder, (void*) &Player$onLadder, (void**) &_Player$onLadder);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);

	return JNI_VERSION_1_6;
}

