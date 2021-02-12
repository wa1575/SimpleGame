#include "stdafx.h"
#include "ObjectUpdateEngine.h"

CObjectUpdateEngine::CObjectUpdateEngine(void)
{
}

CObjectUpdateEngine::~CObjectUpdateEngine(void)
{
}

void CObjectUpdateEngine::Update(double dElaspedSec)
{
	for (CBillboardSuper* pBillboard : Objs()->BackBillboardList)
		pBillboard->OnUpdate(dElaspedSec);

	for (CBillboardSuper* pBillboard : Objs()->FrontBillboardList)
		pBillboard->OnUpdate(dElaspedSec);

	for (CObjectSuper* pObject : Objs()->ObjectList)
		pObject->OnUpdate(dElaspedSec);

	bool bEraseFound = true;
	do
	{
		bEraseFound = false;
		for (CObjectSuper* pObject : Objs()->ObjectList)
		{
			if (!pObject->IsDestroyed())
				continue;

			Objs()->ObjectList.remove(pObject);
			bEraseFound = true;
			break;
		}
	} while (bEraseFound);
}
