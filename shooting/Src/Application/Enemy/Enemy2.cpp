#include "../Scene.h"

void C_Enemy2::Init()
{
	m_pos = { -200,300 };
	m_scale = { 0.5f, 0.5f };
	m_alive = false;
}

void C_Enemy2::Update()
{
	//if (!m_alive)return;

	for (int i = 0; i < 30 ; ++i)
	{
		//プレイヤーの弾と敵の当たり判定(当たっていたら死ぬ)
		m_pBulletpos = SCENE.GetPlayerBullet(i)->GetPos();

		float a = m_pos.x - m_pBulletpos.x;	//底辺
		float b = m_pos.y - m_pBulletpos.y;	//高さ
		float c = sqrt(a * a + b * b);		//斜辺

		if (c < 32 + 8)	//衝突していたら
		{
			//敵を倒す
			//処理がバグっているのでコメントアウト
			//SCENE.GetExplosion()->SetFlg(true);
			m_alive = false;
			SCENE.GetScore()->SetEnemy2Flg(true);

			//弾を未発射状態に
			SCENE.GetPlayerBullet(i)->Reset();

			break;
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Enemy2::Draw()
{
	//if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 256, 256), 1.0f);
}

void C_Enemy2::Reset()
{
	m_pos = { -200,300 };
	//m_alive = true;
}
