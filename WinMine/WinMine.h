
// WinMine.h : WinMine Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWinMineApp:
// �йش����ʵ�֣������ WinMine.cpp
//

class CWinMineApp : public CWinApp
{
public:
	CWinMineApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWinMineApp theApp;
