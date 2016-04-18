
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
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CWinMineView ����/����

CWinMineView::CWinMineView()
{
	// TODO: �ڴ˴���ӹ������
	layout.Init();
	rules.Init(layout);
	//SetTimer(1, 100, NULL);
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
	if (!CDraw::hWnd){
		CDraw::hWnd = GetSafeHwnd();
	}
	layout.Draw(pDC);
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
	if (nFlags & MK_RBUTTON)
	{
		rules.LRButtonPress(point);
	}
	else
	{
		rules.LButtonDown(point);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CWinMineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (nFlags & MK_RBUTTON)
	{
		rules.LRButtonUp(point);
	}
	else
	{
		rules.LButtonUp(point);
	}
	CView::OnLButtonUp(nFlags, point);
}

void CWinMineView::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON)
	{
		rules.LRButtonPress(point);
	}
	else
	{
		rules.RButtonDown(point);
	}
	CView::OnRButtonDown(nFlags, point);
}

void CWinMineView::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON)
	{
		rules.LRButtonUp(point);
	}
	else
	{
		rules.RButtonUp(point);
	}
	CView::OnRButtonUp(nFlags, point);
}

void CWinMineView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	rules.RButtonDown(point);
	rules.RButtonUp(point);
	CView::OnRButtonDblClk(nFlags, point);
}

void CWinMineView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON)
	{
		if (nFlags & MK_RBUTTON)
			rules.LRButtonPress(point);
		else
			rules.LButtonPress(point);
	}
	else
	{
		rules.Release();
	}
	CView::OnMouseMove(nFlags, point);
}



void CWinMineView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent==1)
	{
		++layout.time;
	}
	CView::OnTimer(nIDEvent);
}
