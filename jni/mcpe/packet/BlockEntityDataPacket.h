#pragma once

#include <utility>

#include "Packet.h"
#include "../level/BlockPos.h"
#include "../nbt/CompoundTag.h"

class BlockEntityDataPacket : public Packet {
public:
	int id1; // 4
	int id2; // 8
	BlockPos pos; // 12
	CompoundTag nbt; // 24

	BlockEntityDataPacket(int i1, int i2, BlockPos bp, CompoundTag tag) : id1(i1), id2(i2), pos(bp), nbt(std::move(tag)) { }

	virtual ~BlockEntityDataPacket();
	virtual int getId() const;
	virtual std::string getName() const;
	virtual void* write(BinaryStream&) const;
	virtual void* read(BinaryStream&);
	virtual void* handle(const NetworkIdentifier&, NetEventCallback&) const;
};