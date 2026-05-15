#pragma once

class C_Boss
{
public:
	C_Boss() {};
	~C_Boss() {};

	void Init();
	void Update();
	void Draw();
	void Reset();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetPos(Math::Vector2 pos) { m_pos = pos; }
	void SetFlg(bool flg) { m_flg = flg; }
	void SetNumber(int number) { m_enemyNumber = number; }

	Math::Vector2 GetPos() { return m_pos; }
	bool GetAlive() { return m_alive; }
	bool GetFlg() { return m_flg; }
	int GetEnemy() { return m_enemyNumber; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//テクスチャ
	Math::Vector2 m_pos;		//座標
	Math::Vector2 m_move;		//移動量
	Math::Vector2 m_pBulletpos;	//プレイヤー弾の座標
	Math::Vector2 m_scale;		//拡大率
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_mat;			//合成行列
	bool m_alive;				//生存フラグ
	bool m_flg;					//存在フラグ
	int m_hp;					//体力
	int m_enemyNumber;			//敵の数
};