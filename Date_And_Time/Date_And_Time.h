
// Date_And_Time.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CDate_And_TimeApp:
// �йش����ʵ�֣������ Date_And_Time.cpp
//

class CDate_And_TimeApp : public CWinApp
{
public:
	CDate_And_TimeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDate_And_TimeApp theApp;