#pragma once

#include <string>

#include "GuiElement.h"

class MinecraftClient;
class Color;

class Label : public GuiElement
{
public:
	char filler[50];
public:
	Label(MinecraftClient&,std::string const&,Color const&,int,int,int,bool,bool);
	void setWidth(int);
	void setCentered(bool);
};
