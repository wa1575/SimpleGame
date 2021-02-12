#include "stdafx.h"
#include "Renderer.h"
#include "ObjectContainer.h"
#include "Camera.h"

CRenderer::CRenderer(void)
	: m_VideoMemory()
{
	m_VideoMemory.resize(g_nPixelCountY);

	for (std::string& strLine : m_VideoMemory)
		strLine.resize(g_nPixelCountX);

	{
		// 콘솔 커서 숨기기(윈도우 API)
		CONSOLE_CURSOR_INFO cursorInfo = { 0, };
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	}
	
	{
		// ANSI Escape sequence 지원 모드
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
}

CRenderer::~CRenderer(void)
{
}

void CRenderer::Render(void)
{
	ClearVideoMemory();

	ST_VIEWPORT viewport;
	Camera()->QueryViewport(viewport);

	for (CBillboardSuper* pBillboard : Objs()->BackBillboardList)
		pBillboard->OnDraw(viewport, m_VideoMemory);

	for (CObjectSuper* pObject : Objs()->ObjectList)
	{
		double x = pObject->m_PosX - viewport.cx;
		double y = pObject->m_PosY - viewport.cy;
		double h = pObject->m_Height * viewport.scale;
		double w = pObject->m_Width * viewport.scale;

		DrawOnVideoMemory(x, y, w, h, pObject->m_cPatch, m_VideoMemory);
	}

	for (CBillboardSuper* pBillboard : Objs()->FrontBillboardList)
		pBillboard->OnDraw(viewport, m_VideoMemory);

	FlushToGraphicMemory();
}

void CRenderer::ClearVideoMemory()
{
	for (std::string& strLine : m_VideoMemory)
		memset((void*)strLine.c_str(), ' ', strLine.size());
}

void CRenderer::FlushToGraphicMemory(void)
{
	// ANSI Escape sequence
	// 참고: http://ascii-table.com/ansi-escape-sequences-vt-100.php
	printf("\x1b[H");
	for (std::string& strLine : m_VideoMemory)
		printf("%s\n", strLine.c_str());
}

void DrawOnVideoMemory(double x, double y, double w, double h, char cPatch, std::vector<std::string>& refVideoMemory)
{
	int nLeft = (int)(x - w / 2) + (g_nPixelCountX / 2);
	int nRight = (int)(x + w / 2) + (g_nPixelCountX / 2);
	int nTop = -(int)(y + h) + (g_nPixelCountY / 2);
	int nBottom = -(int)(y)+(g_nPixelCountY / 2);

	if (nRight < 0)
		return;
	if (g_nPixelCountX <= nLeft)
		return;
	if (nBottom < 0)
		return;
	if (g_nPixelCountY <= nTop)
		return;

	nLeft = std::max<int>(0, nLeft);
	nTop = std::max<int>(0, nTop);
	nRight = std::min<int>(g_nPixelCountX - 1, nRight);
	nBottom = std::min<int>(g_nPixelCountY - 1, nBottom);

	for (int y = nTop; y <= nBottom; y++)
	{
		char* pLine = (char*)refVideoMemory[y].c_str();

		for (int x = nLeft; x <= nRight; x++)
			pLine[x] = cPatch;
	}
}