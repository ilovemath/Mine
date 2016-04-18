#include "stdafx.h"
#include "Face.h"


CFace::CFace()
{
	ico = Smile;
	rect = GetIconRect(Smile);
}


CFace::~CFace()
{
}

bool CFace::PtInFace(CPoint&point)
{
	return rect.PtInRect(point);
}

void CFace::Draw(CDC *pDC)
{
	CDC tmpDc;
	if (tmpDc.CreateCompatibleDC(pDC) == NULL)
	{
		AfxMessageBox(L"Cannot Create tmpDc");
		return;
	}
	CBitmap tmpbMap;
	if (tmpbMap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height()) == NULL)
	{
		AfxMessageBox(L"Cannot Create tmpbMap");
		return;
	}
	tmpDc.SelectObject(tmpbMap);
	CDraw::Draw(&tmpDc, CRect(0,0,rect.Width(),rect.Height()), *this);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &tmpDc,
		0, 0, rect.Width(), rect.Height(), SRCCOPY);
}

void CFace::Invalidate(bool bErase)
{
	InvalidateRect(hWnd, rect, bErase);
}
