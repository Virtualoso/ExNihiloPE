#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "mcpe/client/resources/Localization.h"
#include "mcpe/recipe/FurnaceRecipes.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/block/Block.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/Vec3.h"

#include "exnihilope/ExNihiloPE.h"
#include "exnihilope/items/ENItems.h"
#include "exnihilope/ExNihiloPERecipes.h"
#include "exnihilope/registries/HammerRegistry.h"
#include "exnihilope/handlers/HandlerHammer.h"
#include "exnihilope/registries/manager/ExNihiloDefaultRecipes.h"

#define LOG_TAG "ExNihilo-PE"
#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

bool initItems = false;

void (*_loadItems)();
void loadItems()
{
	_loadItems();
	
	if(!initItems)
	{
		LOG("Init Items");
		ENItems::init();
		LOG("Items Initiated");
		
		LOG("Init BlockItems");
		ExNihiloPE::initBlockItems();
		LOG("BlockItems Initiated");

		LOG("Register Hammer Recipes");
		ExNihiloPE::defaultRecipes = new ExNihiloDefaultRecipes();
		HammerRegistry::loadJson("HammerRegistry.json");
		LOG("Hammer Recipes Registered");
		initItems = true;
	}
	
	LOG("Add Items to Creative Inventory");
	ENItems::initCreativeItems();
	LOG("Items added to Creative Inventory");
	
	LOG("Add Blocks to Creative Inventory");
	ExNihiloPE::initCreativeBlocks();
	LOG("Blocks added to Creative Inventory");
}

void (*_initClientData)();
void initClientData()
{
	_initClientData();
	
	ENItems::loadResources();
}

void (*_initBlocks)();
void initBlocks()
{
	_initBlocks();

	LOG("Init Blocks");
	ExNihiloPE::initBlocks();
	LOG("Blocks Initiated");
}

void (*_initBlockGraphics)(ResourcePackManager&);
void initBlockGraphics(ResourcePackManager& rpm)
{
	_initBlockGraphics(rpm);

	LOG("Init Block Graphics");
	ExNihiloPE::initBlockGraphics();
	LOG("Block Graphics Initiated");
}
bool (*_tessellateInWorld)(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf);
bool tessellateInWorld(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf)
{ _tessellateInWorld(tessellator,block,pos,aux,wtf);

LOG("Init BlockTessellator");	ExNihiloPE::initBlockTessellator(tessellator,block,pos,aux,wtf);
	LOG("BlockTessellator Initiated");

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

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" )
		_Localization$_load(self, "exnihilope/" + langCode);
}

void (*Block$_playerDestroy)(Block*, Player*, const BlockPos&, int);
void Block$playerDestroy(Block* self, Player* miner, const BlockPos& pos, int aux)
{
	if(!HandlerHammer::hammer(self, aux, pos, miner))
		Block$_playerDestroy(self, miner, pos, aux);
}


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	LOG("Function Hooking Started");
	
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &loadItems, (void**) &_loadItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*)((void(BlockTessellator::*)(Block const&,BlockPos const&,unsigned char,bool))&BlockTessellator::tessellateInWorld),(void*)&tessellateInWorld,(void**)&_tessellateInWorld);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	MSHookFunction((void*) &Block::playerDestroy, (void*) &Block$playerDestroy, (void**) &Block$_playerDestroy);

	return JNI_VERSION_1_6;
}

