#pragma once

#include "Entity.h"

class Item;
class MobEffectInstance;
class PathNavigation;
class LookControl;
class MoveControl;
class JumpControl;
class BodyControl;
class Sensing;
class MobEffect;
typedef int EntityUniqueID;
class Attribute;
class ItemEntity;
class ListTag;
class AttributeBuffType;
#include "../item/ItemInstance.h"
#include "EquipmentSlot.h"

class Mob : public Entity
{
public:
	float yBodyRot; // 352
	float yBodyRotO; // 356
	float yHeadRot; // 360
	float yHeadRotO; // 364
	char mfiller[2572]; // 368
	ItemInstance armor[4]; // 2940
	char mfiller1[96]; // 3020
	bool wat; // 3116
	bool isJumping; // 3117
	int whocares; // 3120
	float speed; // 3124
	LookControl* lookControl; // 3128
	MoveControl* moveControl; // 3132
	JumpControl* jumpControl; // 3136
	BodyControl* bodyControl; // 3140
	PathNavigation* getNavigation; // 3144
	Sensing* getSensing; // 3148
	char mfiller2[32]; // 3152
	float yYa; // 3184
	char mfiller3[4]; // 3188
	bool wat1; // 3192
	bool isSurfaceMob; // 3193
	int wat2; // 3196
	char mfiller4[52]; // 3200
	bool canPickupLoot; // 3252
	bool removeWhenFarAway; // 3253
	int wat3; // 3256
	int wat4; // 3260
	int arrowCount; // 3264
public:
	virtual ~Mob();
	virtual void reloadHardcodedClient(Entity::InitializationMethod, VariantParameterList const&);
	virtual void initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual bool hasComponent(std::string const&) const;
	virtual void teleportTo(Vec3 const&, int, int);
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual int getHeadHeight() const;
	virtual void playerTouch(Player&);
	virtual bool isImmobile() const;
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(EntityEvent, int);
	virtual EntityType getEntityTypeId()const=0;
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual bool canAddRider(Entity&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual int getYHeadRot() const;
	virtual bool outOfWorld();
	virtual void _hurt(EntityDamageSource const&, int, bool, bool);
	virtual void readAdditionalSaveData(CompoundTag const&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(BlockPos const&, int);
	virtual void knockback(Entity*, int, float, float, float);
	virtual void die(EntityDamageSource const&);
	virtual void resolveDeathLoot(bool, int, EntityDamageSource const&);
	virtual bool canSee(Entity const&) const;
	virtual void spawnAnim();
	virtual bool isSleeping() const;
	virtual void setSneaking(bool);
	virtual bool isSprinting() const;
	virtual void setSprinting(bool);
	virtual float getVoicePitch();
	virtual void playAmbientSound();
	virtual void getAmbientSoundPostponeTicks();
	virtual void getItemInHandIcon(ItemInstance const*, int);
	virtual float getSpeed() const;
	virtual void setSpeed(float);
	virtual float getJumpPower() const;
	virtual void heal(int);
	virtual void hurtEffects(EntityDamageSource const&, int, bool, bool);
	virtual void getMeleeWeaponDamageBonus(Mob*);
	virtual void getMeleeKnockbackBonus();
	virtual void actuallyHurt(int, EntityDamageSource const*, bool);
	virtual bool isInvertedHealAndHarm() const;
	virtual void travel(float, float);
	virtual void applyFinalFriction(float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity*, float, float);
	virtual bool isLookingAtAnEntity();
	virtual void checkSpawnRules(bool);
	virtual void shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual void performRangedAttack(Entity&, float);
	virtual ItemInstance* getCarriedItem();
	virtual ItemInstance* getCarriedItem() const;
	virtual void setCarriedItem(ItemInstance const&);
	virtual UseDuration getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual void getMaxHeadXRot();
	virtual void getLastHurtByMob();
	virtual void setLastHurtByMob(Mob*);
	virtual void getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player*);
	virtual void getLastHurtMob();
	virtual void setLastHurtMob(Entity*);
	virtual bool canAttack(Entity*, bool);
	virtual bool isAlliedTo(Mob*);
	virtual void doHurtTarget(Entity*);
	virtual void canBeControlledByRider();
	virtual void getMutableAttribute(Attribute const&);
	virtual void getAttribute(Attribute const&) const;
	virtual void getEquipmentCount() const;
	virtual void getArmorValue();
	virtual void getArmorCoverPercentage() const;
	virtual void hurtArmor(int);
	virtual void setArmor(ArmorSlot, ItemInstance const*);
	virtual void getArmor(ArmorSlot) const;
	virtual void getAllArmor() const;
	virtual void getAllArmor();
	virtual void getAllHand() const;
	virtual void getAllHand();
	virtual void getAllEquipment() const;
	virtual void getAllEquipment();
	virtual void getArmorTypeHash();
	virtual void sendInventory() const;
	virtual bool canBeAffected(MobEffectInstance const&);
	virtual void getDamageAfterMagicAbsorb(EntityDamageSource const&, int);
	virtual void onBorn(Mob&, Mob&);
	virtual void onLove();
	virtual void getWaterSlowDown() const;
	virtual void _removeWhenFarAway();
	virtual void jumpFromGround();
	virtual void _pickUpItem(ItemEntity&);
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void _serverAiMobStep();
	virtual void getDamageAfterArmorAbsorb(EntityDamageSource const&, int);
	virtual void getExperienceReward() const;
	virtual void dropEquipment(EntityDamageSource const&, int);
	virtual void useNewAi() const;
	virtual void tickDeath();
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(MobEffectInstance const&);
	virtual void onEffectRemoved(MobEffectInstance&);
public:
	enum class TravelType : int
	{
		
	};
public:
	Mob(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
	Mob(Level&);
	bool hasEffect(MobEffect const&) const;
	void setYHeadRot(float);
	void getAttributes();
	bool isGliding() const;
	void _sendDirtyMobData();
	void updateAttackAnim();
	void addEffect(MobEffectInstance const&);
	void healEffects(int);
	int getHealth() const;
	LookControl* getLookControl();
	void setJumping(bool);
	JumpControl* getJumpControl();
	void setYya(float);
	void getTravelType();
	void calcMoveRelativeSpeed(Mob::TravelType);
	void setFlightSpeed(float);
	void serializationSetHealth(int);
	void setYRotA(float);
	float getYRotA() const;
	void setJumpVelRedux(bool);
	void getVillage() const;
	void getLastHurtMobTimestamp();
	float getFlightSpeed();
	void getMoveControl();
	int getMaxHealth() const;
	float getXxa() const;
	float getYya() const;
	void getEffect(MobEffect const&) const;
	void _doSprintParticleEffect();
	void getAllEffects();
	void setRiderRotLimit(float);
	void setRiderLockedBodyRot(float);
	ItemInstance* getItemSlot(EquipmentSlot);
	void setItemSlot(EquipmentSlot, ItemInstance&);
	void tickEffects();
	void updateMobId(EntityUniqueID&);
	bool checkDespawn(Mob*);
	bool checkDespawn();
	void removeEffect(int);
	void setInvisible(bool);
	void createAIGoals();
	bool hasAnyEffects();
	void setSurfaceMob(bool);
	void updateGliding();
	void _addSpeedBonus(mce::UUID const&, std::string const&, float);
	void _isHeadInWater();
	void playSpawnSound();
	void tickAttributes();
	void resetAttributes();
	void removeAllEffects();
	void setCanPickUpLoot(bool);
	void _removeSpeedBonus(mce::UUID const&);
	void _verifyAttributes();
	void registerAttributes();
	void setWantsToBeJockey(bool);
	void incrementArrowCount(int);
	void removeEffectNoUpdate(int);
	void _updateSprintingState();
	void removeEffectParticles();
	void getCurrentSwingDuration();
	void onPlayerDimensionChanged(Player*, DimensionId);
	void updateInvisibilityStatus();
	void getLastHurtByMobTimestamp();
	void _applyRidingRotationLimits();
	void loadArmor(ListTag const*);
	void saveArmor();
	bool _isPersistent() const;
	void getGlidingTicks() const;
	void wantsToBeJockey() const;
	bool canPickickUpLoot() const;
	bool hasAttributeBuff(AttributeBuffType) const;
	void getActiveEffectCount() const;
};
