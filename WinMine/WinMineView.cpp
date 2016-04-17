
// WinMineView.cpp : CWinMineView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "WinMine.h"
#endif

#include "WinMineDoc.h"
#include "WinMineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinMineView

IMPLEMENT_DYNCREATE(CWinMineView, CView)

BEGIN_MESSAGE_MAP(CWinMineView, CView)
	ON_WM_LBUTTONDOWN() 
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWinMineView ����/����

CWinMineView::CWinMineView()
{
	// TODO: �ڴ˴���ӹ������ 
	field.SetOrigin(CPoint(10, 50));
	field.SetType(CMineField::Hard);
	field.InitMine();
}

CWinMineView::~CWinMineView()
{
}

BOOL CWinMineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CWinMineView ����

void CWinMineView::OnDraw(CDC* pDC)
{
	field.SetHwnd(GetSafeHwnd());
	field.Draw(pDC);
}


// CWinMineView ���

#ifdef _DEBUG
void CWinMineView::AssertValid() const
{
	CView::AssertValid();
}

void CWinMineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinMineDoc* CWinMineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinMineDoc)));
	return (CWinMineDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinMineView ��Ϣ�������


void CWinMineView::OnLButtonDown(UINT nFlags, CPoint point)
{ 
	int index = field.PtToIndex(point);
	if (nFlags & MK_RBUTTON)
	{
		field.LRButtonPress(index);
	}
	else
	{
		field.LButtonDown(index);
	}
	field.Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CWinMineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	int index = field.PtToIndex(point);
	if (nFlags & MK_RBUTTON)
	{
		field.LRButtonUp(index);
	}
	else
	{
		field.LButtonUp(index);
	}
	field.Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CWinMineView::OnRButtonDown(UINT nFlags, CPoint point)
{
	int index = field.PtToIndex(point);
	if (nFlags & MK_LBUTTON)
	{
		field.LRButtonPress(index);
	}
	else
	{
		field.RButtonDown(index);
	}
	field.Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

void CWinMineView::OnRButtonUp(UINT nFlags, CPoint point)
{
	int index = field.PtToIndex(point);
	if (nFlags & MK_LBUTTON)
	{
		field.LRButtonUp(index);
	}
	field.Invalidate();
	CView::OnRButtonUp(nFlags, point);
}

void CWinMineView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	int index = field.PtToIndex(point);
	field.RButtonDown(index);
	field.Invalidate();
	CView::OnRButtonDblClk(nFlags, point);
}

void CWinMineView::OnMouseMove(UINT nFlags, CPoint point)
{
	field.NotPress();
	int index = field.PtToIndex(point);
	if (nFlags & MK_LBUTTON)
	{
		if (nFlags & MK_RBUTTON)
			field.LRButtonPress(index);
		else
			field.LButtonPress(index);
	}
	field.Invalidate();
	CView::OnMouseMove(nFlags, point);
}

