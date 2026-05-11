#pragma once
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Enemy/Enemy2.h"
#include "Enemy/Boss.h"
#include "Bullet/PlayerBullet/PlayerBullet.h"
#include "Bullet/EnemyBullet/EnemyBullet.h"
#include "Effect/Explosion.h"
#include "Title/Title.h"
#include "Result/Result.h"
#include "Back/Back.h"

class Scene
{
private:

	int playerHp;
	C_Player m_player;
	KdTexture m_playerTex;

	static const int eNum = 5;
	C_Enemy m_enemy[eNum];
	KdTexture m_enemyTex;

	C_Enemy2 m_enemy2;
	KdTexture m_enemy2Tex;

	C_Boss m_boss;
	KdTexture m_bossTex;

	static const int pBulletNum = 30;
	C_PlayerBullet m_playerBullet[pBulletNum];
	KdTexture m_playerBulletTex;

	C_EnemyBullet m_enemyBullet;
	KdTexture m_enemyBulletTex;

	C_Explosion m_explosion;
	KdTexture m_explosionTex;

	C_Title m_title;
	KdTexture m_titleTex;

	C_Result m_result;
	KdTexture m_resultTex;

	C_Back m_back;
	C_Back m_back2;
	KdTexture m_backTex;
	KdTexture m_backTex2;

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
	C_Enemy* GetEnemy(int index) { return &m_enemy[index]; }
	C_Enemy2* GetEnemy2() { return &m_enemy2; }
	C_Boss* GetBoss() { return &m_boss; }
	C_PlayerBullet* GetPlayerBullet(int index) { return &m_playerBullet[index]; }
	C_EnemyBullet* GetEnemyBullet() { return &m_enemyBullet; }
	C_Explosion* GetExplosion() { return &m_explosion; }
	C_Title* GetTitle() { return &m_title; }
	C_Result* GetResult() { return &m_result; }
	C_Back* GetBack() { return &m_back; }

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
