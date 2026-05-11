#pragma once

class Scene;

class C_PlayerBullet;

class C_Player
{
public:
	C_Player() {};
	~C_Player() {};

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetHp(int hp) { m_hp = hp; }
	void SetHpFlg(int hp) { m_hpFlg = hp; }

	Math::Vector2 GetPos() { return m_pos; }
	bool GetAlive() { return m_alive; }
	bool GetHp() { return m_hp; }
	bool GetHpFlg() { return m_hpFlg; }

private:

	Scene* m_owner;

	KdTexture* m_tex;		//テクスチャ
	Math::Vector2 m_pos;	//座標
	Math::Vector2 m_move;	//移動量
	Math::Vector2 m_enemypos;//敵の座標
	Math::Matrix m_scaleMat;//拡大行列
	Math::Matrix m_transMat;//移動行列
	Math::Matrix m_mat;		//合成行列
	bool m_alive;			//生存フラグ
	bool m_hpFlg;			//Hpが減ったかどうかのフラグ
	int m_hp;				//体力
	int m_shotCnt = 0;		//弾を打つまでのカウント
};