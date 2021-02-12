#include "stdafx.h"
#include "CollisionDetectionEngine.h"

CCollisionDetectionEngine::CCollisionDetectionEngine(void)
{
}

CCollisionDetectionEngine::~CCollisionDetectionEngine(void)
{
}


bool CheckCollision(const CObjectSuper* a, const CObjectSuper* b)
{
	double leftForA = a->m_PosX - a->m_Width * 0.5;
	double rightForA = a->m_PosX + a->m_Width * 0.5;
	double topForA = a->m_PosY + a->m_Height;
	double bottomForA = a->m_PosY;

	double leftForB = b->m_PosX - b->m_Width * 0.5;
	double rightForB = b->m_PosX + b->m_Width * 0.5;
	double topForB = b->m_PosY + b->m_Height;
	double bottomForB = b->m_PosY;


	if( rightForA < leftForB)
		return false;

	if (topForB <  bottomForA)
		return false;

	if (rightForB < leftForA)
		return false;

	if (topForA < bottomForB)
		return false;

	return true;
}

void CCollisionDetectionEngine::Update(double dElaspedSec)
{
	for (CObjectSuper* pObjectA : Objs()->ObjectList)
	{
		for (CObjectSuper* pObjectB : Objs()->ObjectList)
		{
			if (pObjectA == pObjectB)
				continue;
			if (!CheckCollision(pObjectA, pObjectB))
				continue; //depth ÃÖ´ëÇÑ Âª°Ô 
			
				pObjectA->onCollide(pObjectB);
				pObjectB->onCollide(pObjectA);
			
		}
	}
}
