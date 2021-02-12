#pragma once

#include "UpdateEngineSuper.h"

class CObjectUpdateEngine : public CUpdateEngineSuper
{
public:
	CObjectUpdateEngine(void);
	~CObjectUpdateEngine(void);

	void Update(double dElaspedSec);
};

