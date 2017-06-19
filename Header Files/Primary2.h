
// Primary2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "SecondDlg.h"



// CPrimary2App:
// See Primary2.cpp for the implementation of this class
//

class CPrimary2App : public CWinApp
{
public:
	CPrimary2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPrimary2App theApp;