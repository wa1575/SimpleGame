#pragma once

#include <map>

class CKeyInputEngine
{
	std::map<int, short> m_mapKey;

	CKeyInputEngine(void);
	~CKeyInputEngine(void);

	bool IsKeyDown(int nVirtKey);
	bool IsKeyUp(int nVirtKey);
	bool IsKeyPressing(int nVirtKey);

public:
	void Update(double dElaspedSec);

	static CKeyInputEngine* GetInstance(void)
	{
		static CKeyInputEngine instance;
		return &instance;
	}
};

inline CKeyInputEngine* KeyInput(void)
{
	return CKeyInputEngine::GetInstance();
}