#ifndef ENEMY2GUARD
#define ENEMY2GUARD
#include"../CObjectBase.h"

#define CHOCHIN_HP 5
#define CHOCHIN_AT 3
#define CHOCHIN_SPEED 4
/*

製作者　青木

*/
//提灯
class CEnemy2 :public CObjectBase {
public:
	CEnemy2(CVector3D *pos);
	~CEnemy2();
	void Update();
};




#endif // !ENEMY4GUARD
