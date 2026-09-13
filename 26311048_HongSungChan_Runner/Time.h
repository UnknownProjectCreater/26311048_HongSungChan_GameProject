#pragma once
#include "Windows.h"

class Time
{
private:
	double deltaTime;
	double m_periodFrequency;
	double m_lastTime;
	double m_timeScale;
	double m_currentTime;

public:
	Time();
	double GetDeltaTime();
};