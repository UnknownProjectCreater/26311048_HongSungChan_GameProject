#pragma once
#include <unordered_map>
#include "GameObject.h"

enum class CollisionDirection
{
	Left,
	Right,
	Top,
	Bottom
};

struct CollisionInfo
{
	GameObject* other = nullptr;

	CollisionDirection collisionDir;
};

class Entity : public GameObject
{
protected:
	VEC2 m_velocity;
	int m_hp;

	bool m_onGround;
	
public:
	Entity();
	~Entity() override;

	std::unordered_map<GameObject*, CollisionInfo> m_colliders;
	std::unordered_map<GameObject*, CollisionInfo> m_previousColliders;

	void AddCollision(GameObject* other);

	bool IsColliding() const { return !m_colliders.empty(); };
	bool IsOnGround() const
	{
		for (const auto& collide : m_colliders)
		{
			if (collide.second.collisionDir == CollisionDirection::Bottom)
				return true;
		}

		return false;
	}

	void BeginCollisionUpdate();
	void AddCollider(GameObject* other, CollisionDirection direction);
	void ProcessCollision();

	int Update(float deltaTime) override;
	int Render() override;

	bool CollisionX(const GameObject* obj);
	bool CollisionY(const GameObject* obj);
	void OnCollision(const CollisionInfo& info);

	VEC2 GetVelocity() const { return m_velocity; };
	void SetVelocity(const VEC2& v) { m_velocity = v; };
};

