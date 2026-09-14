#include <unordered_map>
#include "TextureManager.h"
#include "glc2d.h"

int TextureManager::SetTextureFiles()
{
	printf("..... Set TextureFiles");

	m_textureFiles[TextureType::ENTITY_PLAYER] = "resource/Texture/Player.png";
	m_textureFiles[TextureType::BACKGROUND] = "resource/Texture/Background/desert.png";
	m_textureFiles[TextureType::GAMEOBJECT_OBSTACLE_ONEBLOCK] = "resource/Texture/Obstacle2.png";
	m_textureFiles[TextureType::GAMEOBJECT_OBSTACLE_TWOBLOCK] = "resource/Texture/Obstacle.png";
	m_textureFiles[TextureType::UI_TITLE_GAMEMAINMENU] = "resource/Texture/ImageText/Title_GameMainMenu.png";
	m_textureFiles[TextureType::UI_BUTTON_GAMESTART] = "resource/Texture/ImageText/Button_Start.png";

	return 0;
}