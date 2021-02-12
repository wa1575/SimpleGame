#include "stdafx.h"
#include "GravityUpdateEngine.h"

CGravityUpdateEngine::CGravityUpdateEngine(void)
	: CUpdateEngineSuper()
	, m_Gravity(-9.8)
{
}

CGravityUpdateEngine::~CGravityUpdateEngine(void)
{
}

void CGravityUpdateEngine::Update(double dElaspedSec)
{
	for (CObjectSuper* pObject : Objs()->ObjectList)
	{
		if (0 == pObject->m_Weight)
			continue;

		pObject->m_VelY += m_Gravity * dElaspedSec;
	}
}
