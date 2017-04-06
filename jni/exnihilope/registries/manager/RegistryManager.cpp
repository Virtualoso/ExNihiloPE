#include "RegistryManager.h"

#include "ISieveDefaultRegistryProvider.h"
#include "IHammerDefaultRegistryProvider.h"
#include "ICompostDefaultRegistryProvider.h"
#include "ICrookDefaultRegistryProvider.h"
#include "ICrucibleDefaultRegistryProvider.h"
#include "IFluidBlockDefaultRegistryProvider.h"
#include "IFluidTransformDefaultRegistryProvider.h"
#include "IFluidOnTopDefaultRegistryProvider.h"
#include "IHeatDefaultRegistryProvider.h"
#include "IOreDefaultRegistryProvider.h"

std::vector<ISieveDefaultRegistryProvider*> RegistryManager::defaultSieveRecipeHandlers = {};
std::vector<IHammerDefaultRegistryProvider*> RegistryManager::defaultHammerRecipeHandlers = {};
std::vector<ICompostDefaultRegistryProvider*> RegistryManager::defaultCompostRecipeHandlers = {};
std::vector<ICrookDefaultRegistryProvider*> RegistryManager::defaultCrookRecipeHandlers = {};
std::vector<ICrucibleDefaultRegistryProvider*> RegistryManager::defaultCrucibleRecipeHandlers = {};
std::vector<IFluidBlockDefaultRegistryProvider*> RegistryManager::defaultFluidBlockRecipeHandlers = {};
std::vector<IFluidTransformDefaultRegistryProvider*> RegistryManager::defaultFluidTransformRecipeHandlers = {};
std::vector<IFluidOnTopDefaultRegistryProvider*> RegistryManager::defaultFluidOnTopRecipeHandlers = {};
std::vector<IHeatDefaultRegistryProvider*> RegistryManager::defaultHeatRecipeHandlers = {};
std::vector<IOreDefaultRegistryProvider*> RegistryManager::defaultOreRecipeHandlers = {};
		
void RegistryManager::registerSieveDefaultRecipeHandler(ISieveDefaultRegistryProvider* provider) {
	defaultSieveRecipeHandlers.push_back(provider);
}

void RegistryManager::registerHammerDefaultRecipeHandler(IHammerDefaultRegistryProvider* provider) {
	defaultHammerRecipeHandlers.push_back(provider);
}
	
void RegistryManager::registerCompostDefaultRecipeHandler(ICompostDefaultRegistryProvider* provider) {
	defaultCompostRecipeHandlers.push_back(provider);
}

void RegistryManager::registerCrookDefaultRecipeHandler(ICrookDefaultRegistryProvider* provider) {
	defaultCrookRecipeHandlers.push_back(provider);
}

void RegistryManager::registerCrucibleDefaultRecipeHandler(ICrucibleDefaultRegistryProvider* provider) {
	defaultCrucibleRecipeHandlers.push_back(provider);
}

void RegistryManager::registerFluidBlockDefaultRecipeHandler(IFluidBlockDefaultRegistryProvider* provider) {
	defaultFluidBlockRecipeHandlers.push_back(provider);
}

void RegistryManager::registerFluidTransformDefaultRecipeHandler(IFluidTransformDefaultRegistryProvider* provider) {
	defaultFluidTransformRecipeHandlers.push_back(provider);
}

void RegistryManager::registerFluidOnTopDefaultRecipeHandler(IFluidOnTopDefaultRegistryProvider* provider) {
	defaultFluidOnTopRecipeHandlers.push_back(provider);
}

void RegistryManager::registerHeatDefaultRecipeHandler(IHeatDefaultRegistryProvider* provider) {
	defaultHeatRecipeHandlers.push_back(provider);
}

void RegistryManager::registerOreDefaultRecipeHandler(IOreDefaultRegistryProvider* provider) {
	defaultOreRecipeHandlers.push_back(provider);
}