// AquariusWnd.h: interface for the CAquariusWnd class.
//
//////////////////////////////////////////////////////////////////////
#ifndef AQUARIUSWND_H_
#define AQUARIUSWND_H_

#include "lib2.h"
#include <AFXPRIV.H>

#if !defined(AFX_AQUARIUSWND_H__3F5B3477_BCBA_474F_81A5_C6DF39EAF6D6__INCLUDED_)
#define AFX_AQUARIUSWND_H__3F5B3477_BCBA_474F_81A5_C6DF39EAF6D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//命令列表
extern INT s_nAquariusWndElementCmdIndex[];
extern INT s_nAquariusWndElementCmdCount;

//属性列表
extern UNIT_PROPERTY g_aquariusWndProperty [];
extern INT g_aquariusWndPropertyCount;

//事件列表
extern INT g_nAquariusWndEventCount;
extern EVENT_INFO2 g_aquariusWndEvent [];

#define CUR_UNIT_VER		1
#define AQUA_TIMER_INITIAL			(1733)
#define AQUA_MSG_INITIAL			(WM_APP + 0x5199)

extern "C"
PFN_INTERFACE WINAPI aquarius_GetInterface_aquariuscef (INT nInterfaceNO);
HUNIT WINAPI Create_Viewer (LPBYTE pAllData, INT nAllDataSize,
							DWORD dwStyle, HWND hParentWnd, UINT uID, HMENU hMenu, INT x, INT y, INT cx, INT cy,
							DWORD dwWinFormID, DWORD dwUnitID, HWND hDesignWnd = 0, BOOL blInDesignMode = FALSE);
BOOL WINAPI NotifyPropertyChanged_Viewer (HUNIT hUnit, INT nPropertyIndex,
										  PUNIT_PROPERTY_VALUE pPropertyVaule, LPTSTR* ppszTipText);
BOOL WINAPI GetPropertyData_Viewer (HUNIT hUnit, INT nPropertyIndex,
									PUNIT_PROPERTY_VALUE pPropertyVaule);
HGLOBAL WINAPI GetAllPropertyData_Viewer (HUNIT hUnit);


class CAquariusApp : public CWinApp
{
public:
	CAquariusApp();
	DECLARE_MESSAGE_MAP()
};

class CPropertyInfo2
{
public:
	CPropertyInfo2 ()
	{
		init ();
	}
	
	virtual void init ()  { }
	virtual BOOL Serialize (CArchive& ar)
	{
		if (ar.IsLoading () == TRUE)
			init ();
		return TRUE;
	}
	
	HGLOBAL SaveData (){
		CSharedFile file;
		CArchive ar (&file, CArchive::store);
		
		if (Serialize (ar) == TRUE)
		{
			ar.Close ();
			
			DWORD dwLength = file.GetLength ();
			HGLOBAL hGlobal = file.Detach ();
			::GlobalUnlock (hGlobal);
			::GlobalReAlloc (hGlobal, dwLength, GMEM_DDESHARE | GMEM_MOVEABLE);
			//     注意由于Windows系统内存管理按字对齐的原因，最后hGlobal的大小（GloalSize返回）
			// 可能会大于dwLength值0-3个字节。
				return hGlobal;
		}
		else
		return NULL;
	}
	BOOL LoadData (LPBYTE pData, INT nDataSize){
		init ();
		
		if (pData != NULL && nDataSize > 0)
		{
			CMemFile file;
			file.Attach (pData, nDataSize);
			
			CArchive ar (&file, CArchive::load);
			return Serialize (ar);
		}
		else
		return TRUE;
	}
};

class CPIAquariusViewer : public CPropertyInfo2
{
public:
	int m_nBorderStyle;
	CString m_package;
	CString m_defaultEncoding;
	int m_nJavaScript;
	int m_nPlugins;
	int m_nWebSecurity;
	int m_nImageLoading;
	int m_nWebGL;

public:
	CPIAquariusViewer ()  
	{
		m_nBorderStyle = 0;
		m_nJavaScript = 0;
		m_nPlugins = 0;
		m_nWebSecurity = 0;
		m_nImageLoading = 0;
		m_nWebGL = 0;
	}
	
	virtual void init (){
		CPropertyInfo2::init ();
	}
	virtual BOOL Serialize (CArchive& ar){
		if (CPropertyInfo2::Serialize (ar) == FALSE)
			return FALSE;
		
		CString strTrace;
		TRY
		{
			if (ar.IsLoading () == TRUE)
			{
				DWORD dwUnitDataVer;
				ar >> dwUnitDataVer;
				if (dwUnitDataVer > 1)
					return FALSE;
				ar >> m_nBorderStyle >> m_package>>
					m_defaultEncoding>>m_nJavaScript>>
					m_nWebSecurity>>m_nImageLoading>>m_nWebGL;
				
			}
			else
			{
				ar << (DWORD)1;
				ar << m_nBorderStyle << m_package<<
					m_defaultEncoding<<m_nJavaScript<<m_nPlugins<<m_nWebSecurity<<m_nImageLoading<<m_nWebGL;
			}
			return TRUE;
		}
		END_TRY
			
	return FALSE;
	}
};

class CAquariusWnd : public CWnd  
{
public:
	CAquariusWnd();
	virtual ~CAquariusWnd();

public:
	static CAquariusWnd* GetMainWnd(void);

public:
///////////////////////////
	
	CPIAquariusViewer m_info;
	DWORD m_dwWinFormID, m_dwUnitID;
	BOOL m_blInDesignMode;
	LPVOID m_pDefaultBsValue;
	
///////////////////////////
	BOOL Create (HWND hParentWnd, DWORD dwStyle, UINT nID,
			INT x, INT y, INT cx, INT cy);

public:
	void ChangeBroder(void);

public:
	afx_msg virtual BOOL OnWndMsg(UINT message,WPARAM wParam,LPARAM lParam,LRESULT *pResult);
	virtual void PostNcDestroy();
	//{{AFX_MSG(CHHCtrl)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnPaint();
    afx_msg void OnDestroy();
	afx_msg LRESULT OnInitial(WPARAM wParam,LPARAM lParam);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
    //}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	DECLARE_EVENTSINK_MAP()
};


#endif // !defined(AFX_AQUARIUSWND_H__3F5B3477_BCBA_474F_81A5_C6DF39EAF6D6__INCLUDED_)

#endif
