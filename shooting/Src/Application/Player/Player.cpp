#include "../Scene.h"

void C_Player::Init()
{
	m_pos = { 0,0 };
	m_move = { 0,0 };
	m_alive = true;
}

void C_Player::Update()
{
	m_pos += m_move;

	m_move = {0,0};

	//ÉLÅ[Ç≈à⁄ìÆ
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_move.x = 1.0f;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_move.x = -1.0f;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_move.y = 1.0f;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_move.y = -1.0f;
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Player::Draw()
{
	//if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}
