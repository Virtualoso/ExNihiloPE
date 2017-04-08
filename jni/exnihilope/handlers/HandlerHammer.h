#pragma once

class Block;
class Player;
class BlockPos;

class HandlerHammer {
public:
	static bool hammer(Block*, int, const BlockPos&, Player*);
};
