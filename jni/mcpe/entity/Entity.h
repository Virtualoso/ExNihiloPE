#pragma once

#include <string>
#include <vector>
#include "SynchedEntityData.h"
#include "../util/AABB.h"
#include "../util/Vec2.h"
#include "../util/Color.h"
#include "../util/BlockID.h"
#include "EntityRendererId.h"
#include "../level/DimensionId.h"
#include "EntityType.h"
#include "EntityCategory.h"
#include "PaletteColor.h"
#include "../item/ArmorSlot.h"
#include "../block/material/MaterialType.h"
#include "../util/FullBlock.h"
#include "../util/Brightness.h"
class EntityInteraction;
class Dimension;
class Level;
class SeatDescription;
class LevelSoundEvent;
class BlockSource;
class EntityLocation;
class Random;
class SetEntityDataPacket;
class EntityDefinitionIdentifier;
class Vec3;
class Material;
class Player;
class EntityDamageSource;
class EntityEvent;
class CompoundTag;
class ItemInstance;
class EntityPos;
class EntityLink;
class ChangeDimensionPacket;
class BlockPos;
class Vec2;
class ExplodeComponent;
class EntityDefinitionGroup;
class VariantParameterList;
class Inventory;
class EntityFlags;
class Block;
class Mob;
namespace mce
{
	class UUID;
}
typedef int EntityUniqueID;
typedef int EntityRuntimeID;

// Size : 324
class Entity;
typedef std::vector<Entity*> EntityList;

class Entity 
{
public:
	void* synchedData; // 4
	Vec3 pos; // 8
	Vec3 oldPos; // 20
	Vec3 chunkPos; // 32
	Vec3 velocity; // 44
	Vec2 rotation; // 56
	Vec2 idk; // 64
	Vec2 idk1; // 72
	SynchedEntityData entityData; // 80
	char filler[12]; // 96
	DimensionId dimensionId; // 108
	char filler1[4]; // 112
	Level& level; // 116
	char idec[4]; // 120
	Color lastLightColor; // 124
	AABB boundingBox; // 140
	float someFloat; // 168;
	float headHeight; // 172
	char filler2[12]; // 176
	float ridingHeight; // 188
	Vec2 idk2; // 192
	char filler3[16]; // 200
	int airSupply; // 216
	int fireTicks; // 220
	char filler4[8]; // 224
	BlockID block; // 232
	int noclue; // 236  **ALWAYS 255**
	char filler5[4]; // 240
	EntityRendererId rendererId; // 244
	EntityList riders; // 248
	Entity& rider; // 252
	Entity& riding; // 256
	bool isRiding_; // 260
	int idk5; // 264
	char filler6[12]; // 268
	bool what1; // 280
	bool what2; // 281
	bool what3; // 282
	bool what4; // 283
	bool what5; // 284
	bool what6; // 285
	bool hurtMarked; // 286
	bool noPhysics; // 287
	bool shouldRender_; // 288
	bool isInvincible; // 289
	bool idk6; // 290
	bool notaclue; // 291
	bool huh; // 292
	bool noidea; // 293
	char uniqueId[8]; //  296
	int autoSend; // 304
	Vec3 someVec; // 308
	char filler7[8]; // 320
	bool what7; // 328
	bool isStuckInWeb; // 329
	bool inWater; // 330
	bool immobile; // 331
	bool changed; // 332
	ExplodeComponent* exploder; // 336
	int idk4; // 340
	bool isRemoved_; // 344
	bool isGlobal_; // 345
	bool isRegistered; // 346
	BlockSource& region; // 348
public:
	class InitializationMethod
	{
		
	};
	
public:
	virtual ~Entity();
	virtual void reloadHardcoded(Entity::InitializationMethod, VariantParameterList const&);
	virtual void reloadHardcodedClient(Entity::InitializationMethod, VariantParameterList const&);
	virtual void initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual void reloadComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual bool hasComponent(std::string const&) const;
	virtual bool hasInventory() const;
	virtual Inventory& getInventory();
	virtual void reset();
	virtual EntityType getOwnerEntityType();
	virtual void remove();
	virtual void setPos(Vec3 const&);
	virtual Vec3 const&getPos() const;
	virtual Vec3 const&getPosOld() const;
	virtual Vec3 const&getPosExtrapolated(float) const;
	virtual void getVelocity() const;
	virtual void setRot(Vec2 const&);
	virtual void move(Vec3 const&);
	virtual bool checkBlockCollisions(AABB const&);
	virtual bool checkBlockCollisions();
	virtual bool canFly();
	virtual void moveRelative(float, float, float);
	virtual void teleportTo(Vec3 const&, int, int);
	virtual void tryTeleportTo(Vec3 const&, bool, bool, int, int);
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void lerpMotion(Vec3 const&);
	virtual void turn(Vec2 const&, bool);
	virtual void interpolateTurn(Vec2 const&);
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity&) const;
	virtual int getRidingHeight();
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void flagRiderToRemove(Entity&);
	virtual void intersects(Vec3 const&, Vec3 const&);
	virtual bool isFree(Vec3 const&, float);
	virtual bool isFree(Vec3 const&);
	virtual bool isInWall() const;
	virtual bool isInvisible() const;
	virtual bool canShowNameTag();
	virtual bool canExistInPeaceful() const;
	virtual void setNameTagVisible(bool);
	virtual std::string getNameTag() const;
	virtual std::string getFormattedNameTag() const;
	virtual void setNameTag(std::string const&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(MaterialType) const;
	virtual bool onLadder(bool);
	virtual void makeStuckInWeb();
	virtual int getHeadHeight() const;
	virtual int getCameraOffset() const;
	virtual float getShadowHeightOffs();
	virtual float getShadowRadius() const;
	virtual bool isSwimmer();
	virtual bool canSeeInvisible();
	virtual bool isSkyLit(float);
	virtual Brightness getBrightness(float) const;
	virtual void interactPreventDefault();
	virtual void playerTouch(Player&);
	virtual void push(Entity&, bool);
	virtual void push(Vec3 const&);
	virtual bool isImmobile() const;
	virtual bool isSilent();
	virtual bool isPickable();
	virtual bool isFishable() const;
	virtual bool isPushable() const;
	virtual bool isPushableByPiston() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual bool isOnFire() const;
	virtual bool isCreativeModeAllowed();
	virtual bool isSurfaceMob() const;
	virtual void setTarget(Entity*);
	virtual void setOwner(EntityUniqueID);
	virtual void setSitting(bool);
	virtual void onTame();
	virtual void onFailedTame();
	virtual void onMate(Mob&);
	virtual bool shouldRender() const;
	virtual bool isInvulnerableTo(EntityDamageSource const&) const;
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void onLightningHit();
	virtual void onBounceStarted(BlockPos const&, FullBlock const&);
	virtual void feed(int);
	virtual void handleEntityEvent(EntityEvent, int);
	virtual float getPickRadius();
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(FullBlock, int);
	virtual void spawnAtLocation(FullBlock, int, float);
	virtual void spawnAtLocation(ItemInstance const&, float);
	virtual bool killed(Entity*);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, ItemInstance const&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(CompoundTag const&);
	virtual void loadLinks(CompoundTag const&, std::vector<EntityLink, std::allocator<EntityLink> >&);
	virtual EntityType getEntityTypeId()const=0;
	virtual void acceptClientsideEntityData(Player&, SetEntityDataPacket const&);
	virtual void queryEntityRenderer();
	virtual void getSourceUniqueID() const;
	virtual void setOnFire(int);
	virtual void getHandleWaterAABB() const;
	virtual void handleInsidePortal(BlockPos const&);
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual void canChangeDimensions() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket const&);
	virtual void getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSynchronizedSound(LevelSoundEvent, Vec3 const&, int, bool);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual bool canBeLeashed();
	virtual bool isLeashableType();
	virtual void tickLeash();
	virtual void getEyeHeight() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual void openContainerComponent(Player&);
	virtual bool useItem(ItemInstance&) const;
	virtual void hasOutputSignal(signed char) const;
	virtual void getOutputSignal() const;
	virtual void getDebugText(std::vector<std::string, std::allocator<std::string> >&);
	virtual void startSeenByPlayer(Player&);
	virtual void stopSeenByPlayer(Player&);
	virtual void getMapDecorationRotation();
	virtual int getRiderDecorationRotation(Player&);
	virtual int getYHeadRot() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual void add(ItemInstance&);
	virtual void drop(ItemInstance const&, bool);
	virtual void canDestroyBlock(Block const&) const;
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void setPos(EntityPos const&);
	virtual bool outOfWorld();
	virtual void _hurt(EntityDamageSource const&, int, bool, bool);
	virtual void markHurt();
	virtual void lavaHurt();
	virtual void readAdditionalSaveData(CompoundTag const&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(BlockPos const&, int);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vec3 const&);
	virtual void updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);
	virtual void getLootTable() const;
	virtual void getDefaultLootTable() const;
	virtual void _removeRider(Entity&, bool);
public:
	Entity(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
	Entity(BlockSource&, std::string const&);
	Entity(Level&);
	Level& getLevel();
	bool hasCategory(EntityCategory) const;
	bool isRiding() const;
	BlockSource& getRegion() const;
	EntityUniqueID* getUniqueID() const;
	Vec2 getRotation() const;
	EntityRuntimeID* getRuntimeID() const;
	void setUniqueID(EntityUniqueID);
	void setRuntimeID(EntityRuntimeID);
	void setPreviousPosRot(Vec3 const&, Vec2 const&);
	void reload();
	void distanceTo(Vec3 const&) const;
	void distanceTo(Entity const&) const;
	void getBossComponent() const;
	void getContainerComponent() const;
	bool isRide() const;
	Entity& getRide() const;
	void isRider(Entity&) const;
	void getAgentCommandComponent() const;
	void setPersistent();
	bool isAutonomous() const;
	bool isGlobal()const;
	void hurt(EntityDamageSource const&, int, bool, bool);
	void buildForward() const;
	void removeAllRiders(bool, bool);
	void _playMovementSound(bool);
	void getDamageSensorComponent() const;
	void distanceToSqr(Vec3 const&) const;
	void distanceSqrToBlockPosCenter(BlockPos const&) const;
	bool isRemoved() const;
	bool isRegionValid() const;
	void setAutonomous(bool);
	void setStatusFlag(EntityFlags, bool);
	void getAttachPos(EntityLocation) const;
	void getStatusFlag(EntityFlags) const;
	Level& getLevel() const;
	Entity& getOwner() const;
	void dropTowards(ItemInstance const&, Vec3);
	Dimension& getDimension() const;
	void distanceToSqr(Entity const&) const;
	Entity& getTarget() const;
	void getBreedableComponent() const;
	bool canMate(Entity const&) const;
	bool isInLove() const;
	float getRadius() const;
	bool isSitting() const;
	void getShooterComponent() const;
	bool isBaby() const;
	void getLeashHolder();
	void moveTo(Vec3 const&, Vec2 const&);
	bool isLeashed();
	bool isTame() const;
	int getAge() const;
	bool wantsMoreFood();
	void setInLove(Entity*);
	void lovePartnerId() const;
	void getAngryComponent() const;
	bool isWithinRestriction(BlockPos const&) const;
	void getRestrictCenter() const;
	bool isWithinRestriction() const;
	void setCharged(bool);
	bool hasType(EntityType) const;
	bool isIgnited() const;
	void initParams(VariantParameterList&);
	void getOwnerId() const;
	bool hasRestriction() const;
	void getRestrictRadius() const;
	void playSound(LevelSoundEvent, Vec3 const&, int);
	void setVariant(int);
	void setMarkVariant(int);
	void sendMotionToServer(bool);
	void setSaddle(bool);
	int getVariant() const;
	bool hasRuntimeID() const;
	int getMarkVariant() const;
	void getEquippableComponent() const;
	bool hasSaddle() const;
	bool isChested() const;
	void restrictTo(BlockPos const&, float);
	void clearRestriction();
	PaletteColor getColor() const;
	void getAirSupply() const;
	void getViewVector(float) const;
	void getTotalAirSupply() const;
	void setColor(PaletteColor);
	bool isAngry() const;
	BlockPos getBlockTarget();
	void setBlockTarget(BlockPos const&);
	Vec3 getEyePos();
	Vec3 _randomHeartPos();
	void setLeashHolder(EntityUniqueID);
	void dropLeash(bool);
	void spawnTamingParticles(bool);
	void getEntityData();
	void setLastHitBB(Vec3 const&, Vec3 const&);
	void setChainedDamageEffects(bool);
	void getProjectileComponent() const;
	void setSeatDescription(Vec3 const&, SeatDescription const&);
	void setEnforceRiderRotationLimit(bool);
	void getAgeableComponent() const;
	void _countFood(int);
	void setChanged();
	void setPowered(bool);
	void _tryPlaceAt(Vec3 const&);
	void getTargetId();
	void resetRegion();
	void _manageRiders(BlockSource&);
	void hasExcessFood();
	void _getBlockOnPos();
	void getInteraction(Player&, EntityInteraction&);
	void _convertOldSave(CompoundTag const&);
	void loadEntityFlags(CompoundTag const&);
	void saveEntityFlags(CompoundTag&);
	void getCollidableMob();
	void setCollidableMob(bool);
	void _updateOwnerChunk();
	void onOnewayCollision(BlockPos);
	void onOnewayCollision(AABB const&);
	void setBaseDefinition(std::string const&, bool, bool);
	void spawnEatParticles(ItemInstance const&, int);
	void updateDescription();
	void addDefinitionGroup(std::string const&);
	void spawnDeathParticles();
	void enableAutoSendPosRot(bool);
	void getCollidableMobNear();
	void getRandomPointInAABB(Random&);
	bool hasEnoughFoodToBreed();
	void setCollidableMobNear(bool);
	void isSpawnableInCreative(EntityType);
	void removeDefinitionGroup(std::string const&);
	void testForCollidableMobs(BlockSource&, AABB const&, std::vector<AABB, std::allocator<AABB> >&);
	void testForEntityStacking(BlockSource&, AABB const&, std::vector<AABB, std::allocator<AABB> >&);
	void doEnchantDamageEffects(Mob&, Mob&);
	void _updateOnewayCollisions(BlockSource&);
	void enforceRiderRotationLimit();
	void checkEntityOnewayCollision(BlockSource&, BlockPos const&);
	void setInheritRotationWhenRiding(bool);
	void burn(int, bool);
	void tick(BlockSource&);
	void moveBBs(Vec3 const&);
	void _exitRide(Entity const&, float);
	void setGlobal(bool);
	void setRegion(BlockSource&);
	void operator==(Entity&);
	void _findRider(Entity&) const;
	bool isInClouds() const;
	bool hasUniqueID() const;
	bool isDebugging() const;
	bool isStackable() const;
	EntityUniqueID* _findRiderID(Entity&) const;
	Color getHurtColor() const;
	void calcCenterPos() const;
	void getEntityData() const;
	void getViewVector2(float) const;
	void _sendLinkPacket(EntityLink const&) const;
	void getNpcComponent() const;
	void getTimerComponent() const;
	bool isAutoSendEnabled() const;
	void getHopperComponent() const;
	void getLookAtComponent() const;
	void hasDefinitionGroup(std::string const&) const;
	void buildDebugGroupInfo(std::string&) const;
	void getExplodeComponent() const;
	bool isInsideBorderBlock(float) const;
	void getHealableComponent() const;
	void getInteractComponent() const;
	void getNameableComponent() const;
	void getRideableComponent() const;
	void getTameableComponent() const;
	void getTeleportComponent() const;
	void getBoostableComponent() const;
	void getLeashableComponent() const;
	void getPortalEntranceAxis() const;
	void getBreathableComponent() const;
	void getScaleByAgeComponent() const;
	void getChainedDamageEffects() const;
	void getInterpolatedPosition(float) const;
	void getInterpolatedRotation(float) const;
	void getMountTamingComponent() const;
	void getInterpolatedPosition2(float) const;
	void getRailMovementComponent() const;
	void getTripodCameraComponent() const;
	void getRailActivatorComponent() const;
	void getSpeedInMetersPerSecond() const;
	void getTransformationComponent() const;
	void isControlledByLocalInstance() const;
	void getLinks() const;
	void getCenter(float) const;
	bool hasFamily(std::string const&) const;
	bool isCharged() const;
	bool isInWorld() const;
	bool isPowered() const;
	bool isSheared() const;
	void saveLinks() const;
public:
	static int RIDING_TAG;
	static int mEntityCounter;
	static int TOTAL_AIR_SUPPLY;
};
