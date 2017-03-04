#pragma once

#include <memory>
#include <functional>
#include "BaseScreen.h"
#include "mcpe/client/MinecraftClient.h"

class Screen;
class SkinPack;

// Size : 20
class ScreenChooser
{
public:
	MinecraftClient *mc;
public:
	ScreenChooser(MinecraftClient &, bool, bool);
	~ScreenChooser();
	void pushLocalPlayScreen();
	void popScreen(AbstractScreen &, int);
	void schedulePopScreen(int);
	void pushAddExternalServerScreen(void);
	void pushAnvilScreen(Player &, BlockPos const &);
	void pushBlockSelectionScreen(void);
	void pushBrewingStandScreen(Player &, BlockPos const &);
	void pushChatScreen(void);
	void pushChestScreen(Player &, BlockPos const &);
	void pushConsoleScreen(void);
	void pushDebugScreen();
	void pushDeathScreen(void);
	void pushEnchantingScreen(Player &, BlockPos const &);
	void pushFurnaceScreen(Player &, BlockPos const &);
	void pushGamePadLayoutScreen(bool);
	void pushGameViewerScreen(void);
	void pushHudScreen(void);
	void pushInBedScreen(void);
	void pushKeyboardLayoutScreen(bool);
	void pushLanguageScreen(void);
	void pushLocalPlayScreen(bool, bool);
	void pushMessageBoxScreen(std::string const &);
	void pushMobEffectsScreen(void);
	void pushOptionsScreen(bool, bool, std::string const &);
	void pushPausePrevScreen(void);
	void pushPauseScreen(void);
	void pushPlaySpaceScreen(void);
	void pushProgressScreen(bool, std::function<void (void)>);
	void pushRealityScreen(void);
	void pushRemotePlayScreen(void);
	void pushSelectSkinTypeScreen(bool, bool, std::string const &);
	void pushShowSkinPackScreen(SkinPack const &, std::string const &, bool);
	void pushSkinsScreen(void);
	void pushUpsellScreen(bool);
	void pushNetworkProgressScreen(std::string const&);
	void pushXblLoginScreen(void);
	void setDisconnectScreen(std::string const &);
	void setGameplayScreen(void);
	void setStartMenuScreen(void);
	void pushResourcePacksScreen(bool);
	void _pushScreen(std::shared_ptr<BaseScreen>,bool);
};
