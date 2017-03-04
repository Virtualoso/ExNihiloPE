#pragma once

#include <memory>

class MinecraftClient;
class UIControl;
class HudVignetteRenderer
{
public:
	void _renderVignette(MinecraftClient&,float,int,int);
	void render(MinecraftClient&,std::shared_ptr<UIControl>&,int,RectangleArea&);
};
