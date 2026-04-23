#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_player.Draw();
	m_enemy.Draw();

	// 文字列表示
	//SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));
}

void Scene::Update()
{
	m_player.Update();
	m_enemy.Update();
}

void Scene::Init()
{
	m_playerTex.Load("Texture/player.png");
	m_player.Init();
	m_player.SetTex(&m_playerTex);

	m_enemyTex.Load("Texture/enemy.png");
	m_enemy.Init();
	m_enemy.SetTex(&m_enemyTex);
}

void Scene::Release()
{
	m_playerTex.Release();
	m_enemyTex.Release();
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
