#ifndef WINDOWINFOFUNC_H_
#define WINDOWINFOFUNC_H_
#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_window_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaWindowCreate();
}

extern "C"
void aquarius_window_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaWindowDestoryed(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_window_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaWindowCopy(pArgInf[1].m_pCompoundData);
}

extern "C"
void aquarius_window_setaschild (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL) return;
	if(pArgInf[1].m_dtDataType == _SDT_NULL){

	}
	else {
		AquaWindowSetAsChild(*pArgInf->m_ppCompoundData,(HWND)pArgInf[1].m_int,pArgInf[2].m_int,\
		pArgInf[3].m_int,pArgInf[4].m_int,pArgInf[5].m_int);
	}
}

extern "C"
void aquarius_window_setaspopup (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL) return;
	AquaWindowSetAsPopupA(*pArgInf->m_ppCompoundData,(HWND)pArgInf[1].m_int,pArgInf[2].m_pText);
}

extern "C"
void aquarius_window_setaswindowless (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL) return;
	AquaWindowSetAsWindowless(*pArgInf->m_ppCompoundData,(HWND)pArgInf[1].m_int);
}

extern "C"
void aquarius_window_modifystyle (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL) return;
	AquaWindowModifyStyle(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,pArgInf[2].m_int);
}

#endif