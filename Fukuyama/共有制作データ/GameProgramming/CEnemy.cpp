#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
#include"random"
#include"math.h"
#include"stdio.h"
struct EnemyTable{
	float x, y, z;
	int m_EnemyKind;
};
EnemyTable s_enemy_table[] = {
	{//0
		700, 0, 35,
		E_KIN, },
	{//1
		700, 0, -105,
			E_KIN, },
	{//2
		700, 0, -235,
			E_KIN, },
	{//3
		700, 0, -365,
			E_KIN, },
	{//4
		-700, 0, 35,
			E_KIN, },
	{//5
		-700, 0, -105,
			E_KIN, },
	{//6
		-700, 0, -235,
			E_KIN, },
	{//7
		-700, 0, -365,
			E_KIN, },
	{//8
		700, 0, 35,
		E_ESCAPE, },
	{//9
		700, 0, -105,
		E_ESCAPE, },
	{//10
		700, 0, -235,
		E_ESCAPE, },
	{//11
		700, 0, -365,
			E_ESCAPE, },

};
void CEnemy::Init(){
	m_ActionInterval = ACTION_INTERVAL;
	m_EnemySet = rand()/100 % 12;
	EnemyTable *data = &s_enemy_table[m_EnemySet];
	m_Position=C_Vector3(data->x, data->y, data->z);
	m_EnemyKind = data->m_EnemyKind;
	m_EnemyMode = E_NORMAL;
}
void CEnemy::Update(){
	m_TargetR = C_Player::m_Playerpoint->i_JumpPoint;
	m_TargetL = C_Player::m_Playerpoint->i_JumpPoint;
	m_TargetR.x += 100;
	m_TargetL.x -= 100;
	float m_LongR = sqrtf((m_TargetR.x - m_Position.x)*(m_TargetR.x - m_Position.x)
		+ (m_TargetR.z - m_Position.z)*(m_TargetR.z - m_Position.z));
	float m_LongL = sqrtf((m_TargetL.x - m_Position.x)*(m_TargetL.x - m_Position.x)
		+ (m_TargetL.z - m_Position.z)*(m_TargetL.z - m_Position.z));
	C_Vector3 diaPlayerR =
		m_TargetR - m_Position;
	C_Vector3 diaPlayerL =
		m_TargetL - m_Position;
	//近距離戦闘型の敵の処理
	if (m_EnemyKind == E_KIN){
	}
	//逃走型の敵の処理
	if (m_EnemyKind == E_ESCAPE){
		if (m_Position.x <= 150){

			m_EnemyMode = E_ACTION;
		}
		if (m_EnemyMode == E_ACTION){
			if (m_ActionInterval >= 0){
				m_ActionInterval--;
			}
			if (m_ActionInterval <= 0){
				m_Position.x += ENEMY_LR_SPEED;
				m_Turn = E_RIGHT;
			}
			//if (m_Position.x >= 700){
			//	CTaskManager::GetInstance()->Kill(this);
			//	new CEnemy();
			//	Init();

			//}
		}
	}
		if (m_EnemyMode == E_NORMAL){
			//左側にいるときの追跡処理
			if (m_Position.x <= m_TargetL.x){
				m_Position.x += diaPlayerL.x / m_LongL * ENEMY_LR_SPEED;
				m_Position.z += diaPlayerL.z / m_LongL * ENEMY_UD_SPEED;
				m_Turn = E_RIGHT;

			}
			//右側にいるときの追跡処理
			else{
				m_Position.x += diaPlayerR.x / m_LongR * ENEMY_LR_SPEED;
				m_Position.z += diaPlayerR.z / m_LongR * ENEMY_UD_SPEED;
				m_Turn = E_LEFT;
			}
		}
		//描画順番の変更
		CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
		C_Object::Scroll(&m_Position, m_Scroll);
		C_Object::Rect(&m_image, &m_Position);
		m_Colimage = m_image;
}


void CEnemy::Draw(){
	//
	RunAnime(&i_Enemy_Run, E_ENEMY);
	//
}

