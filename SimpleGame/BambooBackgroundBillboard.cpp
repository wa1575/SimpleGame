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
	
	// ���, 1m ���� �볪��
	for (int i = (int)viewport.left; i < (int)viewport.right + 5; i++)
	{
		double dTempX = (int)(i / 10) * 10.0;	// 10 ���� ���� ����

		double x = dTempX - viewport.cx;
		double y = 10 - viewport.cy;
		double h = 0.1 * viewport.scale;
		double w = 0.2 * viewport.scale;

		DrawOnVideoMemory(x, y, w, h, '-', refVideoMemory);
	}

	// �ణ ���ʹ��, ���� 50m ���� �볪��
	const double outscale = 0.7;
	for (int i = (int)(viewport.left / outscale); 
		i < (int)((viewport.right + 5)/ outscale); i++)
	{
		double dTempX = (int)(i / 10) * 10.0;	// 10 ���� ���� ����

		double x = dTempX - viewport.cx * outscale;
		double y = 11 - viewport.cy * outscale;
		double h = 0.5 * viewport.scale * outscale;
		double w = 0.2 * viewport.scale * outscale;

		DrawOnVideoMemory(x, y, w, h, 'O', refVideoMemory);
	}
	
}
