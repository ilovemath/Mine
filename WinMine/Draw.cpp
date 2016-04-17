#include "stdafx.h"
#include "Draw.h"

CDraw::CDraw()
{
	bitmap.LoadBitmap(IDB_VISTA_BLUE_MINE);
}

CDraw::CDraw(UINT id)
{
	bitmap.LoadBitmap(id);
}

CDraw::~CDraw(void)
{
}

void CDraw::SetOrigin(CPoint origin)
{
	this->origin = origin;
}

void CDraw::SetHwnd(HWND hWnd)
{
	this->hWnd = hWnd;
}

void CDraw::SetBitmap(UINT id)
{
	bitmap.LoadBitmap(id);
}


void CDraw::Draw(CDC *pDC, CRect dst, CRect src, DWORD dwRop)
{
	CDC Dc;
	if (Dc.CreateCompatibleDC(pDC) == FALSE)
	{
		AfxMessageBox(L"Cannot Create Dc");
		return;
	}
	Dc.SelectObject(bitmap);
	//dst.OffsetRect(origin);
	pDC->StretchBlt(dst.left, dst.top, dst.Width(), dst.Height(), &Dc,
		src.left, src.top, src.Width(), src.Height(), dwRop);
}
