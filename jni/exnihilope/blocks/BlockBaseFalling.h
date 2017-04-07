#pragma once

#include "mcpe/block/HeavyBlock.h"

class BlockBaseFalling : public HeavyBlock {
public:
	BlockBaseFalling(const std::string&, int);
	virtual Color* getDustColor(unsigned char) const;
};