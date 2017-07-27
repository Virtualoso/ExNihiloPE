#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "mcpe/locale/Localization.h"
#include "mcpe/item/recipes/FurnaceRecipes.h"
#include "mcpe/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/block/Block.h"
#include "mcpe/item/Item.h"
#include "mcpe/level/BlockPos.h"
#include "mcpe/block/entity/BlockEntityFactory.h"
#include "mcpe/client/MinecraftGame.h"
#include "mcpe/client/gui/GuiData.h"

#include "exnihilope/ExNihiloPE.h"
#include "exnihilope/items/ENItems.h"
#include "exnihilope/blocks/ENBlocks.h"
#include "exnihilope/ExNihiloPERecipes.h"
#include "exnihilope/handlers/HandlerHammer.h"
#include "exnihilope/handlers/HandlerCrook.h"
#include "exnihilope/blockentity/BlockEntityRegistry.h"
#include "exnihilope/blockentity/BlockEntityBase.h"
#include "exnihilope/blockentity/BlockEntityInfestedLeaves.h"

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

void (*_Localization$loadFromPack)(Localization*, std::string const&, PackAccessStrategy&, std::vector<std::string> const&);
void Localization$loadFromPack(Localization *self, std::string const& s1, PackAccessStrategy& pas, std::vector<std::string> const& stringVec) {
	_Localization$loadFromPack(self, s1, pas, stringVec);
	
	if(self->langCode == "en_US" )
	{
		std::string backupString = self->langCode;
		self->langCode = "exnihilope/" + self->langCode;
		_Localization$loadFromPack(self, s1, pas, stringVec);
		self->langCode = backupString;
	}

}

void (*_Localization$loadFromResourcePackManager)(Localization*, ResourcePackManager&, std::vector<std::string> const&);
void Localization$loadFromResourcePackManager(Localization *self, ResourcePackManager& rpm, std::vector<std::string> const& stringVec) {
	_Localization$loadFromResourcePackManager(self, rpm, stringVec);
	
	if(self->langCode == "en_US" )
	{
		std::string backupString = self->langCode;
		self->langCode = "exnihilope/" + self->langCode;
		_Localization$loadFromResourcePackManager(self, rpm, stringVec);
		self->langCode = backupString;
	}
}

void (*Block$_playerDestroy)(Block*, Player*, const BlockPos&, int);
void Block$playerDestroy(Block* self, Player* miner, const BlockPos& pos, int aux) {
	if(!HandlerHammer::hammer(self, aux, pos, miner) && !HandlerCrook::crook(self, aux, pos, miner))
		Block$_playerDestroy(self, miner, pos, aux);
}

std::unique_ptr<BlockEntity> (*_BlockEntityFactory$createBlockEntity)(BlockEntityType, const BlockPos&, BlockID);
std::unique_ptr<BlockEntity> BlockEntityFactory$createBlockEntity(BlockEntityType type, const BlockPos& pos, BlockID id) {
	std::unique_ptr<BlockEntity> retval = _BlockEntityFactory$createBlockEntity(type, pos, id);
	if(retval)
		return retval;

	for(BlockEntityBase* owner : BlockEntityRegistry::owners) {
		if(owner->getBlockEntityType() == type)
			return owner->createBlockEntity(pos);
	}
	return retval;
}

void (*_MinecraftGame$onPlayerLoaded)(MinecraftGame*, Player&);
void MinecraftGame$onPlayerLoaded(MinecraftGame* self, Player& player) {
	_MinecraftGame$onPlayerLoaded(self, player);
	BlockEntityInfestedLeaves::guiData = self->getGuiData();
}


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)  {
	LOG("Function Hooking Started");
	
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &loadMinecraft, (void**) &_loadMinecraft);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*)((void(BlockTessellator::*)(Block const&,BlockPos const&,unsigned char,bool))&BlockTessellator::tessellateInWorld),(void*)&tessellateInWorld,(void**)&_tessellateInWorld);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	MSHookFunction((void*) &Localization::loadFromPack, (void*) &Localization$loadFromPack, (void**) &_Localization$loadFromPack);
	MSHookFunction((void*) &Localization::loadFromResourcePackManager, (void*) &Localization$loadFromResourcePackManager, (void**) &_Localization$loadFromResourcePackManager);
	MSHookFunction((void*) &Block::playerDestroy, (void*) &Block$playerDestroy, (void**) &Block$_playerDestroy);
	MSHookFunction((void*) &BlockEntityFactory::createBlockEntity, (void*) &BlockEntityFactory$createBlockEntity, (void**) &_BlockEntityFactory$createBlockEntity);
	MSHookFunction((void*) &MinecraftGame::onPlayerLoaded, (void*) &MinecraftGame$onPlayerLoaded, (void**) &_MinecraftGame$onPlayerLoaded);

	return JNI_VERSION_1_6;
}

