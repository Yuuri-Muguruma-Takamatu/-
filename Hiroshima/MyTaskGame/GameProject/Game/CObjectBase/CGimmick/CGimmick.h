#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CObjectBase.h"
/*

製作者　河野

*/

class CFire :public CObjectBase {
public:
	CFire(CVector3D *pos);
	~CFire();
	void Update();
	void Draw();

private:
	int m_cnt;	//わからん
};

#endif // !GIMMICK_GUARD