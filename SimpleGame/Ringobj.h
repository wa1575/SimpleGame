#pragma once

#include "ObjectSuper.h"

class Ringobj : public CObjectSuper
{

public:
	double m_hp;
	double m_power;

	Ringobj(void);
	~Ringobj(void);


private:
	bool IsDestroyed(void);
	void OnUpdate(double dElapsedSec);
    //void OnLanded(void);
	void onCollide(const CObjectSuper* pOther);
};

