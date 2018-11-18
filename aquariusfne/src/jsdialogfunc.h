#ifndef JSDIALOGFUNC_H_
#define JSDIALOGFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_jsdialogcallback_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_jsdialogcallback_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_jsdialogcallback_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_jsdialogcallback_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_jsdialogcallback_continue (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaJSDialogContinue(PPTR,pArgInf[1].m_bool,pArgInf[2].m_pText);
}


#endif