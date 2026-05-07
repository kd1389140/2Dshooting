#include "../Scene.h"

void C_Back::Init()
{
	m_flg = true;

	//縦スクロール用の2枚目の初期座標
	m_pos2 = { 0,720 };

	//横スクロール用の2枚目の初期座標
	//m_pos2 = { 1280,0 };
}

void C_Back::Update()
{
	if (!m_flg)return;

	//縦背景スクロール
	m_pos.y -= 5;
	m_pos2.y -= 5;

	if (m_pos.y <= -720)
	{
		m_pos.y = 720;
	}

	if (m_pos2.y <= -720)
	{
		m_pos2.y = 720;
	}

	//横背景スクロール
	//m_pos.x -= 5;
	//m_pos2.x -= 5;

	//if (m_pos.x <= -1280)
	//{
	//	m_pos.x = 1280;
	//}

	//if (m_pos2.x <= -1280)
	//{
	//	m_pos2.x = 1280;
	//}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_transMat2 = Math::Matrix::CreateTranslation(m_pos2.x, m_pos2.y, 0);
	m_mat = m_scaleMat * m_transMat;
	m_mat2 = m_scaleMat * m_transMat2;
}

void C_Back::Draw()
{
	if (!m_flg)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
	SHADER.m_spriteShader.SetMatrix(m_mat2);
	SHADER.m_spriteShader.DrawTex(m_tex2, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}

void C_Back::Reset()
{
	m_flg = true;
}