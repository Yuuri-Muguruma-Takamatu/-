#ifndef ENEMY4GUARD
#define ENEMY4GUARD
#include"../CObjectBase.h"

#define KAMAITACHI_HP 10
#define KAMAITACHI_AT 10
#define KAMAITACHI_SPEED 7
/*

製作者　青木

*/
//かまいたち
class CEnemy4 :public CObjectBase {
private:
	float m_a;
public:
	CEnemy4(CVector3D *pos);
	~CEnemy4();
	void Update();
};




#endif // !ENEMY4GUARD
