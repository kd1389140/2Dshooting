#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_back.Draw();

	for (int i = 0; i < pBulletNum; ++i)
	{
		m_playerBullet[i].Draw();
	}
	
	//m_enemyBullet.Draw();

	for (int i = 0; i < eNum; ++i)
	{
		m_enemy[i].Draw();
	}

	m_enemy2.Draw();

	m_boss.Draw();

	m_player.Draw();

	m_explosion.Draw();

	m_result.Draw();

	m_gameover.Draw();

	m_score.Draw();

	m_title.Draw();

	// 文字列表示
	/*playerHp = SCENE.GetPlayer()->GetHp();
	char hp[200];
	sprintf_s(hp, sizeof(hp), "PlayerHp:%d", playerHp);
	SHADER.m_spriteShader.DrawString(400, 360, hp, Math::Vector4(1, 1, 1, 1));*/
}

void Scene::Update()
{
	for (int i = 0; i < pBulletNum; ++i)
	{
		m_playerBullet[i].Update();
	}

	//m_enemyBullet.Update();

	for (int i = 0; i < eNum; ++i)
	{
		m_enemy[i].Update();
	}

	m_enemy2.Update();

	m_boss.Update();

	m_player.Update();

	m_score.Update();

	m_explosion.Update();

	m_title.Update();

	m_result.Update();

	m_gameover.Update();

	m_back.Update();
}

void Scene::Init()
{
	srand(time(0));

	//ShowCursor(false);

	m_playerBulletTex.Load("Texture/pBullet.png");
	for (int i = 0; i < pBulletNum; ++i)
	{
		m_playerBullet[i].Init();
		m_playerBullet[i].SetTex(&m_playerBulletTex);
	}

	/*m_enemyBulletTex.Load("Texture/Bullet.png");
	m_enemyBullet.Init();
	m_enemyBullet.SetTex(&m_enemyBulletTex);*/

	m_enemyTex.Load("Texture/enemy.png");
	for (int i = 0; i < eNum; ++i)
	{
		m_enemy[i].Init();
		m_enemy[i].SetTex(&m_enemyTex);
	}

	m_enemy2Tex.Load("Texture/enemy.png");
	m_enemy2.Init();
	m_enemy2.SetTex(&m_enemy2Tex);

	m_bossTex.Load("Texture/enemy.png");
	m_boss.Init();
	m_boss.SetTex(&m_bossTex);

	m_playerTex.Load("Texture/player.png");
	m_player.Init();
	m_player.SetTex(&m_playerTex);

	m_explosionTex.Load("Texture/Red Explosion.png");
	m_explosion.Init();
	m_explosion.SetTex(&m_explosionTex);


	m_titleTex.Load("Texture/Title.png");
	m_title.Init();
	m_title.SetTex(&m_titleTex);

	m_resultTex.Load("Texture/result.png");
	m_result.Init();
	m_result.SetTex(&m_resultTex);

	m_gameoverTex.Load("Texture/result.png");
	m_gameover.Init();
	m_gameover.SetTex(&m_resultTex);

	m_backTex.Load("Texture/back.png");
	m_back.Init();
	m_back.SetTex(&m_backTex);
	m_back.SetTex2(&m_backTex);

	m_scoreTex.Load("Texture/BoldPixelsB.png");
	m_score.Init();
	m_score.SetTex(&m_scoreTex);
}

void Scene::Reset()
{
	for (int i = 0; i < pBulletNum; ++i)
	{
		m_playerBullet[i].Init();
	}

	//m_enemyBullet.Init();

	for (int i = 0; i < eNum; ++i)
	{
		m_enemy[i].Init();
	}

	m_enemy2.Init();
	m_boss.Init();
	m_player.Init();
	m_explosion.Init();
	m_score.Init();

	//m_title.Init();
	//m_result.Init();
	//m_gameover.Init();
	//m_back.Init();

}

void Scene::Release()
{
	m_playerTex.Release();
	m_enemyTex.Release();
	m_enemy2Tex.Release();
	m_bossTex.Release();
	m_playerBulletTex.Release();
	m_enemyBulletTex.Release();
	m_explosionTex.Release();
	m_titleTex.Release();
	m_resultTex.Release();
	m_gameoverTex.Release();
	m_backTex.Release();
	m_scoreTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
