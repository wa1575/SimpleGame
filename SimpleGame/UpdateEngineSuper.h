#pragma once

class CUpdateEngineSuper
{
protected:
	CUpdateEngineSuper(void);

public:
	virtual ~CUpdateEngineSuper(void);
	virtual void Update(double dElaspedSec) = 0;
};

