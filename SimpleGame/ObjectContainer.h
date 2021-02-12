#pragma once

#include <list>
#include "ObjectSuper.h"
#include "BillboardSuper.h"
#include "PlayerObject.h"

class CObjectContainer
{
	CObjectContainer(void);
	~CObjectContainer(void);

public:
	std::list<CBillboardSuper*> BackBillboardList;
	std::list<CBillboardSuper*> FrontBillboardList;

	std::list<CObjectSuper*> ObjectList;
	CPlayerObject* pPlayer;

	void DestroyAll(void);
	void AddBackBillboard(CBillboardSuper* pNewBillboad);
	void AddFrontBillboard(CBillboardSuper* pNewBillboad);
	void AddObject(CObjectSuper* pNewObject);

	static CObjectContainer* GetInstance(void)
	{
		static CObjectContainer instance;
		return &instance;
	}
};

inline CObjectContainer* Objs(void)
{
	return CObjectContainer::GetInstance();
}
