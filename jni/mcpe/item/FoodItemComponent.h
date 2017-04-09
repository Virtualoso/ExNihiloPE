#pragma once
#include <string>
#include <vector>
class Item;
class ItemInstance;
class Player;
class Entity;
class BlockPos;
class Level;
class Vec3;
namespace Json {
	class Value;
};

class FoodItemComponent {
public:
	class Effect {
		
	};
	
	FoodItemComponent(Item&);
	
	int getNutrition() const;
	float getSaturationModifier() const;
	void use(ItemInstance&, Player&);
	void useOn(ItemInstance&, Entity&, const BlockPos&, signed char, const Vec3&);
	void useTimeDepleted(ItemInstance&, Player&, Level&);
	void init(Json::Value&);
	
	Item& item; // 0
	int healAmount; // 4
	float saturation; // 8
	bool isMeat; // 12
	std::string eatSound; // 16
	std::string using_converts_to; // 20
	std::vector<FoodItemComponent::Effect> effects; // 24
};
