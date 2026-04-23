#include "../../Scene.h"

void C_PlayerBullet::Init()
{
	m_pos = { 0,0 };
	m_move = { 0,0 };
	m_alive = true;
}

void C_PlayerBullet::Update()
{
	m_pos += m_move;

	m_move = { 0,0 };

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_PlayerBullet::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 16, 16), 1.0f);
}
