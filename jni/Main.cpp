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
#include "mcpe/item/Item.h"
#include "mcpe/util/BlockPos.h"

#include "exnihilope/ExNihiloPE.h"
#include "exnihilope/items/ENItems.h"
#include "exnihilope/blocks/ENBlocks.h"
#include "exnihilope/ExNihiloPERecipes.h"
#include "exnihilope/handlers/HandlerHammer.h"

#define LOG_TAG "ExNihilo-PE"
#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

bool loaded = false;

void (*_loadMinecraft)();
void loadMinecraft() {
	_loadMinecraft();
	
	if(!loaded) {
		ExNihiloPE::init();
		loaded = true;
	}

	ExNihiloPE::initCreative();
}

void (*_initClientData)();
void initClientData() {
	_initClientData();
	
	ENItems::loadResources();
}

void (*_initBlockGraphics)(ResourcePackManager&);
void initBlockGraphics(ResourcePackManager& rpm) {
	_initBlockGraphics(rpm);

	LOG("Init Block Graphics");
	ENBlocks::initGraphics();
	LOG("Block Graphics Initiated");
}

bool (*_tessellateInWorld)(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf);
bool tessellateInWorld(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf) { 
	_tessellateInWorld(tessellator,block,pos,aux,wtf);

	LOG("Init BlockTessellator");
	ExNihiloPE::initBlockTessellator(tessellator,block,pos,aux,wtf);
	LOG("BlockTessellator Initiated");
}

void (*_initRecipes)(Recipes*);
void initRecipes(Recipes *self) {
	_initRecipes(self);

	ExNihiloPERecipes::initRecipes(self);
	LOG("Recipes Initiated");
}

void (*_initFurnaceRecipes)(FurnaceRecipes*);
void initFurnaceRecipes(FurnaceRecipes *recipes) {
	_initFurnaceRecipes(recipes);
	
	ExNihiloPERecipes::initFurnaceRecipes(recipes);
	LOG("Furnace Recipes Initiated");
}

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode) {
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" )
		_Localization$_load(self, "exnihilope/" + langCode);
}

void (*Block$_playerDestroy)(Block*, Player*, const BlockPos&, int);
void Block$playerDestroy(Block* self, Player* miner, const BlockPos& pos, int aux) {
	if(!HandlerHammer::hammer(self, aux, pos, miner))
		Block$_playerDestroy(self, miner, pos, aux);
}


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)  {
	LOG("Function Hooking Started");
	
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &loadMinecraft, (void**) &_loadMinecraft);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*)((void(BlockTessellator::*)(Block const&,BlockPos const&,unsigned char,bool))&BlockTessellator::tessellateInWorld),(void*)&tessellateInWorld,(void**)&_tessellateInWorld);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	MSHookFunction((void*) &Block::playerDestroy, (void*) &Block$playerDestroy, (void**) &Block$_playerDestroy);

	return JNI_VERSION_1_6;
}

