#include <unordered_map>
#include "SoundManager.h"
#include "glc2d.h"

int SoundManager::SetTextureFiles()
{
	printf("..... Set SoundFiles");

	m_soundFiles[SoundType::PLAYER_MOUSE_CLICKSOUND] = "resource/Sound/click.wav";

	return 0;
}