#pragma once
#include <vector>
#include <unordered_map>
#include "GameObject.h"
#include "Background.h"

class GameManager
{
private:
	std::unordered_map<BackgroundType, GameObject*> m_backgrounds;
	std::unordered_map<int, GameObject*> m_gameObjects;
	static int m_nextId;

public:
	BackgroundType m_currentBackgroundType;

	int UpdateAll(float deltaTime);
	int RenderAll();
	int ClearAll();

	template<typename T>
	 T* CreateObject()
	 {
		 T* newObj = new T;
		 m_gameObjects.insert({ m_nextId++, newObj });

		 return newObj;
	 }
	 Background* CreateBackground(BackgroundType type)
	 {
		 Background* newObj = new Background;
		 m_backgrounds[type] = newObj;

		 return newObj;
	 }
};