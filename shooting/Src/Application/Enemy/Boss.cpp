#include "../Scene.h"

void C_Boss::Init()
{
	m_pos = { 200,300 };
	m_alive = true;
	m_flg = false;
	m_hp = 3;
	m_scale = { 3,3 };
}

void C_Boss::Update()
{
	if (!m_alive)return;
	if (!m_flg)return;
	//敵が弾を打つ処理
	//C_EnemyBullet* enemyBullet = SCENE.GetEnemyBullet();
	//enemyBullet->SetShoot(true);

	for (int i = 0; i < 30; ++i)
	{
		//プレイヤーの弾とボスの当たり判定(当たっていたら死ぬ)
		m_pBulletpos = SCENE.GetPlayerBullet(i)->GetPos();

		float a = m_pos.x - m_pBulletpos.x;	//底辺
		float b = m_pos.y - m_pBulletpos.y;	//高さ
		float c = sqrt(a * a + b * b);		//斜辺

		if (c < 96 + 8)	//衝突していたら
		{
			//ボスを倒す
			SCENE.GetExplosion()->SetFlg(true);
			m_alive = false;

			//弾を未発射状態に
			SCENE.GetPlayerBullet(i)->Reset();

			break;
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Boss::Draw()
{
	if (!m_alive)return;
	if (!m_flg)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void C_Boss::Reset()
{
	m_pos = { -200,300 };
	m_alive = true;
}
