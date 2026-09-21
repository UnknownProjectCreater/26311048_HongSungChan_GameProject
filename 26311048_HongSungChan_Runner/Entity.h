#pragma once
#include "GameObject.h"

class Entity : public GameObject
{
protected:
	VEC2 m_velocity;
	int m_hp;
	
public:
	Entity();
	~Entity() override;

	int Update(float deltaTime) override;
	int Render() override;

	bool CollisionX(const GameObject* obj);
	bool CollisionY(const GameObject* obj);
	void OnCollision(const GameObject* obj) override;

	VEC2 GetVelocity() const { return m_velocity; };
	void SetVelocity(const VEC2& v) { m_velocity = v; };
};

