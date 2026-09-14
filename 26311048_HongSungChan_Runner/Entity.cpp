#include "Entity.h"

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
	m_pos.x += m_velocity.x * deltaTime;
	m_pos.y += m_velocity.y * deltaTime;

	return 0;
}

int Entity::Render()
{
	//g2_DrawAlphaOption(m_image.alphaOption);
	g2_Draw2D(m_image.texture, NULL, &m_pos, &m_image.scaling);

	return 0;
}