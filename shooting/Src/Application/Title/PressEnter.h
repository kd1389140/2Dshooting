#pragma once

class Scene;

class C_PressEnter
{
public:
	C_PressEnter() {};
	~C_PressEnter() {};

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetFlg(bool flg) { m_flg = flg; }
	void SetPressFlg(bool flg) { m_pressFlg = flg; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//テクスチャ
	Math::Vector2 m_pos;		//座標
	Math::Vector2 m_scale;		//拡大率
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_mat;			//合成行列
	bool m_flg;					//存在フラグ
	bool m_pressFlg;			//キー入力フラグ
};