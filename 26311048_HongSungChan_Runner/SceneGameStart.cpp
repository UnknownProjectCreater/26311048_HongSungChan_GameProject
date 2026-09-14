#include <iostream>
#include <Windows.h>
#include "glc2d.h"
#include "SceneGameStart.h"
#include "CApplication.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Entity.h"
#include "Platform.h"
#include "Background.h"

extern CApplication g_app;
extern GameManager g_gameManager;

Entity* player;
Entity* obj;
Background* background;

int nTexW;
int nTexH;

FLOAT scaleX;
FLOAT scaleY;

int PlayerController()
{
	const KEYCODE* pKeyboard = g2_GetKeyboard();

	float speed = 300.0f;

	if (pKeyboard[68])
	{
		VEC2 v(speed, 0);
		player->SetVelocity(v);
	}
	else if (pKeyboard[65])
	{
		VEC2 v(-speed, 0);
		player->SetVelocity(v);
	}

	return 0;
}

int BackGroundScaling()
{
	int nTx = background->m_image.texture;
	nTexW = g2_TextureWidth(nTx);
	nTexH = g2_TextureHeight(nTx);

	scaleX = (FLOAT)g_app.m_winSize.cx / nTexW;
	scaleY = (FLOAT)g_app.m_winSize.cy / nTexH;

	return 0;
}

int SceneGameStart::Init()
{
	player = g_gameManager.CreateObject<Entity>();
	background = g_gameManager.CreateBackground(BackgroundType::SCREEN_PLAY);
	g_gameManager.m_currentBackgroundType = BackgroundType::SCREEN_PLAY;

	player->Init(Texture::PLAYER);
	VEC2 objPos(10, 500);
	player->SetPosition(objPos);
	background->Init(Texture::BACKGROUND);

	BackGroundScaling();

	return 0;
}

int SceneGameStart::Update(float deltaTime)
{
	PlayerController();

	g_gameManager.UpdateAll(deltaTime);

	return 0;
}

int SceneGameStart::Render()
{
	VEC2 scale(scaleX, scaleY);

	background->SetScaling(scale);

	g_gameManager.RenderAll();

	return 0;
}

int SceneGameStart::Destroy()
{
	g_gameManager.ClearAll();

	return 0;
}