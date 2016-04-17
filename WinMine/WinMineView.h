
// WinMineView.h : CWinMineView ��Ľӿ�
//

#pragma once
#include "MineField.h"

class CWinMineView : public CView
{
protected: // �������л�����
	CWinMineView();
	DECLARE_DYNCREATE(CWinMineView)

private:
	CMineField field;
// ����
public:
	CWinMineDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CWinMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // WinMineView.cpp �еĵ��԰汾
inline CWinMineDoc* CWinMineView::GetDocument() const
   { return reinterpret_cast<CWinMineDoc*>(m_pDocument); }
#endif

