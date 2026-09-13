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

	VEC2 GetVelocity() const { return m_velocity; };
	void SetVelocity(const VEC2& v) { m_velocity = v; };
};

