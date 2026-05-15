#include "../Scene.h"

void C_Title::Init()
{
	m_flg = true;
	m_pressFlg = false;
	m_scale = { 0.766f, 0.766f };
}

void C_Title::Update()
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

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.x, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Title::Draw()
{
	if (!m_flg)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 1672, 941), 1.0f);
}
