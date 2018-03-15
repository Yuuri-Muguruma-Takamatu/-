#include "CGo.h"

CGo::CGo() : CObjectBase(eID_Flag,eU_UI,eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("GO"));
	m_img.SetSize(GO_SIZ, GO_SIZ);
	m_pos3D = CVector3D(SCREEN_WIDTH - 150, 300,0);
}

CGo::~CGo()
{
}

void CGo::Update()
{
	m_pos3D += m_vec3D;
	m_a += GO_TIME;
	m_vec3D.y = sin(m_a);
}
