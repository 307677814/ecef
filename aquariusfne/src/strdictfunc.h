#ifndef STRDICTFUNC_H_
#define STRDICTFUNC_H_

#include "lib2.h"
#include "wapper.h"


extern "C"
void aquarius_strdict_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrDictAlloc();
}

extern "C"
void aquarius_strdict_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_strdict_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrDictCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_strdict_insert(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictInsertA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,pArgInf[2].m_pText);
}

extern "C"
void aquarius_strdict_find(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaStrDictFindA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,NULL,0);
	if (len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrDictFindA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_strdict_getbound(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaStrDictGetBound(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_strdict_getfirst(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = (int)AquaStrDictGetFirst(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_strdict_getnext(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	pRetData->m_bool = AquaStrDictGetNext(*pArgInf->m_ppCompoundData,(LPVOID)pArgInf[1].m_int);
}

extern "C"
void aquarius_strdict_erase(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	AquaStrDictErase((LPVOID)pArgInf[1].m_int);
}

extern "C"
void aquarius_strdict_getkey(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	int len = AquaStrDictGetKeyA((LPVOID)pArgInf[1].m_int,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrDictGetKeyA((LPVOID)pArgInf[1].m_int,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_strdict_getvalue(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	int len = AquaStrDictGetValueA((LPVOID)pArgInf[1].m_int,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrDictGetValueA((LPVOID)pArgInf[1].m_int,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_strdict_setvalue(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_int==0) return;
	if(strlen(pArgInf[2].m_pText)<=0) return;
	AquaStrDictSetValueA((LPVOID)pArgInf[1].m_int,pArgInf[2].m_pText);
}

extern "C"
void aquarius_strdict_remove(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictRemoveA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

extern "C"
void aquarius_strdict_clear(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrDictClear(*pArgInf->m_ppCompoundData);
}

#endif