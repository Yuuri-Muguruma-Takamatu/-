#ifndef GIMMICK2_GUARD
#define GIMMICK2_GUARD

#include "../CObjectBase.h"
/*

製作者　河野

*/

class CGimmick2 :public CObjectBase {
public:
	CGimmick2(CVector3D *pos);
	~CGimmick2();
	void Update();
private:
	int m_cnt;	//わからん
};

#endif // !GIMMICK2_GUARD
