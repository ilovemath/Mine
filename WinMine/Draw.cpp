#include "stdafx.h"
#include "Draw.h"

HWND CDraw::hWnd = NULL;

CDraw::CDraw()
{
	origin = CPoint(0, 0);
}

CDraw::~CDraw(void)
{
}

void CDraw::SetOrigin(CPoint &origin)
{
	rect.MoveToXY(origin);
	this->origin = origin;
}

void CDraw::SetCenterPoint(int x, int y)
{
	SetCenterPoint(CPoint(x, y));
}

void CDraw::SetCenterPoint(CPoint point)
{
	int w = -rect.Width();
	int h = -rect.Height();
	point.Offset(w / 2, h / 2);
	SetOrigin(point);
}

void CDraw::Draw(CDC *pDC, CRect &pos, CTexture &texture, DWORD dwRop)
{
	CDC Dc;
	if (Dc.CreateCompatibleDC(pDC) == FALSE)
	{
		AfxMessageBox(L"Cannot Create Dc");
		return;
	}
	Dc.SelectObject(texture.bitmap);
	CRect &src = texture.GetIconRect();
	pDC->StretchBlt(pos.left, pos.top, pos.Width(), pos.Height(), &Dc,
		src.left, src.top, src.Width(), src.Height(), dwRop);
}
