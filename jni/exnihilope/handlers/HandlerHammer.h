#pragma once

class Block;
class Player;
class ItemInstance;
class BlockPos;

class HandlerHammer {
public:
	static bool hammer(Block*, int, const BlockPos&, Player*);
};
