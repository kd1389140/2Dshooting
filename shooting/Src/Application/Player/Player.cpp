#include "../Scene.h"

void C_Player::Init()
{
	m_alive = true;
}

void C_Player::Update()
{
	if (!m_alive)return;

	m_pos += m_move;

	m_move = {0,0};

	//キーで移動
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_move.x = 10.0f;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_move.x = -10.0f;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_move.y = 10.0f;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_move.y = -10.0f;
	}

	//プレイヤー爆発確認用処理
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		m_alive = false;
		SCENE.GetExplosion()->SetFlg(true);
	}

	//スペースキーで弾を発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		C_PlayerBullet* playerBullet = SCENE.GetPlayerBullet();
		playerBullet->SetShoot(true);
	}

	//画面内固定処理
	if (m_pos.x > 640 - 32)
	{
		m_pos.x = 640 - 32;
	}

	if (m_pos.x < -640 + 32)
	{
		m_pos.x = -640 + 32;
	}

	if (m_pos.y > 360 - 32)
	{
		m_pos.y = 360 - 32;
	}

	if (m_pos.y < -360 + 32)
	{
		m_pos.y = -360 + 32;
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Player::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}
