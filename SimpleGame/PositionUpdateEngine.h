#pragma once

#include "UpdateEngineSuper.h"

class CPositionUpdateEngine : public CUpdateEngineSuper
{
public:
	CPositionUpdateEngine(void);
	~CPositionUpdateEngine(void);

	void Update(double dElaspedSec);
};

