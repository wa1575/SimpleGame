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
		// ���ӵ� ó��
		pObject->m_PosX += pObject->m_VelX * dElaspedSec;
		pObject->m_PosY += pObject->m_VelY * dElaspedSec;

		// ���԰� �ִ� ��ü�鸸 ������Ģ ����
		if (0 < pObject->m_Weight)
		{
			// ���鿡 ����
			if (pObject->m_PosY < 0)
			{
				pObject->m_PosY = 0;
				pObject->m_VelY = 0;
				pObject->OnLanded();
			}
		}
	}
}
