#include <unordered_map>
#include "SoundManager.h"
#include "glc2d.h"

int SoundManager::SetTextureFiles()
{
	printf("..... Set SoundFiles");

	m_soundFiles[SoundType::PLAYER_MOUSE_CLICKSOUND] = "resource/Sound/click.wav";
	m_soundFiles[SoundType::CHARACTER_JUMPSOUND] = "resource/Sound/jump.wav";

	return 0;
}