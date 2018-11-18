#ifndef STRDICTEXFUNC_H_
#define STRDICTEXFUNC_H_

#include "lib2.h"
#include "wapper.h"


extern "C"
void aquarius_strdictex_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrDictExAlloc();
}

extern "C"
void aquarius_strdictex_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictExDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_strdictex_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrDictExCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_strdictex_insert(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictExInsertA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,pArgInf[2].m_pText);
}

extern "C"
void aquarius_strdictex_find(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	if(*pArgInf->m_ppCompoundData!=NULL){
		if(pArgInf[2].m_dtDataType!=_SDT_NULL){
			*pRetData->m_ppCompoundData = AquaStrDictExFindA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,(void**)pArgInf[2].m_pInt);
		}
		else {
			*pRetData->m_ppCompoundData = AquaStrDictExFindA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,NULL);
		}
	}
}

extern "C"
void aquarius_strdictex_getbound(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaStrDictExGetBound(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_strdictex_getfirst(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = (int)AquaStrDictExGetFirst(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_strdictex_getnext(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	pRetData->m_bool = AquaStrDictExGetNext(*pArgInf->m_ppCompoundData,(LPVOID)pArgInf[1].m_int);
}

extern "C"
void aquarius_strdictex_erase(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	AquaStrDictExErase((LPVOID)pArgInf[1].m_int);
}

extern "C"
void aquarius_strdictex_getkey(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	int len = AquaStrDictExGetKeyA((LPVOID)pArgInf[1].m_int,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrDictExGetKeyA((LPVOID)pArgInf[1].m_int,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_strdictex_getvalue(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	int len = AquaStrDictExGetValueA((LPVOID)pArgInf[1].m_int,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrDictExGetValueA((LPVOID)pArgInf[1].m_int,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_strdictex_setvalue(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	if(strlen(pArgInf[2].m_pText)<=0) return;
	AquaStrDictExSetValueA((LPVOID)pArgInf[1].m_int,pArgInf[2].m_pText);
}

extern "C"
void aquarius_strdictex_remove(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictExRemoveA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

extern "C"
void aquarius_strdictex_clear(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictExClear(*pArgInf->m_ppCompoundData);
}

#endif