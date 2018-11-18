#ifndef V8FUNC_H_
#define V8FUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_v8_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaV8ValueAlloc();
}

extern "C"
void aquarius_v8_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaV8ValueCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_v8_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaV8ValueDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_v8_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_v8_gettype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int v = AquaV8ValueGetType(*pArgInf->m_ppCompoundData, pArgInf[1].m_int);
	if(v == 0){
		pRetData->m_int = 7;
	}
	else if(v == 1){
		pRetData->m_int = 3;
	}
	else if(v == 2){
		pRetData->m_int = 6;
	}
	else if(v == 3){
		pRetData->m_int = 10;
	}
}

extern "C"
void aquarius_v8_getvalue (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	V8VALUESTRUCT *retval = (V8VALUESTRUCT*)AquaV8ValueGetValue(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
	if(retval){
		if(retval->type == 0){
			pRetData->m_dtDataType = SDT_BOOL;
			pRetData->m_bool = retval->v1;
		}
		else if(retval->type == 1){
			pRetData->m_dtDataType = SDT_INT;
			pRetData->m_bool = retval->v2;
		}
		else if(retval->type == 2){
			pRetData->m_dtDataType = SDT_DOUBLE;
			pRetData->m_double = retval->v3;
		}
		else if(retval->type == 3){
			pRetData->m_dtDataType = SDT_TEXT;
			pRetData->m_pText = COPYSTRING(retval->v4,0);
		}
		retval->free(retval);
	}
}

extern "C"
void aquarius_v8_setvalue (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	V8VALUESTRUCT v8;
	v8.type = -1;
	if((pArgInf[1].m_dtDataType&SDT_BOOL) == SDT_BOOL){
		v8.type = 0;
		v8.v1 = pArgInf[1].m_bool;
	}
	else if((pArgInf[1].m_dtDataType&SDT_INT) == SDT_INT){
		v8.type = 1;
		v8.v2 = pArgInf[1].m_int;
	}
	else if((pArgInf[1].m_dtDataType&SDT_DOUBLE) == SDT_DOUBLE){
		v8.type = 2;
		v8.v3 = pArgInf[1].m_double;
	}
	else if((pArgInf[1].m_dtDataType&SDT_TEXT) == SDT_TEXT){
		v8.type = 3;
		v8.v4 = pArgInf[1].m_pText;
	}
	if(v8.type!=-1){
		AquaV8ValueSetValue(*pArgInf->m_ppCompoundData,&v8);
	}
}

#endif