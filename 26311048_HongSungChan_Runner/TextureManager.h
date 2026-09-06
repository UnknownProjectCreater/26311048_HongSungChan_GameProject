#pragma once
#include <iostream>
#include <unordered_map>
#include "glc2d.h"

class TextureManager
{
public:
	int SetTextureFiles();

	std::unordered_map<int, CSTR> m_textureFiles;
};

enum TEXTURE
{
	TEXTURE_CUBE,
	TEXTURE_BACKGROUND,
	TEXTURE_PLAYER,
	TEXTURE_OBSTACLE 
};