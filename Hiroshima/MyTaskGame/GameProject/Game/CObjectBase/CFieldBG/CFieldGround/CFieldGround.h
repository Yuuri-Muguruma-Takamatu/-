#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

class CPlayer;

/*

»ìÒ@ZÔ
ÒW@@{ú±

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround(const bool flag);	//nÊBtrueÈçæÊEOÉ¶¬
	~CFieldGround();
	void Update();
	void Draw();
	void GroundHitCheck(CPlayer * pl);
private:
//	CRect m_rect_tourou[4];
	bool m_flag;
};

#endif // !FIELDGROUND_GUARD
