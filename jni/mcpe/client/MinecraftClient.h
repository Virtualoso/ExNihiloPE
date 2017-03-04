#pragma once

#include <functional>
#include <memory>
#include <vector>
#include "App.h"
#include "../gamemode/GameType.h"
#include "../util/Vec3.h"
#include "Realms.h"

class AbstractScreen;
class Font;
class GameRenderer;
class GuiData;
class Screen;
class ScreenChooser;
class Minecraft;
class Music;
class BuildActionIntention;
class Level;
class Mob;
class Dimension;
class Timer;
class Options;
class VoiceCommand;
class DirectionId;
class InputMode;
class Side;
class HolographicPlatform;
class VoiceSystem;
class Player;
class LocalPlayer;
class LevelSettings;
class SoundEngine;
class TextureAtlas;
class GameStore;
class GeometryGroup;
class SkinRepository;
class MinecraftTelemetry;
class ExternalServerFile;
class UIDefRepository;
class MobEffectsLayout;
class LevelRenderer;
class HolosceneRenderer;
class ParticleEngine;
class MinecraftInputHandler;
class MusicManager;
class LevelArchiver;
class SnoopClient;
class Entity;
class LevelRenderer;
class FocusImpact;
class TextureData;
class ResourcePacksInfoData;
class HoloUIInputMode;
class ResourcePackResponse;
class PushNotificationMessage;
class HoloGameMode;
class Server;
class ResourcePackManager;

namespace mce { class TextureGroup; }
namespace ui { class GameEventNotification; };
namespace Social 
{ 
	class UserManager; 
	class Multiplayer;
	class XboxLiveGameInfo;
	class GameConnectionInfo;
	namespace Telemetry 
	{
		class TelemetryManager;
	};
};

// Size : 472
class MinecraftClient : public App
{
public:
	static std::string WORLD_PATH;
	static std::string SETTINGS_PATH;
	static float GUI_SCALE_VALUES[8];
	static bool _hasInitedStatics;
	static int INTERACTION_FREQ_MS;
	static std::string RESOURCE_PACKS_SAVE_FILENAME;
public:
	char mcclient_vars[36]; // 28
	std::string worldPath; // 64
	std::string mainPath; // 68
	std::string idk_s; // 72
	int width; // 76
	int height; // 80
	char mcclient_vars1[4]; // 84
	Minecraft* minecraft; // 88
	std::unique_ptr<LevelRenderer> levelRenderer; // 92
	GameRenderer* gameRenderer; // 96
	HolosceneRenderer* holoRenderer; // 100
	ParticleEngine* particleEngine; // 104
	ExternalServerFile* serverFile; // 108
	mce::TextureGroup* textureGroup; // 112 
	Font* defualtFont; // 116
	Font* runeFont; // 120
	Entity* targetEntity; // 124
	char mcclient_vars2[12]; // 128
	bool isMouseGrabbed; // 140
	char* connectedServer; // 144
	char mcclient_vars3[12]; // 148
	bool inhibitDueToTextBoxMode; // 160
	int filler_i; // 164
	char mcclient_vars4[40]; // 168
	bool isDictionaryDataAvailable; // 208
	char* dictationText; // 212
	char mcclient_vars5[48]; // 216
	std::unique_ptr<LocalPlayer> localPlayer; // 264
	MinecraftInputHandler* mcInputHandler; // 268
	std::unique_ptr<HolographicPlatform> holoInput; // 272
	void* voidSystem; // 276
	GuiData* gui; // 280
	UIDefRepository* UIRepo; // 284
	Options* options; // 288
	SoundEngine* soundEngine; // 292
	MusicManager* musicManager; // 296
	SnoopClient* snoopClient; // 300
	char mcclient_vars6[4]; // 304
	MobEffectsLayout* mobEffectsLayout; // 308
	GameStore* gameStore; // 312
	GeometryGroup* geometryGroup; // 316
	SkinRepository* skinRepo; // 320
	Social::UserManager* userManager; // 324
	Social::Multiplayer* multiplayer; // 328
	LevelArchiver* levelArchiver; // 332
	TextureAtlas* blockAtlas; // 336
	TextureAtlas* itemAtlas; // 340
	char mcclient_vars7[8]; // 344
	ScreenChooser* screenChooser; // 352
	char mcclient_vars8[16]; // 356
	bool idk_b; // 372
	int filler_i2; // 376
	char mcclient_vars9[16]; // 380
	float dPadScale; // 396
	char mcclient_vars10[32]; // 400
	bool isEdu; // 432
	bool isMcWorld; // 433
	std::string idk_s1; // 436  (set to Util::EMPTY_STRING)
	char mcclient_vars11[4]; // 440
	float keyboardHeight; // 444
	char mcclient_vars12[12]; // 448
	Social::Telemetry::TelemetryManager* telemetryManager; // 460
public:
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppPaused();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onPushNotificationReceived(PushNotificationMessage const&);
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual bool useTouchscreen();
	virtual void setTextboxText(std::string const&);
	virtual void update();
	virtual void setUISizeAndScale(int, int, float);
	virtual void setRenderingSize(int, int);
	virtual void init();
	virtual void handleBack(bool);
	virtual void onInternetUpdate();
	virtual void playerListChanged();
	virtual bool canActivateKeyboard();
	virtual void onActiveResourcePacksChanged(ResourcePackManager&);
	virtual void onLanguageSubpacksChanged();
	virtual void onLevelCorrupt();
	virtual void onGameModeChanged();
	virtual void onGameSessionReset();
	virtual void createSkin();
	virtual void onLevelExit();
	virtual void onTick(int, int);
	virtual void vibrate(int);
public:
	MinecraftClient(int, char**);
	Options* getOptions();
	Server* getServer();
	void getHoloInput() const;
	void getSkinRepository() const;
	void getInput() const;
	void getAutomationClient() const;
	void setEduMode(bool);
	void getLevelLoader();
	void getContentManager();
	void setLaunchedFromOculusApp(bool);
	float getDpadScale();
	int getScreenWidth() const;
	int getScreenHeight() const;
	void getLevelArchiver();
	void startLocalServer(std::string, std::string, LevelSettings);
	void updateScheduledScreen();
	void leaveGame(bool);
	void getEventing() const;
	ScreenChooser* getScreenChooser() const;
	GuiData* getGuiData();
	void pushScreen(std::shared_ptr<AbstractScreen>, bool);
	void resetInput();
	void startFrame();
	void getGuiScale(int);
	void setGameMode(GameType);
	void setHoloMode(HoloGameMode);
	void updateStats();
	void _reloadFancy(bool);
	void handleInvite();
	void initEventing();
	bool isKindleFire(int);
	void joinLiveGame(std::string const&);
	void onUserSignin();
	void refocusMouse();
	void releaseMouse();
	void setDpadScale(float);
	void setHoloInput(std::unique_ptr<HolographicPlatform, std::default_delete<HolographicPlatform> >);
	void forEachScreen(std::function<bool (std::shared_ptr<AbstractScreen>&)>, bool);
	void getScreenName();
	void onUserSignout();
	void reloadShaders(bool);
	void restartServer();
	void setupRenderer();
	void useController();
	void checkForPiracy();
	LocalPlayer* getLocalPlayer();
	std::vector<std::string> getScreenNames();
	void handleTextChar(std::string const&, bool, FocusImpact);
	void joinRealmsGame(Realms::World const&, Social::GameConnectionInfo const&);
	void onPlayerLoaded(Player&);
	void setVoiceSystem(std::unique_ptr<VoiceSystem, std::default_delete<VoiceSystem> >);
	void updateGraphics(Timer const&);
	void getToastManager();
	void handleDirection(DirectionId, float, float, FocusImpact);
	void isServerVisible();
	void joinMultiplayer(Social::GameConnectionInfo, bool);
	void setCameraEntity(Entity*);
	void setDisableInput(bool);
	void setSuspendInput(bool);
	void setupClientGame(std::function<void (bool)>, bool);
	void tickBuildAction();
	void _reloadLanguages();
	void getGuiScaleIndex(float);
	void sendLocalMessage(std::string const&, std::string const&);
	void teardownRenderer();
	void _updateScreenshot();
	void calculateGuiScale(int);
	void composeScreenshot(TextureData&, std::string const&, bool);
	void handleBuildAction(BuildActionIntention&);
	void handleVectorInput(short, float, float, float, FocusImpact);
	void onResourcesLoaded();
	void requestScreenshot(std::string const&);
	void schedulePopScreen(int);
	void addDownloadingPack(std::string, unsigned long long);
	void getHoloviewerScale();
	void handleCommandEvent(VoiceCommand const&);
	void handleIdentityLost();
	void handleSimTimePause(bool);
	void handleSimTimeScale(float);
	void onDimensionChanged();
	void onMobEffectsChange();
	void setupCommandParser();
	void validateLocalLevel(std::string, std::string, LevelSettings);
	void getMobEffectsLayout();
	void getSituationalMusic();
	void handleCaretLocation(int, FocusImpact);
	void initOptionObservers();
	void joinRealmFromInvite(Social::XboxLiveGameInfo const&);
	void setupLevelRendering(Level*, Dimension*, Entity*);
	void transformResolution(int*, int*);
	void updateFoliageColors();
	void _initMinecraftClient();
	void captureScreenAsImage(TextureData&);
	void forEachVisibleScreen(std::function<void (std::shared_ptr<AbstractScreen>&)>, bool);
	void getUIMeasureStrategy();
	void handleDictationEvent();
	void handleIdentityGained();
	void handleLicenseChanged();
	void hasNetworkPrivileges(bool);
	void initializeTrialWorld(Player*);
	void onClientStartedLevel(std::unique_ptr<Level, std::default_delete<Level> >, std::unique_ptr<LocalPlayer, std::default_delete<LocalPlayer> >);
	void registerUpsellScreen();
	void waitAsyncSuspendWork();
	void createDynamicTextures();
	void getUserAuthentication();
	void handleDropButtonPress();
	void handleMenuButtonPress(short, FocusImpact);
	void handlePointerLocation(short, short, FocusImpact);
	void handleToggleUIProfile();
	void onPrepChangeDimension();
	void setCameraTargetEntity(Entity*);
	void startHoloviewerReveal();
	void updateDownloadingPack(std::string, unsigned long long, bool);
	void _toggleThirdPersonView();
	void destroyDynamicTextures();
	void getHoloscreenHalfWidth();
	void handleInputModeChanged(InputMode);
	void handlePauseButtonPress();
	void handleShowUpsellScreen(bool);
	void setHoloscreenHalfWidth(float);
	void getResourcePackProgress();
	void handleChatButtonRelease();
	void handleMenuButtonRelease(short, FocusImpact);
	void handlePaddleButtonPress(Side);
	void onGameEventNotification(ui::GameEventNotification);
	void setHoloviewerPlayerMode(bool, bool);
	void setKeyboardForcedHeight(float);
	void _adjustGazeCursorByMouse(float, float);
	void getResourcePacksInfoData();
	void handleDropAllButtonPress();
	void setResourcePacksInfoData(ResourcePacksInfoData const&);
	void handleCraftingButtonPress();
	void handleDismountButtonPress();
	void handleInteractButtonPress();
	void handlePaddleButtonRelease(Side);
	void handleReloadUIDefinitions();
	void handleUIScalingRuleChange();
	void setProcessRegistrationKey(std::string const&);
	void getActiveDirectoryIdentity();
	void handleConsoleButtonRelease();
	void handleHoloInputModeChanged(HoloUIInputMode);
	void handleInventoryButtonPress();
	void repopulatePlayScreenWorlds();
	void _registerOnInitUriListeners();
	void clearDictationDataAvailable();
	void handleControllerTypeChanged();
	void handleDebugToggleLSRCommand();
	void handleMobEffectsButtonPress();
	void handleSetGazeControllerMode();
	void handleSlotSelectButtonPress(int);
	void handleMemoryStatsButtonPress();
	void handleNextAVCStatButtonPress();
	void handleRenderDebugButtonPress();
	void handleStickCursorButtonPress();
	void _processNewGazeHoloScreenData();
	void _unregisterOnInitUriListeners();
	void currentScreenShouldStealMouse();
	void handleBiomeDisplayButtonPress();
	void handleDropAllItemsButtonPress();
	void handleToggleNoClipButtonPress();
	void handleBuildActionButtonRelease();
	void handleBuildOrAttackButtonPress();
	void handleInventoryMoveButtonPress(int);
	void handleNextAVCStatButtonRelease();
	void handleResourcePackConfirmation(ResourcePackResponse, bool);
	void handleStickCursorButtonRelease();
	void handleSuspendResumeButtonPress();
	void handleToggleTexelAAButtonPress();
	void _deserializeGlobalResourcePacks();
	void _getGuiScaleIndexForLargeScreen(int, int);
	void _getGuiScaleIndexForSmallScreen(int, int);
	void handleAttackActionButtonRelease();
	void handleDebugToggleAnchorsCommand();
	void handlePointerPressedButtonPress();
	void handleToggleFlyFlastButtonPress();
	void handleToggleGameModeButtonPress();
	void setInhibitInputDueToTextBoxMode();
	void handleBuildOrInteractButtonPress();
	void handleDestoryOrAttackButtonPress();
	void handlePickDebugObjectButtonPress();
	void handleTimeStepForwardButtonPress();
	void handleToastInteractButtonRelease();
	void displayActiveDirectoryLoginDialog();
	void handleLowMemoryWarningButtonPress();
	void handlePointerPressedButtonRelease();
	void handleSetSpawnPositionButtonPress();
	void resetInhibitInputDueToTextBoxMode();
	void setDeferRenderingUntilChunksReady();
	void setupStartMenuScreenCommandParser();
	void _recenterGazeActivationOriginPoint();
	void getResourcePackDownloadingProgress(std::string&);
	void handleDestroyOrInteractButtonPress();
	void handleDebugWorkerThreadsButtonPress();
	void handleToggleLivingroomButtonRelease();
	void handleToggleShowChunkMapButtonPress();
	void _loadLastGlobalResourcePacksFromFile();
	void handleToggleSimulateTouchButtonPress();
	void handlePointerLocationWithGazeOverride(short, short);
	void handleToggleDayCycleActiveButtonPress();
	void initFoliageAndBlockTextureTessellator();
	void handleCreativeBlockSelectButtonRelease();
	void handleToggleAdvancedCullingButtonPress();
	void handleToggleThirdPersonViewButtonPress();
	void handleDecreaseRenderDistanceButtonPress();
	void handleIncreaseRenderDistanceButtonPress();
	void handleToggleChatTextToSpeechButtonPress();
	void handleTogglePlayerUpdateMobsButtonPress();
	void _computeScreenCoordsFromScreenNormCoords(float, float, short&, short&);
	void handleToggleFrameTimerDisplayButtonPress();
	void handleDecrementMaxCullingStepsButtonPress();
	void handleIncrementMaxCullingStepsButtonPress();
	void _shouldUseLastPointerLocationOnFocusChange();
	void currentInputModeIsGamePadOrMotionController();
	void handleToggleEnableNewScreensDebugButtonPress();
	void returnJoinLobbyResultBasedOnPendingRealmsInvites();
	void play(std::string const&, Vec3 const&, float, float);
	void playUI(std::string const&, float, float);
	void ResetBai(int);
	void endFrame();
	void isInGame();
	void getRealms();
	Screen* getScreen();
	void grabMouse();
	void tickInput();
	int getUIWidth() const;
	void getRuneFont() const;
	void getTextures() const;
	void getUIHeight() const;
	bool allowPicking() const;
	void getUIDefRepo() const;
	bool isNotVLRMode() const;
	bool isInBedScreen() const;
	bool isShowingMenu() const;
	LocalPlayer* getLocalPlayer() const;
	void getMultiplayer() const;
	void getSoundEngine() const;
	void getUserManager() const;
	void getVoiceSystem() const;
	bool isUserSignedIn() const;
	Entity* getCameraEntity() const;
	void getGameRenderer() const;
	void getMouseGrabbed() const;
	std::string getSettingsPath() const;
	bool isIPv4Supported() const;
	bool isIPv6Supported() const;
	std::string getDictationText() const;
	void getGeometryGroup() const;
	LevelRenderer* getLevelRenderer() const;
	void getClientRandomId() const;
	void getExternalServer() const;
	void getParticleEngine() const;
	bool isSRPlacementMode() const;
	void getDownloadMonitor() const;
	void getForceMonoscopic() const;
	void getOfferRepository() const;
	bool isHoloCursorNeeded() const;
	void getCurrentInputMode() const;
	bool hasPendingScreenPop() const;
	bool isRealityFullVRMode() const;
	bool isScreenReplaceable() const;
	void getHolosceneRenderer() const;
	void getSkinGeometryGroup() const;
	Entity* getCameraTargetEntity() const;
	void getCurrentLevelSummary() const;
	void getResourcePackManager() const;
	bool isLaunchedFromOculusApp() const;
	void getResourcePackRepository() const;
	void newDictationDataAvailable() const;
	void getOculusPlatformMessagePump() const;
	bool isHostingLocalDedicatedServer() const;
	void getResourcePackDownloadManager(std::string const&) const;
	Font* getFont() const;
	Screen* getScreen() const;
	bool isEduMode() const;
};
