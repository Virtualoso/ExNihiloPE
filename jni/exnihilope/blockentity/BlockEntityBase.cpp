#include "BlockEntityBase.h"

BlockEntityBase::BlockEntityBase(const std::string& descriptionId, int id, const Material& material) : EntityBlock(descriptionId, id, material) {}

BlockEntityBase::~BlockEntityBase() {}