#pragma once
#include "Scene.h"
#include "Image.h"
#include "Background.h"

class SceneGameStart : public Scene
{
private:
	Background* background = nullptr;
	Image* gameTitle = nullptr;
	Image* startButton = nullptr;

public:
	int Init() override;
	int Update(float deltaTime) override;
	int Render() override;
	int Destroy() override;
};

