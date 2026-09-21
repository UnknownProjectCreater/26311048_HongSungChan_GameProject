#pragma once
#include "Scene.h"
#include "Entity.h"
#include "Platform.h"

class SceneGamePlay : public Scene
{
private:
	Entity* m_player = nullptr;
	Platform* m_ground = nullptr;

	int m_jumpSound;

public:
	int Init() override;
	int Update(float deltaTime) override;
	int Render() override;
	int Destroy() override;
};