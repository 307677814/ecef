#ifndef HOSTFUNC_H_
#define HOSTFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_host_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_host_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_host_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_host_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_host_getbrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL){
		*pRetData->m_ppCompoundData = AquaBrowserHostGetBrowser(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_host_closebrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostCloseBrowser(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
	}
}

extern "C"
void aquarius_host_tryclosebrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostTryCloseBrowser(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_setfocus (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostSetFocus(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
	}
}
extern "C"
void aquarius_host_getwindowhandle (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_int = (int)AquaBrowserHostGetWindowHandle(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_getzoomlevel (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_double = AquaBrowserHostGetZoomLevel(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_setzoomlevel (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
			AquaBrowserHostSetZoomLevel(*pArgInf->m_ppCompoundData,pArgInf[1].m_double);
	}
}
extern "C"
void aquarius_host_startdownloada (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostStartDownloadA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
	}
}
extern "C"
void aquarius_host_print (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostPrint(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_showdevtools (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		LPVOID bs = AquaTypeBsCreate();
		AquaBrowserHostShowDevTools(*pArgInf->m_ppCompoundData,*pArgInf[1].m_ppCompoundData,bs,pArgInf[2].m_int,pArgInf[3].m_int);
		AquaTypeBsDestoryed(bs);
	}
}
extern "C"
void aquarius_host_closedevtools (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostCloseDevTools(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_hasdevtools (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostHasDevTools(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_setmousecursorchangedisabled (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostSetMouseCursorChangeDisabled(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
	}
}
extern "C"
void aquarius_host_ismousecursorchangedisabled (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = AquaBrowserHostIsMouseCursorChangeDisabled(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_iswindowrenderingdisabled (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = AquaBrowserHostIsWindowRenderingDisabled(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_wasresized (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostWasResized(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_washidden (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostWasHidden(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
	}
}
extern "C"
void aquarius_host_notifyscreeninfochanged (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostNotifyScreenInfoChanged(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_sendfocusevent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostSendFocusEvent(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
	}
}
extern "C"
void aquarius_host_sendcapturelostevent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostSendCaptureLostEvent(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_notifymoveorresizestarted (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostNotifyMoveOrResizeStarted(*pArgInf->m_ppCompoundData);
	}
}
extern "C"
void aquarius_host_getwindowlessframerate (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_int = AquaBrowserHostGetWindowlessFrameRate(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_host_setwindowlessframerate (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		AquaBrowserHostSetWindowlessFrameRate(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
	}
}

extern "C"
void aquarius_host_getcookiemanager (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL){
		*pRetData->m_ppCompoundData = AquaBrowserHostGetCookieManager(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_host_sendkeyevent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_KEYEVENT_ORG_STRUCT org = {0};
	AQUA_KEYEVENT_STRUCT *vkey = (AQUA_KEYEVENT_STRUCT*)pArgInf[1].m_pCompoundData;
	org.type = vkey->type;
	org.modifiers = vkey->modifiers;
	org.window_key_codev = vkey->window_key_codev;
	org.native_key_code = vkey->native_key_code;
	org.is_system_key = vkey->is_system_key;
	org.character = vkey->character;
	org.unmodified_character = vkey->unmodified_character;
	org.focus_on_editable_field = vkey->focus_on_editable_field;
	AquaBrowserHostSendKeyEvent(PPTR,&org);
}

extern "C"
void aquarius_host_sendmouseclickevent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaBrowserHostSendMouseClickEvent(PPTR,pArgInf[1].m_pCompoundData,pArgInf[2].m_int,pArgInf[3].m_bool,pArgInf[4].m_int);
}

extern "C"
void aquarius_host_sendmousemoveevent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaBrowserHostSendMouseMoveEvent(PPTR,pArgInf[1].m_pCompoundData,pArgInf[2].m_bool);
}

extern "C"
void aquarius_host_sendmousewheelevent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaBrowserHostSendMouseWheelEvent(PPTR,pArgInf[1].m_pCompoundData,pArgInf[2].m_int,pArgInf[3].m_int);
}

#endif