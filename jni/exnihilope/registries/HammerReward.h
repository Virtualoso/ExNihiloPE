#pragma once

class ItemInstance;

class HammerReward {
private:
	ItemInstance* stack;
	int miningLevel;
	float chance;
	float fortuneChance;

public:
	HammerReward(ItemInstance* _stack, int _miningLevel, float _chance, float _fortuneChance) : stack(_stack), miningLevel(_miningLevel), chance(_chance), fortuneChance(_fortuneChance) {}

	ItemInstance* getStack() { return stack; }
	int getMiningLevel() { return miningLevel; }
	float getChance() { return chance; }
	float getFortuneChance() { return fortuneChance; }
};
