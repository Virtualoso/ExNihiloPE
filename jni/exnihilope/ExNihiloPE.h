#pragma once

class BlockTessellator;
class Block;
class BlockPos;
class ExNihiloDefaultRecipes;
typedef unsigned char uchar;

class ExNihiloPE {
public:
	static void init();
	static void initCreative();
	static bool initBlockTessellator(BlockTessellator*, const Block&, const BlockPos&, uchar, bool);

	static ExNihiloDefaultRecipes* defaultRecipes;
};

