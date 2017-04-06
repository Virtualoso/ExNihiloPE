#pragma once

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

class ExNihiloDefaultRecipes: public ISieveDefaultRegistryProvider, public IHammerDefaultRegistryProvider,
public ICompostDefaultRegistryProvider, public ICrookDefaultRegistryProvider, public ICrucibleDefaultRegistryProvider, public IFluidBlockDefaultRegistryProvider,
public IFluidTransformDefaultRegistryProvider, public IFluidOnTopDefaultRegistryProvider, public IHeatDefaultRegistryProvider, public IOreDefaultRegistryProvider {
public:
	ExNihiloDefaultRecipes();

	virtual void registerSieveRecipeDefaults();
	virtual void registerHammerRecipeDefaults();
	virtual void registerCompostRecipeDefaults();
	virtual void registerCrookRecipeDefaults();
	virtual void registerCrucibleRecipeDefaults();
	virtual void registerFluidBlockRecipeDefaults();
	virtual void registerFluidTransformRecipeDefaults();
	virtual void registerFluidOnTopRecipeDefaults();
	virtual void registerHeatRecipeDefaults();
	virtual void registerOreRecipeDefaults();
};
