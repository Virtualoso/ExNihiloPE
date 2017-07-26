#pragma once

#include <string>

class Block;
class FullBlock;
class CompoundTag;
class ItemInstance;

class BlockInfo {
private:
	Block* block;
	int meta;

public:
	BlockInfo(Block*, int);
	BlockInfo(const FullBlock&);
	BlockInfo(ItemInstance*);
	BlockInfo(const std::string&);
	
	std::string toString();
	FullBlock getBlockState();
	CompoundTag* writeToNBT(CompoundTag*);
	
	static BlockInfo* readFromNBT(CompoundTag*);

	int hashCode();
	bool equals(BlockInfo*);

	static bool areEqual(BlockInfo*, BlockInfo*);

	Block* getBlock() { return block; }
	int getMeta() { return meta; }
};