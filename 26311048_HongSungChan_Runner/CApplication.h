#pragma once
#include <windows.h>
#include <string>
#include "Scene.h"
#include "SceneGameStart.h"
#include "SceneGamePlay.h"
#include "SceneGameResult.h"

class CApplication
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

	int SceneChange(Scene* changeScene);

	// windows
	POINT m_winPos{ 100, 100 };
	SIZE m_winSize{ 1024, 600 };
	std::string m_winName = "Block Runner";

protected:
	int InitSdk();

	// scene manage
	Scene* m_currentScene = nullptr;
	SceneGameStart m_sceneStart;
	SceneGamePlay m_scenePlay;
	SceneGameResult m_sceneResult;
};