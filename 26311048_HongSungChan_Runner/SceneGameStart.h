#pragma once
#include "Scene.h"
class SceneGameStart : Scene
{
public:
	int Init() override;
	int Update() override;
	int Render() override;
	int Destroy() override;
protected:
	int m_texture = -1;
};

