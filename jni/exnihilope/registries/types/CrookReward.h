#pragma once

class ItemInstance;

class CrookReward {
private:
	ItemInstance* stack;
	float chance;
	float fortuneChance;

public:
	CrookReward(ItemInstance* _stack, float _chance, float _fortuneChance) : stack(_stack), chance(_chance), fortuneChance(_fortuneChance) {}

	ItemInstance* getStack() { return stack; }
	float getChance() { return chance; }
	float getFortuneChance() { return fortuneChance; }
};