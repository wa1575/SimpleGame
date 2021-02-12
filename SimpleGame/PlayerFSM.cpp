#include "stdafx.h"
#include "PlayerFSM.h"

CPlayerFSM::CPlayerFSM(void)
	: CObjectSuper()
	, m_nState(PLAYER_STATE_IDLE)
	, m_dwStopSignalTimeStamp(0)
{
}

CPlayerFSM::~CPlayerFSM(void)
{
}

void CPlayerFSM::OnLeftDown(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_LEFT_DOWN);
}

void CPlayerFSM::OnLeftUp(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_LEFT_UP);
}

void CPlayerFSM::OnRightDown(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_RIGHT_DOWN);
}

void CPlayerFSM::OnRightUp(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_RIGHT_UP);
}

void CPlayerFSM::OnLeftRightBothUp(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_LEFT_RIGHT_BOTH_UP);
}

void CPlayerFSM::OnUpDown(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_UP_DOWN);
}

void CPlayerFSM::OnLanded(void)
{
	m_nState = ChangeState(m_nState, PLAYER_EVENT_LANDED);
}

E_PLAYER_STATE CPlayerFSM::ChangeState(E_PLAYER_STATE nCurState, E_PLAYER_EVENT nEvent)
{
	const double jumpVel = 13;
	switch (nCurState)
	{
	case PLAYER_STATE_IDLE:
		if (PLAYER_EVENT_LEFT_DOWN == nEvent)
		{
			m_nDirX = -1;
			m_VelX = -5;
			return PLAYER_STATE_WALKING;
		}
		if (PLAYER_EVENT_RIGHT_DOWN == nEvent)
		{
			m_nDirX = 1;
			m_VelX = 5;
			return PLAYER_STATE_WALKING;
		}
		if (PLAYER_EVENT_UP_DOWN == nEvent)
		{
			m_VelY = jumpVel;
			return PLAYER_STATE_JUMPING;
		}
		break;

	case PLAYER_STATE_WALKING:
		if (PLAYER_EVENT_LEFT_DOWN == nEvent)
		{
			if (m_nDirX < 0)
			{
				m_VelX = -10;
				return PLAYER_STATE_RUNNING;
			}
			else
			{
				m_nDirX = -1;
				m_VelX = -5;
				return PLAYER_STATE_WALKING;
			}			
		}
		if (PLAYER_EVENT_RIGHT_DOWN == nEvent)
		{
			if (m_nDirX > 0)
			{
				m_VelX = 10;
				return PLAYER_STATE_RUNNING;
			}
			else
			{
				m_nDirX = 1;
				m_VelX = 5;
				return PLAYER_STATE_WALKING;
			}
		}
		if (PLAYER_EVENT_LEFT_RIGHT_BOTH_UP == nEvent)
		{
			if (0 == m_dwStopSignalTimeStamp)
				m_dwStopSignalTimeStamp = GetTickCount();

			DWORD dwElapsedTick = GetTickCount() - m_dwStopSignalTimeStamp;
			if (500 < dwElapsedTick)
			{
				m_VelX = 0;
				m_dwStopSignalTimeStamp = 0;
				return PLAYER_STATE_IDLE;
			}
		}
		if (PLAYER_EVENT_UP_DOWN == nEvent)
		{
			m_VelY = jumpVel;
			return PLAYER_STATE_JUMPING;
		}
		break;

	case PLAYER_STATE_RUNNING:
		if (PLAYER_EVENT_LEFT_RIGHT_BOTH_UP == nEvent)
		{
			m_VelX = 0;
			return PLAYER_STATE_IDLE;
		}
		if (PLAYER_EVENT_UP_DOWN == nEvent)
		{
			m_VelY = jumpVel;
			return PLAYER_STATE_JUMPING;
		}
		break;

	case PLAYER_STATE_JUMPING:
		/* 2단 점프 금지 
		if (PLAYER_EVENT_UP_DOWN == nEvent)
		{
			m_VelY = jumpVel;
			return PLAYER_STATE_DOUBLE_JUMPING;
		}*/ 
		if (PLAYER_EVENT_LANDED == nEvent)
		{
			return PLAYER_STATE_IDLE;
		}
		break;

	case PLAYER_STATE_DOUBLE_JUMPING:
		if (PLAYER_EVENT_LANDED == nEvent)
		{
			return PLAYER_STATE_IDLE;
		}
		break;

	case PLAYER_STATE_DIE:
		
		break;
	}
	return nCurState;
}
