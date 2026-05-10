#include "../../Scene.h"

void C_EnemyBullet::Init()
{
	static int _cnt = 0;
	C_Enemy* enemy = SCENE.GetEnemy(_cnt);
	if (++_cnt > 5)_cnt = 0;
	m_pos = SCENE.GetEnemy(_cnt)->GetPos();
	m_flg = true;
	m_shootFlg = false;
}

void C_EnemyBullet::Update()
{
	static int _cnt = 0;
	C_Enemy* enemy = SCENE.GetEnemy(_cnt);
	if (++_cnt > 5)_cnt = 0;
	if (SCENE.GetEnemy(_cnt)->GetAlive() == false)return;
	{
		if (m_shootFlg == false)
		{
			m_pos = SCENE.GetEnemy(_cnt)->GetPos();
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
	static int _cnt = 0;
	C_Enemy* enemy = SCENE.GetEnemy(_cnt);
	if (++_cnt > 5)_cnt = 0;
	if (SCENE.GetEnemy(_cnt)->GetAlive() == false)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(16, 0, 16, 16), 1.0f);
}

void C_EnemyBullet::Reset()
{
	m_flg = false;
	Init();
}