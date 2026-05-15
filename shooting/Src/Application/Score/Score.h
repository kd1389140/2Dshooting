#pragma once

class Scene;

class C_Score
{
public:
	C_Score() {};
	~C_Score() {};

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* tex) { m_tex = tex; }
	void SetFlg(bool flg) { m_flg = flg; }
	void SetPos(Math::Vector2 pos) { m_pos = pos; }

	void SetEnemyFlg(bool flg) { m_enemyFlg = flg; }
	void SetEnemy2Flg(bool flg) { m_enemy2Flg = flg; }
	void SetBossFlg(bool flg) { m_bossFlg = flg; }

private:

	Scene* m_owner;

	KdTexture* m_tex;			//テクスチャ
	Math::Vector2 m_pos;		//座標
	Math::Vector2 m_scale;		//拡大率
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_mat;			//合成行列
	bool m_flg;					//存在フラグ
	bool m_enemyFlg;			//エネミー撃破時のスコア増加フラグ
	bool m_enemy2Flg;			//エネミー2撃破時のスコア増加フラグ
	bool m_bossFlg;				//ボス撃破時のスコア増加フラグ

	//扱う桁数の最大値
	static const int maxDigit = 6;
	unsigned long m_score;	//現在のスコア
	int m_digits[maxDigit] = {};	//各桁を管理する配列

	const int digitWidth = 9;   // フォント画像上の1文字幅
	const int digitHeight = 16;  // フォント画像上の1文字高さ

	int digit;
	float offsetX;
};