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
	std::unordered_map<int, Entity*> m_entities;
	static int m_nextId;
	static VEC2 m_gravity;

	Map m_map;

public:
	GameManager();
	~GameManager();

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

	 Entity* CreateEntity()
	 {
		 Entity* newEntity = new Entity;
		 newEntity->SetId(m_nextId++);
		 m_entities.insert({ newEntity->GetId(), newEntity });
	 }

	 Background* CreateBackground(BackgroundType type)
	 {
		 Background* newObj = new Background;
		 m_backgrounds[type] = newObj;

		 return newObj;
	 }

	 void CheckCollistion();

	 /// <summary>
	 /// AABB 알고리즘을 이용하여 충돌 여부를 점검한다.
	 /// </summary>
	 bool CheckAABBCollision(const GameObject* a, const GameObject* b);
};