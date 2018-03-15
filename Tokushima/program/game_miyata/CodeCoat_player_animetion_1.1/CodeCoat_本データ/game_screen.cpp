#include "game_screen.h"
#include "player_manager.h"
#include "Task\CTaskManager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include "enemy_manager.h"

int g_stage = 1;

//コンストラクタ
CGameScreen::CGameScreen(){
	m_state = GAME_SCREEN;
	CItemManager::GetInstance()->Create(&CVector3D(300,0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(500, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(700, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(900, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(1100, 0, 300));
	//new CMapControl;
	CEnemyManager *em = CEnemyManager::getInstance();
}

//デストラクタ
CGameScreen::~CGameScreen(){}

void CGameScreen::Dest(){
}

//ロード
void CGameScreen::Load(){
	//m_bgm = LoadSoundMem("media\\mp3\\main\\game_maoudamashii_6_dangeon09.mp3");
	/*m_Mcnt.loadFiles();
	m_Pcnt.loadFiles();
	m_Tcnt.load();
	m_Icnt.LoadFiles();*/
}

//初期化
void CGameScreen::Init(){
	/*m_Mcnt.Init();
	m_Pcnt.init();
	m_Tcnt.init();*/
}


//更新処理
void CGameScreen::Update(){
	/*m_Mcnt.move(m_Pcnt.getMoveAmount());
	m_Icnt.move(m_Pcnt.getMoveAmount());
	m_Pcnt.move(&m_Mcnt,&m_Icnt);
	m_Tcnt.move(m_Pcnt.getBodyPos());
	m_Icnt.eraseidata();

	if (m_Tcnt.GetTime() == 0){
		m_state = GAMEOVER_SCREEN;
	}*/
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->KillAppoint();
	CPlayerManager::GetInstance()->Update();
	CEnemyManager::getInstance()->Update();
}

void CGameScreen::Draw()
{
	ClearDrawScreen();
	/*m_Mcnt.draw();
	m_Pcnt.draw();
	m_Icnt.draw();
	m_Tcnt.draw();
	m_Pcnt.draw();*/
	CTaskManager::GetInstance()->DrawAll();
}

//次のステージへ
SCREEN CGameScreen::GetNextScreen()
{
	return (m_state);
}