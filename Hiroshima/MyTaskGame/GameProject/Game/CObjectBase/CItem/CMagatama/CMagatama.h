#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

#define MAGATAMA_POS_X 0
#define MAGATAMA_POS_Y 0

class CMagatama :public CObjectBase {
private:
	int m_cnt;

public:
	CMagatama();
	~CMagatama();
	void Update();
	void Draw();
	//当たった時の処理
	void Hit(CObjectBase *t);
	//必殺技発動
	void SetAttack();
};

#endif // !MAGATAMA_GUARD