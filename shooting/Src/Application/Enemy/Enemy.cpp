#include "../Scene.h"

void C_Enemy::Init()
{
	m_pos = { 0,300 };
	m_move = { 0,0 };
	m_alive = true;
}

void C_Enemy::Update()
{
	m_pos += m_move;

	m_pBulletpos = SCENE.GetPlayerBullet()->GetPos();

	if (m_alive)	//敵が生きているか
	{
		float a = m_pos.x - m_pBulletpos.x;	//底辺
		float b = m_pos.y - m_pBulletpos.y;	//高さ
		float c = sqrt(a * a + b * b);	//斜辺

		if (c < 32 + 8)	//衝突していたら
		{
			//敵を倒す
			m_alive = false;

			//弾を未発射状態に
			SCENE.GetPlayerBullet()->Reset();
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Enemy::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}
