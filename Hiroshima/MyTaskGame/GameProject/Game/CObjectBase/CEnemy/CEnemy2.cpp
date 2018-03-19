#include "CEnemy2.h"


/*

製作者　青木

*/
//提灯
CEnemy2::CEnemy2(const CVector3D *pos) :CEnemyBase() {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy2"));
	m_img.SetSize(ENEMY_SIZ_X, ENEMY_SIZ_Y);
	m_pos3D = *pos;
	m_hp = CHOCHIN_HP;
	m_at = CHOCHIN_AT;
	m_rect = CRect(77, 68, 170, 161);
	m_rect_F = CRect(77, 68, 170, ENEMY_SIZ_Y);

	m_damage = false;
	m_end_flag = false;
	m_state = eMove;

}

void CEnemy2::Update() {
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
	m_rect_F.m_bottom = ENEMY_SIZ_Y - m_pos3D.y;
}


void CEnemy2::Nutral() {

}

void CEnemy2::Move() {
	m_pos3D += m_vec3D;

	if (m_pos3D.x - m_scroll.x < 0 || m_pos3D.x - m_scroll.x > SCREEN_WIDTH - ENEMY_SIZ_X) {
		m_flipH = !m_flipH;
	}

	if (m_flipH) {
		m_vec3D.x = CHOCHIN_SPEED;
	}
	else {
		m_vec3D.x = -CHOCHIN_SPEED;
	}

	//上下浮遊
	m_a += CHOCHIN_FLOAT;
	m_vec3D.y = sin(m_a) * 2;


	m_img.ChangeAnimation(eAnimEnemyMove);
}

void CEnemy2::Attack() {
	m_img.ChangeAnimation(eAnimEnemyAttack);
	if (m_img.GetIndex() == 2) {
		m_state = eMove;
	}
}

void CEnemy2::KnockBack() {
	m_img.ChangeAnimation(eAnimEnemyKnockBack);
	Damage();
	if (m_img.GetIndex() == 1) {
		m_state = eMove;
	}
}
