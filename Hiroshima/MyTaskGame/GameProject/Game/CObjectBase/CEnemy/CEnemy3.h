#ifndef EBEMY3GUAD
#define EBEMY3GUAD
#include"../CObjectBase.h"
/*

製作者　青木

*/
class CEnemy3 :public CObjectBase {
public:
	CEnemy3(CVector2D *pos);
	~CEnemy3();
	void Update();
};




#endif // !EBEMY3GUAD
