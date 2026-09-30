#include <iostream>
#include <algorithm>
#include "Entity.h"
#include "GameManager.h"

extern GameManager g_gameManager;

inline float GetMax(float a, float b)
{
	return a > b ? a : b;
}

inline float GetMin(float a, float b)
{
	return a > b ? b : a;
}

Entity::Entity()
{
	m_velocity = { 0, 0 };
	m_hp = 0;
	m_onGround = false;
}

Entity::~Entity()
{
}

void Entity::BeginCollisionUpdate()
{
	m_previousColliders = std::move(m_colliders);

	m_colliders.clear();
}

void Entity::AddCollider(GameObject* other, CollisionDirection direction)
{
	CollisionInfo info;

	info.other = other;
	info.collisionDir = direction;

	m_colliders[other] = info;
}

void Entity::ProcessCollision()
{
	for (const auto& collider : m_colliders)
	{
		auto previous = m_previousColliders.find(collider.first);

		if (previous == m_previousColliders.end())
			OnCollision(collider.second);
	}
}

int Entity::Update(float deltaTime)
{
	if (!m_onGround)
	{
		VEC2 g = g_gameManager.GetGravity();
		m_velocity = m_velocity + deltaTime * g;
	}

	m_pos = m_pos + m_velocity * deltaTime;

	return 0;
}

int Entity::Render()
{
	//g2_DrawAlphaOption(m_image.alphaOption);
	g2_Draw2D(m_image.texture, NULL, &m_pos, &m_image.scaling);

	return 0;
}

bool Entity::CollisionX(const GameObject* obj)
{
	if (m_pos.x < obj->GetRight() && m_pos.x > obj->GetLeft())
	{
		m_pos.x = obj->GetRight();
	}
	else if (GetRight() > obj->GetLeft() && GetRight() < obj->GetRight())
	{
		m_pos.x = obj->GetLeft() - m_collider.width;
	}
	else
	{
		return false;
	}

	m_velocity.x = 0;

	return true;
}

bool Entity::CollisionY(const GameObject* obj)
{
	if (m_velocity.y < 0 && m_pos.y > obj->GetBottom())
	{
		m_pos.y = obj->GetBottom();
	}
	else if (m_velocity.y > 0)
	{
		m_pos.y = obj->GetTop() - m_collider.height;
	}
	else
	{
		return false;
	}

	m_velocity.y = 0;

	return true;
}

void Entity::OnCollision(const CollisionInfo& info)
{
	GameObject* obj = info.other;

	if (obj->IsTrigger())
		return;

	float overlapX = GetMin(GetRight(), obj->GetRight()) - GetMax(GetLeft(), obj->GetLeft());
	float overlapY = GetMin(GetBottom(), obj->GetBottom()) - GetMax(GetTop(), obj->GetTop());

	if (overlapX <= 0 || overlapY <= 0)
		return;

	if (overlapX < overlapY)
	{
		CollisionX(obj);
	}
	else
	{

		m_onGround = true;
		CollisionY(obj);
	}
}

void Entity::ExitCollision(const GameObject* obj)
{
	m_onGround = false;
}