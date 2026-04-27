#pragma once

class Scene;

class C_PlayerBullet
{
public:
	C_PlayerBullet() {};
	~C_PlayerBullet() {};

	void Init();
	void Update();
	void Draw();
	void Reset();

	void SetTex(KdTexture* tex) { m_tex = tex; }

	void SetShoot(bool flg) { m_shootFlg = flg; }

private:

	Scene* m_owner;

	KdTexture* m_tex;		//テクスチャ
	Math::Vector2 m_pos;	//座標
	Math::Vector2 m_move;	//移動量
	Math::Matrix m_scaleMat;//拡大行列
	Math::Matrix m_transMat;//移動行列
	Math::Matrix m_mat;		//合成行列
	bool m_flg;				//存在フラグ
	bool m_shootFlg;		//発射フラグ
};