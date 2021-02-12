#pragma once

#include "Struct.h"
#include "ObjectSuper.h"

class CBillboardSuper : public CObjectSuper
{
public:
	CBillboardSuper(void);
	~CBillboardSuper(void);

	virtual void OnDraw(const ST_VIEWPORT& viewport, std::vector<std::string>& refVideoMemory) = 0;
};

