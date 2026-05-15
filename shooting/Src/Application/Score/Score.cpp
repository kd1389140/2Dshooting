#include "../Scene.h"

void C_Score::Init()
{
	//m_flg = true;
	m_pos = { -610, 330};
	m_score = 0;
	m_scale = { 3, 3 };
}

void C_Score::Update()
{
	if (m_enemyFlg == true)
	{
		m_score += 100;
		m_enemyFlg = false;
	}

	if (m_enemy2Flg == true)
	{
		m_score += 200;
		m_enemy2Flg = false;
	}

	if (m_bossFlg == true)
	{
		m_score += 500;
		m_bossFlg = false;
	}

	/*if (GetAsyncKeyState('S') & 0x8000)
	{
		if (m_score <= 0)
		{
			m_score = 0;
		}
		else
		{
			m_score -= 100;
		}
	}*/

	//スコアのオーバーフロー防止処理
	if (m_score > 999999)
	{
		m_score = 999999;
	}

	if (m_score <= 0)
	{
		m_score = 0;
	}

	//配列に各行の数値を格納
	unsigned long tmp = m_score;
	for (int i = maxDigit - 1; i >= 0; --i)
	{
		//下位の桁から抽出し、配列に格納
		m_digits[i] = tmp % 10;
		tmp /= 10;
	}

	for (int i = 0; i < maxDigit; ++i)
	{
		m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
		m_transMat = Math::Matrix::CreateTranslation(m_pos.x + i * 70, m_pos.y, 0);
		m_mat = m_scaleMat * m_transMat;
	}
}

void C_Score::Draw()
{
	
	// 基本のスケール行列は共通で作る
	Math::Matrix baseScale = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);

	for (int i = 0; i < maxDigit; ++i)
	{
		digit = m_digits[i];
		// フォント画像上の切り取り矩形
		Math::Rectangle srcRect = Math::Rectangle(digitWidth * digit, 0, digitWidth, digitHeight);

		// 桁ごとの描画位置（桁幅は digitWidth をスケールで拡大した分）
		offsetX = static_cast<float>(i) * (digitWidth * m_scale.x);
		Math::Matrix digitTrans = Math::Matrix::CreateTranslation(m_pos.x + offsetX, m_pos.y, 0.0f);

		// スケール→平行移動の順で合成（スケールの後に移動）
		Math::Matrix mat = baseScale * digitTrans;

		SHADER.m_spriteShader.SetMatrix(mat);
		SHADER.m_spriteShader.DrawTex(m_tex, srcRect, 1.0f);
	}
}