#pragma once

#include "UpdateEngineSuper.h"


class CCollisionDetectionEngine : public CUpdateEngineSuper
{
public:
	CCollisionDetectionEngine(void);
	~CCollisionDetectionEngine(void);

private:
	void Update(double dElaspedSec);

};

