#pragma once
#include "Draw.h"

class CFace :
	public CDraw, public CTexture
{
public:
	CFace();
	~CFace();
public:
	bool PtInFace(CPoint&point);			//当前点是否在区域中

	void Draw(CDC *pDC);
	void Invalidate(bool bErase = false);	//使区域无效	

};

