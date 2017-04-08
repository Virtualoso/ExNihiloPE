#include "CrookRegistry.h"

#include "mcpe/util/Random.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"

#include "../util/BlockInfo.h"
#include "types/CrookReward.h"
#include "manager/RegistryManager.h"
#include "manager/ICrookDefaultRegistryProvider.h"

std::map<BlockInfo*, std::vector<CrookReward*>> CrookRegistry::registry;
std::map<BlockInfo*, std::vector<CrookReward*>> CrookRegistry::externalRegistry;

void CrookRegistry::loadJson(const std::string& filePath) {
	registry.clear();

	/*if (file.exists())
	{
		try
		{
			FileReader fr = new FileReader(file);
			HashMap<String, ArrayList<CrookReward>> gsonInput = gson.fromJson(fr, new TypeToken<HashMap<String, ArrayList<CrookReward>>>(){}.getType());

			Iterator<String> it = gsonInput.keySet().iterator();

			while (it.hasNext())
			{
				String s = (String) it.next();
				BlockInfo stack = new BlockInfo(s);
				registry.put(stack, gsonInput.get(s));
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	else
	{*/
		registerDefaults();
		saveJson(filePath);
	//}
}

void CrookRegistry::saveJson(const std::string& path) {
	/*try
	{
		FileWriter fw = new FileWriter(file);

		gson.toJson(registry, fw);

		fw.close();
	}
	catch (Exception e)
	{
		e.printStackTrace();
	}*/
}

/**
 * Use registerRecipe instead
 */
void CrookRegistry::addCrookRecipe(BlockInfo* info, ItemInstance* reward, float chance, float fortuneChance) {
	registerRecipe(info, reward, chance, fortuneChance);
}

void CrookRegistry::registerRecipe(BlockInfo* info, ItemInstance* reward, float chance, float fortuneChance) {
	registerInternal(info, reward, chance, fortuneChance);

	std::vector<CrookReward*> rewards = getExternalRegistryValue(info);

	rewards.emplace_back(new CrookReward(reward, chance, fortuneChance));
	externalRegistry[info] = rewards;
}

void CrookRegistry::registerInternal(BlockInfo* info, ItemInstance* reward, float chance, float fortuneChance) {
	std::vector<CrookReward*> rewards = getRegistryValue(info);

	rewards.emplace_back(new CrookReward(reward, chance, fortuneChance));
	registry[info] = rewards;
}

std::vector<CrookReward*> CrookRegistry::getRewards(Block* block, int meta) {
	return getRegistryValue(new BlockInfo(block, meta));
}

bool CrookRegistry::registered(const Block* block) {
	return !(getRegistryValue(new BlockInfo(new ItemInstance(block->blockId, 1, 0))).empty());
}

void CrookRegistry::registerDefaults() {
	for (ICrookDefaultRegistryProvider* provider : RegistryManager::getDefaultCrookRecipeHandlers()) {
		provider->registerCrookRecipeDefaults();
	}
}

std::vector<CrookReward*> CrookRegistry::getRegistryValue(BlockInfo* key) {
	for (auto iter = registry.begin(); iter != registry.end(); ++iter) {
		if(key->equals((BlockInfo*) iter->first))
			return iter->second;
	}
	return std::vector<CrookReward*>{};
}

std::vector<CrookReward*> CrookRegistry::getExternalRegistryValue(BlockInfo* key) {
	for (auto iter = externalRegistry.begin(); iter != externalRegistry.end(); ++iter) {
		if(key->equals((BlockInfo*) iter->first))
			return iter->second;
	}
	return std::vector<CrookReward*>{};
}