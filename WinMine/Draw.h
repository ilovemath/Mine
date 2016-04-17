#pragma once
#include "resource.h"

class CDraw
{
public:
	CDraw();
	CDraw(UINT id);
	~CDraw(void);
private:
	//位图对象
	CBitmap bitmap;
protected:
	//窗口句柄
	HWND hWnd;
	//坐标原点
	CPoint origin;
public:
	void SetBitmap(UINT id);
	void SetOrigin(CPoint origin);
	void SetHwnd(HWND hWnd);
	void Draw(CDC *pDC, CRect dst, CRect src, DWORD dwRop = SRCCOPY);

	virtual void Draw(CDC *pDC) = 0;
	virtual void Invalidate(bool bErase = false) = 0;
};
