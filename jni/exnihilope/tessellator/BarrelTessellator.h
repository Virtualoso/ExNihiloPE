#pragma once

#include "mcpe/client/renderer/BlockTessellator.h"

class BarrelTessellator : public BlockTessellator
{
public:
	bool tessellate(Block const&,BlockPos const&,unsigned char,bool);
};
