#pragma once
#include "Draw.h"
#include "Picture.h"

class CFace :
	public CDraw, public CPicture
{
public:
	CFace();
	~CFace();
public:
	void Draw(CDC *pDC);
	void Invalidate(bool bErase = false);//使区域无效
	

};

