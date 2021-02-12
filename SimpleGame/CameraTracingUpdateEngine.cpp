#include "stdafx.h"
#include "CameraTracingUpdateEngine.h"
#include "Camera.h"

CCameraTracingUpdateEngine::CCameraTracingUpdateEngine(void)
{
}

void CCameraTracingUpdateEngine::Update(double dElaspedSec)
{
	Camera()->m_CenterPosX += (Objs()->pPlayer->m_PosX - Camera()->m_CenterPosX) * dElaspedSec;
	Camera()->m_CenterPosY += (Objs()->pPlayer->m_PosY - Camera()->m_CenterPosY) * dElaspedSec;
}
