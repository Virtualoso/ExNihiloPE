#include "CrucibleTessellator.h"

#include "mcpe/level/BlockSource.h"

bool CrucibleTessellator::tessellate(Block const&b,BlockPos const&pos,unsigned char aux,bool wtf)
{
	tessellateCauldronInWorld(b, pos, aux);

	return true;
}
