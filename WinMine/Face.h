#pragma once
#include "Draw.h"

class CFace :
	public CDraw, public CTexture
{
public:
	CFace();
	~CFace();
public:
	bool PtInFace(CPoint&point);			//��ǰ���Ƿ���������

	void Draw(CDC *pDC);
	void Invalidate(bool bErase = false);	//ʹ������Ч	

};

