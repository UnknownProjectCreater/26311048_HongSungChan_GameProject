#pragma once
#include <string>
#include "glc2d.h"
#include "TextureManager.h"
class GameObject
{
public:
	int LoadTexture(TEXTURE textureID);
	int Render(VEC2* scaling);
	int ReleaseTexture();

	std::string m_name;
	VEC2 m_pos{0, 0};
	int m_texture = -1;
};