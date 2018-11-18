#ifndef POSTDATAFUNC_H_
#define POSTDATAFUNC_H_
#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_postdataelement_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_postdataelement_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_postdataelement_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_postdataelement_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_postdataelement_isreadnoly (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaPostDataElementIsReadOnly(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_postdataelement_settoempty (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL) *pArgInf->m_ppCompoundData = AquaPostDataElementCreate();
	AquaPostDataElementSetToEmpty(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_postdataelement_settofile (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_pText!= NULL && strlen(pArgInf[1].m_pText) > 0){
		if(*pArgInf->m_ppCompoundData == NULL) *pArgInf->m_ppCompoundData = AquaPostDataElementCreate();
		AquaPostDataElementSetToFile(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
	}
}

extern "C"
void aquarius_postdataelement_settobytes (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_pText!= NULL> 0){
		if(*pArgInf->m_ppCompoundData == NULL) *pArgInf->m_ppCompoundData = AquaPostDataElementCreate();
		LPBYTE buf = pArgInf[1].m_pBin;
		AquaPostDataElementSetToBytes(*pArgInf->m_ppCompoundData,*(int*)&buf[4],&buf[8]);
	}
}

extern "C"
void aquarius_postdataelement_gettype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaPostDataElementGetType(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_postdataelement_getfile (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaPostDataElementGetFile(*pArgInf->m_ppCompoundData,NULL,0);
	char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
	AquaPostDataElementGetFile(*pArgInf->m_ppCompoundData,buf,len);
	buf[len]=0;
	pRetData->m_pText = buf;
}

extern "C"
void aquarius_postdataelement_getbytes (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaPostDataElementGetBytesCount(PPTR);
	LPBYTE buf = (BYTE*)g_fnAquaNotifySys(NRS_MALLOC,len+sizeof(int)*2,0);
	*(int*)&buf[0] = 1;
	*(int*)&buf[4] = len;
	AquaPostDataElementGetBytes(*pArgInf->m_ppCompoundData,len,&buf[8]);
	pRetData->m_pBin = buf;
}


//////////////////////////////////////////////////////////////////////////////////

extern "C"
void aquarius_postdata_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_postdata_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_postdata_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_postdata_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_postdata_isreadnoly (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaPostDataIsReadOnly(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_postdata_hasexcludedelements (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaPostDataHasExcludedElements(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_postdata_getelementcount (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaPostDataGetElementCount(*pArgInf->m_ppCompoundData);
}

void CALLBACK OnElementReceive(int total,int index,LPVOID element,LPVOID params){
	AQUA_POSTDATA_CALLING *calling = (AQUA_POSTDATA_CALLING*)params;
	if(calling->pAddr == NULL){
		calling->total = 2;
		calling->pAddr = (LPINT)g_fnAquaNotifySys(NRS_MALLOC,sizeof(int)*(total+2),0);
		calling->pAddr[0] = 1;
		calling->pAddr[1] = total;
		if(total == 0) return;
	}
	LPVOID data = (void*)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*(DWORD*)data = (DWORD)element;
	calling->pAddr[calling->total++] = (INT)data;
}

extern "C"
void aquarius_postdata_getelements (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_POSTDATA_CALLING calling = {0};
	calling.pRetData = pRetData;
	AquaPostDataGetElements(PPTR,OnElementReceive,&calling);
	pRetData->m_pCompoundData = (void*)calling.pAddr;
}

extern "C"
void aquarius_postdata_removeelement (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaPostDataCreate();
	AquaPostDataRemoveElement(PPTR,*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_postdata_addelement (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR == NULL) PPTR = AquaPostDataCreate();
	AquaPostDataAddElement(PPTR,*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_postdata_removeelements (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(PPTR){
		AquaPostDataRemoveElements(PPTR);
	}

}


#endif