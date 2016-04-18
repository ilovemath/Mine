#pragma once
#include "Texture.h"
class CDraw
{
public:
	CDraw(void);
	~CDraw(void);
protected:
	//坐标原点
	CRect rect;
	CPoint origin;
	//窗口句柄
public:
	static HWND hWnd;
	void SetOrigin(CPoint &origin);
	void SetCenterPoint(int x,int y);
	void SetCenterPoint(CPoint point);
	void Draw(CDC *pDC, CRect &pos, CTexture &texture, DWORD dwRop = SRCCOPY);

	virtual void Draw(CDC *pDC) = 0;
	virtual void Invalidate(bool bErase = false) = 0;
};
