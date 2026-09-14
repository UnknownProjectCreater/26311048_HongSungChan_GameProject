#pragma once
#include <unordered_map>
#include "glc2d.h"

enum class SoundType
{
	PLAYER_MOUSE_CLICKSOUND
};

class SoundManager
{
public:
	int SetTextureFiles();
	std::unordered_map<SoundType, CSTR> m_soundFiles;
};