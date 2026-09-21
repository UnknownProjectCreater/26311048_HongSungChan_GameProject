#include <iostream>
#include <Windows.h>
#include "glc2d.h"
#include "SceneGamePlay.h"
#include "CApplication.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "GameObject.h"
#include "Entity.h"
#include "Platform.h"

extern CApplication g_app;
extern SoundManager g_soundManager;
extern GameManager g_gameManager;

Platform* platformTest;

int PlayerController(Entity* player, int jumpSound)
{
	const KEYCODE* pKeyboard = g2_GetKeyboard();

	float jumpForce = 350.0f;

	if (pKeyboard[VK_SPACE] && player->OnGround())
	{
		g2_SoundPlay(jumpSound);

		VEC2 playerV = player->GetVelocity();
		VEC2 v(playerV.x, -jumpForce);
		player->SetVelocity(v);
	}

	return 0;
}

int SceneGamePlay::Init()
{
	g_gameManager.m_currentBackgroundType = BackgroundType::SCREEN_PLAY;

	m_player = g_gameManager.CreateObject<Entity>();

	m_player->Init(TextureType::ENTITY_PLAYER);
	VEC2 objPos(200, 400);
	m_player->SetPosition(objPos);

	VEC2 scale(0.5f, 0.5f);
	m_player->SetScaling(scale);
	m_player->SetColliderSize();

	m_ground = g_gameManager.CreateObject<Platform>();
	m_ground->Init(TextureType::GROUND);
	m_ground->SetColliderSize();
	objPos = { 0, 500 };
	m_ground->SetPosition(objPos);
	m_ground->m_name = "df";

	platformTest = g_gameManager.CreateObject<Platform>();
	platformTest->Init(TextureType::GAMEOBJECT_OBSTACLE_TWOBLOCK);
	objPos = { 300, 450 };
	platformTest->SetPosition(objPos);

	scale = { 0.5f, 0.5f };
	platformTest->SetScaling(scale);
	platformTest->SetColliderSize();
	platformTest->m_name = "asdf";

	m_jumpSound = g2_SoundLoad(g_soundManager.m_soundFiles[SoundType::CHARACTER_JUMPSOUND]);

	return 0;
}

int SceneGamePlay::Update(float deltaTime)
{
	PlayerController(m_player, m_jumpSound);

	float posX = platformTest->GetPosition().x + -100.0f * deltaTime;
	VEC2 pos(posX, platformTest->GetPosition().y);
	platformTest->SetPosition(pos);

	g_gameManager.UpdateAll(deltaTime);

	return 0;
}

int SceneGamePlay::Render()
{
	g_gameManager.RenderAll();

	return 0;
}

int SceneGamePlay::Destroy()
{
	g_gameManager.ClearAll();

	return 0;
}