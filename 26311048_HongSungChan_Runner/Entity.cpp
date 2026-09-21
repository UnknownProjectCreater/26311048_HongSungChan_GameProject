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
}

Entity::~Entity()
{
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
	if (m_velocity.x < 0)
	{
		m_pos.x = obj->GetRight();
	}
	else if (m_velocity.x > 0)
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

void Entity::OnCollision(const GameObject* obj)
{
	if (obj->IsTrigger())
		return;

	float overlapX = GetMin(GetRight(), obj->GetRight()) - GetMax(GetLeft(), obj->GetLeft());
	float overlapY = GetMin(GetRight(), obj->GetRight()) - GetMax(GetLeft(), obj->GetLeft());

	if (overlapX <= 0 || overlapY <= 0)
		return;

	if (overlapX > overlapY)
	{
		CollisionX(obj);
	}
	else
	{
		m_onGround = true;
		CollisionY(obj);
	}
}