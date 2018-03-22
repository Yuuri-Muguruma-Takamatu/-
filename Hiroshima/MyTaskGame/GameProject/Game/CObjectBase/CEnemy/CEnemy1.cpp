#include "CEnemy1.h"

/*

製作者　青木

*/
//だるま
CEnemy1::CEnemy1(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_img.SetRect(0, 0, 512, 512);
	m_pos3D = *pos;
	m_pos3D.y = 0;
	m_hp = DARUMA_HP;
	m_at = DARUMA_AT;
	m_rect = CRect(64, 135, 166, 237);
	m_rect_F = m_rect;
	m_pleneVec = CVector3D(0, 0, 0);
	m_cnt = 0;
	//影設定
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(102, 26);
	m_img_shadow.SetCenter(-64, 26 / 2);
}

void CEnemy1::Update() {
	switch (m_state)
	{
		//待機
	case eIdol:
		Nutral();
		break;
		//移動
	case eMove:
		Move();
		break;
		//攻撃
	case eAttack:
		Attack();
		break;
		//のけぞり
	case eKnockBack:
		KnockBack();
		break;
		//倒されたとき
	case eFall:
		Fall();
		break;
	}

	m_img.UpdateAnimation();
	CheckOverlap();
	m_rect_F.m_bottom = 237 - m_pos3D.y;

}


void CEnemy1::Nutral() {

}
void CEnemy1::Move() {
	CTask *p = CTaskManager::GetInstance()->GetTask(eID_Player);
	CObjectBase *PL = dynamic_cast<CObjectBase*>(p);
	m_cnt++;
	m_pos3D += m_vec3D;
	if (m_pos3D.x - m_scroll.x < 0)
		m_flipH = false;
	if (m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X)
		m_flipH = true;
	m_pleneVec = PL->GetPos() - m_pos3D;
	if (m_cnt == 1) {
		if (m_pleneVec.Length() >= 512) {
			if (TWO_RANDOM) {
				if (m_pos3D.x < SCREEN_WIDTH - ENEMY_SIZ_X + m_scroll.x)
					m_vec3D.x = 2;
			}else {
				if (0 + m_scroll.x < m_pos3D.x)
					m_vec3D.x = -2;
			}
		}else if (100 <= m_pleneVec.Length())
			m_vec3D.x = m_pleneVec.GetNormalize().x * DARUMA_SPEED;
		else {
			m_vec3D.x = -m_pleneVec.GetNormalize().x * DARUMA_SPEED;
		}
		if (m_vec3D.x < 0)
			m_flipH = false;
		else
			m_flipH = true;
	}
	else if (60 <= m_cnt && m_cnt < 120) {
		m_vec3D = CVector3D(0, 0, 0);
	}
	else if (m_cnt == 120) {
		if (192 >= m_pleneVec.Length())
			m_state = eAttack;
		m_cnt = 0;
	}
	m_img.ChangeAnimation(eAnimEnemyMove);
}

void CEnemy1::Attack() {
	m_img.ChangeAnimation(eAnimEnemyAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eMove;
	}
}

void CEnemy1::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}
