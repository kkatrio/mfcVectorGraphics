
// mfcVectorGraphics.h : main header file for the mfcVectorGraphics application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CmfcVectorGraphicsApp:
// See mfcVectorGraphics.cpp for the implementation of this class
//

class CmfcVectorGraphicsApp : public CWinApp
{
public:
	CmfcVectorGraphicsApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CmfcVectorGraphicsApp theApp;
