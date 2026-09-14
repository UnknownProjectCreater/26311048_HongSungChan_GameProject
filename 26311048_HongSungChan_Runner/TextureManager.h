#pragma once
#include <iostream>
#include <unordered_map>
#include "glc2d.h"

enum class TextureType
{
	BACKGROUND,
	ENTITY_PLAYER,
	GAMEOBJECT_OBSTACLE_ONEBLOCK,
	GAMEOBJECT_OBSTACLE_TWOBLOCK,
	UI_TITLE_GAMEMAINMENU,
	UI_BUTTON_GAMESTART
};

class TextureManager
{
public:
	int SetTextureFiles();
	std::unordered_map<TextureType, CSTR> m_textureFiles;
};