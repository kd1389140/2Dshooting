#pragma once
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Bullet/PlayerBullet/PlayerBullet.h"
#include "Bullet/EnemyBullet/EnemyBullet.h"
#include "Effect/Explosion.h"
#include "Title/Title.h"

class Scene
{
private:

	C_Player m_player;
	KdTexture m_playerTex;

	C_Enemy m_enemy;
	KdTexture m_enemyTex;

	C_PlayerBullet m_playerBullet;
	KdTexture m_playerBulletTex;

	C_EnemyBullet m_enemyBullet;
	KdTexture m_enemyBulletTex;

	C_Explosion m_explosion;
	KdTexture m_explosionTex;

	C_Title m_title;
	KdTexture m_titleTex;

public:

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	// GUIˆ—
	void ImGuiUpdate();

	C_Player* GetPlayer() { return &m_player; }
	C_Enemy* GetEnemy() { return &m_enemy; }
	C_PlayerBullet* GetPlayerBullet() { return &m_playerBullet; }
	C_EnemyBullet* GetEnemyBullet() { return &m_enemyBullet; }
	C_Explosion* GetExplosion() { return &m_explosion; }
	C_Title* GetTitle() { return &m_title; }

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
