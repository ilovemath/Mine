#include "stdafx.h"
#include "Layout.h"


CLayout::CLayout()
{
}


CLayout::~CLayout()
{
}


void CLayout::Init()
{
	for (int i = 0; i < 13; i++)
		corner[i] = tool.GetIconRect(CTexture::Icon(i));
	int m = 50;
	field.SetOrigin(CPoint(corner[tool.LT].Width(), corner[tool.LT].Height() + m + corner[tool.LM].Height()));
	field.InitField();
	CRect &frt = field.GetFieldRect();
	//第一层
	corner[tool.LT].MoveToXY(0, 0);
	corner[tool.RT].MoveToXY(frt.right, 0);
	CRect &lt = corner[tool.LT];
	CRect &rt = corner[tool.RT];
	corner[tool.TM].SetRect(lt.right, lt.top, rt.left, rt.bottom);
	//第二层
	corner[tool.LTM].SetRect(lt.left, lt.bottom, lt.right, lt.bottom + m);
	corner[tool.RTM].SetRect(rt.left, rt.bottom, rt.right, rt.bottom + m);
	CRect &ltm = corner[tool.LTM];
	CRect &rtm = corner[tool.RTM];
	//第三层
	corner[tool.LM].MoveToXY(ltm.left, ltm.bottom);
	corner[tool.RM].MoveToXY(rtm.left, rtm.bottom);
	CRect &lm = corner[tool.LM];
	CRect &rm = corner[tool.RM];
	corner[tool.MM].SetRect(lm.right, lm.top, rm.left, rm.bottom);
	//第四层
	corner[tool.LBM].SetRect(lm.left, lm.bottom, lm.right, frt.bottom);
	corner[tool.RBM].SetRect(rm.left, rm.bottom, rm.right, frt.bottom);
	CRect &lbm = corner[tool.LBM];
	CRect &rbm = corner[tool.RBM];
	//第五层
	corner[tool.LB].MoveToXY(lbm.left, lbm.bottom);
	corner[tool.RB].MoveToXY(rbm.left, rbm.bottom);
	CRect &lb = corner[tool.LB];
	CRect &rb = corner[tool.RB];
	corner[tool.BM].SetRect(lb.right, lb.top, rb.left, rb.bottom);
	rect.SetRect(CPoint(0,0),rb.BottomRight());
	
	int x = frt.CenterPoint().x;
	int y = ltm.CenterPoint().y;
	face.SetCenterPoint(x, y);
	mine.SetCenterPoint(lm.right + m, y);
	time.SetCenterPoint(rm.left - m, y);
}

void CLayout::Invalidate(bool bErase)
{
}

void CLayout::Draw(CDC* pDC)
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
	for (int i = 0; i < 13; i++)
	{
		tool.SetIcon(CTexture::Icon(i));
		CDraw::Draw(&tmpDc, corner[i], tool);
	}
	time.Draw(&tmpDc);
	mine.Draw(&tmpDc);
	face.Draw(&tmpDc);
	field.Draw(&tmpDc);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &tmpDc,
		0, 0, rect.Width(), rect.Height(), SRCCOPY);
}