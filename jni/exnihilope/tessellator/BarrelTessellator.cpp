#include "BarrelTessellator.h"

//#include "blocks/BlockTextures.h"
#include "mcpe/level/BlockSource.h"

bool BarrelTessellator::tessellate(Block const&b,BlockPos const&pos,unsigned char aux,bool wtf)
{
	_setShapeAndTessellate(Vec3(0.1354,0,0.1354),Vec3(1.0-0.1354,0.1354*2.0,1.0-0.1354),b,pos,0);

	return true;
}
