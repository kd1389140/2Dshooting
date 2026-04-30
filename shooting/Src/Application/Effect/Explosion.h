#pragma once

class Scene;

class C_Explosion
{
public:
	C_Explosion() {};
	~C_Explosion() {};

	void Init();
	void Update();
	void Draw();
	void Reset();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetFlg(bool flg) { m_explosionFlg = flg; }

	Math::Vector2 GetPos() { return m_pos; }

private:

	Scene* m_owner;

	KdTexture* m_tex;		//テクスチャ
	Math::Vector2 m_pos;	//座標
	Math::Vector2 m_scale;	//拡大率
	Math::Matrix m_scaleMat;//拡大行列
	Math::Matrix m_transMat;//移動行列
	Math::Matrix m_mat;		//合成行列
	bool m_explosionFlg;//動作フラグ
	bool m_AnimeFlg;//アニメーション開始フラグ
	bool m_endEffectFlg;//エフェクト終了通知フラグ
	float m_AnimeCount;//アニメーションのカウント
};