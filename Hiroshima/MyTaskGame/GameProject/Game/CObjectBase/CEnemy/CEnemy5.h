#ifndef EBEMY5GUAD
#define EBEMY5GUAD

#include"../CObjectBase.h"
/*

製作者　青木

*/
class CEnemy5 :public CObjectBase {
public:
	CEnemy5(CVector2D *pos);
	~CEnemy5();
	void Update();
};




#endif // !EBEMY1GUAD