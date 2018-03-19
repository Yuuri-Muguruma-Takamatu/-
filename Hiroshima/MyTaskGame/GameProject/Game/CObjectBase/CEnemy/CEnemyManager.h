#ifndef ENEMYMANAGER
#define ENEMYMANAGER

#include"CEnemyBase.h"
#include"../GameProject/Source/Gamesource.h"
/*

制作者　青木

*/

class CEnemyManager :public CEnemyBase {
protected:
	int m_wave, m_timing, m_push;
	bool m_old;
public:
	CEnemyManager();
	void Update();
	void PushEnemy(const int *id,const CVector3D *pos);
};
















#endif // !ENEMYMANAGER