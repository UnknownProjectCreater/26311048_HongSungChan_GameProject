#include "CApplication.h"
#include "TextureManager.h"
#include "GameObject.h"

extern TextureManager g_textureManager;

int GameObject::LoadTexture(TEXTURE textureID)
{
	m_texture = g2_TextureLoad(g_textureManager.m_textureFiles[textureID]);

	return 0;
}

int GameObject::Render(VEC2* scaling)
{
	g2_Draw2D(m_texture, NULL, &this->m_pos, scaling);

	return 0;
}

int GameObject::ReleaseTexture()
{
	g2_TextureRelease(m_texture);

	return 0;
}