#pragma once
#include <vector>
#include "Platform.h"

class Stage
{
private:
	float m_mapScrollSpeed;
	float m_baseY;
	float m_lastRightX;

	bool m_loop;
public:
	Stage();
	~Stage();

	int Update(float deltaTime);
};