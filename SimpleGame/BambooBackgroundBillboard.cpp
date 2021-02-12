#include "stdafx.h"
#include "BambooBackgroundBillboard.h"
#include "Renderer.h"

CBambooBackgroundBillboard::CBambooBackgroundBillboard(void)
{
}

CBambooBackgroundBillboard::~CBambooBackgroundBillboard(void)
{
}

void CBambooBackgroundBillboard::OnDraw(const ST_VIEWPORT& viewport, std::vector<std::string>& refVideoMemory)
{
	
	// 배경, 1m 마다 대나무
	for (int i = (int)viewport.left; i < (int)viewport.right + 5; i++)
	{
		double dTempX = (int)(i / 10) * 10.0;	// 10 단위 이하 절삭

		double x = dTempX - viewport.cx;
		double y = 10 - viewport.cy;
		double h = 0.1 * viewport.scale;
		double w = 0.2 * viewport.scale;

		DrawOnVideoMemory(x, y, w, h, '-', refVideoMemory);
	}

	// 약간 뒤쪽배경, 역시 50m 마다 대나무
	const double outscale = 0.7;
	for (int i = (int)(viewport.left / outscale); 
		i < (int)((viewport.right + 5)/ outscale); i++)
	{
		double dTempX = (int)(i / 10) * 10.0;	// 10 단위 이하 절삭

		double x = dTempX - viewport.cx * outscale;
		double y = 11 - viewport.cy * outscale;
		double h = 0.5 * viewport.scale * outscale;
		double w = 0.2 * viewport.scale * outscale;

		DrawOnVideoMemory(x, y, w, h, 'O', refVideoMemory);
	}
	
}
