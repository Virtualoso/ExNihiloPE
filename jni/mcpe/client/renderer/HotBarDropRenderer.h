#pragma once

#include <memory>

class MinecraftClient;
class UIControl;
class RectangleArea;
class HotBarDropRenderer
{
public:
	void render(MinecraftClient&,std::shared_ptr<UIControl>&,int,RectangleArea&);
};
