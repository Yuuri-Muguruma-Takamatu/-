#ifndef BOSSGUARD
#define BOSSGUARD

#include"../CObjectBase.h"
/*

製作者　青木

*/
class CBoss :public CObjectBase {
public:
	CBoss(CVector3D *pos);
	~CBoss();
	void Update();
};




#endif // !EBEMY1GUARD
