#pragma once
#include "Scene.h"
class SceneGamePlay : Scene
{
public:
	int Init() override;
	int Update() override;
	int Render() override;
	int Destroy() override;
};

