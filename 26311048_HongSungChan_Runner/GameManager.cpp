#include <iostream>
#include "GameManager.h"

int GameManager::m_nextId = 0;

int GameManager::UpdateAll(float deltaTime)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* gameObject = m_gameObjects[i];

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

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* gameObject = m_gameObjects[i];

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