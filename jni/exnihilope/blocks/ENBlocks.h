#pragma once

class Block;

class ENBlocks {
public:
	static Block* barrelWood;
	static Block* crucible;

	static void init();
	static void initBlockItems();
	static void initGraphics();
	static void initCreativeBlocks();
};