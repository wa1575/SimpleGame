#pragma once

class CObjectSuper
{
	friend class CKeyInputEngine;
	friend class CRenderer;

	friend class CPositionUpdateEngine;
	friend class CGravityUpdateEngine;
	friend class CObjectUpdateEngine;
	friend class CCameraTracingUpdateEngine;
	friend class CCollisionDetectionEngine;
	friend bool CheckCollision(const CObjectSuper* a, const CObjectSuper* b);

protected:
	double	m_PosX		;
	double	m_PosY		;
	double	m_VelX		;
	double	m_VelY		;
	double	m_Height	;
	double	m_Width		;
	double	m_Weight	;
	char	m_cPatch	;

	int m_nDirX;
	int m_nDirY;

	CObjectSuper(void);

public:
	virtual ~CObjectSuper(void);

	virtual bool IsDestroyed(void);
	virtual void OnUpdate(double dElapsedSec);
	virtual void OnLanded(void);
	virtual void onCollide(const CObjectSuper* pOther);
};

