#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_playerBullet.Draw();
	m_enemyBullet.Draw();
	m_enemy.Draw();
	m_player.Draw();
	m_explosion.Draw();
	m_title.Draw();
	m_result.Draw();

	// 文字列表示
	//SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));
}

void Scene::Update()
{
	m_playerBullet.Update();
	m_enemyBullet.Update();
	m_enemy.Update();
	m_player.Update();
	m_explosion.Update();
	m_title.Update();
	m_result.Update();
}

void Scene::Init()
{
	m_playerBulletTex.Load("Texture/Bullet.png");
	m_player.Init();
	m_playerBullet.SetTex(&m_playerBulletTex);

	m_enemyBulletTex.Load("Texture/Bullet.png");
	m_enemy.Init();
	m_enemyBullet.SetTex(&m_enemyBulletTex);

	m_enemyTex.Load("Texture/enemy.png");
	m_enemy.Init();
	m_enemy.SetTex(&m_enemyTex);

	m_playerTex.Load("Texture/player.png");
	m_player.Init();
	m_player.SetTex(&m_playerTex);

	m_explosionTex.Load("Texture/Red Explosion.png");
	m_explosion.Init();
	m_explosion.SetTex(&m_explosionTex);

	m_titleTex.Load("Texture/Title.png");
	m_title.Init();
	m_title.SetTex(&m_titleTex);

	m_resultTex.Load("Texture/back.png");
	m_result.Init();
	m_result.SetTex(&m_resultTex);
}

void Scene::Release()
{
	m_playerTex.Release();
	m_enemyTex.Release();
	m_playerBulletTex.Release();
	m_enemyBulletTex.Release();
	m_explosionTex.Release();
	m_titleTex.Release();
	m_resultTex.Release();
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
