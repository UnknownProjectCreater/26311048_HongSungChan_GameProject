#include <stdio.h>
#include "glc2d.h"
#include "CApplication.h"
#include "GameManager.h"
#include "TextureManager.h"
#include "Time.h"

#include "GameObject.h"
#include "Entity.h"
#include "Background.h"

extern CApplication g_app;
GameManager g_gameManager;
TextureManager g_textureManager;
Time g_time;

Background* entity;

int AddUpdate()
{
	return g_app.Update();
}

int AddRender()
{
	return g_app.Render();
}

int CApplication::Init()
{
	InitSdk();
	g_textureManager.SetTextureFiles();

	m_currentScene = &m_sceneStart;
	m_currentScene->Init();

	return 0;
}

int CApplication::Update()
{
	m_currentScene->Update(g_time.GetDeltaTime());

	return 0;
}

int CApplication::Render()
{
	m_currentScene->Render();

	return 0;
}

int CApplication::Destroy()
{
	m_currentScene->Destroy();

	g2_DestroyWin();

	return 0;
}

int CApplication::InitSdk()
{
	g2_InitSdk();

	g2_SetFrameMove(AddUpdate);
	g2_SetRender(AddRender);

	g2_CreateWin(m_winPos.x, m_winPos.y, m_winSize.cx, m_winSize.cy, m_winName.c_str());
	
	return 0;
}