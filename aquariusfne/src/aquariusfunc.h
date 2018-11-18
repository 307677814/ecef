#ifndef AQUARIUSFUNC_H_
#define AQUARIUSFUNC_H_

#include "lib2.h"
#include "aquariuseventer.h"
#include "dispatch.h"

extern "C"
PFN_INTERFACE WINAPI aquarius_GetInterface_aquariuscef (INT nInterfaceNO){
	return nInterfaceNO == ITF_CREATE_UNIT ? (PFN_INTERFACE)Create_Viewer :
	nInterfaceNO == ITF_NOTIFY_PROPERTY_CHANGED ? (PFN_INTERFACE)NotifyPropertyChanged_Viewer :
	nInterfaceNO == ITF_GET_ALL_PROPERTY_DATA ? (PFN_INTERFACE)GetAllPropertyData_Viewer :
	nInterfaceNO == ITF_GET_PROPERTY_DATA ? (PFN_INTERFACE)GetPropertyData_Viewer :
	NULL;
}

HUNIT WINAPI Create_Viewer (LPBYTE pAllData, INT nAllDataSize,
							DWORD dwStyle, HWND hParentWnd, UINT uID, HMENU hMenu, INT x, INT y, INT cx, INT cy,
							DWORD dwWinFormID, DWORD dwUnitID, HWND hDesignWnd, BOOL blInDesignMode){
	CAquariusWnd *pUnit = new CAquariusWnd;
	if (pUnit->m_info.LoadData (pAllData, nAllDataSize) == FALSE)
	{
		return NULL;
	}
	pUnit->m_dwWinFormID = dwWinFormID;
	pUnit->m_dwUnitID = dwUnitID;
	pUnit->m_blInDesignMode = blInDesignMode;
	if (pUnit->Create (hParentWnd, dwStyle | WS_CHILD | WS_CLIPSIBLINGS,
		uID, x, y, cx, cy))
	{	
		pUnit->ChangeBroder();
		//pUnit->m_pDefaultBsValue = AquaTypes::BrowserSettings::AquaTypeBsCreate();
		if(blInDesignMode == FALSE)
		{
			//Local::pBsConf = AquaTypeBsCreate();

		}
		return (HUNIT)pUnit;
	}
	else return NULL;
}

BOOL WINAPI NotifyPropertyChanged_Viewer (HUNIT hUnit, INT nPropertyIndex,
										  PUNIT_PROPERTY_VALUE pPropertyVaule, LPTSTR* ppszTipText){
	ASSERT (hUnit != NULL);
	if (hUnit == NULL)  return FALSE;
	ASSERT (pUnit->GetSafeHwnd () != NULL);
	if (ppszTipText != NULL)
		*ppszTipText = NULL;
	//MessageBox(NULL,"NotifyPropertyChanged_Viewer",NULL,NULL);
	CAquariusWnd *pWindow = (CAquariusWnd*)hUnit;
	switch(nPropertyIndex){
	case 0:		pWindow->m_info.m_nBorderStyle = pPropertyVaule->m_int; pWindow->ChangeBroder(); break;
	case 1:		pWindow->m_info.m_package = pPropertyVaule->m_szText;	break;
	case 2:		pWindow->m_info.m_defaultEncoding = pPropertyVaule->m_szText; break;
	case 3:		pWindow->m_info.m_nJavaScript = pPropertyVaule->m_int; break;
	case 4:		pWindow->m_info.m_nPlugins = pPropertyVaule->m_int; break;
	case 5:		pWindow->m_info.m_nWebSecurity = pPropertyVaule->m_int; break;
	case 6:		pWindow->m_info.m_nImageLoading = pPropertyVaule->m_int; break;
	case 7:		pWindow->m_info.m_nWebGL = pPropertyVaule->m_int; break;
	}
	return NULL;
}

BOOL WINAPI GetPropertyData_Viewer (HUNIT hUnit, INT nPropertyIndex,
									PUNIT_PROPERTY_VALUE pPropertyVaule){
	ASSERT (hUnit != NULL);
	if (hUnit == NULL)  return FALSE;
	ASSERT (pUnit->GetSafeHwnd () != NULL);
	CAquariusWnd *pWindow = (CAquariusWnd*)hUnit;
	switch(nPropertyIndex){
	case 0:		pPropertyVaule->m_int = pWindow->m_info.m_nBorderStyle; break;
	case 1:		pPropertyVaule->m_szText = (LPTSTR)(LPCTSTR)pWindow->m_info.m_package; break;
	case 2:		pPropertyVaule->m_szText = (LPTSTR)(LPCTSTR)pWindow->m_info.m_defaultEncoding; break;
	case 3:		pPropertyVaule->m_int = pWindow->m_info.m_nJavaScript; break;
	case 4:		pPropertyVaule->m_int = pWindow->m_info.m_nPlugins; break;
	case 5:		pPropertyVaule->m_int = pWindow->m_info.m_nWebSecurity; break;
	case 6:		pPropertyVaule->m_int = pWindow->m_info.m_nImageLoading; break;
	case 7:		pPropertyVaule->m_int = pWindow->m_info.m_nWebGL; break;
	}
	return NULL;
}

HGLOBAL WINAPI GetAllPropertyData_Viewer (HUNIT hUnit){
	ASSERT (hUnit != NULL);
	CAquariusWnd *pWindow = (CAquariusWnd*)hUnit;
	//MessageBox(NULL,"GetAllPropertyData_Viewer",NULL,NULL);
	return pWindow->m_info.SaveData();
}

INT s_nAquariusWndElementCmdIndex[]={
	75,76,127,157,158,182,183,184,296
};
INT s_nAquariusWndElementCmdCount = sizeof(s_nAquariusWndElementCmdIndex) / sizeof(s_nAquariusWndElementCmdIndex[0]);



//初始化回调
void dispEventer::OnInitial(LPVOID pUnit,LPCSTR package){
	if(AquaAddRef == NULL){
		wapper::DoLoadLibrary(package);
	}
	if(AquaAddRef){
		initialWnd = pUnit;
		s_evtEvents.OnBeforeCommandLineProcessing = OnEvtBeforeCommandLineProcessingCallback;
		s_evtEvents.OnContextInitialized = OnEvtContextInitialized;
		s_evtEvents.OnAddressChange = OnEvtAddressChange;
		s_evtEvents.OnTitleChange = OnEvtTitleChange;
		s_evtEvents.OnFaviconURLChange = OnEvtFaviconURLChange;
 		s_evtEvents.OnFullscreenModeChange = OnEvtFullscreenModeChange;
 		s_evtEvents.OnStatusMessage = OnEvtStatusMessage;
		s_evtEvents.OnConsoleMessage = OnEvtConsoleMessage;
		s_evtEvents.OnBeforePopup = OnEvtBeforePopup;
		s_evtEvents.OnAfterCreated = OnEvtAfterCreated;
		s_evtEvents.DoClose = OnEvtDoClose;
		s_evtEvents.OnBeforeClose = OnEvtBeforeClose;
		s_evtEvents.OnLoadingStateChange = OnEvtLoadingStateChange;
		s_evtEvents.OnLoadStart = OnEvtLoadStart;
		s_evtEvents.OnLoadEnd = OnEvtLoadEnd;
		s_evtEvents.OnLoadError = OnEvtLoadError;
		s_evtEvents.OnContextCreated = OnEvtContextCreated;
		s_evtEvents.OnContextRelease = OnEvtContextRelease;
		s_evtEvents.OnV8AccessorGet = OnEvtAccessorGet;
		s_evtEvents.OnV8AccessorSet = OnEvtAccessorSet;
		s_evtEvents.OnV8AccessorExecute = OnEvtAccessorExecute;
		s_evtEvents.OnBeforeResourceLoad = OnEvtBeforeResourceLoad;
		s_evtEvents.OnResourceRedirect = OnEvtResourceRedirect;
		s_evtEvents.OnResourceLoadComplete = OnEvtResourceLoadComplete;
		s_evtEvents.OnJSDialog = OnEvtJSDialog;
		s_evtEvents.OnFileDialog = OnEvtFileDialog;
		s_evtEvents.OnPreKeyEvent = OnEvtPreKeyEvent;
		s_evtEvents.OnBeforeDownload = OnEvtBeforeDownload;
		s_evtEvents.OnDownloadUpdated = OnEvtDownloadUpdate;
		s_evtEvents.RunContextMenu = OnEvtContextMenu;
		s_evtEvents.GetAuthCredentials = OnEvtGetAuthCredentials;
		AquaBind(&s_evtEvents);
		AquaDoWinMain(OnEvtInitialCallback);
	}
}


// 
extern "C"
void aquarius_browser_quitprocess (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaQuitProcess();
}

//取组件包版本
extern "C"
void aquarius_browser_getadapter (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_pText = COPYSTRING(AquaGetAdapter(),0);
}

// 初始化
extern "C"
void aquarius_initial_initsettings (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	dispEventer::OnInitial(pWnd,(LPCSTR)pWnd->m_info.m_package);
}

void SetBrowserConf(CAquariusWnd *pWnd,LPVOID pBsConf){
	if(pWnd->m_info.m_defaultEncoding.GetLength() >0){
		AquaTypeBsDefaultEncodingA(pBsConf,pWnd->m_info.m_defaultEncoding);
	}
	AquaTypeBsJavaScript(pBsConf,(TypeBsStateType)pWnd->m_info.m_nJavaScript);
	AquaTypeBsPlugins(pBsConf,(TypeBsStateType)pWnd->m_info.m_nPlugins);
	AquaTypeBsWebSecurity(pBsConf,(TypeBsStateType)pWnd->m_info.m_nWebSecurity);
	AquaTypeBsImageLoading(pBsConf,(TypeBsStateType)pWnd->m_info.m_nImageLoading);
	AquaTypeBsWebGL(pBsConf,(TypeBsStateType)pWnd->m_info.m_nWebGL);
}

//创建浏览器
extern "C"
void aquarius_browser_createbrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	const char *homePage = "about:blank";
	LPVOID windowInfo = NULL;
	LPVOID pRscConf = NULL;
	if(pArgInf[1].m_dtDataType!=_SDT_NULL){
		homePage = pArgInf[1].m_pText;
	}
	if(pArgInf[2].m_dtDataType!=_SDT_NULL){
		windowInfo = *pArgInf[2].m_ppCompoundData;
	}
	else {
		windowInfo = AquaWindowCreate();
		RECT rc = {0};
		GetClientRect(pWnd->GetSafeHwnd(),&rc);
		AquaWindowSetAsChild(windowInfo,pWnd->GetSafeHwnd(),rc.left,rc.top,rc.right-rc.left,rc.bottom-rc.top);
	}
	LPVOID pBsConf = AquaTypeBsCreate();
	SetBrowserConf(pWnd,pBsConf);
	pRetData->m_bool = AquaBrowserHostCreateBrowserA(homePage,windowInfo,pBsConf,pRscConf);
	if(pArgInf[2].m_dtDataType==_SDT_NULL){
		AquaWindowDestoryed(windowInfo);
	}
	AquaTypeBsDestoryed(pBsConf);
}

//查询浏览器
extern "C"
void aquarius_browser_querybrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(IsWindow((HWND)pArgInf[1].m_int) == FALSE) {
		return;
	}
	LPVOID pBi = AquaManagerQueryActor((HWND)pArgInf[1].m_int);
	if(pBi){
		*pRetData->m_ppCompoundData = pBi;
	}
}

//尺寸被改变回调
void dispEventer::OnResized(LPVOID pUnit){
	CAquariusWnd *pWnd = (CAquariusWnd*)pUnit;
	if(AquaManagerMoveOrResized){
		RECT rc;
		pWnd->GetClientRect(&rc);
		AquaManagerMoveOrResized(pWnd->GetSafeHwnd(),rc.left,rc.top,rc.right-rc.left,rc.bottom-rc.top);
	}
}

//置为前台
extern "C"
void aquarius_browser_setmainheroine(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	if(pArgInf[1].m_dtDataType == SDT_INT){
		if(IsWindow((HWND)pArgInf[1].m_int) == FALSE){
			pRetData->m_bool = FALSE;
			return;
		}
		AquaManagerSetMainHeroine(pWnd->GetSafeHwnd(),(HWND)pArgInf[1].m_int);
	}
	else if((pArgInf[1].m_dtDataType &MAKELONG(10,0))){
		LPVOID pBi = *pArgInf[1].m_ppCompoundData;
		if(pBi == 0) {
			pRetData->m_bool = FALSE;
			return ;
		}
		LPVOID pHi = AquaBrowserGetHost(pBi);
		HWND child = AquaBrowserHostGetWindowHandle(pHi);
		AquaManagerSetMainHeroine(pWnd->GetSafeHwnd(),child);
		AquaRelease(pHi);
	}
	else if((pArgInf[1].m_dtDataType & MAKELONG(11,0))){
		LPVOID pHi = *pArgInf[1].m_ppCompoundData;
		if(pHi == FALSE) {
			pRetData->m_bool = FALSE;
			return ;
		}
		HWND child = AquaBrowserHostGetWindowHandle(pHi);
		AquaManagerSetMainHeroine(pWnd->GetSafeHwnd(),child);
	}
}

//取浏览器数量
extern "C"
void aquarius_browser_getcount (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaManagerGetCount();
}

//关闭所有浏览器
extern "C"
void aquarius_browser_closeallbrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaManagerCloseAllBrowser();
}

void dispEventer::OnDestory(void){

}

//注册脚本类
extern "C"
void aquarius_browser_regv8accessor (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	*pRetData->m_ppCompoundData = AquaV8SpecCreateAccessor(pArgInf[1].m_pText);
}

//注册脚本变量
extern "C"
void aquarius_browser_regv8var (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	pRetData->m_bool = AquaV8SpecRegisterVar(*pArgInf[1].m_ppCompoundData,pArgInf[2].m_pText);
}

//注册脚本函数
extern "C"
void aquarius_browser_regv8function (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	pRetData->m_bool = AquaV8SpecRegisterFunction(*pArgInf[1].m_ppCompoundData,pArgInf[2].m_pText);
}


#endif