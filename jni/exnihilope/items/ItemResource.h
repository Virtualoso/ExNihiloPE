#pragma once

#include "mcpe/item/Item.h"

class ItemResource : public Item {
public:
	static const std::string PORCELAIN_CLAY;
	static const std::string SILKWORM;
	static const std::string ANCIENT_SPORES;
	static const std::string GRASS_SEEDS;
	static const std::string DOLL_BASE;
	
private:
	static std::string names[6];
	static std::string textures[6];

public:
	ItemResource(const std::string&, int);
	virtual std::string buildDescriptionName(ItemInstance const&) const;
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
	virtual TextureUVCoordinateSet const& getIcon(int, int, bool) const;

	static ItemInstance* getResourceStack(const std::string&);
	static ItemInstance* getResourceStack(const std::string&, int);
};