#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#define ROGO_SIZ_X 600
#define ROGO_SIZ_Y 800

#define START_SIZ_X 350
#define START_SIZ_Y 100

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
	CAnimImage m_img_start;		//X^[gæ
	CAnimImage m_img_start_2;		//X^[gæ

	CColorRGBA m_col_rogo;			//SæJ[
	CColorRGBA m_col_rogo_s;		//Sæ·ªJ[
	CColorRGBA m_col_start;			//X^[gæJ[
	CColorRGBA m_col_start_2;			//X^[gæJ[

	CVector2D m_st_siz;

	bool m_end_flag;			//{ÉIíèÜ·ætO
	bool m_sabun_flag;			//falseÈç·ªªÁ¦éBtrueÈç·ªªoé
	float m_f_time;					//(tF[hAEgÊQl)
	int   m_time;					//G^[L[ðµÄ©çÌÔ(tF[hAEgÊQl)

	void RogoUpdate();			//Sæ{ÌÌAbvf[g
	void PushStartUpdate();		//PushStartæ{ÌÌAbvf[g
	void FadeIn(float *a);				//tF[hC
	void FadeOut(float *a);				//tF[hAEg

};

#endif // !TITLE_BG_GUARD
