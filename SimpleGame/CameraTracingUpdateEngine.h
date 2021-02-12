#pragma once

#include "UpdateEngineSuper.h"

class CCameraTracingUpdateEngine : public CUpdateEngineSuper
{
public:
	CCameraTracingUpdateEngine(void);
	void Update(double dElaspedSec);
};

