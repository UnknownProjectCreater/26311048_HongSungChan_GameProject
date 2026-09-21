#include <iostream>
#include <unordered_map>
#include "GameManager.h"

int GameManager::m_nextId = 0;
VEC2 GameManager::m_gravity = { 0, 980.0f };

GameManager::GameManager()
{
	m_map = { 0 };
}

GameManager::~GameManager()
{
}

int GameManager::UpdateAll(float deltaTime)
{
	CheckCollistion();

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

void GameManager::CheckCollistion()
{
	for (auto itA = m_gameObjects.begin(); itA != m_gameObjects.end(); ++itA)
	{
		auto itB = itA;
		++itB;

		for (; itB != m_gameObjects.end(); ++itB)
		{
			GameObject* objA = itA->second;
			GameObject* objB = itB->second;

			if (CheckAABBCollision(objA, objB))
			{
				objA->OnCollision(objB);
				objB->OnCollision(objA);
			}
			else
			{
				objA->m_onGround = false;
				objB->m_onGround = false;
			}
		}
	}
}

bool GameManager::CheckAABBCollision(const GameObject* a, const GameObject* b)
{
	if (a->GetRight() <= b->GetLeft() || a->GetLeft() >= b->GetRight())
		return false;

	if (a->GetBottom() <= b->GetTop() || a->GetTop() >= b->GetBottom())
		return false;

	return true;
}
