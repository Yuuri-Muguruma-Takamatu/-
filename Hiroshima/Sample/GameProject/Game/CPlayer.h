#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "CBase.h"

/*

制作者　六車　

*/

class CPlayer :public CBase {
public:
	CPlayer();
	~CPlayer();
	 void Update();
	 void Draw();
private:
	bool m_punch;
	int m_anim;
};

#endif // !PLAYER_GUARD