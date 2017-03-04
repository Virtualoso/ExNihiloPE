#pragma once

#include <memory>

class MinecraftClient;
class UIControl;

class SplashTextRenderer
{
public:
	void render(MinecraftClient &,std::shared_ptr<UIControl> &,int,RectangleArea&) ;
};
