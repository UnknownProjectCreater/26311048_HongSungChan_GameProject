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
#include "Image.h"

extern CApplication g_app;
extern GameManager g_gameManager;

Background* background;
Image* gameTitle;
Image* startButton;

FLOAT scaleX;
FLOAT scaleY;

int BackGroundScaling()
{
	int nTexW{ 0 };
	int nTexH{ 0 };

	int nTx = background->m_image.texture;
	nTexW = g2_TextureWidth(nTx);
	nTexH = g2_TextureHeight(nTx);

	scaleX = (FLOAT)g_app.m_winSize.cx / nTexW;
	scaleY = (FLOAT)g_app.m_winSize.cy / nTexH;

	return 0;
}

int SceneGameStart::Init()
{
	background = g_gameManager.CreateBackground(BackgroundType::SCREEN_PLAY);
	g_gameManager.m_currentBackgroundType = BackgroundType::SCREEN_PLAY;
	background->Init(TextureType::BACKGROUND);

	gameTitle = g_gameManager.CreateObject<Image>();
	gameTitle->Init(TextureType::UI_TITLE_GAMEMAINMENU);
	VEC2 titlePos = { 310, 10 };
	gameTitle->SetPosition(titlePos);

	startButton = g_gameManager.CreateObject<Image>();
	startButton->Init(TextureType::UI_BUTTON_GAMESTART);
	VEC2 startButtonPos = { 400, 300 };
	startButton->SetPosition(startButtonPos);

	BackGroundScaling();

	return 0;
}

int SceneGameStart::Update(float deltaTime)
{
	g_gameManager.UpdateAll(deltaTime);

	const KEYCODE* pKeyboard = g2_GetKeyboard();

	if (pKeyboard[VK_SPACE])
	{
		g_app.SignChangeScene(SceneType::SCENEPLAY);
	}

	return 0;
}

int SceneGameStart::Render()
{
	VEC2 backgroundScale(scaleX, scaleY);
	background->SetScaling(backgroundScale);

	VEC2 titleScale(2, 2);
	gameTitle->SetScaling(titleScale);

	//VEC2 startButtonScale(1, 1);
	//startButton->SetScaling(startButtonScale);

	g_gameManager.RenderAll();

	return 0;
}

int SceneGameStart::Destroy()
{
	g_gameManager.ClearAll();

	return 0;
}