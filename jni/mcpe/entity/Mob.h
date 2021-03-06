#pragma once

#include "Entity.h"

class Attribute;
class AttributeInstance;
enum class AttributeBuffType;
class MobEffect;
class MobEffectInstance;
enum class EquipmentSlot;
namespace mce { class UUID; }

class Mob : public Entity {

public:

	enum class TravelType;

	// virtual
	virtual void reloadHardcodedClient(Entity::InitializationMethod, VariantParameterList const&);
	virtual void initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
	virtual bool hasComponent(std::string const&) const;
	virtual ~Mob();
	virtual Vec2 getInterpolatedBodyRot(float);
	virtual void teleportTo(Vec3 const&, int, int);
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual float getHeadHeight() const;
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
	virtual EntityType getEntityTypeId() const = 0;
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual bool canAddRider(Entity&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual void stopRiding(bool, bool);
	virtual void buildDebugInfo(std::string&) const;
	virtual float getYHeadRot() const;
	virtual bool outOfWorld();
	virtual void _hurt(EntityDamageSource const&, int, bool, bool);
	virtual void readAdditionalSaveData(CompoundTag const&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(BlockPos const&, int);
	virtual void knockback(Entity*, int, float, float, float);
	virtual void die(EntityDamageSource const&);
	virtual void* resolveDeathLoot(bool, int, EntityDamageSource const&);
	virtual bool canSee(Entity const&) const;
	virtual void spawnAnim();
	virtual bool isSleeping() const;
	virtual void setSneaking(bool);
	virtual bool isSprinting() const;
	virtual void setSprinting(bool);
	virtual float getVoicePitch();
	virtual void playAmbientSound();
	virtual int getAmbientSoundPostponeTicks();
	virtual void* getItemInHandIcon(ItemInstance const*, int);
	virtual float getSpeed() const;
	virtual void setSpeed(float);
	virtual float getJumpPower() const;
	virtual void heal(int);
	virtual bool hurtEffects(EntityDamageSource const&, int, bool, bool);
	virtual void* getMeleeWeaponDamageBonus(Mob*);
	virtual void* getMeleeKnockbackBonus();
	virtual void actuallyHurt(int, EntityDamageSource const*, bool);
	virtual bool isInvertedHealAndHarm() const;
	virtual void travel(float, float);
	virtual void applyFinalFriction(float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity*, float, float);
	virtual bool isLookingAtAnEntity();
	virtual bool checkSpawnRules(bool);
	virtual bool shouldDespawn() const;
	virtual float getAttackAnim(float);
	virtual void performRangedAttack(Entity&, float);
	virtual ItemInstance* getCarriedItem();
	virtual ItemInstance const* getCarriedItem() const;
	virtual void setCarriedItem(ItemInstance const&);
	virtual int getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual float getMaxHeadXRot();
	virtual Mob* getLastHurtByMob();
	virtual void setLastHurtByMob(Mob*);
	virtual Player* getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player*);
	virtual Entity* getLastHurtMob();
	virtual void setLastHurtMob(Entity*);
	virtual bool canAttack(Entity*, bool);
	virtual bool isAlliedTo(Mob*);
	virtual bool doHurtTarget(Entity*);
	virtual bool canBeControlledByRider();
	virtual AttributeInstance* getMutableAttribute(Attribute const&);
	virtual AttributeInstance const* getAttribute(Attribute const&) const;
	virtual int getEquipmentCount() const;
	virtual int getArmorValue();
	virtual float getArmorCoverPercentage() const;
	virtual void hurtArmor(int);
	virtual void setArmor(ArmorSlot, ItemInstance const*);
	virtual ItemInstance* getArmor(ArmorSlot) const;
	virtual std::vector<ItemInstance const*> getAllArmor() const;
	virtual std::vector<ItemInstance*> getAllArmor();
	virtual std::vector<ItemInstance const*> getAllHand() const;
	virtual std::vector<ItemInstance*> getAllHand();
	virtual std::vector<ItemInstance const*> getAllEquipment() const;
	virtual std::vector<ItemInstance*> getAllEquipment();
	virtual int getArmorTypeHash();
	virtual void sendInventory() const;
	virtual bool canBeAffected(MobEffectInstance const&);
	virtual int getDamageAfterMagicAbsorb(EntityDamageSource const&, int);
	virtual void onBorn(Mob&, Mob&);
	virtual void onLove();
	virtual float getWaterSlowDown() const;
	virtual bool _removeWhenFarAway();
	virtual void jumpFromGround();
	virtual void _pickUpItem(ItemEntity&);
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void _serverAiMobStep();
	virtual int getDamageAfterArmorAbsorb(EntityDamageSource const&, int);
	virtual int getExperienceReward() const;
	virtual void dropEquipment(EntityDamageSource const&, int);
	virtual bool useNewAi() const;
	virtual void tickDeath();
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(MobEffectInstance const&);
	virtual void onEffectRemoved(MobEffectInstance&);

	// non virtual
	Mob(EntityDefinitionGroup&, EntityDefinitionIdentifier const&);
	Mob(Level&);
	void registerAttributes();
	void resetAttributes();
	void createAIGoals();
	void* getAttributes();
	void removeEffect(int);
	void addEffect(MobEffectInstance const&);
	void removeAllEffects();
	void* getVillage() const;
	bool _isHeadInWater();
	void playSpawnSound();
	int getHealth() const;
	void tickAttributes();
	void* _sendDirtyMobData();
	void tickEffects();
	void _updateSprintingState();
	void setInvisible(bool);
	bool isGliding() const;
	void* healEffects(int);
	bool hasEffect(MobEffect const&) const;
	MobEffectInstance* getEffect(MobEffect const&) const;
	Mob::TravelType getTravelType();
	void* calcMoveRelativeSpeed(Mob::TravelType);
	void* saveArmor();
	bool hasAnyEffects();
	void serializationSetHealth(int);
	void* loadArmor(ListTag const*);
	void _verifyAttributes();
	void _applyRidingRotationLimits();
	void updateGliding();
	void checkDespawn(Mob*);
	void checkDespawn();
	bool _isPersistent() const;
	void setYya(float);
	void setYHeadRot(float);
	void setRiderLockedBodyRot(float);
	void setRiderRotLimit(float);
	int getGlidingTicks() const;
	void setWantsToBeJockey(bool);
	bool wantsToBeJockey() const;
	void setJumping(bool);
	void setJumpVelRedux(bool);
	void _doSprintParticleEffect();
	float getCurrentSwingDuration();
	void updateAttackAnim();
	ItemInstance& getItemSlot(EquipmentSlot);
	void setItemSlot(EquipmentSlot, ItemInstance&);
	void* getNavigation();
	void* getLookControl();
	void* getMoveControl();
	void* getJumpControl();
	void* getSensing();
	void* updateMobId(EntityUniqueID&);
	int getLastHurtMobTimestamp();
	int getLastHurtByMobTimestamp();
	void removeEffectNoUpdate(int);
	int getActiveEffectCount() const;
	void removeEffectParticles();
	void updateInvisibilityStatus();
	void* getAllEffects();
	bool hasAttributeBuff(AttributeBuffType) const;
	int getMaxHealth() const;
	void setCanPickUpLoot(bool);
	bool canPickickUpLoot() const;
	float getXxa() const;
	float getYya() const;
	float getYRotA() const;
	void setYRotA(float);
	void incrementArrowCount(int);
	void setSurfaceMob(bool);
	void _addSpeedBonus(mce::UUID const&, std::string const&, float);
	void _removeSpeedBonus(mce::UUID const&);
	float getFlightSpeed();
	void setFlightSpeed(float);
	void onPlayerDimensionChanged(Player*, DimensionId);

	// static fields
	static void* PLAYER_HURT_EXPERIENCE_TIME;

};

