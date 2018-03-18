#include "gamescore_screen.h"

//コンストラクタ
CGameScoreScreen::CGameScoreScreen()
{
	m_state = GAMESCORE_SCREEN;
	//初期化
	m_lasttime = GetNowCount() & INT_MAX;
	//PlaySoundMem(m_GoverSound, DX_PLAYTYPE_BACK);
	//ロード
	//m_BGclearImage = LoadGraph("media\\img\\GAMECLEAR2.png");
	//m_GoverSound = LoadSoundMem("media\\mp3\\gameover\\sousou3.mp3");
}

//デストラクタ
CGameScoreScreen::~CGameScoreScreen(){}

void CGameScoreScreen::Dest(){
	StopSoundMem(m_GoverSound);
}

//実行処理
void CGameScoreScreen::Update()
{
	if (((GetNowCount() & INT_MAX) - m_lasttime) > BADGAMECLEAR_TIME){
		m_state = TITLE_SCREEN;
		//StopSoundMem(m_GoverSound);
	}
	//if (CheckHitKey(KEY_INPUT_X) == 1){
		//m_state = GAME_SCREEN;
		//StopSoundMem(m_GoverSound);
	//}
}

//描画
void CGameScoreScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SCORE Screen 5Seconds to Next Screen", GetColor
		(255, 255, 255));
	//DrawGraph(0, 0, m_BGclearImage, TRUE);
}


//次にステージ
SCREEN CGameScoreScreen::GetNextScreen()
{
	return (m_state);
}