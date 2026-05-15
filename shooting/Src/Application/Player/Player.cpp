#include "../Scene.h"

void C_Player::Init()
{
	m_alive = true;
	m_hp = 5;
	m_maxHp = 5;
	m_pos = { 0, 0 };
	m_scale = { 0.3, 0.3};
	m_nonDieFlg = false;
	m_enemyNumber = 0;
}

void C_Player::Update()
{
	if (!m_alive)return;

	m_pos += m_move;

	m_move = {0,0};

	//キーで移動
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_move.x = 5.0f;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_move.x = -5.0f;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_move.y = 5.0f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_move.y = -5.0f;
	}

	//プレイヤー爆発確認用処理
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		m_hp--;
	}

	//デバック用
	//無敵キー
	if (GetAsyncKeyState('P') & 0x8000)
	{
		m_nonDieFlg = true;
	}
	//無敵解除
	if(GetAsyncKeyState('O') & 0x8000)
	{
		m_nonDieFlg = false;
	}
	
	//Hp0で死亡
	if (m_hp <= 0)
	{
		if (!m_nonDieFlg)
		{
			m_alive = false;
			SCENE.GetExplosion()->SetFlg(true);
		}
	}
	
	//発射までのカウント減少
	if (--m_shotCnt < 0)m_shotCnt = 0;

	//スペースキーで弾を発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (m_shotCnt == 0)
		{
			static int _cnt = 0;
			C_PlayerBullet* playerBullet = SCENE.GetPlayerBullet(_cnt);
			if (++_cnt > 29)_cnt = 0;
			playerBullet->SetShoot(true);

			//発射間隔設定
			m_shotCnt = 6;
		}
	}

	//プレイヤーと敵の当たり判定(当たっていたら死ぬ)
	for (int i = 0; i < 5; ++i)
	{
		C_Enemy* enemy = SCENE.GetEnemy(i);
		m_enemypos = SCENE.GetEnemy(i)->GetPos();

		float a = m_pos.x - m_enemypos.x;	//底辺
		float b = m_pos.y - m_enemypos.y;	//高さ
		float c = sqrt(a * a + b * b);		//斜辺

		if (c < 32 + 8)	//衝突していたら
		{
			if (SCENE.GetEnemy(i)->GetAlive() == true)
			{
				//プレイヤーにダメージ
				m_hp--;

				//敵を倒す
				SCENE.GetExplosion()->SetPos(m_pos);
				SCENE.GetExplosion()->SetFlg(true);
				SCENE.GetEnemy(i)->SetAlive(false);
				m_enemyNumber = SCENE.GetBoss()->GetEnemy();
				m_enemyNumber++;
				SCENE.GetBoss()->SetNumber(m_enemyNumber);

				break;
			}
		}
	}

	//プレイヤーとボスの当たり判定
	C_Boss* boss = SCENE.GetBoss();
	m_enemypos = SCENE.GetBoss()->GetPos();

	float a = m_pos.x - m_enemypos.x;	//底辺
	float b = m_pos.y - m_enemypos.y;	//高さ
	float c = sqrt(a * a + b * b);		//斜辺

	if (c < 96 + 8)	//衝突していたら
	{
		if (SCENE.GetBoss()->GetAlive() == true)
		{
			m_pos = { 0.0 };

			//プレイヤーにダメージ
			m_hp--;

			//プレイヤーの爆発アニメーション
			m_hpFlg = true;
			SCENE.GetExplosion()->SetPos(m_pos);
			SCENE.GetExplosion()->SetFlg(true);
		}
	}

	//画面内固定処理
	if (m_pos.x > 640 - 32)
	{
		m_pos.x = 640 - 32;
	}

	if (m_pos.x < -640 + 32)
	{
		m_pos.x = -640 + 32;
	}

	if (m_pos.y > 360 - 32)
	{
		m_pos.y = 360 - 32;
	}

	if (m_pos.y < -360 + 32)
	{
		m_pos.y = -360 + 32;
	}

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_Player::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 256, 256), 1.0f);
}
