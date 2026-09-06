#include <stdio.h>
#include "glc2d.h"
#include "CApplication.h"
#include "TextureManager.h"

extern CApplication g_app;
TextureManager g_textureManager;

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
	m_currentScene->Update();

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

int CApplication::SceneChange(Scene* changeScene)
{
	m_currentScene = changeScene;

	return 0;
}