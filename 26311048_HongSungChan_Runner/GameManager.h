#pragma once
#include <vector>
#include <unordered_map>
#include "GameObject.h"
#include "Background.h"

struct Map
{
	float right;
	float left;
	float bottom;
	float top;
};

class GameManager
{
private:
	std::unordered_map<BackgroundType, GameObject*> m_backgrounds;
	std::unordered_map<int, GameObject*> m_gameObjects;
	static int m_nextId;
	static VEC2 m_gravity;

public:
	BackgroundType m_currentBackgroundType;

	int UpdateAll(float deltaTime);
	int RenderAll();
	int ClearAll();

	VEC2 GetGravity() const { return m_gravity; };

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

	 /// <summary>
	 /// AABB 알고리즘을 이용하여 충돌 여부를 점검한다.
	 /// </summary>
	 bool OnCollision(const GameObject* a, const GameObject* b);
};