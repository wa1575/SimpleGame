#include "stdafx.h"
#include "PlayerObject.h"
#include "EffectObject.h"
#include "Ringobj.h"

CPlayerObject::CPlayerObject(void)
	: CPlayerFSM()
	, m_HP(10)
	, m_MP(0)
	, m_Dex(20)
	, m_Jump(10)
	, m_Power(30)
{
	m_Height = 1.8;
	m_Width = 0.5;
	m_Weight = 70;
}

CPlayerObject::~CPlayerObject(void)
{
}

void CPlayerObject::LookUp(void)
{
	m_nDirY = 1;
}

void CPlayerObject::LookDown(void)
{
	m_nDirY = -1;
}

void CPlayerObject::LookCenter(void)
{
	m_nDirY = 0;
}

void CPlayerObject::SkillA(void)
{
	CEffectObject* pEnergy = new CSmallEnergyObject(m_Power, m_PosX, m_PosY + m_Height * 0.9, m_VelX + 10 * m_nDirX, m_VelY + 10 * m_nDirY);
	Objs()->ObjectList.push_back(pEnergy);
}

void CPlayerObject::SkillB(void)
{
	CEffectObject* pEnergy = new CBigEnergyObject(m_Power, m_PosX, m_PosY + m_Height * 0.9, m_VelX + 5 * m_nDirX, m_VelY + 5 * m_nDirY);
	Objs()->ObjectList.push_back(pEnergy);
}

void CPlayerObject::SkillC(void)
{
	CBombObject* pBomb = new CBombObject(m_Power, m_PosX, m_PosY + m_Height * 1.1, m_VelX);
	Objs()->ObjectList.push_back(pBomb);
}

void CPlayerObject::onCollide(const CObjectSuper* pOther)
{
	const Ringobj* pRing = dynamic_cast<const Ringobj*>(pOther);
	if (nullptr == pRing)
		return;


	{
		Ringobj* pRingNaive = const_cast<Ringobj*>(pRing);
		m_HP -=  pRing->m_power;
		pRingNaive->OnLanded();
		CBombObject* pBomb = new CBombObject(m_Power, m_PosX, m_PosY + m_Height * 1.1, m_VelX);
		Objs()->ObjectList.push_back(pBomb);
	}

}
