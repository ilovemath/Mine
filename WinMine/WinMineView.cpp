
// WinMineView.cpp : CWinMineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CWinMineView 构造/析构

CWinMineView::CWinMineView()
{
	// TODO: 在此处添加构造代码 
	field.SetOrigin(CPoint(10, 50));
	field.SetType(CMineField::Hard);
	field.InitMine();
}

CWinMineView::~CWinMineView()
{
}

BOOL CWinMineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWinMineView 绘制

void CWinMineView::OnDraw(CDC* pDC)
{
	field.SetHwnd(GetSafeHwnd());
	field.Draw(pDC);
}


// CWinMineView 诊断

#ifdef _DEBUG
void CWinMineView::AssertValid() const
{
	CView::AssertValid();
}

void CWinMineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinMineDoc* CWinMineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinMineDoc)));
	return (CWinMineDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinMineView 消息处理程序


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

