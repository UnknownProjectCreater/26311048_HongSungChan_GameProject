#include <iostream>
#include <Windows.h>
#include "glc2d.h"
#include "SceneGameStart.h"
#include "CApplication.h"
#include "GameObject.h"

extern CApplication g_app;

GameObject* obj = new GameObject();
GameObject* backGround = new GameObject();

int nTexW;
int nTexH;

FLOAT scaleX;
FLOAT scaleY;

static long long g_lastTime = 0;

int PlayerController()
{
	const KEYCODE* pKeyboard = g2_GetKeyboard();

	long long now = g2_TimeGetTime();
	float deltaTime = (g_lastTime == 0) ? 0.0f : (now - g_lastTime) / 1000.0f;
	g_lastTime = now;

	float speed = 300.0f;

	if (pKeyboard[68])
	{
		obj->m_pos.x += speed * deltaTime;
	}
	else if (pKeyboard[65])
	{
		obj->m_pos.x -= speed * deltaTime;
	}

	return 0;
}

int BackGroundScaling()
{
	int nTx = backGround->m_texture;
	nTexW = g2_TextureWidth(nTx);
	nTexH = g2_TextureHeight(nTx);

	scaleX = (FLOAT)g_app.m_winSize.cx / nTexW;
	scaleY = (FLOAT)g_app.m_winSize.cy / nTexH;

	return 0;
}

int SceneGameStart::Init()
{
	obj->LoadTexture(TEXTURE_CUBE);
	VEC2 objPos(10, 500);
	obj->m_pos = objPos;

	backGround->LoadTexture(TEXTURE_BACKGROUND);
	BackGroundScaling();

	return 0;
}

int SceneGameStart::Update()
{
	PlayerController();
	
	return 0;
}

int SceneGameStart::Render()
{
	VEC2 pos(0, 0);
	VEC2 scale(scaleX, scaleY);

	backGround->Render(&scale);

	obj->Render(0);

	return 0;
}

int SceneGameStart::Destroy()
{
	return 0;
}