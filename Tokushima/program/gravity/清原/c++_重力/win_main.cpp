#include "myLib.h"
#include "main.h"

//ローカル変数
CMain*		g_pMain = NULL;
const bool	WINDOW_SCREEN = true;

//ローカル関数
void win_main_init();
void win_main_loop();
void win_main_dest();

//ウィンドウ画面のメイン
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, LPSTR IpCmdLine,
	int nShowCmd)
{
	win_main_init();

	while (true){
		win_main_loop();
#if defined( _DEBUG ) | defined( DEBUG )
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) exit(-1);
#endif
	}
	win_main_dest();
}

//メインの初期化処理

void win_main_init()
{
	//DirectX関係

	ChangeWindowMode(WINDOW_SCREEN);
	if (WINDOW_SCREEN)
	{
		SetGraphMode(800, 600, 32);
		SetMainWindowText(_T("テストプログラム"));
	}
	if (DxLib_Init() == -1)		//ライブラリの初期化処理
		return;

	//GAME関係
	g_pMain = new CMain();
	g_pMain->Init();
}

//メインループ処理
void win_main_loop()
{
	//メイン処理
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//メイン終了処理
void win_main_dest()
{
	g_pMain->Dest();
	delete g_pMain;
	g_pMain = NULL;
}