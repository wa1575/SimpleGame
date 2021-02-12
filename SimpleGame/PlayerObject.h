#pragma once

#include "PlayerFSM.h"

class CPlayerObject
	: public CPlayerFSM
{
	double m_HP;
	double m_MP;
	double m_Dex;
	double m_Jump;
	double m_Power;

public:
	CPlayerObject(void);
	~CPlayerObject(void);

	void LookUp(void);
	void LookDown(void);
	void LookCenter(void);

	void SkillA(void);
	void SkillB(void);
	void SkillC(void);

	void onCollide(const CObjectSuper* pOthe);
};

