#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#include"../CObjectBase.h"
/*

製作者　青木

*/
//だるま
class CEnemy1 :public CObjectBase {
public:
	CEnemy1(CVector3D *pos);
	~CEnemy1();
	void Update();
};




#endif // !ENEMY1GUARD