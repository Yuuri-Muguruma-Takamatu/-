#ifndef EBEMY4GUAD
#define EBEMY4GUAD
#include"../CObjectBase.h"
/*

製作者　青木

*/
class CEnemy4 :public CObjectBase {
public:
	CEnemy4(CVector2D *pos);
	~CEnemy4();
	void Update();
};




#endif // !EBEMY4GUAD
