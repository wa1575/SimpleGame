#include "stdafx.h"
#include "KeyInputEngine.h"
#include "UpdateEngineSuper.h"
#include "GravityUpdateEngine.h"
#include "ObjectUpdateEngine.h"
#include "PositionUpdateEngine.h"
#include "Camera.h"
#include "Renderer.h"
#include "PlayerObject.h"
#include "EffectObject.h"
#include "ObjectContainer.h"
#include "PlainLandObject.h"
#include "BambooBackgroundBillboard.h"
#include "CameraTracingUpdateEngine.h"
#include "Ringobj.h"
#include "CollisionDetectionEngine.h"

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}


int main()
{
	std::vector<CUpdateEngineSuper*> vecUpdateEngine;
	vecUpdateEngine.push_back(new CObjectUpdateEngine());
	vecUpdateEngine.push_back(new CGravityUpdateEngine());
	vecUpdateEngine.push_back(new CPositionUpdateEngine());
	vecUpdateEngine.push_back(new CCollisionDetectionEngine());
	vecUpdateEngine.push_back(new CCameraTracingUpdateEngine());

	Objs()->pPlayer = new CPlayerObject();
	Objs()->AddObject(new CPlainLandObject());
	Objs()->AddObject(Objs()->pPlayer);

	for (int i = 0; i < 20; i++)
	{
		Objs()->AddObject(new Ringobj());
	}
	Objs()->AddBackBillboard(new CBambooBackgroundBillboard());

	const DWORD dwFPS = 30;
	const DWORD dwTickPerFrame = 1000 / dwFPS;
	const double dFrameElaspedSec = 1.0 / dwFPS;

	DWORD dwLastTick = GetTickCount();
	while (true)
	{
		const DWORD dwCurrentTick = GetTickCount();
		const DWORD dwElapsedTick = dwLastTick < dwCurrentTick ? (dwCurrentTick - dwLastTick) : 0;
		const DWORD dwRemainedTick = dwElapsedTick < dwTickPerFrame ? (dwTickPerFrame - dwElapsedTick) : 0;

		dwLastTick += dwTickPerFrame;

		KeyInput()->Update(dFrameElaspedSec);
		//for (CUpdateEngineSuper* pUpdateEngine : vecUpdateEngine)
		//	pUpdateEngine->Update(dFrameElaspedSec);
		//for (size_t i=0; i<vecUpdateEngine.size(); i++)
		//	vecUpdateEngine[i]->Update(dFrameElaspedSec);
		//for (std::vector<CUpdateEngineSuper*>::iterator iter=vecUpdateEngine.begin();
		//	iter!=vecUpdateEngine.end();
		//	iter++)
		//	(*iter)->Update(dFrameElaspedSec);
		for (auto iter = vecUpdateEngine.begin(); iter != vecUpdateEngine.end(); iter++)
			(*iter)->Update(dFrameElaspedSec);

		// 너무 빠르면 딜레이를 줌
		if (0 < dwRemainedTick)
			Sleep(dwRemainedTick);

		// 너무 느리면 그리기 생략
		if (dwTickPerFrame < dwElapsedTick)
			continue;


		Renderer()->Render();
	}

	Objs()->DestroyAll();
	for (size_t i = 0; i < vecUpdateEngine.size(); i++)
		delete vecUpdateEngine[i];
	vecUpdateEngine.clear();

	return 0;
}
