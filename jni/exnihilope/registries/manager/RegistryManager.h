#pragma once

#include <vector>

class ISieveDefaultRegistryProvider;
class IHammerDefaultRegistryProvider;
class ICompostDefaultRegistryProvider;
class ICrookDefaultRegistryProvider;
class ICrucibleDefaultRegistryProvider;
class IFluidBlockDefaultRegistryProvider;
class IFluidTransformDefaultRegistryProvider;
class IFluidOnTopDefaultRegistryProvider;
class IHeatDefaultRegistryProvider;
class IOreDefaultRegistryProvider;

class RegistryManager {
private:
	static std::vector<ISieveDefaultRegistryProvider*> defaultSieveRecipeHandlers;
	static std::vector<IHammerDefaultRegistryProvider*> defaultHammerRecipeHandlers;
	static std::vector<ICompostDefaultRegistryProvider*> defaultCompostRecipeHandlers;
	static std::vector<ICrookDefaultRegistryProvider*> defaultCrookRecipeHandlers;
	static std::vector<ICrucibleDefaultRegistryProvider*> defaultCrucibleRecipeHandlers;
	static std::vector<IFluidBlockDefaultRegistryProvider*> defaultFluidBlockRecipeHandlers;
	static std::vector<IFluidTransformDefaultRegistryProvider*> defaultFluidTransformRecipeHandlers;
	static std::vector<IFluidOnTopDefaultRegistryProvider*> defaultFluidOnTopRecipeHandlers;
	static std::vector<IHeatDefaultRegistryProvider*> defaultHeatRecipeHandlers;
	static std::vector<IOreDefaultRegistryProvider*> defaultOreRecipeHandlers;
		
public:
	static void registerSieveDefaultRecipeHandler(ISieveDefaultRegistryProvider* provider);
	static void registerHammerDefaultRecipeHandler(IHammerDefaultRegistryProvider* provider);
	static void registerCompostDefaultRecipeHandler(ICompostDefaultRegistryProvider* provider);
	static void registerCrookDefaultRecipeHandler(ICrookDefaultRegistryProvider* provider);
	static void registerCrucibleDefaultRecipeHandler(ICrucibleDefaultRegistryProvider* provider);
	static void registerFluidBlockDefaultRecipeHandler(IFluidBlockDefaultRegistryProvider* provider);
	static void registerFluidTransformDefaultRecipeHandler(IFluidTransformDefaultRegistryProvider* provider);
	static void registerFluidOnTopDefaultRecipeHandler(IFluidOnTopDefaultRegistryProvider* provider);
	static void registerHeatDefaultRecipeHandler(IHeatDefaultRegistryProvider* provider);
	static void registerOreDefaultRecipeHandler(IOreDefaultRegistryProvider* provider);

	static std::vector<ISieveDefaultRegistryProvider*> getDefaultSieveRecipeHandlers() { return defaultSieveRecipeHandlers; }
	static std::vector<IHammerDefaultRegistryProvider*> getDefaultHammerRecipeHandlers() { return defaultHammerRecipeHandlers; }
	static std::vector<ICompostDefaultRegistryProvider*> getDefaultCompostRecipeHandlers() { return defaultCompostRecipeHandlers; }
	static std::vector<ICrookDefaultRegistryProvider*> getDefaultCrookRecipeHandlers() { return defaultCrookRecipeHandlers; };
	static std::vector<ICrucibleDefaultRegistryProvider*> getDefaultCrucibleRecipeHandlers() { return defaultCrucibleRecipeHandlers; };
	static std::vector<IFluidBlockDefaultRegistryProvider*> getDefaultFluidBlockRecipeHandlers() { return defaultFluidBlockRecipeHandlers; };
	static std::vector<IFluidTransformDefaultRegistryProvider*> getDefaultFluidTransformRecipeHandlers() { return defaultFluidTransformRecipeHandlers; };
	static std::vector<IFluidOnTopDefaultRegistryProvider*> getDefaultFluidOnTopRecipeHandlers() { return defaultFluidOnTopRecipeHandlers; };
	static std::vector<IHeatDefaultRegistryProvider*> getDefaultHeatRecipeHandlers() { return defaultHeatRecipeHandlers; };
	static std::vector<IOreDefaultRegistryProvider*> getDefaultOreRecipeHandlers() { return defaultOreRecipeHandlers; };
};
