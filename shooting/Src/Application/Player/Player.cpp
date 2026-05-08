#include "../Scene.h"

void C_Player::Init()
{
	m_alive = true;
	m_hp = 3;
}

void C_Player::Update()
{
	if (!m_alive)return;

	m_pos += m_move;

	m_move = {0,0};

	//キーで移動
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_move.x = 10.0f;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_move.x = -10.0f;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_move.y = 10.0f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_move.y = -10.0f;
	}

	//プレイヤー爆発確認用処理
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		m_hp--;
	}

	//Hp0で死亡
	if (!m_hp)
	{
		m_alive = false;
		SCENE.GetExplosion()->SetFlg(true);
	}

	
	//発射までのカウント減少
	if (--m_shotCnt < 0)m_shotCnt = 0;

	//スペースキーで弾を発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (m_shotCnt == 0)
		{
			static int _cnt = 0;
			C_PlayerBullet* playerBullet = SCENE.GetPlayerBullet(_cnt);
			if (++_cnt > 29)_cnt = 0;
			playerBullet->SetShoot(true);

			//発射間隔設定
			m_shotCnt = 4;
		}
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
