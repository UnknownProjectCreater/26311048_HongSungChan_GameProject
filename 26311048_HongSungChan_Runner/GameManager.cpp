#include <iostream>
#include "GameManager.h"

int GameManager::m_nextId = 0;
VEC2 GameManager::m_gravity = { 0, 980.0f };

int GameManager::UpdateAll(float deltaTime)
{
	for (auto& pair : m_gameObjects)
	{
		GameObject* gameObject = pair.second;

		if (gameObject->isActive())
		{
			gameObject->Update(deltaTime);
		}
	}

	return 0;
}

int GameManager::RenderAll()
{
	m_backgrounds[m_currentBackgroundType]->Render();

	for (auto& pair : m_gameObjects)
	{
		GameObject* gameObject = pair.second;

		if (gameObject->isActive())
		{
			gameObject->Render();
		}
	}

	return 0;
}

int GameManager::ClearAll()
{
	for (auto& pair : m_gameObjects)
	{
		delete pair.second;
		pair.second = nullptr;
	}

	m_gameObjects.clear();

	return 0;
}

bool GameManager::OnCollision(const GameObject* a, const GameObject* b)
{
	if (a->GetRight() <= b->GetLeft() || a->GetLeft() >= b->GetRight())
		return false;

	if (a->GetBottom() <= b->GetTop() || a->GetTop() >= b->GetBottom())
		return false;

	return true;
}
