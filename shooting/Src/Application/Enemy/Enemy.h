#pragma once

class C_Enemy
{
public:
	C_Enemy() {};
	~C_Enemy() {};

	void Init();
	void Update();
	void Draw();
	void Reset();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetPos(Math::Vector2 pos) { m_pos = pos; }
	void SetAlive(bool alive) { m_alive = alive; }
	void SetRespawn(bool respawn) { m_respawnFlg = respawn; }
	void SetNumber(bool number) { m_enemyNumber = number; }

	Math::Vector2 GetPos() { return m_pos; }
	bool GetAlive() { return m_alive; }
	int GetNumber() { return m_enemyNumber; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//テクスチャ
	Math::Vector2 m_pos;		//座標
	Math::Vector2 m_move;		//移動量
	Math::Vector2 m_scale;		//拡大率
	Math::Vector2 m_pBulletpos;	//プレイヤー弾の座標
	Math::Vector2 m_Ppos;		//プレイヤーの座標
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_rotateMat;	//回転行列
	Math::Matrix m_mat;			//合成行列
	bool m_alive;				//生存フラグ
	bool m_respawnFlg;			//復活フラグ
	int m_hp;					//体力
	int m_enemyNumber;			//倒した敵の数
	bool m_completedFlg;		//実行済みフラグ
};