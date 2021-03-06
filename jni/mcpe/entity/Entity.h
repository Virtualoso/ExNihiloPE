#pragma once

#include <string>
#include <vector>
#include <memory>
#include "EntityType.h"
#include "EntityUniqueID.h"
#include "../math/Vec2.h"
#include "../math/Vec3.h"
#include "../math/AABB.h"
#include "../level/BlockPos.h"
#include "../level/FullBlock.h"

class Random;
class Level;
class Dimension;
class BlockSource;
class ItemInstance;
class Mob;
class Player;
class ItemEntity;
class EntityDefinitionGroup;
class EntityDefinitionIdentifier;
class VariantParameterList;
class EntityDamageSource;
class EntityInteraction;
class ContainerComponent;
class FillingContainer;
class CompoundTag;
class ListTag;
class SetEntityDataPacket;
class ChangeDimensionPacket;
class SeatDescription;

enum class EntityLocation;
enum class EntityFlags;
enum class EntityCategory;
class ArmorSlot;
enum class EntityEvent;
enum class DimensionId;
enum class LevelSoundEvent;
enum class MaterialType;
enum class PaletteColor;

struct EntityPos {
	Vec3 pos;

	EntityPos(Vec3 pos) : pos(pos) { }
	operator Vec3() { return pos; }
};

struct EntityLink {
	char type; // 1 or 2
	EntityUniqueID riderId;
	EntityUniqueID ridingId;
	char unknown = 0;
};

class Entity {

public:

	enum class InitializationMethod;

	char filler[0xCA8];
	/* size = 0xCAC */

	// virtual
	virtual void reloadHardcoded(Entity::InitializationMethod, VariantParameterList const&);
	virtual void reloadHardcodedClient(Entity::InitializationMethod, VariantParameterList const&);
	virtual void initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual void reloadComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual bool hasComponent(std::string const&) const;
	virtual bool hasInventory() const;
	virtual FillingContainer* getInventory();
	virtual ~Entity();
	virtual void reset();
	virtual EntityType getOwnerEntityType();
	virtual void remove();
	virtual void setPos(Vec3 const&);
	virtual EntityPos const& getPos() const;
	virtual EntityPos const& getPosOld() const;
	virtual Vec3 getPosExtrapolated(float) const;
	virtual Vec3 const& getVelocity() const;
	virtual void setRot(Vec2 const&);
	virtual void move(Vec3 const&);
	virtual Vec2 getInterpolatedBodyRot(float) const;
	virtual void checkBlockCollisions(AABB const&);
	virtual void checkBlockCollisions();
	virtual bool canFly();
	virtual void moveRelative(float, float, float);
	virtual void teleportTo(Vec3 const&, int, int);
	virtual bool tryTeleportTo(Vec3 const&, bool, bool, int, int);
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void lerpMotion(Vec3 const&);
	virtual void turn(Vec2 const&, bool);
	virtual void interpolateTurn(Vec2 const&);
	virtual void* getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(Entity&) const;
	virtual float getRidingHeight();
	virtual void startRiding(Entity&);
	virtual void addRider(Entity&);
	virtual void flagRiderToRemove(Entity&);
	virtual bool intersects(Vec3 const&, Vec3 const&);
	virtual bool isFree(Vec3 const&, float);
	virtual bool isFree(Vec3 const&);
	virtual bool isInWall() const;
	virtual bool isInvisible() const;
	virtual bool canShowNameTag();
	virtual bool canExistInPeaceful() const;
	virtual void setNameTagVisible(bool);
	virtual std::string const& getNameTag() const;
	virtual std::string getFormattedNameTag() const;
	virtual void setNameTag(std::string const&);
	virtual bool isInWater() const;
	virtual bool isInWaterOrRain();
	virtual bool isInLava();
	virtual bool isUnderLiquid(MaterialType) const;
	virtual bool onLadder(bool);
	virtual void makeStuckInWeb();
	virtual float getHeadHeight() const;
	virtual float getCameraOffset() const;
	virtual float getShadowHeightOffs();
	virtual float getShadowRadius() const;
	virtual bool isSwimmer();
	virtual bool canSeeInvisible();
	virtual bool isSkyLit(float);
	virtual float getBrightness(float) const;
	virtual bool interactPreventDefault();
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
	virtual ItemEntity* spawnAtLocation(int, int);
	virtual ItemEntity* spawnAtLocation(int, int, float);
	virtual ItemEntity* spawnAtLocation(FullBlock, int);
	virtual ItemEntity* spawnAtLocation(FullBlock, int, float);
	virtual ItemEntity* spawnAtLocation(ItemInstance const&, float);
	virtual void killed(Entity*);
	virtual void awardKillScore(Entity&, int);
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, ItemInstance const&);
	virtual void save(CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(CompoundTag const&);
	virtual void loadLinks(CompoundTag const&, std::vector<EntityLink, std::allocator<EntityLink>>&);
	virtual EntityType getEntityTypeId() const = 0;
	virtual bool acceptClientsideEntityData(Player&, SetEntityDataPacket const&);
	virtual void* queryEntityRenderer();
	virtual EntityUniqueID getSourceUniqueID() const;
	virtual void setOnFire(int);
	virtual void* getHandleWaterAABB() const;
	virtual void handleInsidePortal(BlockPos const&);
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual DimensionId getDimensionId() const;
	virtual bool canChangeDimensions() const;
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket const&);
	virtual EntityUniqueID getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSynchronizedSound(LevelSoundEvent, Vec3 const&, int, bool);
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Entity&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual bool canBeLeashed();
	virtual bool isLeashableType();
	virtual void tickLeash();
	virtual float getEyeHeight() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual void openContainerComponent(Player&);
	virtual void useItem(ItemInstance&) const;
	virtual bool hasOutputSignal(signed char) const;
	virtual int getOutputSignal() const;
	virtual void getDebugText(std::vector<std::string, std::allocator<std::string>>&);
	virtual void startSeenByPlayer(Player&);
	virtual void stopSeenByPlayer(Player&);
	virtual float getMapDecorationRotation();
	virtual float getRiderDecorationRotation(Player&);
	virtual float getYHeadRot() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual void add(ItemInstance&);
	virtual void drop(ItemInstance const&, bool);
	virtual bool canDestroyBlock(Block const&) const;
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
	virtual bool updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void updateInsideBlock();
	virtual void onBlockCollision(int);
	virtual void* getLootTable() const;
	virtual void* getDefaultLootTable() const;
	virtual void _removeRider(Entity&, bool);

	// non virtual
	Entity(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
	void setBaseDefinition(std::string const&, bool, bool);
	Entity(Level&);
	Entity(BlockSource&, std::string const&);
	void setRegion(BlockSource&);
	void reload();
	bool isRegionValid() const;
	void updateDescription();
	Level* getLevel();
	void setVariant(int);
	void setMarkVariant(int);
	void setColor(PaletteColor);
	void setStatusFlag(EntityFlags, bool);
	void addDefinitionGroup(std::string const&);
	void removeDefinitionGroup(std::string const&);
	bool hasDefinitionGroup(std::string const&) const;
	ContainerComponent* getContainerComponent() const;
	bool hasCategory(EntityCategory) const;
	bool hasType(EntityType) const;
	bool hasFamily(std::string const&) const;
	bool isSpawnableInCreative(EntityType);
	bool hasUniqueID() const;
	bool hasRuntimeID() const;
	EntityRuntimeID getRuntimeID() const;
	EntityUniqueID getUniqueID() const;
	void setRuntimeID(EntityRuntimeID);
	void setUniqueID(EntityUniqueID);
	bool isInClouds() const;
	int getVariant() const;
	int getMarkVariant() const;
	Entity* getTarget() const;
	Level* getLevel() const;
	EntityUniqueID getTargetId();
	void initParams(VariantParameterList&);
	bool isBaby() const;
	Vec3 getAttachPos(EntityLocation) const;
	void setBlockTarget(BlockPos const&);
	BlockPos getBlockTarget();
	bool getStatusFlag(EntityFlags) const;
	bool isStackable() const;
	int getAge() const;
	bool isTame() const;
	Player* getOwner() const;
	EntityUniqueID getOwnerId() const;
	bool isSitting() const;
	BlockSource* getRegion() const;
	void setPersistent();
	void moveBBs(Vec3 const&);
	void testForEntityStacking(BlockSource&, AABB const&, std::vector<AABB, std::allocator<AABB>>&);
	void testForCollidableMobs(BlockSource&, AABB const&, std::vector<AABB, std::allocator<AABB>>&);
	BlockPos _getBlockOnPos();
	void _playMovementSound(bool);
	void playSound(LevelSoundEvent, Vec3 const&, int);
	void onOnewayCollision(BlockPos);
	void onOnewayCollision(AABB const&);
	void _updateOnewayCollisions(BlockSource&);
	void* checkEntityOnewayCollision(BlockSource&, BlockPos const&);
	bool isRiding() const;
	void _updateOwnerChunk();
	bool isInWorld() const;
	void setPreviousPosRot(Vec3 const&, Vec2 const&);
	float getRadius() const;
	Vec3 getCenter(float) const;
	Vec3 getInterpolatedPosition(float) const;
	Vec3 getViewVector(float) const;
	Vec2 getInterpolatedRotation(float) const;
	Vec2 getViewVector2(float) const;
	void setEnforceRiderRotationLimit(bool);
	void setInheritRotationWhenRiding(bool);
	float getSpeedInMetersPerSecond() const;
	bool enforceRiderRotationLimit();
	void burn(int, bool);
	Vec3 getRandomPointInAABB(Random&);
	void tick(BlockSource&);
	bool isGlobal() const;
	bool isControlledByLocalInstance() const;
	void _manageRiders(BlockSource&);
	std::vector<EntityLink> getLinks() const;
	void _sendLinkPacket(EntityLink const&) const;
	void removeAllRiders(bool, bool);
	bool isRemoved() const;
	void* getRideableComponent() const;
	void* getEntityData();
	Entity* getRide() const;
	bool _tryPlaceAt(Vec3 const&);
	void _exitRide(Entity const&, float);
	Vec2 getRotation() const;
	void moveTo(Vec3 const&, Vec2 const&);
	void* _findRider(Entity&) const;
	void* _findRiderID(Entity&) const;
	void* getBoostableComponent() const;
	void setSeatDescription(Vec3 const&, SeatDescription const&);
	void buildDebugGroupInfo(std::string&) const;
	float distanceTo(Entity const&) const;
	float distanceTo(Vec3 const&) const;
	float distanceToSqr(Vec3 const&) const;
	float distanceToSqr(Entity const&) const;
	float distanceSqrToBlockPosCenter(BlockPos const&) const;
	bool hurt(EntityDamageSource const&, int, bool, bool);
	void* getProjectileComponent() const;
	void spawnTamingParticles(bool);
	void* _randomHeartPos();
	bool isInLove() const;
	bool canMate(Entity const&) const;
	bool isAngry() const;
	bool isSheared() const;
	bool isChested() const;
	bool isIgnited() const;
	bool hasSaddle() const;
	bool isCharged() const;
	void setCharged(bool);
	bool isPowered() const;
	void setPowered(bool);
	void setSaddle(bool);
	void spawnDeathParticles();
	void spawnEatParticles(ItemInstance const&, int);
	Dimension* getDimension() const;
	void resetRegion();
	std::unique_ptr<ListTag> saveLinks() const;
	bool isRide() const;
	void saveEntityFlags(CompoundTag&);
	void* getColor() const;
	void loadEntityFlags(CompoundTag const&);
	void* _convertOldSave(CompoundTag const&);
	void setChanged();
	void* getEntityData() const;
	bool isDebugging() const;
	bool isInsideBorderBlock(float) const;
	bool isRider(Entity&) const;
	bool isLeashed();
	EntityUniqueID getLeashHolder();
	void setLeashHolder(EntityUniqueID);
	void dropLeash(bool);
	short getAirSupply() const;
	short getTotalAirSupply() const;
	Vec3 getEyePos();
	bool isAutoSendEnabled() const;
	void sendMotionToServer(bool);
	void setGlobal(bool);
	bool isAutonomous() const;
	void setAutonomous(bool);
	void enableAutoSendPosRot(bool);
	void* getHurtColor() const;
	Vec3 getInterpolatedPosition2(float) const;
	Vec3 buildForward() const;
	void* getPortalEntranceAxis() const;
	void* getAgeableComponent() const;
	void* getAngryComponent() const;
	void* getBreathableComponent() const;
	void* getBreedableComponent() const;
	void* getExplodeComponent() const;
	void* getTameableComponent() const;
	void* getLookAtComponent() const;
	void* getTeleportComponent() const;
	void* getMountTamingComponent() const;
	void* getTimerComponent() const;
	void* getInteractComponent() const;
	void* getEquippableComponent() const;
	void* getHealableComponent() const;
	void* getScaleByAgeComponent() const;
	void* getRailMovementComponent() const;
	void* getDamageSensorComponent() const;
	void* getLeashableComponent() const;
	void* getTransformationComponent() const;
	void* getNameableComponent() const;
	void* getHopperComponent() const;
	void* getRailActivatorComponent() const;
	void* getNpcComponent() const;
	void* getTripodCameraComponent() const;
	void* getBossComponent() const;
	void* getAgentCommandComponent() const;
	void* getShooterComponent() const;
	void setLastHitBB(Vec3 const&, Vec3 const&);
	bool isWithinRestriction() const;
	bool isWithinRestriction(BlockPos const&) const;
	bool hasRestriction() const;
	void restrictTo(BlockPos const&, float);
	BlockPos getRestrictCenter() const;
	float getRestrictRadius() const;
	void clearRestriction();
	ItemEntity* dropTowards(ItemInstance const&, Vec3);
	EntityUniqueID lovePartnerId() const;
	void setInLove(Entity*);
	Vec3 calcCenterPos() const;
	bool hasEnoughFoodToBreed();
	bool _countFood(int);
	bool hasExcessFood();
	bool wantsMoreFood();
	void doEnchantDamageEffects(Mob&, Mob&);
	bool getInteraction(Player&, EntityInteraction&);
	void setChainedDamageEffects(bool);
	bool getChainedDamageEffects() const;
	void setCollidableMobNear(bool);
	bool getCollidableMobNear();
	void setCollidableMob(bool);
	bool getCollidableMob();

	// static fields
	static void* TOTAL_AIR_SUPPLY;
	static void* mEntityCounter;
	static std::string RIDING_TAG;

};
