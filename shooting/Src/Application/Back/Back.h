#pragma once

class Scene;

class C_Back
{
public:
	C_Back() {};
	~C_Back() {};

	void Init();
	void Update();
	void Draw();
	void Reset();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetTex2(KdTexture* tex) { m_tex2 = tex; }

	void SetFlg(bool flg) { m_flg = flg; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//テクスチャ
	KdTexture* m_tex2;			//テクスチャ
	Math::Vector2 m_pos;		//座標
	Math::Vector2 m_pos2;		//座標
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_transMat2;	//移動行列
	Math::Matrix m_mat;			//合成行列
	Math::Matrix m_mat2;		//合成行列
	bool m_flg;					//存在フラグ
};