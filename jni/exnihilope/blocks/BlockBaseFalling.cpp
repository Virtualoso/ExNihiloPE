#include "BlockBaseFalling.h"

#include "ENBlocks.h"

#include "mcpe/util/Color.h"

BlockBaseFalling::BlockBaseFalling(const std::string& name, int id) : HeavyBlock(name, id, Material::getMaterial(MaterialType::SAND)) {

}

Color* BlockBaseFalling::getDustColor(unsigned char aux) const {
	if(blockId == ENBlocks::dust->blockId)
		return new Color(219.0F, 216.0F, 188.0F, 1.0F);
	
	return new Color(1.0F, 1.0F, 1.0F, 1.0F);
}