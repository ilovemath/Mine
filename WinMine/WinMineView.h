
// WinMineView.h : CWinMineView 类的接口
//

#pragma once
#include "MineField.h"

class CWinMineView : public CView
{
protected: // 仅从序列化创建
	CWinMineView();
	DECLARE_DYNCREATE(CWinMineView)

private:
	CMineField field;
// 特性
public:
	CWinMineDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CWinMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); 
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WinMineView.cpp 中的调试版本
inline CWinMineDoc* CWinMineView::GetDocument() const
   { return reinterpret_cast<CWinMineDoc*>(m_pDocument); }
#endif

