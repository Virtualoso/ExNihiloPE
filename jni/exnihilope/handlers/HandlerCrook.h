#pragma once

class Block;
class Player;
class BlockPos;

class HandlerCrook {
public:
	static bool crook(Block*, int, const BlockPos&, Player*);
};
