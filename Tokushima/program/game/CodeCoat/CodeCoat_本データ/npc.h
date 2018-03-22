//--------------------------
//npc.h 6/14
///--------------------------

#ifndef __NPC_H__
#define __NPC_H__

//ヘッダーファイル
#include <DxLib.h>
#include "myLib.h"
#include "item.h"
#include "Task\CTask.h"

//定数
const int N_ANIM_COUNT = 9;
/*const int MOVEING_RANGE_DOWN = 640;		//下の移動限界範囲
const int MOVEING_RANGE_UP = 430;		//上の移動限界範囲
const int MOVEING_RANGE_LEFT = -25;		//左の移動限界範囲
const int MOVEING_RANGE_RIGHT = 1150;	//右の移動限界範囲*/
const float N_START_POSX = -200;			//NPCのスタート位置：x座標
const float N_START_POSZ = 300;			//NPCのスタート位置：z座標
const int NPC_SHADOW_HEIGHT_POS = 170;//影の位置：縦
const int NPC_SHADOW_WIDTH_POS = 53;//影の位置：横
const int SELL_COUNT = 3; //ショップUIの数
const int N_ANIM_RATE = 6;//アニメーションの再生速度
const int N_MOVEING_SPEED = 380.0f;//npcの移動速度
const int N_WAIT_TIME = 10000;
const int FLAME_INTERVAL = 230;
const int FLAME_YPOS = 100;
const float DASH_START_POS = 4000.0f;
const int CHECK_POINT_NUMBER = 3;
const int FLAME_NUM = 5;//フレームの数
const int PRICENUM_INIT_X = 220;
const int PRICENUM_INIT_Y = 200;


class CNpc : public CTask{
private:
	int m_animcounter;
	int m_ac;
	int m_shadowimg;								//npcの影画像
	int m_bodyimg[N_ANIM_COUNT];
	int m_scorenum_img[12];		//スコアの数字画像
	CVector3D m_pos;
	bool m_movestate;
	CItemData m_sell_item[SELL_COUNT];
	bool m_shop_flag;
	bool m_dash_flag;
	int m_flame[FLAME_NUM];
	int m_cursor;
	int m_leave_time;
	float m_chk_pt;
	int m_chk_pt_num;
public:
	CNpc();
	~CNpc();
	void Update();
	void Draw();
	bool getShopFlag(){ return m_shop_flag; }
	bool getDashFlag(){ return m_dash_flag; }
};

bool IsLeftKeyTrigger(int key);
bool IsRightKeyTrigger(int key);
bool IsZKeyTrigger(int key);
#endif __NPC_H__