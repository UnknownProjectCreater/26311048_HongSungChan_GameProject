#include "Platform.h"

Platform::Platform()
{

}

Platform::~Platform()
{
}

int Platform::Update(float deltaTime)
{
	return 0;
}

int Platform::Render()
{
	g2_Draw2D(m_image.texture, NULL, &m_pos, &m_image.scaling);

	return 0;
}

void Platform::OnCollision(const GameObject* obj)
{

}
