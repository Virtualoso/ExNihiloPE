#pragma once

class Block;

class ENBlocks {
public:
	static Block* dust;
	static Block* netherrackCrushed;
	static Block* endstoneCrushed;
	static Block* barrelWood;
	static Block* infestedLeaves;
	static Block* crucible;

	static void init();
	static void initBlockItems();
	static void initGraphics();
	static void initCreativeBlocks();
	static int getNextBlockId();
};