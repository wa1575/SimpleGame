#include "stdafx.h"
#include "Camera.h"
#include "ObjectContainer.h"
#include "Renderer.h"

CCamera::CCamera(void)
: m_Scale(1)
, m_CenterPosX(0)
, m_CenterPosY(0)
{
}

CCamera::~CCamera(void)
{
}

void CCamera::Zoom(double scale)
{
	m_Scale += scale;
}

void CCamera::MoveVertical(double diff)
{
	m_CenterPosY += diff;
}

void CCamera::MoveHorizontal(double diff)
{
	m_CenterPosX += diff;
}

void CCamera::QueryViewport(ST_VIEWPORT& viewport)
{
	viewport.left = m_CenterPosX - g_nPixelCountX * 0.5 * m_Scale;
	viewport.right = m_CenterPosX + g_nPixelCountX * 0.5 * m_Scale;
	viewport.top = m_CenterPosY + g_nPixelCountY * 0.5 * m_Scale;
	viewport.bottom = m_CenterPosY - g_nPixelCountY * 0.5 * m_Scale;
	viewport.cx = m_CenterPosX;
	viewport.cy = m_CenterPosY;
	viewport.scale = m_Scale;
}
