#include "stdafx.h"
#include "ObjectContainer.h"

CObjectContainer::CObjectContainer(void)
	: ObjectList()
	, pPlayer(nullptr)
{
}

CObjectContainer::~CObjectContainer(void)
{
}

void CObjectContainer::DestroyAll(void)
{
	for (auto iter = BackBillboardList.begin(); iter != BackBillboardList.end(); iter++)
		delete* iter;
	BackBillboardList.clear();

	for (auto iter = FrontBillboardList.begin(); iter != FrontBillboardList.end(); iter++)
		delete* iter;
	FrontBillboardList.clear();

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); iter++)
		delete *iter;
	ObjectList.clear();
}

void CObjectContainer::AddBackBillboard(CBillboardSuper* pNewBillboad)
{
	BackBillboardList.push_back(pNewBillboad);
}

void CObjectContainer::AddFrontBillboard(CBillboardSuper* pNewBillboad)
{
	FrontBillboardList.push_back(pNewBillboad);
}

void CObjectContainer::AddObject(CObjectSuper* pNewObject)
{
	ObjectList.push_back(pNewObject);
}
