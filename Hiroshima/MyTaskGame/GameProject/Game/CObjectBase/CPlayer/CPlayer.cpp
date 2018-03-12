#include "CPlayer.h"

/*

制作者　六車　

編集　　河野

*/

CPlayer::CPlayer(){
	m_vec3D = CVector3D(0, 0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256, 256);
	m_img.SetFlipH(m_flipH);
	m_punch = false;
	m_jump = false;
}

CPlayer::~CPlayer() {
}

void CPlayer::Update() {
	m_move_length = false;
	m_move_side = false;
	m_squat = false;
	m_punch = false;
	m_anim = 0;

	m_pos3D += m_vec3D;

	if (HOLD_X) {
		m_squat = true;
		m_anim = 3;
	}
	if (!m_squat && !m_jump) {
		//移動
		if (HOLD_UP) {
			m_vec3D.z = -10;
			m_pos3D.x += (640 - m_pos3D.x) / 500;
			m_move_length = true;
			m_anim = 1;
		}
		if (HOLD_DOWN) {
			m_vec3D.z = 10;
			m_pos3D.x -= (640 - m_pos3D.x) / 500;
			m_move_length = true;
			m_anim = 1;
		}
		if (HOLD_RIGHT) {
			//加速
			m_vec3D.x = Price_Up(m_vec3D.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = 1;
		}
		if (HOLD_LEFT) {
			//加速
			m_vec3D.x = Price_Down(m_vec3D.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = 1;
		}
		//パンチ
		if (PUSH_R) {
			m_punch = true;
			m_anim = 4;
			m_pos3D.x++;

		}
	}
	//ジャンプ
	if (PUSH_Z && !m_jump) {
		//ジャンプする前のy座標を取得
		m_y = m_pos3D.y;
		m_jump = true;
		m_anim = 2;
		m_vec3D.y = -32;
	}
	if (m_jump) {
		//重力
		m_vec3D.y += 1.2;
		//元の位置に戻ったら
		if (m_pos3D.y > m_y) {
			m_vec3D.y = 10;
			//微調整
			m_pos3D.y = m_y;
			m_jump = false;
		}
	}

	//減速(左右)
	if (!m_move_side) {
		if (!m_jump) {
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 1.0f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 1.0f);
		}
		else {
			//ジャンプ中の減速
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.1f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
		}
	}
	//停止(上下)
	if (!m_move_length && !m_jump) {
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}
	
	//アニメーション
	m_img.ChangeAnimation(m_anim);
	if (m_anim == 4 && m_img.GetIndex() == 3) {
		m_anim = 0;
	}
	if (m_squat&&m_img.GetCount() == 1) {

	}
	else {
		m_img.UpdateAnimation();
	}
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	
}
