#include "stdafx.h"
#include "ObjectSuper.h"

CObjectSuper::CObjectSuper(void)
	: m_PosX(0)
	, m_PosY(0)
	, m_VelX(0)
	, m_VelY(0)
	, m_Height(0)
	, m_Width(0)
	, m_Weight(0)
	, m_cPatch('*')
	, m_nDirX(1)
	, m_nDirY(0)
{
}

CObjectSuper::~CObjectSuper(void)
{
}

bool CObjectSuper::IsDestroyed(void)
{
	return false;
}

void CObjectSuper::OnUpdate(double dElapsedSec)
{
}

void CObjectSuper::OnLanded(void)
{
}

void CObjectSuper::onCollide(const CObjectSuper* pOthe)
{

}
