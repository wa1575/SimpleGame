#pragma once

#include "ObjectSuper.h"

class CEffectObject : public CObjectSuper
{
	double m_Power;
	DWORD m_dwTimeOutTick;

public:
	CEffectObject(double power, double size, double x, double y, double vx, double vy, double duration);
	bool IsDestroyed(void);
};

class CSmallEnergyObject : public CEffectObject
{
public:
	CSmallEnergyObject(double power, double x, double y, double vx, double vy);
};

class CBigEnergyObject : public CEffectObject
{
public:
	CBigEnergyObject(double power, double x, double y, double vx, double vy);
};

class CBombObject : public CObjectSuper
{
public:
	double m_Power;
	bool m_bDestroyed;


	CBombObject(double power, double x, double y, double vx);

	bool IsDestroyed(void);
	void OnLanded(void);
};


class CExplodingObject : public CEffectObject
{
	double m_Power;

public:
	CExplodingObject(double power, double x, double y);

	bool IsDestroyed(void);
	void OnUpdate(double dElapsedSec);
};
