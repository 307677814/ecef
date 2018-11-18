// fne.h : main header file for the FNE DLL
//

#if !defined(AFX_FNE_H__19D64901_C0F5_4548_9EA4_955350A76397__INCLUDED_)
#define AFX_FNE_H__19D64901_C0F5_4548_9EA4_955350A76397__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFneApp
// See fne.cpp for the implementation of this class
//

class CFneApp : public CWinApp
{
public:
	CFneApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFneApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFneApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FNE_H__19D64901_C0F5_4548_9EA4_955350A76397__INCLUDED_)
