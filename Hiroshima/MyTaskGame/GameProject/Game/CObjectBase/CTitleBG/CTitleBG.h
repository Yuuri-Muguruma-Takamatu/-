#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#include "../CObjectBase.h"

/*

§ìÒ@{ú±

*/
class CTitleBG : public CObjectBase
{
public:
	//^Cgæ
	CTitleBG();
	~CTitleBG();
	void Update();
	void Draw();
private:
	CAnimImage m_img_rogo;		//Sæ
	CAnimImage m_img_rogo_s;	//Sæ·ª
	CAnimImage m_img_start;	//Sæ·ª
	bool m_end_flag;			//G^[³ê½ÌÅIíèÜ·ætO
	bool m_pika_flag;			//falseÈçÒ©ªÁ¦éBtrueÈçÒ©ªoé
	void BGUpdate();			//^Cgæ{ÌÌAbvf[g
	void RogoUpdate();			//Sæ{ÌÌAbvf[g
	void PushStartUpdate();		//PushStartæ{ÌÌAbvf[g

};

#endif // !TITLE_BG_GUARD
