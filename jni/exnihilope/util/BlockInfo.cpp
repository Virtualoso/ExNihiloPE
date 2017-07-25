#include "BlockInfo.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/util/Util.h"
#include "mcpe/block/FullBlock.h"
#include "mcpe/nbt/CompoundTag.h"

#include "StringUtils.h"

BlockInfo::BlockInfo(Block* _block, int blockMeta) {
	block = _block == NULL ? NULL : _block;
	meta = _block == NULL ? -1 : blockMeta;
}

BlockInfo::BlockInfo(const FullBlock& fullBlock) {
	block = fullBlock.id.id == NULL ? NULL : Block::mBlocks[fullBlock.id.id];
	meta = fullBlock.data == NULL ? -1 : fullBlock.data;
}
	
BlockInfo::BlockInfo(ItemInstance* stack) {
	block = (stack == NULL || stack->tile == NULL) ? NULL : stack->tile;
	meta = stack == NULL ? -1 : stack->data;
}

BlockInfo::BlockInfo(const std::string& string) {
	std::vector<std::string> splitStr = StringUtils::split(string, ':');
		
	if(splitStr.size() == 1) {
		block = Block::lookupByName(splitStr[0], true);
	}
	else if(splitStr.size() == 2) {
		meta = splitStr[1] == "*" ? -1 : Util::stringToInt(splitStr[1]);
		block = Block::lookupByName(splitStr[0], true);
	}
	else {
		meta = -1;
	}
}
	
std::string BlockInfo::toString() {
	std::stringstream stm;
	stm<<Util::toLower(block->nameId);
	stm<<(meta == -1 ? "" : (":" + meta));
	std::string ret;
	stm>>ret;
	return ret;
}
	
FullBlock BlockInfo::getBlockState() {
	return FullBlock(BlockID(block->blockId), meta);
}
	
CompoundTag* BlockInfo::writeToNBT(CompoundTag* tag) {
	tag->putString("block", Util::toLower(block->nameId));
	tag->putInt("meta", meta);
	
	return tag;
}
	
BlockInfo* BlockInfo::readFromNBT(CompoundTag* tag) {
	Block* block_ = Block::lookupByName(tag->getString("block"), true);
	int meta_ = tag->getInt("meta");
	
	return new BlockInfo(block_, meta_);
}
	
int BlockInfo::hashCode() {
	return 37; // todo
}

bool BlockInfo::equals(BlockInfo* info) {

	if(block == NULL || info->block == NULL)
		return false;
		
	if (meta == -1 || info->meta == -1)
		return block == info->block;
		
	return  meta == info->meta && block == info->block;
}

bool BlockInfo::areEqual(BlockInfo* block1, BlockInfo* block2) {
	if (block1 == NULL && block2 == NULL)
   		return true;
    	
   	if (block1 == NULL && block2 != NULL)
   		return false;
    	
   	if (block1 != NULL && block2 == NULL)
   		return false;
    	
   	return block1->equals(block2);
}