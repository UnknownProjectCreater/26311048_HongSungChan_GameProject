#include <iostream>
#include "GameManager.h"

int GameManager::m_nextId = 0;

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