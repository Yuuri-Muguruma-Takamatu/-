#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "../task/CTask.h"
#include "CVector3.h"
#include "../draw/CRectangle.h"

#define RUN_ANIME_INTERVAL 8   //アニメーション1枚当たりのフレーム数
#define RUN_ANIME_FRAME 6    //走りアニメの絵の数
#define RUN_ANIME RUN_ANIME_INTERVAL*RUN_ANIME_FRAME    //アニメーション用変数を回す上限

enum PLAYER_STATE{
	E_RIGHT,    //右向き
	E_LEFT,     //左向き
	E_JUMP,     //ジャンプ中
	E_NJUMP,    //ジャンプ中ではない
	E_THROW,    //カラーボール投げ中
	E_NTHROW,   //カラーボール投げ中ではない
};

class C_Object :public CTask{
public:
	//コンストラクタでidとプライオリティの設定とメンバーの初期化
	C_Object(int id, int updatePrio, int drawPrio, float posx, float posy, float posz)
		:CTask(id, updatePrio, drawPrio)
		, init(false)
		, m_Position(posx, posy, posz)
		, m_Speed(0.0f, 0.0f, 0.0f)
		, m_Gravity(0.0f,-9.8f,0.0f)
	{}
	bool init;  //Initを通ったかどうか
	void Init();
	C_Vector3 m_Position;  //座標を管理
	static float m_Scroll;  //スクロール基準点
	int m_Turn;             //右を向いているか左を向いているか
	int m_Jump;             //ジャンプしているかしていないのか
	int m_Throw;            //ボールを投げているか
protected:
	C_Rectangle i_Shadow;   //影用インスタンス
	C_Rectangle m_image;  //メンバー変数にする
	C_Vector3 m_Speed;  //速度を管理
	C_Vector3 m_Gravity;  //重力
	void Rect(C_Rectangle* m_image,const C_Vector3* pos);  //ポジションの場所にC_Rectangle表示
	void Scroll(C_Vector3 *m_pos,float m_Scroll);     //スクロール処理をします
};
#endif