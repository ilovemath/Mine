#pragma once
#include "Texture.h"
class CDraw
{
public:
	CDraw(void);
	~CDraw(void);
protected:
	//����ԭ��
	CRect rect;
	CPoint origin;
	//���ھ��
public:
	static HWND hWnd;
	void SetOrigin(CPoint &origin);
	void SetCenterPoint(int x,int y);
	void SetCenterPoint(CPoint point);
	void Draw(CDC *pDC, CRect &pos, CTexture &texture, DWORD dwRop = SRCCOPY);

	virtual void Draw(CDC *pDC) = 0;
	virtual void Invalidate(bool bErase = false) = 0;
};
