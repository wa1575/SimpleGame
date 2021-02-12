#pragma once

class CCamera
{
	friend class CCameraTracingUpdateEngine;

	double m_Scale;
	double m_CenterPosX;
	double m_CenterPosY;

	CCamera(void);
	~CCamera(void);

public:
	void Zoom(double scale);
	void MoveVertical(double diff);
	void MoveHorizontal(double diff);

	void QueryViewport(ST_VIEWPORT& viewport);

	static CCamera* GetInstance(void)
	{
		static CCamera instance;
		return &instance;
	}
};

inline CCamera* Camera(void)
{
	return CCamera::GetInstance();
}