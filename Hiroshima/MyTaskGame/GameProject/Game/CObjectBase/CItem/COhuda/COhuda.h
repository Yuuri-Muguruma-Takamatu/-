#ifndef OHUDA_GUARD
#define OHUDA_GUARD

#include "../../CObjectBase.h"

class COhuda :public CObjectBase {
private:
	int m_cnt;
public:
	COhuda(const CVector3D &pos, bool flipH);
	~COhuda();
	void Update();
	void Draw();
	//当たった時の処理
	void Hit(CObjectBase * t);
};

#endif // !OHUDA_GUARD
