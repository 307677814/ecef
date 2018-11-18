#ifndef RESPONSFUNC_H_
#define RESPONSFUNC_H_
#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_response_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_response_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_response_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_response_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_response_isreadyonly (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaResponseIsReadOnly(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_response_getstatus (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaResponseGetStatus(PPTR);
}

extern "C"
void aquarius_response_setstatus (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaResponseCreate();
	AquaResponseSetStatus(PPTR,pArgInf[1].m_int);
}

extern "C"
void aquarius_response_getstatustext (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaResponseGetStatusText(PPTR,NULL,0);
	if(len > 0 ){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaResponseGetStatusText(PPTR,buf,len);
		buf[len] = 0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_response_setstatustext (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaResponseCreate();
	AquaResponseSetStatusText(PPTR,pArgInf[1].m_pText);
}

extern "C"
void aquarius_response_getmimetype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaResponseGetMimeType(PPTR,NULL,0);
	if(len > 0 ){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaResponseGetMimeType(PPTR,buf,len);
		buf[len] = 0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_response_setmimetype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaResponseCreate();
	AquaResponseSetMimeType(PPTR,pArgInf[1].m_pText);
}

extern "C"
void aquarius_response_getheadermap (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	*pRetData->m_ppCompoundData = AquaResponseGetHeaderMap(PPTR);
}

extern "C"
void aquarius_response_setheadermap (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaResponseCreate();
	AquaResponseSetHeaderMap(PPTR,*pArgInf[1].m_ppCompoundData);
}

#endif