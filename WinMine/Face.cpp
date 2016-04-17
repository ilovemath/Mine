#include "stdafx.h"
#include "Face.h"


CFace::CFace()
{
}


CFace::~CFace()
{
}
void CFace::Draw(CDC *pDC)
{
}
void CFace::Invalidate(bool bErase)
{
	CRect rt;
	rt.OffsetRect(origin);
	InvalidateRect(hWnd, rt, bErase);
}
