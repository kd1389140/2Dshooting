#include "../../Scene.h"

void C_PlayerBullet::Init()
{
	m_pos = { 0,0 };
	m_move = { 0,0 };
	m_flg = true;
	m_shootFlg = false;
}

void C_PlayerBullet::Update()
{
	//if (m_flg)
	{

		m_pos += m_move;

		//m_move = { 0,0 };

		if (m_shootFlg)
		{
			m_move.y = 10.0f;
		}

		//画面外に出たら消去
		if (m_pos.y > 360 - 8)
		{
			m_flg = false;
			Init();
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_PlayerBullet::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
}
