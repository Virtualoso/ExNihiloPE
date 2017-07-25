#pragma once

#include <vector>
#include <string>

class BlockEntityBase;

class BlockEntityRegistry {
public:
	static std::vector<BlockEntityBase*> owners;

	static void registerBlockEntity(BlockEntityBase*, const std::string&);
};