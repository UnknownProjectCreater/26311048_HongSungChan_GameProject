#include <unordered_map>
#include "TextureManager.h"
#include "glc2d.h"

int TextureManager::SetTextureFiles()
{
	printf("..... Set TextureFiles");

	m_textureFiles[TEXTURE_CUBE] = "resource/Texture/Sq.png";
	m_textureFiles[TEXTURE_BACKGROUND] = "resource/Texture/BackGround/desert.png";

	return 0;
}