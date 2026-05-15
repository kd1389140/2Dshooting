#include "../Scene.h"

void C_PressEnter::Init()
{
	m_flg = true;
	m_pressFlg = false;
	m_pos = { 0, -200 };
	m_scale = { 2, 2 };
}

void C_PressEnter::Update()
{
	if (!m_flg)return;

	if (!(GetAsyncKeyState(VK_RETURN) & 0x8000))
	{
		m_pressFlg = false;
	}

	//長押しでタイトル画面スキップを出来なくする処理
	if (!m_pressFlg)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			m_flg = false;
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_PressEnter::Draw()
{
	if (!m_flg)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 214, 46), 1.0f);
}
