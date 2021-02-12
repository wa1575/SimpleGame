#pragma once

#include "UpdateEngineSuper.h"

const int g_nPixelCountX = 60;
const int g_nPixelCountY = 20;

void DrawOnVideoMemory(double x, double y, double w, double h, char cPatch, std::vector<std::string>& refVideoMemory);

class CRenderer
{
	friend class CCamera;

	std::vector<std::string> m_VideoMemory;

	CRenderer(void);
	~CRenderer(void);

	void ClearVideoMemory();
	void FlushToGraphicMemory(void);

public:
	void Render(void);

	static CRenderer* GetInstance(void)
	{
		static CRenderer instance;
		return &instance;
	}
};

inline CRenderer* Renderer(void)
{
	return CRenderer::GetInstance();
}