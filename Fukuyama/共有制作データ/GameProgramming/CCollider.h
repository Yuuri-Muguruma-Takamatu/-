#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "object\C_Object.h"

class C_Collider : public C_Object{
public:
	static bool Collision(C_Object* ip_MyCol, C_Object* ip_YouCol, C_Vector3* ip_MyShadowCol, C_Vector3* ip_YouShadowCol);
	static bool CCollisionX(C_Object *ip_Col, const C_Object *ip_Col2); //左右衝突判定,r1は衝突しに行く方,r2は衝突される方
	static bool CCollisionZ(C_Object *ip_Col, const C_Object *ip_Col2); //上下衝突判定,r1は衝突しに行く方,r2は衝突される方
};
#endif