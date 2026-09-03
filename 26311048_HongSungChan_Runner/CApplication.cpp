#include <stdio.h>
#include "glc2d.h"
#include "CApplication.h"

extern CApplication g_app;

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

	m_sceneStart.Init();

	return 0;
}

int CApplication::Update()
{
	m_sceneStart.Update();

	return 0;
}

int CApplication::Render()
{
	m_sceneStart.Render();

	return 0;
}

int CApplication::Destroy()
{
	m_sceneStart.Destroy();

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

