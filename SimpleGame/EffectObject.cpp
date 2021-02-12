#include "stdafx.h"
#include "EffectObject.h"

CEffectObject::CEffectObject(double power, double size, double x, double y, double vx, double vy, double duration)
	: CObjectSuper()
	, m_Power(power)
{
	m_Width = size;
	m_Height = size;
	m_PosX = x;
	m_PosY = y;
	m_VelX = vx;
	m_VelY = vy;
	m_Weight = 0;
	m_cPatch = '+';

	m_dwTimeOutTick = GetTickCount() + (DWORD)(duration * 1000);
}

bool CEffectObject::IsDestroyed(void)
{
	return m_dwTimeOutTick < GetTickCount();
}

CBombObject::CBombObject(double power, double x, double y, double vx)
	: CObjectSuper()
	, m_Power(power)
	, m_bDestroyed(false)
{
	m_Width = 0.2;
	m_Height = 0.2;
	m_PosX = x;
	m_PosY = y;
	m_VelX = vx;
	m_VelY = 5;
	m_Weight = 1;
	m_cPatch = '#';
}

bool CBombObject::IsDestroyed(void)
{
	return m_bDestroyed;
}

void CBombObject::OnLanded(void)
{
	m_bDestroyed = true;
	Objs()->AddObject(new CExplodingObject(m_Power, m_PosX, m_PosY));
}

CExplodingObject::CExplodingObject(double power, double x, double y)
	: CEffectObject(0, 1, x, y, 0, 0, 1)
	, m_Power(power)
{
	m_cPatch = 'o';
}

bool CExplodingObject::IsDestroyed(void)
{
	return m_Power < m_Width;
}

void CExplodingObject::OnUpdate(double dElapsedSec)
{
	m_Width += m_Power * dElapsedSec;
	m_Height += m_Power * dElapsedSec;
}

CSmallEnergyObject::CSmallEnergyObject(double power, double x, double y, double vx, double vy)
	: CEffectObject(power * 0.5, 0.5, x, y, vx, vy, 2)
{
	m_cPatch = vx < 0 ? '<' : '>';
}

CBigEnergyObject::CBigEnergyObject(double power, double x, double y, double vx, double vy)
	: CEffectObject(power * 1, 1, x, y, vx, vy, 1)
{
	m_cPatch = vx < 0 ? '<' : '>';
}
