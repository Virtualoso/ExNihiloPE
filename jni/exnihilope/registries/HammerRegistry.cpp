#include "HammerRegistry.h"

#include "mcpe/util/Random.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"

#include "../util/ItemInfo.h"
#include "HammerReward.h"
#include "manager/RegistryManager.h"
#include "manager/IHammerDefaultRegistryProvider.h"

std::map<ItemInfo*, std::vector<HammerReward*>> HammerRegistry::registry;

void HammerRegistry::loadJson(const std::string& filePath) {
	registry.clear();

	/*if (file.exists())
	{
		try
		{
			FileReader fr = new FileReader(file);
			HashMap<String, ArrayList<HammerReward>> gsonInput = gson.fromJson(fr, new TypeToken<HashMap<String, ArrayList<HammerReward>>>(){}.getType());

			Iterator<String> it = gsonInput.keySet().iterator();

			while (it.hasNext())
			{
				String s = (String) it.next();
				ItemInfo stack = new ItemInfo(s);
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

void HammerRegistry::saveJson(const std::string& path) {
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
 * Use register instead
 */
void HammerRegistry::addHammerRecipe(Block* block, int meta, ItemInstance* reward, int miningLevel, float chance, float fortuneChance) {
	registerRecipe(block, meta, reward, miningLevel, chance, fortuneChance);
}

/**
 * Adds a new Hammer recipe for use with Ex Nihilo hammers.
 * 
 * @param block
 *			Block
 * @param meta
 *			Block meta
 * @param reward
 *			Reward
 * @param miningLevel
 *			Mining level of hammer. 0 = Wood/Gold, 1 = Stone, 2 = Iron, 3 = Diamond. Can be higher, but will need corresponding tool material.
 * @param chance
 *			Chance of drop
 * @param fortuneChance
 *			Chance of drop per level of fortune
 */
void HammerRegistry::registerRecipe(Block* block, int meta, ItemInstance* reward, int miningLevel, float chance, float fortuneChance) {
	registerRecipe(block, meta, reward, miningLevel, chance, fortuneChance, false);
}

void HammerRegistry::registerRecipe(Block* block, int meta, ItemInstance* reward, int miningLevel, float chance, float fortuneChance, bool wildcard) {
	ItemInfo* key = new ItemInfo(block, meta);
	if (wildcard)
		key->setMeta(-1);

	std::vector<HammerReward*> rewards = getRegistryValue(key);

	rewards.emplace_back(new HammerReward(reward, miningLevel, chance, fortuneChance));
	registry[key] = rewards;
}

std::vector<ItemInstance*> HammerRegistry::getRewardDrops(Random& random, Block* block, int meta, int miningLevel, int fortuneLevel) {
	std::vector<ItemInstance*> rewards;

	for (HammerReward* reward : getRewards(block, meta)) {
		if (miningLevel >= reward->getMiningLevel()) {
			if (random.nextFloat() <= reward->getChance() + (reward->getFortuneChance() * fortuneLevel)) {
				rewards.emplace_back(reward->getStack());
			}
		}
	}

	return rewards;
}

std::vector<HammerReward*> HammerRegistry::getRewards(Block* block, int meta) {
	return getRegistryValue(new ItemInfo(block, meta));
}

bool HammerRegistry::registered(const Block* block) {
	return !(getRegistryValue(new ItemInfo(new ItemInstance(block->blockId, 1, 0))).empty());
}

void HammerRegistry::registerDefaults() {
	for (IHammerDefaultRegistryProvider* provider : RegistryManager::getDefaultHammerRecipeHandlers()) {
		provider->registerHammerRecipeDefaults();
	}
}

// Legacy
std::vector<HammerReward*> HammerRegistry::getRewards(Block* block, int meta, int miningLevel) {
	std::vector<HammerReward*> mapList = getRewards(block, meta);
	std::vector<HammerReward*> ret = std::vector<HammerReward*> {};

	for (HammerReward* reward : mapList) {
		if (reward->getMiningLevel() <= miningLevel)
			ret.emplace_back(reward);
	}

	return ret;
}

std::vector<HammerReward*> HammerRegistry::getRegistryValue(ItemInfo* key) {
	for (auto iter = registry.begin(); iter != registry.end(); ++iter) {
		if(key->equals((ItemInfo*) iter->first))
			return iter->second;
	}
	return std::vector<HammerReward*>{};
}