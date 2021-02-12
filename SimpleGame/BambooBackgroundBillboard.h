#pragma once

#include "BillboardSuper.h"

class CBambooBackgroundBillboard : public CBillboardSuper
{
public:
	CBambooBackgroundBillboard(void);
	~CBambooBackgroundBillboard(void);

private:
	void OnDraw(const ST_VIEWPORT& viewport, std::vector<std::string>& refVideoMemory);
};

