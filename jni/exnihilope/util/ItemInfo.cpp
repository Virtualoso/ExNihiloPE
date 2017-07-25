#include "ItemInfo.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "mcpe/block/Block.h"
#include "mcpe/util/Util.h"
#include "mcpe/block/FullBlock.h"
#include "mcpe/nbt/CompoundTag.h"

#include "StringUtils.h"

ItemInfo* ItemInfo::getItemInfoFromStack(ItemInstance* stack) {
	return new ItemInfo(stack);
}
	
ItemInfo::ItemInfo(ItemInstance* stack) {
	item = stack == NULL ? NULL : stack->item;
	meta = stack == NULL ? -1 : stack->data;
}
	
ItemInfo::ItemInfo(Block* block, int blockMeta) {
	item = Item::mItems[block->blockId];
	meta = block == NULL ? -1 : blockMeta;
}
	
ItemInfo::ItemInfo(const std::string& string) {
	std::vector<std::string> splitStr = StringUtils::split(string, ':');
		
	if(splitStr.size() == 1) {
		item = Item::lookupByName(splitStr[0], true);
	}
	else if(splitStr.size() == 2) {
		meta = splitStr[1] == "*" ? -1 : Util::stringToInt(splitStr[1]);
		item = Item::lookupByName(splitStr[0], true);
	}
	else {
		meta = -1;
	}
}
	
ItemInfo::ItemInfo(const FullBlock& block) {
	item = block.id.id == NULL ? NULL : Item::mItems[block.id.id];
	meta = block.data == NULL ? -1 : block.data;
}
	
std::string ItemInfo::toString() {
	std::stringstream stm;
	stm<<Util::toLower(item->simpleName);
	stm<<(meta == -1 ? "" : (":" + meta));
	std::string ret;
	stm>>ret;
	return ret;
}
	
ItemInstance* ItemInfo::getItemStack() {
	return item == NULL ? NULL : new ItemInstance(*item, 1, meta == -1 ? 0 : meta);
}
	
CompoundTag* ItemInfo::writeToNBT(CompoundTag* tag) {
	tag->putString("item", Util::toLower(item->simpleName));
	tag->putInt("meta", meta);
	
	return tag;
}
	
ItemInfo* ItemInfo::readFromNBT(CompoundTag* tag) {
	Item* item_ = Item::lookupByName(tag->getString("item"), true);
	int meta_ = tag->getInt("meta");
	
	return new ItemInfo(new ItemInstance(*item_, 1, meta_));
}
	
int ItemInfo::hashCode() {
	return 41; // todo
}

bool ItemInfo::equals(ItemInfo* info) {

	if(item == NULL || info->item == NULL)
		return false;
		
	if (meta == -1 || info->meta == -1)
		return item == info->item;
		
	return  meta == info->meta && item == info->item;
}