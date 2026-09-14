#include <iostream>
#include <Windows.h>
#include "glc2d.h"
#include "SceneGamePlay.h"
#include "CApplication.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Entity.h"
#include "Platform.h"
#include "Background.h"

extern CApplication g_app;
extern GameManager g_gameManager;

Entity* player;

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

int SceneGamePlay::Init()
{
	player = g_gameManager.CreateObject<Entity>();
	g_gameManager.m_currentBackgroundType = BackgroundType::SCREEN_PLAY;

	player->Init(TextureType::ENTITY_PLAYER);
	VEC2 objPos(10, 500);
	player->SetPosition(objPos);

	return 0;
}

int SceneGamePlay::Update(float deltaTime)
{
	PlayerController();

	g_gameManager.UpdateAll(deltaTime);

	return 0;
}

int SceneGamePlay::Render()
{
	g_gameManager.RenderAll();

	return 0;
}

int SceneGamePlay::Destroy()
{
	g_gameManager.ClearAll();

	return 0;
}