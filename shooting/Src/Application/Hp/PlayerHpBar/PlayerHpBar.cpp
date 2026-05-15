#include "../../Scene.h"

void C_PlayerHpBar::Init()
{
	//m_flg = true;
	m_pos = { -500, -330 };
	m_scale = { 3, 3 };
	//m_hp = SCENE.GetPlayer()->GetHp();
	m_scope = 0;
}

void C_PlayerHpBar::Update()
{
	m_hp = SCENE.GetPlayer()->GetHp();

	if (m_hp <= 0)
	{
		m_scope = 160;
	}
	else if (m_hp <= 1)
	{
		m_scope = 128;
	}
	else if (m_hp <= 2)
	{
		m_scope = 96;
	}
	else if (m_hp <= 3)
	{
		m_scope = 64;
	}
	else if (m_hp <= 4)
	{
		m_scope = 32;
	}

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_PlayerHpBar::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, m_scope, 80, 16), 1.0f);
}