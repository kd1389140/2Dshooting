#pragma once
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Bullet/PlayerBullet/PlayerBullet.h"
#include "Effect/Explosion.h"

class Scene
{
private:

	C_Player m_player;
	KdTexture m_playerTex;

	C_Enemy m_enemy;
	KdTexture m_enemyTex;

	C_PlayerBullet m_playerBullet;
	KdTexture m_playerBulletTex;

	C_Explosion m_explosion;
	KdTexture m_explosionTex;

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
	C_Explosion* GetExplosion() { return &m_explosion; }

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
