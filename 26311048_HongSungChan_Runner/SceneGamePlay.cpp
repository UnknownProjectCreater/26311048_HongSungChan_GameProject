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
Platform* platformTest2;

int PlayerController(Entity* player, int jumpSound)
{
	const KEYCODE* pKeyboard = g2_GetKeyboard();

	float jumpForce = 350.0f;
	float moveSpeed = 200.0f;

	//for (int i = 9; i < 128; ++i)
	//{
	//	if (pKeyboard[i])
	//	{
	//		printf("You Pressed %d key!!!\n", i);
	//	}
	//}

	if (pKeyboard[65])
	{
		VEC2 playerV = player->GetVelocity();
		VEC2 v(-moveSpeed, playerV.y);
		player->SetVelocity(v);
		player->SetTexture(TextureType::ENTITY_PLAYER_BACK);
	}
	else if (pKeyboard[68])
	{
		VEC2 playerV = player->GetVelocity();
		VEC2 v(moveSpeed, playerV.y);
		player->SetVelocity(v);
		player->SetTexture(TextureType::ENTITY_PLAYER_FRONT);
	}
	else
	{
		VEC2 playerV = player->GetVelocity();
		VEC2 v(0, playerV.y);
		player->SetVelocity(v);
	}

	if (pKeyboard[VK_SPACE] && player->IsOnGround())
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

	m_player->Init(TextureType::ENTITY_PLAYER_FRONT);
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
	objPos = { 500, 450 };
	platformTest->SetPosition(objPos);

	scale = { 0.5f, 0.5f };
	platformTest->SetScaling(scale);
	platformTest->SetColliderSize();

	platformTest2 = g_gameManager.CreateObject<Platform>();
	platformTest2->Init(TextureType::GAMEOBJECT_OBSTACLE_TWOBLOCK);
	objPos = { 700, 450 };
	platformTest2->SetPosition(objPos);

	scale = { 0.5f, 0.5f };
	platformTest2->SetScaling(scale);
	platformTest2->SetColliderSize();

	m_jumpSound = g2_SoundLoad(g_soundManager.m_soundFiles[SoundType::PLAYER_JUMPSOUND]);

	return 0;
}

int SceneGamePlay::Update(float deltaTime)
{
	g_gameManager.UpdateAll(deltaTime);

	PlayerController(m_player, m_jumpSound);

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