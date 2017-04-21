#pragma once

#include <string>
#include <vector>
#include "TextureUVCoordinateSet.h"

struct TextureAtlasItem {
	std::string name;
	int index;
	std::vector<TextureUVCoordinateSet> sets;
};