#ifndef ENEMY2GUARD
#define ENEMY2GUARD
#include"../CObjectBase.h"
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
