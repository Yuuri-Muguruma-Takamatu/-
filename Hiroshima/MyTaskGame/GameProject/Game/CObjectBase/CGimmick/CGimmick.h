#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CObjectBase.h"
/*

製作者　河野

*/

class CGimmick :public CObjectBase {
public:
	CGimmick(CVector3D *pos);
	~CGimmick();
	void Update();
	void Draw();

private:
	int m_cnt;	//わからん
};

#endif // !GIMMICK_GUARD