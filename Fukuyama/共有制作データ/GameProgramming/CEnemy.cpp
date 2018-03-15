#include"CEnemy.h"
#include"task\CTaskManager.h"
#include"chara\C_Player.h"
#include"random"
C_Player *ip_Player;
int EnemyCount = 0;
void CEnemy::Init(){
	srand((unsigned)time(NULL));
	m_EnemySet = rand() % 12;
	switch (m_EnemySet)
	{
	case 0:
		C_Vector3(700,0,35);
		m_EnemyKind = 0;
		break;
	case 1:
		C_Vector3(700, 0, -105);
		m_EnemyKind = 0;
		break;
	case 2:
		C_Vector3(700, 0, -235);
		m_EnemyKind = 0;
		break;
	case 3:
		C_Vector3(700, 0, -365);
		m_EnemyKind = 0;
		break;
	case 4:
		C_Vector3(-700, 0, 35);
		m_EnemyKind = 0;
		break;
	case 5:
		C_Vector3(-700, 0, -105);
		m_EnemyKind = 0;
		break;
	case 6:
		C_Vector3(-700, 0,-235);
		m_EnemyKind = 0;
		break;
	case 7:
		C_Vector3(-700, 0, -365);
		m_EnemyKind = 0;
		break;
	case 8:
		C_Vector3(700, 0, 35);
		m_EnemyKind = 1;
		break;
	case 9:
		C_Vector3(700, 0, -105);
		m_EnemyKind = 1;
		break;
	case 10:
		C_Vector3(700, 0, -235);
		m_EnemyKind = 1;
		break;
	case 11:
		C_Vector3(700, 0, -365);
		m_EnemyKind = 1;
		break;
		m_EnemyCount += 1;
	}
}
void CEnemy::Update(){
	//近距離戦闘型の敵の処理
	if (m_EnemyKind == 0){

	}
	//逃走型の敵の処理
	else{
		if (m_Position.x<=700){
			
		}
	}
	m_Target = ip_Player;
	C_Vector3 diaPlayer =
		m_Target->m_Position - m_Position;
	//左側にいるときの追跡処理
	if (m_Position.x < ip_Player->m_Position.x){
		m_Position.x = m_Position.x + (diaPlayer.x + 90 / ENEMY_LR_SPEED);
	}
	//右側にいるときの追跡処理
	else{
		m_Position.x = m_Position.x + (diaPlayer.x - 90 / ENEMY_LR_SPEED);
	}

	m_Position.z = m_Position.z + (diaPlayer.z / ENEMY_UD_SPEED);

}
void CEnemy::Draw(){

	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
}