#ifndef REQUESTFUNC_H_
#define REQUESTFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_request_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_request_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_request_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_request_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_request_isreadyonly (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaRequestIsReadOnly(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_request_geturl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaRequestGetURL(PPTR,NULL,0);
	if(len > 0 ){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaRequestGetURL(PPTR,buf,len);
		buf[len] = 0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_request_seturl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestSetURL(PPTR,pArgInf[1].m_pText);
}

extern "C"
void aquarius_request_getmethod (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaRequestGetMethod(PPTR,NULL,0);
	if(len > 0 ){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaRequestGetMethod(PPTR,buf,len);
		buf[len] = 0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_request_setmethod (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestSetMethod(PPTR,pArgInf[1].m_pText);
}

extern "C"
void aquarius_request_setreferrerurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestsetReferrerURL(PPTR,pArgInf[1].m_pText,0);
}

extern "C"
void aquarius_request_getreferrer (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaRequestGetReferrer(PPTR,NULL,0);
	if(len > 0 ){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaRequestGetReferrer(PPTR,buf,len);
		buf[len] = 0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_request_getreferrerpolicy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaRequestGetReferrerPolicy(PPTR);
}

extern "C"
void aquarius_request_getpostdata (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	*pRetData->m_ppCompoundData = AquaRequestGetPostData(PPTR);
}

extern "C"
void aquarius_request_setpostdata (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestSetPostData(PPTR,*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_request_getheadermap (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	*pRetData->m_ppCompoundData = AquaRequestGetHeaderMap(PPTR);
}

extern "C"
void aquarius_request_setheadermap (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestSetHeaderMap(PPTR,*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_request_getflags (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaRequestGetFlags(PPTR);
}

extern "C"
void aquarius_request_setflags (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestSetFlags(PPTR,pArgInf[1].m_int);
}

extern "C"
void aquarius_request_getfirstpartyforcookies (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaRequestGetFirstPartyForCookies(PPTR,NULL,0);
	if(len > 0 ){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaRequestGetFirstPartyForCookies(PPTR,buf,len);
		buf[len] = 0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_request_setfirstpartyforcookies (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaRequestCreate();
	AquaRequestSetFirstPartyForCookies(PPTR,pArgInf[1].m_pText);
}

extern "C"
void aquarius_request_getresourcetype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaRequestGetResourceType(PPTR);
}

#endif