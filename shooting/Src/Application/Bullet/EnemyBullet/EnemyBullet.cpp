#include "../../Scene.h"

void C_EnemyBullet::Init()
{
	m_pos = SCENE.GetEnemy()->GetPos();
	m_flg = true;
	m_shootFlg = false;
}

void C_EnemyBullet::Update()
{
	if (SCENE.GetEnemy()->GetAlive() == false)return;
	{
		if (m_shootFlg == false)
		{
			m_pos = SCENE.GetEnemy()->GetPos();
		}

		m_pos += m_move;

		if (m_shootFlg)
		{
			m_move.y = -10.0f;
		}

		//画面外に出たら消去
		if (m_pos.y < -360 - 8)
		{
			Reset();
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_EnemyBullet::Draw()
{
	if (SCENE.GetEnemy()->GetAlive() == false)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(16, 0, 16, 16), 1.0f);
}

void C_EnemyBullet::Reset()
{
	m_flg = false;
	Init();
}