#pragma once
#include <iostream>
#include <unordered_map>
#include "glc2d.h"

enum class TextureType
{
	BACKGROUND,
	GROUND,
	ENTITY_PLAYER,
	GAMEOBJECT_OBSTACLE_ONEBLOCK,
	GAMEOBJECT_OBSTACLE_TWOBLOCK,
	GAMEOBJECT_OBSTACLE_THORN,
	UI_TITLE_GAMEMAINMENU,
	UI_BUTTON_GAMESTART
};

class TextureManager
{
public:
	int SetTextureFiles();
	std::unordered_map<TextureType, CSTR> m_textureFiles;
};