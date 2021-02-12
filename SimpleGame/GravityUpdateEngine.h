#pragma once

#include "UpdateEngineSuper.h"

class CGravityUpdateEngine : public CUpdateEngineSuper
{
	double m_Gravity;

public:
	CGravityUpdateEngine(void);
	~CGravityUpdateEngine(void);

	void Update(double dElaspedSec);
};

