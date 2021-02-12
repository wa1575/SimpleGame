#include "stdafx.h"
#include "PlainLandObject.h"

CPlainLandObject::CPlainLandObject(void)
	: CObjectSuper()
{
	m_PosX = 0;
	m_PosY = -1001;
	m_VelX = 0;
	m_VelY = 0;
	m_Width = 99999999;
	m_Height = 1000;
	m_cPatch = '-';
	m_Weight = 0;
}

CPlainLandObject::~CPlainLandObject(void)
{
}
