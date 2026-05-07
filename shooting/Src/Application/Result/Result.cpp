#include "../Scene.h"

void C_Result::Init()
{
	m_flg = false;
}

void C_Result::Update()
{
	if (!m_flg)return;

	//エンターでリザルトを消してタイトル画面に遷移
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_flg = false;
		//タイトル表示フラグ
		SCENE.GetTitle()->SetFlg(true);
		//長押しでタイトル画面スキップを出来なくするためのフラグセット
		SCENE.GetTitle()->SetPressFlg(true);
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Result::Draw()
{
	if (!m_flg)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}

void C_Result::Reset()
{
	m_flg = false;
}