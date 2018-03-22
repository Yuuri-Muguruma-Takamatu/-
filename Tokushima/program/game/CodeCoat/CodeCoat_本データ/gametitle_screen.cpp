#include "gametitle_screen.h"
#include "se_manager.h"

int stagenum;
//コンストラクタ
CTitleScreen::CTitleScreen():
m_titlename_pos(TITLE_INIT_TEXT_X,TITLE_TEXT_Y,0),
m_title_akey_pos(TITLE_INIT_TEXT_X, TITLE_AKEY_Y, 0),
m_count(0),
m_drawtime(0)
, m_start(false)
{
	m_state = TITLE_SCREEN;
	m_titleName_img = LoadGraph("media\\img\\title_02.png");
	m_titleBg_f_img = LoadGraph("media\\img\\bg_front.png");
	m_titleBg_b_img = LoadGraph("media\\img\\bg_back.png");
	m_titlePushA_img = LoadGraph("media\\img\\press_A_key1.png");
	PlaySoundMem(CSeManager::GetInstance()->getsnd(TITLE_BGM), DX_PLAYTYPE_LOOP);
}

//デストラクタ
CTitleScreen::~CTitleScreen() {}

void CTitleScreen::Dest(){}

//実行処理
void CTitleScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_V) == 1)m_state = STAFFROLL_SCREEN;
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (IsHitKeyTrigger(key, PAD_INPUT_4)){
		if (m_titlename_pos.getX() > TITLE_TEXT_X){
			m_titlename_pos.setX(TITLE_TEXT_X);
			m_title_akey_pos.setX(TITLE_AKEY_X);
		}
		else if (!m_start && m_titlename_pos.getX() <= TITLE_TEXT_X)
		m_start = true; 
				
	
	}
	
	//タイトル名移動
	if (m_titlename_pos.getX() > TITLE_TEXT_X || m_start){
		m_titlename_pos += CVector3D(-TITLE_M_TEXT_X,0,0);
	}

	//「Aボタンを押せ」移動
	if (m_title_akey_pos.getX() > TITLE_AKEY_X || m_start){
		m_title_akey_pos += CVector3D(-TITLE_M_AKEY_X,0,0);
	}
	else{
		m_count++;
		m_drawtime = m_count / 45 % 2;
	}

	if (m_start && m_titlename_pos.getX() < -720.0f)
		m_state = GAME_SCREEN;

}

//描画
void CTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawGraph(0, -TITLE_BG_B_Y, m_titleBg_b_img, TRUE);
	DrawGraph(0, -TITLE_BG_F_Y, m_titleBg_f_img, TRUE);
	DrawGraph(m_titlename_pos.getX(), m_titlename_pos.getY(), m_titleName_img, TRUE);
	if (m_drawtime == 0){
		DrawGraph(m_title_akey_pos.getX(), m_title_akey_pos.getY(), m_titlePushA_img, TRUE);
	}
	DrawString(10, 100, "TITLE Screen Hit A key to Next Screen", GetColor
		(255, 255, 255));
}

//次のステージへ
SCREEN CTitleScreen::GetNextScreen()
{
	return (m_state);
}