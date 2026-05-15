#include "../Scene.h"

void C_Enemy::Init()
{
	m_pos = { static_cast<float>(rand() % (640 + 640 - 32 + 1) - 640 + 32),300 };
	m_alive = true;
	m_hp = 3;
}

void C_Enemy::Update()
{
	if (!m_alive)return;

	//敵が弾を打つ処理
	C_EnemyBullet* enemyBullet = SCENE.GetEnemyBullet();
	enemyBullet->SetShoot(true);

	m_pos += m_move;

	m_move.y = -3.0f;

	//画面外に出た時に画面内に戻す処理
	if (m_pos.y <= -360.0f - 32.0f)
	{
		m_pos.y = 360.0f + 32.0f;
	}

	for (int i = 0; i < 30 ; ++i)
	{
		//プレイヤーの弾と敵の当たり判定(当たっていたら死ぬ)
		m_pBulletpos = SCENE.GetPlayerBullet(i)->GetPos();
		m_Ppos = SCENE.GetPlayer()->GetPos();

		float a = m_pos.x - m_pBulletpos.x;	//底辺
		float b = m_pos.y - m_pBulletpos.y;	//高さ
		float c = sqrt(a * a + b * b);		//斜辺

		if (m_pBulletpos != m_Ppos)
		{
			if (c < 32 + 8)	//衝突していたら
			{
				//hp減少
				m_hp--;

				//弾を未発射状態に
				SCENE.GetPlayerBullet(i)->Reset();

				break;
			}

			//hpが0になったら
			if (m_hp == 0)
			{
				//敵を倒す
				SCENE.GetExplosion()->SetPos(m_pos);
				SCENE.GetExplosion()->SetFlg(true);
				m_alive = false;

				//スコア追加
				SCENE.GetScore()->SetEnemyFlg(true);
			}
		}
	}

	m_scaleMat = Math::Matrix::CreateScale(1.0f, 1.0f, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Enemy::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void C_Enemy::Reset()
{
	m_pos = { 0,300 };
	m_alive = true;
}
