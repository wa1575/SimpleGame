#include "stdafx.h"
#include "Ringobj.h"
#include "EffectObject.h"
#include "Renderer.h"


Ringobj::Ringobj(void)
	:  m_hp(30)
	,m_power(30)
{
	double randX = ( rand() % 20 + 1) * 20 ; //최소 20m 간격
		
	//viewport로 링 그리는 방법?
		m_PosX += randX;
		m_PosY = 3;
		m_VelX = -2;
		m_VelY = 0;
		m_Height = 2;
		m_Width = 1;
		m_Weight = 0;
		m_cPatch = '$';

}

Ringobj::~Ringobj(void)
{
}

bool Ringobj::IsDestroyed(void)
{
	return m_hp <= 0.0;
	system("pause");
}

void Ringobj::OnUpdate(double dElapsedSec)
{
}

/*
void Ringobj::OnLanded(void)
{
}
*/

void Ringobj::onCollide(const CObjectSuper* pOther)
{
	const CBombObject* pBomb = dynamic_cast<const CBombObject*>(pOther);
	if (nullptr == pBomb)
		return;
	{
		CBombObject* pBombNaive = const_cast<CBombObject*>(pBomb);
	    m_hp -= pBomb->m_Power;
		pBombNaive->OnLanded();
	}
}
