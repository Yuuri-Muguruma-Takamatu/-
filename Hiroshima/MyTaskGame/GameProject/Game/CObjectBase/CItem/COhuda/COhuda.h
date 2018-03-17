#ifndef OHUDA_GUARD
#define OHUDA_GUARD

#include "../CItemBase/CItemBase.h"

class COhuda :public CItemBase {
public:
	COhuda(CVector3D *pos, bool * flipH);
	~COhuda();
	void Update();
	//当たった時の処理
	void Hit(CObjectBase * t);
};

#endif // !OHUDA_GUARD
