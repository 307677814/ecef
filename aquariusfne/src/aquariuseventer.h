#ifndef AQUARIUSEVENTER_H_
#define AQUARIUSEVENTER_H_

#include "lib2.h"
#include "AquariusWnd.h"
#include "wapper.h"

//初始化设置
LPVOID initialWnd = NULL;
void CALLBACK OnEvtInitialCallback(LPVOID conf){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,0);
		AQUA_INIT_INFO initConf = {0};
		AQUA_INIT_INFO *pInitConf = &initConf;
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pInitConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(initConf.pszCachePath){
			AquaInitCachePathA(conf,initConf.pszCachePath);
			g_fnAquaNotifySys(NRS_MFREE,(DWORD)initConf.pszCachePath,0);
		}
		if(initConf.pszUserDataPath){
			AquaInitUserDataA(conf,initConf.pszUserDataPath);
			g_fnAquaNotifySys(NRS_MFREE,(DWORD)initConf.pszUserDataPath,0);
		}
		if(initConf.pszUserAgent){
			AquaInitUserAgentA(conf,initConf.pszUserAgent);
			g_fnAquaNotifySys(NRS_MFREE,(DWORD)initConf.pszUserAgent,0);
		}
		if(initConf.pszProductVersion){
			AquaInitProductVersionA(conf,initConf.pszProductVersion);
			g_fnAquaNotifySys(NRS_MFREE,(DWORD)initConf.pszProductVersion,0);
		}
		if(initConf.pszLocale){
			AquaInitLocaleA(conf,initConf.pszLocale);
			g_fnAquaNotifySys(NRS_MFREE,(DWORD)initConf.pszLocale,0);
		}
		if(initConf.pszAcceptLanguageList){
			AquaInitAcceptLanguageListA(conf,initConf.pszAcceptLanguageList);
			g_fnAquaNotifySys(NRS_MFREE,(DWORD)initConf.pszAcceptLanguageList,0);
		}
		AquaInitWindowlessRenderingEnabled(conf,initConf.nWindowlessRate);
		AquaInitPersistSessionCookies(conf,initConf.bPersistSessionCookies);
		AquaInitPersistUserPreferences(conf,initConf.bPersistUserPreferences);
		AquaInitRemoteDebuggingPort(conf,initConf.nRemoteDebuggingPort);
		AquaInitIgnoreCertificateErrors(conf,initConf.bIgnoreCertificateErrors);
	}
}

//初始化命令行
void CALLBACK OnEvtBeforeCommandLineProcessingCallback(const char *process_type,LPVOID command){
	if(initialWnd){
		LPVOID pCommandConf = &command;
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,1);
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pCommandConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//初始化完毕
void CALLBACK OnEvtContextInitialized(){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,2);
		event.m_nArgCount = 0;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//地址栏被改变
void CALLBACK OnEvtAddressChange(LPVOID browser,LPVOID frame,const char *url){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,3);
		LPVOID pBiConf = &browser;
		LPVOID pFiConf = &frame;
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=(void**)&pFiConf;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppText=(char**)&url;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//标题栏被改变
void CALLBACK OnEvtTitleChange(LPVOID browser,const char *title){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,4);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 2;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppText=(char**)&title;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//页面图标被改变
void CALLBACK OnEvtFaviconURLChange(LPVOID browser,LPVOID urls_icon){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,5);
		LPVOID pBiConf = &browser;
		LPVOID pIconsConf = &urls_icon;
		event.m_nArgCount = 2;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=(void**)&pIconsConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//显示模式被改变
void CALLBACK OnEvtFullscreenModeChange(LPVOID browser,bool fullscreen){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,6);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 2;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = NULL;
		event.m_arg[1].m_inf.m_bool = fullscreen;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//状态文本被改变
void CALLBACK OnEvtStatusMessage(LPVOID browser,const char *value){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,7);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 2;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppText=(char**)&value;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//控制台
bool CALLBACK OnEvtConsoleMessage(LPVOID browser,int level,const char *message,const char *source,int line){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,8);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 5;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = NULL;
		event.m_arg[1].m_inf.m_int = level;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppText=(char**)&message;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppText=(char**)&source;
		event.m_arg[4].m_dwState = NULL;
		event.m_arg[4].m_inf.m_int = line;
		if(g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0)!=0){
			if(event.m_blHasRetVal){
				result = event.m_infRetData.m_bool;
			}
		}
	}
	return result;
}

//创建完毕
void CALLBACK OnEvtAfterCreated(LPVOID browser){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,9);
		LPVOID pBiConf = &browser;
// 		LPVOID pHi = AquaBrowserGetHost(browser);
// 		if(pHi){
// 			AquaManagerSetMainHeroine(pWnd->GetSafeHwnd(),AquaBrowserHostGetWindowHandle(pHi));
// 			AquaRelease(pHi);
// 		}
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//即将打开新窗口
bool CALLBACK OnEvtBeforePopup(LPVOID browser,LPVOID frame,LPCSTR target_url,
							   LPCSTR target_frame_name,int target_disposition,
							   bool user_gesture,LPVOID popupFeatures,LPVOID windowInfo,
							   LPVOID settings,bool *no_javascript_access){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd=(CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,10);
		LPVOID pBiConf = &browser;
		LPVOID pFiConf = &frame;
		LPVOID pWiConf = &windowInfo;
		AQUA_POPUP_FEATURES popupConf = {0};
		AQUA_POPUP_FEATURES *pPopupConf=&popupConf;
// 		LPVOID pHi = AquaBrowserGetHost(browser);
// 		if(pHi){
// 			RECT rc = {0};
// 			GetClientRect(pWnd->GetSafeHwnd(),&rc);
// 			AquaWindowSetAsChild(windowInfo,pWnd->GetSafeHwnd(),rc.left,rc.top,rc.right-rc.left,rc.bottom-rc.top);
// 			AquaManagerSetMainHeroine(pWnd->GetSafeHwnd(),AquaBrowserHostGetWindowHandle(pHi));
// 			AquaRelease(pHi);
// 		}

		event.m_nArgCount = 9;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=(void**)&pFiConf;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData=(void**)&target_url;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppCompoundData=(void**)&target_frame_name;
		event.m_arg[4].m_dwState = NULL;
		event.m_arg[4].m_inf.m_int=target_disposition;
		event.m_arg[5].m_dwState = NULL;
		event.m_arg[5].m_inf.m_bool=user_gesture;
		event.m_arg[6].m_dwState = EAV_IS_POINTER;
		event.m_arg[6].m_inf.m_ppCompoundData=(void**)&pPopupConf;
		event.m_arg[7].m_dwState = EAV_IS_POINTER;
		event.m_arg[7].m_inf.m_ppCompoundData=(void**)&pWiConf;
		event.m_arg[8].m_dwState = NULL;
		event.m_arg[8].m_inf.m_pBool=(BOOL*)no_javascript_access;
		if(g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0)!=0 && event.m_blHasRetVal){
			result = event.m_infRetData.m_bool;
		}
		AquaTypePfSetFeatures(popupFeatures,popupConf.x,popupConf.xSet,
			popupConf.y,popupConf.ySet,popupConf.width,popupConf.widthSet,
			popupConf.height,popupConf.heightSet,popupConf.menuBarVisible,
			popupConf.statusBarVisible,popupConf.toolBarVisible,popupConf.scrollbarsVisible);
	}
	return result;
}


//可否被关闭
bool CALLBACK OnEvtDoClose(LPVOID browser){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,11);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		if(g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0) != 0){
			if(event.m_blHasRetVal){
				result = event.m_infRetData.m_bool;
			}
		}
	}
	return result;
}

//即将被销毁
void CALLBACK OnEvtBeforeClose(LPVOID browser){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,12);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//载入状态被改变
void CALLBACK OnEvtLoadingStateChange(LPVOID browser,bool isLoading,bool canGoBack,bool canGoForward){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,13);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 4;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = NULL;
		event.m_arg[1].m_inf.m_bool=isLoading;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_bool=canGoBack;
		event.m_arg[3].m_dwState = NULL;
		event.m_arg[3].m_inf.m_bool=canGoForward;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//载入开始
void CALLBACK OnEvtLoadStart(LPVOID browser,LPVOID frame,int transition_type){
	if(initialWnd){
		//MessageBox(NULL,NULL)
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,14);
		LPVOID pBiConf = &browser;
		LPVOID pFiConf = &frame;
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=(void**)&pFiConf;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_int=transition_type;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//载入结束
void CALLBACK OnEvtLoadEnd(LPVOID browser,LPVOID frame,int httpCodeStatus){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,15);
		LPVOID pBiConf = &browser;
		LPVOID pFiConf = &frame;
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=(void**)&pFiConf;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_int=httpCodeStatus;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//载入失败
void CALLBACK OnEvtLoadError(LPVOID browser,LPVOID frame,int errorCode,const char *errorText,const char *failedUrl){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,16);
		LPVOID pBiConf = &browser;
		LPVOID pFiConf = &frame;
		event.m_nArgCount = 5;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=(void**)&pFiConf;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_int=errorCode;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppText=(char**)&errorText;
		event.m_arg[4].m_dwState = EAV_IS_POINTER;
		event.m_arg[4].m_inf.m_ppText=(char**)&failedUrl;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//载入脚本上下文创建完毕
void CALLBACK OnEvtContextCreated(LPVOID browser){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,19);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//载入脚本上下文即将销毁
void CALLBACK OnEvtContextRelease(LPVOID browser){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,20);
		LPVOID pBiConf = &browser;
		event.m_nArgCount = 1;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

//注册变量被赋值
bool CALLBACK OnEvtAccessorSet(LPCSTR mainName, LPCSTR childName, LPVOID value){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,21);
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppText=(char**)&mainName;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppText=(char**)&childName;
		LPVOID pv8Conf = &value;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData=(void**)&pv8Conf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			return event.m_infRetData.m_bool;
		}
	}
	return false;
}

//注册变量被取值
bool CALLBACK OnEvtAccessorGet(LPCSTR mainName, LPCSTR childName, LPVOID retval){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,22);
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppText=(char**)&mainName;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppText=(char**)&childName;
		LPVOID pv8Conf = &retval;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData=(void**)&pv8Conf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			return event.m_infRetData.m_bool;
		}
	}
	return false;
}

//注册函数被调用
bool CALLBACK OnEvtAccessorExecute(LPCSTR mainName, LPCSTR childName, int count, LPVOID argv, LPVOID retval){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,23);
		event.m_nArgCount = 5;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppText=(char**)&mainName;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppText=(char**)&childName;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_int = count;
		LPVOID pv8ArgvConf = &argv;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppCompoundData=(void**)&pv8ArgvConf;
		LPVOID pv8RetValConf = &retval;
		event.m_arg[4].m_dwState = EAV_IS_POINTER;
		event.m_arg[4].m_inf.m_ppCompoundData=(void**)&pv8RetValConf;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			return event.m_infRetData.m_bool;
		}
	}
	return false;
}

bool CALLBACK OnEvtBeforeResourceLoad(LPVOID browser,LPVOID frame,LPVOID request,BOOL *is_coped){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,24);
		LPVOID pBi = (void*)&browser,
			pFi = (void*)&frame,
			pRi = (void*)&request;
		event.m_nArgCount = 4;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pFi;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData=&pRi;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_pBool=is_coped;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			return event.m_infRetData.m_bool;
		}
	}
	return true;
}

typedef void(CALLBACK *LPFN_REDIRECT_NEW_URL)(LPCSTR new_url,LPVOID params);
void CALLBACK OnEvtResourceRedirect(LPVOID browser,LPVOID frame,LPVOID request,LPFN_REDIRECT_NEW_URL callback,LPVOID params){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,25);
		LPVOID pBi = (void*)&browser,
			pFi = (void*)&frame,
			pRi = (void*)&request;
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pFi;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData=&pRi;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			if(event.m_infRetData.m_pText!=NULL && strlen(event.m_infRetData.m_pText) > 0){
				callback(event.m_infRetData.m_pText,params);
				g_fnAquaNotifySys(NRS_MFREE,(DWORD)event.m_infRetData.m_pText,0);
				event.m_infRetData.m_pText = NULL;
			}
		}
	}
}

void CALLBACK OnEvtResourceLoadComplete(LPVOID browser,LPVOID frame,LPVOID request,LPVOID response,int status,__int64 received_content_length,void *data){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,26);
		LPVOID pBi = (void*)&browser,
			pFi = (void*)&frame,
			pRi = (void*)&request,
			pRei = (void*)&response;
		event.m_nArgCount = 7;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pFi;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData=&pRi;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppCompoundData=&pRei;
		event.m_arg[4].m_dwState = NULL;
		event.m_arg[4].m_inf.m_int=status;
		event.m_arg[5].m_dwState = NULL;
		event.m_arg[5].m_inf.m_int = (int)received_content_length;
		if(data!=NULL){
			event.m_arg[6].m_dwState = EAV_IS_POINTER;
			event.m_arg[6].m_inf.m_pBin=(BYTE*)&data;
		}
		else {
			INT bin[3] = {1,0,0};
			LPVOID ppBin = (void*)&bin;
			event.m_arg[6].m_dwState = EAV_IS_POINTER;
			event.m_arg[6].m_inf.m_pBin=(BYTE*)&ppBin;
		}
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

bool CALLBACK OnEvtJSDialog(LPVOID browser,LPCSTR url,LPCSTR lang,int type,LPCSTR msg,LPCSTR defaultInput,LPVOID callback){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,27);
		LPVOID pBi = (void*)&browser;
		LPVOID pCi = (void*)&callback;
		event.m_nArgCount = 7;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppText=(char**)&url;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppText=(char**)&lang;
		event.m_arg[3].m_dwState = NULL;
		event.m_arg[3].m_inf.m_int=type;
		event.m_arg[4].m_dwState = EAV_IS_POINTER;
		event.m_arg[4].m_inf.m_ppText=(char**)&msg;
		event.m_arg[5].m_dwState = EAV_IS_POINTER;
		event.m_arg[5].m_inf.m_ppText = (char**)&defaultInput;
		event.m_arg[6].m_dwState = EAV_IS_POINTER;
		event.m_arg[6].m_inf.m_ppCompoundData =(void**)&pCi;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			result = event.m_infRetData.m_bool;
		}
	}
	return result;
}

bool CALLBACK OnEvtFileDialog(LPVOID browser,int mode,LPCSTR title,LPCSTR default_file_path,
							  LPVOID accept_filters,int selected_accept_filter,
							  LPVOID callback){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,28);
		LPVOID pBi = (void*)&browser;
		LPVOID pCi = (void*)&callback;
		LPVOID pSi = (void*)&accept_filters;
		event.m_nArgCount = 7;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = NULL;
		event.m_arg[1].m_inf.m_int=mode;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppText=(char**)&title;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppText=(char**)&default_file_path;
		event.m_arg[4].m_dwState = EAV_IS_POINTER;
		event.m_arg[4].m_inf.m_ppCompoundData=(void**)&pSi;
		event.m_arg[5].m_dwState = NULL;
		event.m_arg[5].m_inf.m_int = selected_accept_filter;
		event.m_arg[6].m_dwState = EAV_IS_POINTER;
		event.m_arg[6].m_inf.m_ppCompoundData =(void**)&pCi;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			result = event.m_infRetData.m_bool;
		}
	}
	return result;
}

bool CALLBACK OnEvtPreKeyEvent(LPVOID browser,LPVOID key,bool *is_keyboard_shortcut){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		AQUA_KEYEVENT_STRUCT vkey = {0};
		AQUA_KEYEVENT_STRUCT *pvkey = &vkey;
		AQUA_KEYEVENT_ORG_STRUCT *org = (AQUA_KEYEVENT_ORG_STRUCT*)key;
		vkey.type = org->type;
		vkey.modifiers = org->modifiers;
		vkey.window_key_codev = org->window_key_codev;
		vkey.native_key_code = org->native_key_code;
		vkey.is_system_key = org->is_system_key;
		vkey.character = (int)org->character;
		vkey.unmodified_character = (int)org->unmodified_character;
		vkey.focus_on_editable_field = org->focus_on_editable_field;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,29);
		LPVOID pBi = (void*)&browser;
		LPVOID pKi = (void*)&vkey;
		BOOL v = false;
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pKi;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_pBool=&v;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		*is_keyboard_shortcut = (bool)v;
		if(event.m_blHasRetVal){
			result = event.m_infRetData.m_bool;
		}
	}
	return result;
}

void CALLBACK OnEvtBeforeDownload(LPVOID browser,LPVOID download,LPCSTR name,LPVOID callback){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,30);
		LPVOID pBi = (void*)&browser;
		LPVOID pDi = (void*)&download;
		LPVOID pCi = (void*)&callback;
		event.m_nArgCount = 4;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pDi;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppText=(char**)&name;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppCompoundData =(void**)&pCi;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

void CALLBACK OnEvtDownloadUpdate(LPVOID browser,LPVOID download,LPVOID callback){
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,31);
		LPVOID pBi = (void*)&browser;
		LPVOID pDi = (void*)&download;
		LPVOID pCi = (void*)&callback;
		event.m_nArgCount = 3;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pDi;
		event.m_arg[2].m_dwState = EAV_IS_POINTER;
		event.m_arg[2].m_inf.m_ppCompoundData =(void**)&pCi;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
	}
}

bool CALLBACK OnEvtContextMenu(LPVOID browser,LPVOID frame,int x,int y){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,32);
		LPVOID pBi = (void*)&browser;
		LPVOID pFi = (void*)&frame;
		event.m_nArgCount = 4;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pFi;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_int = x;
		event.m_arg[3].m_dwState = NULL;
		event.m_arg[3].m_inf.m_int = y;
		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			result = event.m_infRetData.m_bool;
		}
	}
	return result;
}

bool CALLBACK OnEvtGetAuthCredentials(LPVOID browser,LPVOID frame,bool isProxy,LPCSTR host,int port,LPCSTR realm,LPCSTR scheme,LPVOID callback){
	bool result = false;
	if(initialWnd){
		CAquariusWnd *pWnd = (CAquariusWnd*)initialWnd;
		EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,33);
		LPVOID pBi = (void*)&browser;
		LPVOID pFi = (void*)&frame;
		LPVOID pCi = (void*)&callback;
		event.m_nArgCount = 8;
		event.m_arg[0].m_dwState = EAV_IS_POINTER;
		event.m_arg[0].m_inf.m_ppCompoundData=&pBi;
		event.m_arg[1].m_dwState = EAV_IS_POINTER;
		event.m_arg[1].m_inf.m_ppCompoundData=&pFi;
		event.m_arg[2].m_dwState = NULL;
		event.m_arg[2].m_inf.m_bool = isProxy;
		event.m_arg[3].m_dwState = EAV_IS_POINTER;
		event.m_arg[3].m_inf.m_ppText = (char**)&host;
		event.m_arg[4].m_dwState = NULL;
		event.m_arg[4].m_inf.m_int = port;
		event.m_arg[5].m_dwState = EAV_IS_POINTER;
		event.m_arg[5].m_inf.m_ppText = (char**)&realm;
		event.m_arg[6].m_dwState = EAV_IS_POINTER;
		event.m_arg[6].m_inf.m_ppText = (char**)&scheme;
		event.m_arg[7].m_dwState = EAV_IS_POINTER;
		event.m_arg[7].m_inf.m_ppCompoundData=&pCi;

		g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
		if(event.m_blHasRetVal){
			result = event.m_infRetData.m_bool;
		}
	}
	return result;
}

#endif