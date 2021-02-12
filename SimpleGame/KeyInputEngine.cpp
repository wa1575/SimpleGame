#include "stdafx.h"
#include "KeyInputEngine.h"
#include "PlayerObject.h"
#include "ObjectContainer.h"
#include "Camera.h"

CKeyInputEngine::CKeyInputEngine(void)
{
}

CKeyInputEngine::~CKeyInputEngine(void)
{
}

bool CKeyInputEngine::IsKeyDown(int nVirtKey)
{
	short nKeyState = GetKeyState(nVirtKey);

	bool bRet = false;
	if (m_mapKey.end() == m_mapKey.find(nVirtKey))
		bRet = false;
	else
	{
		bool bPressingBefore = m_mapKey[nVirtKey] & 0x8000;
		bool bPressingCurrent = nKeyState & 0x8000;
		bRet = !bPressingBefore && bPressingCurrent;
	}

	// WARNING: m_mapKey.insert(std::make_pair(nVirtKey, nKeyState));
	// 위와 같이 사용하면 기존의 값을 갱신할 수 없음
	m_mapKey[nVirtKey] = nKeyState;
	return bRet;
}

bool CKeyInputEngine::IsKeyUp(int nVirtKey)
{
	short nKeyState = GetKeyState(nVirtKey);

	bool bPressingBefore = m_mapKey[nVirtKey] & 0x8000;
	bool bPressingCurrent = nKeyState & 0x8000;
	bool bRet = bPressingBefore && !bPressingCurrent;

	m_mapKey[nVirtKey] = nKeyState;
	return bRet;
}

bool CKeyInputEngine::IsKeyPressing(int nVirtKey)
{
	return GetKeyState(nVirtKey) & 0x8000;
}

void CKeyInputEngine::Update(double dElaspedSec)
{
	// 캐릭터 이동
	for (CObjectSuper* pObject : Objs()->ObjectList)
	{
		CPlayerObject* pPlayer = dynamic_cast<CPlayerObject*>(pObject);
		if (nullptr == pPlayer)
			continue;

		if (IsKeyDown('A'))			pPlayer->OnLeftDown();
		if (IsKeyDown('D'))			pPlayer->OnRightDown();
		if (IsKeyUp('A'))			pPlayer->OnLeftUp();
		if (IsKeyUp('D'))			pPlayer->OnRightUp();
		if (!IsKeyPressing('A')	&& !IsKeyPressing('D'))
									pPlayer->OnLeftRightBothUp();

		if (IsKeyPressing('W'))			pPlayer->LookUp();
		if (IsKeyPressing('S'))			pPlayer->LookDown();
		if (!IsKeyPressing('W') && !IsKeyPressing('S'))	pPlayer->LookCenter();

		if (IsKeyDown(' '))				pPlayer->OnUpDown();

		if (IsKeyDown('G'))				pPlayer->SkillA();
		if (IsKeyDown(VK_RBUTTON))		pPlayer->SkillB();
		if (IsKeyDown('H'))				pPlayer->SkillC();
	}

	// 카메라 이동
	{
		if (IsKeyPressing(VK_LEFT))		Camera()->MoveHorizontal(-15.0 * dElaspedSec);
		if (IsKeyPressing(VK_RIGHT))	Camera()->MoveHorizontal(15.0 * dElaspedSec);
		if (IsKeyPressing(VK_DOWN))		Camera()->MoveVertical(-15.0 * dElaspedSec);
		if (IsKeyPressing(VK_UP))		Camera()->MoveVertical(15.0 * dElaspedSec);
		if (IsKeyPressing(VK_HOME))		Camera()->Zoom(5.0 * dElaspedSec);
		if (IsKeyPressing(VK_END))		Camera()->Zoom(-5.0 * dElaspedSec);
	}
}
