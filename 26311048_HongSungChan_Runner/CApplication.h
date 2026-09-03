#pragma once
#include <windows.h>
#include <string>
#include "SceneGameStart.h"

class CApplication
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	int InitSdk();

protected:
	// windows
	POINT m_winPos{ 100, 100 };
	SIZE m_winSize{ 1024, 600 };

	std::string m_winName = "Block Runner";

	
	SceneGameStart m_sceneStart;
};