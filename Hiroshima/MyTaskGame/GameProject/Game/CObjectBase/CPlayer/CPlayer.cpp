#include "CPlayer.h"
#include "../GameProject/Game/CScene/CSceneManager.h"
#include "../CGo/CGo.h"
#include "../CBB/CBB.h"
#include "../CItem/COhuda/COhuda.h"
#include "../CPanchEF/CPanchEF.h"


#define PL_CENTER_X 64
#define PL_CENTER_Y 24

/*

§ìÒ@ZÔ@

ÒW@@Íì {ú±

*/

CPlayer::CPlayer(const int HP) :CObjectBase(eID_Player, eU_Player, eD_Object), m_scoreF("HGsÌ",40){
	m_scroll = CVector2D(0, 0);
	m_vec3D = CVector3D(0, 0, 0);
	m_pos3D = CVector3D(PL_CENTER_X, 0, 0);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256, 256);
	m_img.SetFlipH(m_flipH);
	m_img.SetCenter(PL_CENTER_X, PL_CENTER_Y);
	m_rect = CRect(0, 0, 127, 215);
	m_rect_F = m_rect;
	m_punch1 = false;
	m_punch2 = false;
	m_kick = false;
	m_jump = false;
	m_roof = false;
	m_hp = m_old_hp = HP;
	m_anim = eAnimIdol;
	m_state = eNutral;
	m_cnt = 0;
	m_die = 0;
	damage_vec = CVector2D(5, -10);
	m_sc_plus = 0.0;
	//eÝè
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(127, 33);
	m_img_shadow.SetCenter(0, 33 / 2);

	m_img.ChangeAnimation(m_anim);
	m_img.UpdateAnimation();
}

CPlayer::~CPlayer() {
	//NEW_SCENE(eTitle)
}

void CPlayer::Update() {
	//Ú®
	m_pos3D += m_vec3D;

	//¹ÌªÚ®
	if (m_pos3D.z > 0) {
		m_pos3D.z = 0;
	}
	if (m_pos3D.z <= -400) {
		m_pos3D.z = -400;
	}
	//if (m_pos3D.x - m_scroll.x < 0) {
	//	m_pos3D.x = m_pos3D.x - m_scroll.x;
	//}
	//if (m_pos3D.x + m_rect.m_right + m_scroll.x < SCREEN_WIDTH * 6) {
	//	m_pos3D.x = m_pos3D.x;
	//}

	//Ú®nÌÏú»
	m_move_length = false;
	m_move_side = false;
	m_squat = false;

	//ªò
	switch (m_state) {
	case eNutral:
		Nutral();
		break;
	case eAttack:
		Attack();
		break;
	case eDamage:
		Damage();
		break;
	case eFall:
		Fall();
		break;
	}

	//¶EÚ®I¹ãÌ¸¬
	if (!m_move_side && !m_die) {
		if (!m_jump) {
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 1.0f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 1.0f);
		}else {
			//WvÌ¸¬
			if (m_flipH)
				m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.1f);
			else
				m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.1f);
		}
	}
	//ãºÚ®I¹ãÌâ~
	if (!m_move_length && !m_jump && !m_die) {
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}

	if ((m_hp % 20 == 0 || m_hp <= 0) && m_hp < PLAYER_HP && !m_die && m_old_hp > m_hp) {
		m_state = eFall;
		m_die = 1;
		m_cnt = 0;
	}
	
	//Aj[V
	m_img.ChangeAnimation(m_anim);
	//p`¶»è
	if (m_anim == eAnimPunch && m_img.GetIndex() == 4) {
		if (m_punch2) {
			//p`µÄ½ç
			m_img.UpdateAnimation();
			new CPanchEF(m_flipH, this, eAnimEffectAttack2);
			m_punch1 = false;
			SOUND("SE_PUNCH_KARA")->Play();
		}else {
			//µÄÈ¢
			m_state = eNutral;
		}
	}
	//LbN»è
	if (m_anim == eAnimPunch && m_img.GetIndex() == 7) {
		if (m_kick) {
			//p`µÄ½ç
			m_anim = eAnimKick;
			new CPanchEF(m_flipH, this, eAnimEffectAttack3);
			m_punch2 = false;
			SOUND("SE_PUNCH_KARA")->Play();
		}
		else {
			//µÄÈ¢
			m_state = eNutral;
		}
	}
	if (m_anim == eAnimKick && m_img.GetIndex() == 3) {
		m_state = eNutral;
	}

	if (m_anim == eAnimBill && m_img.GetIndex() == 2) {
		m_state = eNutral;
	}

	if (m_squat&&m_img.GetIndex() == 1) {
	}//±±©çWv[V
	else if(m_jump && m_img.GetIndex() == 0){
		if (m_vec3D.y > -10) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 1) {
		if (m_vec3D.y > 0) {
			m_img.UpdateAnimation();
		}
	}else if (m_jump && m_img.GetIndex() == 2) {
	//±±©ç_[W[V
	}else if(m_anim == eAnimFall && m_img.GetIndex() == 3) {
		m_die = 0;
	}else if (m_anim == eAnimFall && m_img.GetIndex() == 1) {
		if(m_die >= 2)
			m_img.UpdateAnimation();
	}else {
		m_img.UpdateAnimation();

	}

	//XN[

	//	if (m_pos3D.x > SCREEN_WIDTH / 4 && m_pos3D.x < GROUND_WIDTH * 2 - (SCREEN_WIDTH / 4) * 3) {
	////		m_scroll.x = m_pos3D.x - SCREEN_WIDTH / 4;
	//		m_sc_flag_x = true;
	//	}else{
	//		m_sc_flag_x = false;
	//	}

	//Y²
	if (m_pos3D.z <= -400 && m_pos3D.y < 0 && m_pos3D.y > - 1200 + 720) {
			m_scroll.y = m_pos3D.y;
	}
	//X²
	//if (PUSH_ENTER) {
	//	if (m_pos3D.x > SCREEN_WIDTH * 5) {
	//		new CBB(0, 2, false);
	//	}
	//	else { new CGo(); }
	//}

	if (m_pos3D.x - m_scroll.x < PL_CENTER_X) {
		m_pos3D.x = m_scroll.x + PL_CENTER_X;
	}
	if (m_wave_flag && m_pos3D.x + PL_CENTER_X * 3 - m_scroll.x > SCREEN_WIDTH) {
		m_pos3D.x = SCREEN_WIDTH + m_scroll.x - PL_CENTER_X * 3;
	}
	if (m_pos3D.x - m_scroll.x > SCREEN_WIDTH) {
		m_sc_flag_x = true;
	}

	CheckOverlap();
	m_rect_F.m_bottom = m_rect.m_bottom - m_pos3D.y;

	m_old_hp = m_hp;
}

void CPlayer::Nutral() {

	m_punch1 = false;
	m_punch2 = false;
	m_kick = false;
	if (!m_jump) {
		m_anim = eAnimIdol;
	}

	//µáªÝ
	if (HOLD_E && !m_jump) {
		m_squat = true;
		m_anim = eAnimSquat;
	}
	CObjectBase *gr = dynamic_cast<CObjectBase*>(CTaskManager::GetInstance()->GetTask(eID_Ground));

	//ºÈç
	if (m_vec3D.y > 0) {
		//ÊíXe[WÅ
		if (gr->GetState() == eNomalGround &&
			//êÔÉ¢½ç
			1869 - 127 < m_pos3D.x && m_pos3D.x < 2592 && m_pos3D.y > -448 &&
			m_pos3D.z == -400) {
			m_pos3D.y = -448;
			m_vec3D.y = 0;
			m_jump = false;
			SOUND("SE_LANDING")->Play(false);
			m_roof = true;
		}
		//{XXe[WÅ
		//Ð¾è
		if (gr->GetState() == eBossGround &&
			//êÔÉ¢½ç
			122 - 127 < m_pos3D.x && m_pos3D.x < 350 && m_pos3D.y > -520 &&
			m_pos3D.z == -400) {
			m_pos3D.y = -520;
			m_vec3D.y = 0;
			m_jump = false;
			SOUND("SE_LANDING")->Play(false);
			m_roof = true;
		}
		//Ý¬
		if (gr->GetState() == eBossGround &&
			//êÔÉ¢½ç
			968 - 127 < m_pos3D.x && m_pos3D.x < 1280 && m_pos3D.y > -500 &&
			m_pos3D.z == -400) {
			m_pos3D.y = -500;
			m_vec3D.y = 0;
			m_jump = false;
			SOUND("SE_LANDING")->Play(false);
			m_roof = true;
		}
	}
	else if (m_roof) {
		if (gr->GetState() == eNomalGround) {
			if (1869 - 127 >= m_pos3D.x || m_pos3D.x >= 2592) {
				m_jump = true;
				m_roof = false;

			}
		}
		else if (gr->GetState() == eBossGround) {
			if (122 - 127 >= m_pos3D.x || m_pos3D.x >= 350 && 968 - 127 >= m_pos3D.x || m_pos3D.x >= 1280) {
				m_jump = true;
				m_roof = false;

			}
		}
	}

	//Ú®
	if (!m_squat) {
		if (!m_roof && !m_jump && HOLD_UP) {
			m_vec3D.z = -10;
			if (m_pos3D.z != 0 && m_pos3D.z != -430)
				m_variation += (SCREEN_WIDTH / 2 - (m_pos3D.x + m_variation - m_scroll.x)) / 500;
			m_move_length = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (!m_roof && !m_jump && HOLD_DOWN) {
			m_vec3D.z = 10;
			if (m_pos3D.z != 0 && m_pos3D.z != -430)
				m_variation += ((m_pos3D.x + m_variation - m_scroll.x) - SCREEN_WIDTH / 2) / 500;
			m_move_length = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
		if (HOLD_RIGHT) {
			//Á¬
			m_vec3D.x = Price_Up(m_vec3D.x, 10, 1.0f);
			m_move_side = true;
			m_flipH = false;
			m_anim = eAnimDash;
			m_cnt++;
		}
		else if (HOLD_LEFT) {
			//Á¬
			m_vec3D.x = Price_Down(m_vec3D.x, -10, 1.0f);
			m_move_side = true;
			m_flipH = true;
			m_anim = eAnimDash;
			m_cnt++;
		}
	}
	//Wv
	if (PUSH_R && !m_jump && !m_squat) {
		SOUND("SE_JUMP")->Play(false);
		m_vec3D.z = 0;
		m_jump = true;
		m_anim = eAnimJamp;
		m_vec3D.y = -35;
	}
	if (m_jump) {
		//dÍ
		m_anim = eAnimJamp;
		m_vec3D.y += GRAVITY;
		//³ÌÊuÉßÁ½ç
		if (m_pos3D.y > 0) {
			//÷²®
			m_pos3D.y = 0;
			m_jump = false;
			SOUND("SE_LANDING")->Play(false);
		}
	}
	//«¹
	if (m_cnt % 15 == 0 && m_cnt && m_jump == false) {
		m_dash = Utility::Rand(0, 3);
		switch (m_dash) {
		case 0:
			SOUND("SE_DASH1")->Play(false);
			break;
		case 1:
			SOUND("SE_DASH2")->Play(false);
			break;
		case 2:
			SOUND("SE_DASH3")->Play(false);
			break;
		}
		m_cnt++;
	}

	//WvµÄÈ­ÄAp`µ½ç
	if (!m_jump && PUSH_X) {
		if (m_punch1 == false)
			new CPanchEF(m_flipH, this, eAnimEffectAttack1);
		SOUND("SE_PUNCH_KARA")->Play();
		m_punch1 = true;
		m_anim = eAnimPunch;
		m_state = eAttack;
	}
	//¨D
	if (!m_jump && PUSH_V) {
		m_anim = eAnimBill;
		m_state = eBill;
		new COhuda(m_pos3D, m_flipH);
	}

}

void CPlayer::Bill() {
}

void CPlayer::Attack() {
	//LbN
	if (m_punch1 && PUSH_X) {
		m_punch2 = true;
	}
	if (!m_punch1 && PUSH_X) {
		m_kick = true;
	}
	//if (PUSH_ENTER) {
	//	SetKill();
	//}
}

void CPlayer::Damage() {
	m_anim = eAnimDamage;
	if (m_img.GetIndex() == 1) {
		m_anim = 0;
		m_state = eNutral;
	}
}
//ÁòÑ
void CPlayer::Fall() {
	m_cnt++;
	if (m_cnt == 20) {
		if (m_flipH)
			m_vec3D.x = damage_vec.x;
		else
			m_vec3D.x = -damage_vec.x;
		m_vec3D.y = damage_vec.y;
	}
	if (m_cnt >= 20)
		if (m_die != 4)
			m_vec3D = Die(m_vec3D);
	m_anim = eAnimFall;
	//x¸¬
	if (m_flipH)
		m_vec3D.x = Price_Down(m_vec3D.x, 0, 0.05f);
	else
		m_vec3D.x = Price_Up(m_vec3D.x, 0, 0.05f);
	if (m_img.GetIndex() == 2 && m_vec3D.y == 0 && m_hp <= 0)
		new CBB(0, 3, false);
	//N«ãªè
	if (!m_die) {
		//tOú»
		m_die = 0;
		m_state = eNutral;
		//»Ì¼X
		damage_vec.y = -10;
		m_cnt = 0;
		m_anim = eAnimIdol;
	}
}
//ÁòÑ®«
CVector3D CPlayer::Die(CVector3D vec) {
	m_vec3D.z = 0;
	m_vec3D.y += GRAVITY_DIE;
	if (m_pos3D.y > 0) {
		if (m_die == 3) {
			m_vec3D.y = 0;
			m_pos3D.y = 0;
		}else {
			m_pos3D.y = 0;
			damage_vec.y *= REPULSION;
			m_vec3D.y = damage_vec.y;
		}
			m_die++;
	}
	return m_vec3D;
}

void CPlayer::Draw() {
	//XN[(|[Y@\ªg¢½¢©çA±±Å·éµ©È¢)
	if (m_wave_flag == false && m_sc_flag_x) {
		m_pause = true;
		m_scroll.x = Price_Up(m_scroll.x, (m_pos3D.x + PL_CENTER_X), m_sc_plus);
		m_sc_plus = Price_Up(m_sc_plus, 30, 0.5);
	}
	else {
		m_sc_plus = 0.0;
		m_pause = false;
	}
	if (m_deathblow) {
		m_img.ChangeAnimation(eAnimDeathblow);
		m_img.UpdateAnimation();
	}
	m_img.SetFlipH(!m_flipH);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img_shadow.SetColor(1, 1, 1, m_color.w + (m_pos3D.y * 0.001));
	m_img_shadow.SetPos(m_pos3D.x - m_pos3D.z / 7/*m_variation*/ - m_scroll.x, 450 + m_rect_F.m_bottom + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img_shadow.Draw();
	m_img.Draw();
	m_scoreF.Draw(SCREEN_WIDTH - 300, 50, 0, 0, 0, "¾_@%5d_",m_score);
	//Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7/*+ m_variation*/ - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7/*+ m_variation*/ - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CPlayer::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Enemy) {
		if (t->GetState() == eAttack && m_state != eFall && m_state != eDamage) {
			SOUND("SE_Panch")->Play(false);
			m_flipH = t->GetFrip();
			if (m_jump) {
				m_state = eFall;
				m_die = 1;
				m_jump = false;
			}
			else {
				if (m_hp <= 0)
					m_state = eFall;
				else
					m_state = eDamage;
			}
			m_vec3D.y = 0;
			m_hp -= 2;
			m_cnt = 0;
		}
	}
	if (t->GetID() == eID_Effect) {
		CEffectBase *ef = dynamic_cast<CEffectBase*>(t);
		if (ef->GetHit() > 1.0f  && m_state != eFall && m_state != eDamage) {
			if (ef->GetEFtype() == eBress) {
				SOUND("SE_Panch")->Play(false);
				if (m_jump) {
					m_state = eFall;
					m_die = 1;
					m_jump = false;
				}
				else
					m_state = eFall;
				m_vec3D.y = 0;
				m_hp -= 20;
				m_cnt = 0;
			}
		}
	}

}

