
#include <iostream>
#include "CApplication.h"
#include "GameManager.h"
#include "TextureManager.h"
#include "GameObject.h"

extern TextureManager g_textureManager;
extern GameManager g_gameManager;

GameObject::GameObject()
{
	m_pos = { 0, 0 };
	m_collider = { 0, 0 };
	m_tag = Tag::NONE;
	m_isActive = true;

	m_name = "";
	m_image.scaling = { 1, 1 };
	m_image.texture = -1;
	m_image.alphaOption = 1;
}

GameObject::~GameObject()
{
}

int GameObject::Init(Texture textureId)
{
	m_image.texture = g2_TextureLoad(g_textureManager.m_textureFiles[textureId]);

	return 0;
}

int GameObject::Destroy()
{
	g2_TextureRelease(m_image.texture);

	return 0;
}