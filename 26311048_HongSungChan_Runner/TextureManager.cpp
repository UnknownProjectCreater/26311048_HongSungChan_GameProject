#include <unordered_map>
#include "TextureManager.h"
#include "glc2d.h"

int TextureManager::SetTextureFiles()
{
	printf("..... Set TextureFiles");

	m_textureFiles[Texture::PLAYER] = "resource/Texture/Player.png";
	m_textureFiles[Texture::BACKGROUND] = "resource/Texture/Background/desert.png";
	m_textureFiles[Texture::OBSTACLE_ONEBLOCK] = "resource/Texture/Obstacle2.png";
	m_textureFiles[Texture::OBSTACLE_TWOBLOCK] = "resource/Texture/Obstacle.png";

	return 0;
}