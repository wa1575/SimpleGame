#include "stdafx.h"
#include "PositionUpdateEngine.h"

CPositionUpdateEngine::CPositionUpdateEngine(void)
{
}

CPositionUpdateEngine::~CPositionUpdateEngine(void)
{

}

void CPositionUpdateEngine::Update(double dElaspedSec)
{
	for (CObjectSuper* pObject : Objs()->ObjectList)
	{
		// 가속도 처리
		pObject->m_PosX += pObject->m_VelX * dElaspedSec;
		pObject->m_PosY += pObject->m_VelY * dElaspedSec;

		// 무게가 있는 물체들만 물리법칙 적용
		if (0 < pObject->m_Weight)
		{
			// 지면에 착지
			if (pObject->m_PosY < 0)
			{
				pObject->m_PosY = 0;
				pObject->m_VelY = 0;
				pObject->OnLanded();
			}
		}
	}
}
