#ifndef BROWSERFUNC_H_
#define BROWSERFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_browser_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_browser_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_browser_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_browser_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_browser_gethost (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;

	if(*pArgInf->m_ppCompoundData!=NULL) {
		*pRetData->m_ppCompoundData = AquaBrowserGetHost(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_cangoback (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_bool = AquaBrowserCanGoBack(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_goback (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		AquaBrowserGoBack(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_cangoforward (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_bool = AquaBrowserCanGoForward(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_goforward (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		AquaBrowserGoForward(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_isready (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_bool = !AquaBrowserIsLoading(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_reload (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		AquaBrowserReload(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_reloadignorecache (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		AquaBrowserReloadIgnoreCache(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_stopload (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		AquaBrowserStopLoad(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_gettabid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_int64 = AquaBrowserGetIdentifier(*pArgInf->m_ppCompoundData);
	}
	else pRetData->m_int64 = -1;
}

extern "C"
void aquarius_browser_ispopup (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_bool = AquaBrowserIsPopup(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_hasdocument (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_bool = AquaBrowserHasDocument(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_getmainframe (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL){ 
		*pRetData->m_ppCompoundData = AquaBrowserGetMainFrame(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_getfocusframe (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL) {
		*pRetData->m_ppCompoundData = AquaBrowserGetFocusedFrame(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_getframefromid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL) {
		*pRetData->m_ppCompoundData = AquaBrowserGetFrameFromId(*pArgInf->m_ppCompoundData,pArgInf[1].m_int64);
	}
}

extern "C"
void aquarius_browser_getframefromnamea (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL) {
		*pRetData->m_ppCompoundData = AquaBrowserGetFrameFromNameA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
	}
}

extern "C"
void aquarius_browser_getframecount (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL) {
		pRetData->m_int = AquaBrowserGetFrameCount(*pArgInf->m_ppCompoundData);
	}	
}

extern "C"
void aquarius_browser_getframeidentifiers (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL) {
		*pRetData->m_ppCompoundData = AquaBrowserGetFrameIdentifiers(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_browser_getframenames (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL) {
		*pRetData->m_ppCompoundData = AquaBrowserGetFrameNames(*pArgInf->m_ppCompoundData);
	}
}
#endif