#pragma once

#include "ObjectSuper.h"

enum E_PLAYER_STATE
{
	PLAYER_STATE_IDLE = 0,
	PLAYER_STATE_WALKING,
	PLAYER_STATE_RUNNING,
	PLAYER_STATE_JUMPING,
	PLAYER_STATE_DOUBLE_JUMPING,
	PLAYER_STATE_DIE,
};

enum E_PLAYER_EVENT
{
	PLAYER_EVENT_LEFT_DOWN,	// = 0
	PLAYER_EVENT_LEFT_UP,
	PLAYER_EVENT_RIGHT_DOWN,
	PLAYER_EVENT_RIGHT_UP,
	PLAYER_EVENT_LEFT_RIGHT_BOTH_UP,
	PLAYER_EVENT_UP_DOWN,
	PLAYER_EVENT_LANDED,
};

class CPlayerFSM
	: public CObjectSuper
{
	E_PLAYER_STATE m_nState;
	DWORD m_dwStopSignalTimeStamp;

public:
	CPlayerFSM(void);
	~CPlayerFSM(void);

	void OnLeftDown(void);
	void OnLeftUp(void);
	void OnRightDown(void);
	void OnRightUp(void);
	void OnLeftRightBothUp(void);
	void OnUpDown(void);
	void OnLanded(void);

private:
	E_PLAYER_STATE ChangeState(E_PLAYER_STATE nCurState, E_PLAYER_EVENT nEvent);
};

