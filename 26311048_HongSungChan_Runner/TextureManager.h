#pragma once
#include <iostream>
#include <unordered_map>
#include "glc2d.h"

enum class Texture
{
	CUBE,
	BACKGROUND,
	PLAYER,
	OBSTACLE_ONEBLOCK,
	OBSTACLE_TWOBLOCK
};

class TextureManager
{
public:
	int SetTextureFiles();
	std::unordered_map<Texture, CSTR> m_textureFiles;
};