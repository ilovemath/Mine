#include "stdafx.h"
#include "Board.h"


CBoard::CBoard()
{
	one = 0;
	ten = 0;
	hun = 0;
	rect = GetIconRect(LedBk);
}


CBoard::~CBoard(void)
{
}

void CBoard::Inc()
{
	one++;
	if (one > 9){
		ten++;
		one = 0;
		if (ten > 9)
		{
			hun++;
			ten = 0;
		}
	}
	Invalidate();
}
void CBoard::Dec()
{
	one--;
	if (one < 0){
		ten--;
		one = 9;
		if (ten < 0)
		{
			hun--;
			ten = 9;
		}
	}
	Invalidate();
}

void CBoard::SetNum(int num)
{
	if (num>999)
	{
		hun = 0;
		ten = 0;
		one = 0;
	}
	else
	{
		if (num < 0)
		{
			num = -num;
			hun = 10;//符号
		}
		else
		{
			hun = num / 100;
		}
		ten = num % 100 / 10;
		one = num % 10;
	}
}

void CBoard::Draw(CDC *pDC)
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
	CRect rt = GetIconRect(LedBk);
	SetIcon(LedBk);
	rt.MoveToXY(0, 0);
	CDraw::Draw(&tmpDc, rt, *this);
	SetIcon(Led);
	rt = GetIconRect();
	//百位
	num = hun;
	rt.MoveToXY(2, 2);
	CDraw::Draw(&tmpDc, rt, *this);
	//十位
	num = ten;
	rt.MoveToX(4 + rt.Width());
	CDraw::Draw(&tmpDc, rt, *this);
	//个位
	num = one;
	rt.MoveToX(6 + rt.Width() * 2);
	CDraw::Draw(&tmpDc, rt, *this);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &tmpDc,
		0, 0, rect.Width(), rect.Height(), SRCCOPY);
}

void CBoard::Invalidate(bool bErase)
{
	InvalidateRect(hWnd, rect, bErase);
}


CBoard &CBoard::operator--()
{
	Dec();
	return *this;
}

CBoard &CBoard::operator++()
{
	Inc();
	return *this;
}