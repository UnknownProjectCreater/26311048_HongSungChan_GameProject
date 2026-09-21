
#include <iostream>
#include <cmath>
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
	m_isTrigger = false;

	m_name = "";
	m_image.scaling = { 1, 1 };
	m_image.texture = -1;
	m_image.alphaOption = 1;
}

GameObject::~GameObject()
{
}

int GameObject::Init(TextureType textureId)
{
	m_image.texture = g2_TextureLoad(g_textureManager.m_textureFiles[textureId]);

	return 0;
}

int GameObject::Destroy()
{
	g2_TextureRelease(m_image.texture);

	return 0;
}

void GameObject::SetColliderSize()
{
	int nTx = m_image.texture;

	m_collider.height = g2_TextureHeight(nTx) * m_image.scaling.y;
	m_collider.width = g2_TextureWidth(nTx) *m_image.scaling.x;
}