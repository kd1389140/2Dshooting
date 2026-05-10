#pragma once

class C_Enemy2
{
public:
	C_Enemy2() {};
	~C_Enemy2() {};

	void Init();
	void Update();
	void Draw();
	void Reset();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetPos(Math::Vector2 pos) { m_pos = pos; }

	Math::Vector2 GetPos() { return m_pos; }
	bool GetAlive() { return m_alive; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//テクスチャ
	Math::Vector2 m_pos;		//座標
	Math::Vector2 m_pBulletpos;	//プレイヤー弾の座標
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_mat;			//合成行列
	bool m_alive;				//生存フラグ
};