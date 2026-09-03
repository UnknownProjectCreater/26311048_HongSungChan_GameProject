#include "SceneGameStart.h"
#include "glc2d.h"

int SceneGameStart::Init()
{
	this->m_texture = g2_TextureLoad("resource\Texture\Sq.png");
	return 0;
}

int SceneGameStart::Update()
{
	return 0;
}

int SceneGameStart::Render()
{
	VEC2 pos(400, 200);
	g2_Draw2D(m_texture, nullptr, &pos);
	return 0;
}

int SceneGameStart::Destroy()
{
	return 0;
}