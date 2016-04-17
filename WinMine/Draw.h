#pragma once
#include "resource.h"

class CDraw
{
public:
	CDraw();
	CDraw(UINT id);
	~CDraw(void);
private:
	//λͼ����
	CBitmap bitmap;
protected:
	//���ھ��
	HWND hWnd;
	//����ԭ��
	CPoint origin;
public:
	void SetBitmap(UINT id);
	void SetOrigin(CPoint origin);
	void SetHwnd(HWND hWnd);
	void Draw(CDC *pDC, CRect dst, CRect src, DWORD dwRop = SRCCOPY);

	virtual void Draw(CDC *pDC) = 0;
	virtual void Invalidate(bool bErase = false) = 0;
};
