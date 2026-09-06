#pragma once
#include "Scene.h"
class SceneGamePlay : public Scene
{
public:
	int Init() override;
	int Update() override;
	int Render() override;
	int Destroy() override;
};

