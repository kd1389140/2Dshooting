#include "../Scene.h"

void C_Explosion::Init()
{
	m_scale = { 2, 2 };
	m_AnimeCount = 16;
	m_explosionFlg = false;
	m_AnimeFlg = false;
	m_endEffectFlg = false;
	m_animatedFlg = false;
}

void C_Explosion::Update()
{
	if (m_explosionFlg) 
	{
		//敵が死んでいたら、敵の座標に爆発エフェクトを出す
		for (int i = 0; i < 5; ++i)
		{
			/*static int _Ecnt = 5;
			C_Enemy* enemy = SCENE.GetEnemy(_Ecnt);
			if (++_Ecnt > 4)_Ecnt = 0;*/
			if (SCENE.GetEnemy(i)->GetAlive() == false)
			{
				//敵の座標取得
				/*m_pos.x = SCENE.GetEnemy(i)->GetPos().x;
				m_pos.y = SCENE.GetEnemy(i)->GetPos().y;*/

				m_AnimeFlg = true;
				break;
			}
		}

		//敵2の死亡時の爆発アニメーション用
		if (SCENE.GetEnemy2()->GetAlive() == false && !m_animatedFlg)
		{
			m_AnimeFlg = true;

			//敵の座標取得
			m_pos.x = SCENE.GetEnemy2()->GetPos().x;
			m_pos.y = SCENE.GetEnemy2()->GetPos().y;

			m_animatedFlg = true;
		}

		//プレイヤーが死んでいたら、プレイヤーの座標に爆発エフェクトを出す
		if (SCENE.GetPlayer()->GetAlive() == false)
		{
			m_AnimeFlg = true;

			//プレイヤーの座標取得
			m_pos.x = SCENE.GetPlayer()->GetPos().x;
			m_pos.y = SCENE.GetPlayer()->GetPos().y;
		}

		//画像のアニメーション処理
		if (m_AnimeFlg == true)
		{
			m_AnimeCount += 0.3f;
			if (m_AnimeCount > 20)
			{
				if (!SCENE.GetPlayer()->GetAlive())
				{
					SCENE.GetResult()->SetFlg(true);
				}
				m_AnimeFlg = false;
				m_explosionFlg = false;
				m_endEffectFlg = true;
				m_AnimeCount = 16;
			}
		}

		m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
		m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
		m_mat = m_scaleMat * m_transMat;
	}
}

void C_Explosion::Draw()
{
	if(!m_explosionFlg)return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle((int)m_AnimeCount * 32, 12 * 32, 32, 32), 1.0f);
}

//void C_Explosion::Reset()
//{
//	Init();
//}
