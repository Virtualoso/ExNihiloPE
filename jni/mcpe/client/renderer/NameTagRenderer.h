#pragma once

#include <memory>

class MinecraftClient;
class UIControl;
class NameTagRenderer
{
public:
	void render(MinecraftClient&,std::shared_ptr<UIControl>&,int,RectangleArea&);
};
