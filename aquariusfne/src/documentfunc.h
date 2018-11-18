#ifndef DOCUMENTFUNC_H_
#define DOCUMENTFUNC_H_
#include "lib2.h"

#include "wapper.h"

extern "C"
void aquarius_document_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_document_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaAddRef(*pArgInf[1].m_ppCompoundData);
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_document_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_document_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL)
		pRetData->m_bool = TRUE;
	else
		pRetData->m_bool = FALSE;
}

void CALLBACK OnEvalCallback(int type,LPCSTR string_val,bool bool_val,int int_val,double number_val,LPVOID params,LPCSTR exception){
	AQUA_ASYNC_EVAL *calling = (AQUA_ASYNC_EVAL*)params;
	char temp[64];
	if(calling->pRetData!=NULL){
		if(type == -1){
			if(exception!=NULL && calling->pExcept!=NULL){
				*calling->pExcept->m_ppText = COPYSTRING(exception,0);
				return;
			}
		}
		else if(type == 1) {
			if(bool_val == true){
				calling->pRetData->m_pText = COPYSTRING("true",0);
			}
			else {
				calling->pRetData->m_pText = COPYSTRING("false",0);
			}
		}
		else if(type == 2) {
			
			int len = sprintf(temp,"%d",int_val);
			calling->pRetData->m_pText = COPYSTRING(temp,len);
		}
		else if(type == 3) {
			char temp[64];
			int len = sprintf(temp,"%lf",number_val);
			calling->pRetData->m_pText = COPYSTRING(temp,len);
		}
		else if(type == 4) {
			calling->pRetData->m_pText = COPYSTRING(string_val,0);
		}
	}
	else {
		CAquariusWnd *pWnd = CAquariusWnd::GetMainWnd();
		if(pWnd){
			EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,17);
			LPVOID pBiConf = &calling->pBi;
			char *v2 = (char*)exception;
			char *v1 = NULL;
			event.m_nArgCount = 7;
			event.m_arg[0].m_dwState = EAV_IS_POINTER;
			event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;
			
			event.m_arg[1].m_dwState = NULL;
			event.m_arg[1].m_inf.m_int = 2;
			
			event.m_arg[2].m_dwState = NULL;
			event.m_arg[2].m_inf.m_int = calling->params1;
			
			event.m_arg[3].m_dwState = EAV_IS_POINTER;
			event.m_arg[3].m_inf.m_pText = (char*)&calling->params2;
			
			event.m_arg[4].m_dwState = EAV_IS_POINTER;
			event.m_arg[4].m_inf.m_pBin = (BYTE*)&calling->params3;
			

			if(type == -1 || type == 0){
				event.m_arg[5].m_inf.m_pText = (char*)&v1;
			}
			else if(type == 1){
				if(bool_val)
					strcpy(temp,"true");
				else
					strcpy(temp,"false");
				v1 = &temp[0];
				event.m_arg[5].m_inf.m_pText = (char*)&v1;
			}
			else if(type == 2){
				sprintf(temp,"%d",int_val);
				v1 = &temp[0];
				event.m_arg[5].m_inf.m_pText = (char*)&v1;
			}
			else if(type == 3){
				int len = sprintf(temp,"%lf",number_val);
				v1 = &temp[0];
				event.m_arg[5].m_inf.m_pText = (char*)&v1;
			}
			else if(type == 4){
				event.m_arg[5].m_inf.m_pText = (char*)&string_val;
			}
			event.m_arg[5].m_dwState = EAV_IS_POINTER;

			event.m_arg[6].m_dwState = EAV_IS_POINTER;
			event.m_arg[6].m_inf.m_pText = (char*)&v2;

			g_fnAquaNotifySys(NRS_EVENT_NOTIFY2,(DWORD)&event,0);
			if(calling->pBi!=NULL){
				AquaRelease(calling->pBi);
			}
			if(calling->params2!=NULL){
				g_fnAquaNotifySys(NRS_MFREE,(DWORD)calling->params2,0);
			}
			if(calling->params3!=NULL){
				g_fnAquaNotifySys(NRS_MFREE,(DWORD)calling->params3,0);
			}
		}
		delete calling;
	}
}

extern "C"
void aquarius_document_eval (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	LPCSTR url = "about:blank";
	if((pArgInf[2].m_dtDataType&SDT_TEXT) && strlen(pArgInf[2].m_pText) > 0){
		url = pArgInf[2].m_pText;
	}
	if(pArgInf[5].m_dtDataType == _SDT_NULL || pArgInf[5].m_bool == FALSE){
		AQUA_ASYNC_EVAL eval = {0};
		eval.pRetData = pRetData;
		if(pArgInf[4].m_dtDataType !=_SDT_NULL){
			eval.pExcept=&pArgInf[4];
		}
		AquaFrameEvalA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,url,pArgInf[3].m_int,OnEvalCallback,&eval,FALSE);
	}
	else {
		AQUA_ASYNC_EVAL *pAsyncInfo = new AQUA_ASYNC_EVAL;
		ZeroMemory(pAsyncInfo,sizeof(AQUA_ASYNC_EVAL));
		pAsyncInfo->pRetData = NULL;
		if((pArgInf[6].m_dtDataType & MAKELONG(10,0))){
			pAsyncInfo->pBi=*pArgInf[6].m_ppCompoundData;
			AquaAddRef(pAsyncInfo->pBi);
		}
		if(pArgInf[7].m_dtDataType != _SDT_NULL){
			pAsyncInfo->params1 = pArgInf[7].m_int;
		}
		if(pArgInf[8].m_dtDataType != _SDT_NULL){
			pAsyncInfo->params2 = COPYSTRING(pArgInf[8].m_pText,0);
		}
		if(pArgInf[9].m_dtDataType != _SDT_NULL){
			int len = *(INT*)&pArgInf[9].m_pBin[4];
			pAsyncInfo->params3 = COPYBIN(&pArgInf[9].m_pBin[8],len);
		}
		AquaFrameEvalA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,url,pArgInf[3].m_int,OnEvalCallback,pAsyncInfo,TRUE);
	}
}

extern "C"
void aquarius_document_getframe (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	*pRetData->m_ppCompoundData = *pArgInf->m_ppCompoundData;
	AquaAddRef(*pRetData->m_ppCompoundData);
}

#endif