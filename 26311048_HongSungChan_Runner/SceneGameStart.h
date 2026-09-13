#pragma once
#include "Scene.h"
class SceneGameStart : public Scene
{
public:
	int Init() override;
	int Update(float deltaTime) override;
	int Render() override;
	int Destroy() override;
};

