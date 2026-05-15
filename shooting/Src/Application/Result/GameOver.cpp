#include "../Scene.h"

void C_GameOver::Init()
{
	m_flg = false;
}

void C_GameOver::Update()
{
	if (!m_flg)return;

	//エンターでリザルトを消してタイトル画面に遷移
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_flg = false;
		//タイトル表示フラグ
		SCENE.GetTitle()->SetFlg(true);
		SCENE.GetTitleText()->SetFlg(true);
		SCENE.GetPressEnter()->SetFlg(true);
		SCENE.Reset();
		//長押しでタイトル画面スキップを出来なくするためのフラグセット
		SCENE.GetTitle()->SetPressFlg(true);
		SCENE.GetTitleText()->SetPressFlg(true);
		SCENE.GetPressEnter()->SetPressFlg(true);
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_GameOver::Draw()
{
	if (!m_flg)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 891, 96), 1.0f);
}