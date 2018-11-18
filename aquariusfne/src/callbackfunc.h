#ifndef CALLBACKFUNC_H_
#define CALLBACKFUNC_H_
#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_authcallback_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_authcallback_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_authcallback_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_authcallback_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_authcallback_continue (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaAuthCallbackContinue(PPTR,pArgInf[1].m_pText,pArgInf[2].m_pText);
}

extern "C"
void aquarius_authcallback_cancel (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaAuthCallbackCancel(PPTR);
}

#endif