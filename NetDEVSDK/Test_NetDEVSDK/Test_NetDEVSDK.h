
// Test_NetDEVSDK.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTest_NetDEVSDKApp: 
// �йش����ʵ�֣������ Test_NetDEVSDK.cpp
//

class CTest_NetDEVSDKApp : public CWinApp
{
public:
	CTest_NetDEVSDKApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTest_NetDEVSDKApp theApp;