#pragma once

class Scene;

class C_PlayerHpBar
{
public:
	C_PlayerHpBar() {};
	~C_PlayerHpBar() {};

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetFlg(bool flg) { m_flg = flg; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//画像
	Math::Vector2 m_pos;		//外側の座標
	Math::Vector2 m_scale;		//拡大率
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_mat;			//合成行列
	bool m_flg;					//存在フラグ
	int m_hp;					//Hp格納用関数
	int m_MaxHp;				//最大Hp格納用関数
	int m_scope;				//範囲
};