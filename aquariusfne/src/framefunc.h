#ifndef FRAMEFUNC_H_
#define FRAMEFUNC_H_

#include "lib2.h"


extern "C"
void aquarius_frame_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_frame_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaAddRef(*pArgInf[1].m_ppCompoundData);
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_frame_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}
extern "C"
void aquarius_frame_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL)
		pRetData->m_bool = TRUE;
	else
		pRetData->m_bool = FALSE;
}

extern "C"
void aquarius_frame_undo (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameUndo(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_redo (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameRedo(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_cut (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameCut(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_copytext (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameCopy(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_paste (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFramePaste(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_delete (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameDelete(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_selectall (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameSelectAll(*pArgInf->m_ppCompoundData);
}

void CALLBACK OnOutputString(const char *buf,int len,LPVOID params){
	AQUA_ASYNC_CALLING *calling = (AQUA_ASYNC_CALLING*)params;
	if(calling->pRetData !=NULL){
		calling->pRetData->m_pText = COPYSTRING((char*)buf,len);
	}
	else {
		CAquariusWnd *pWnd = CAquariusWnd::GetMainWnd();
		if(pWnd){
			EVENT_NOTIFY2 event(pWnd->m_dwWinFormID,pWnd->m_dwUnitID,17);
			LPVOID pBiConf = &calling->pBi;
			char *v2 = NULL;
			event.m_nArgCount = 7;
			event.m_arg[0].m_dwState = EAV_IS_POINTER;
			event.m_arg[0].m_inf.m_ppCompoundData=(void**)&pBiConf;

			event.m_arg[1].m_dwState = NULL;
			event.m_arg[1].m_inf.m_int = calling->cmd;

			event.m_arg[2].m_dwState = NULL;
			event.m_arg[2].m_inf.m_int = calling->params1;

			event.m_arg[3].m_dwState = EAV_IS_POINTER;
			event.m_arg[3].m_inf.m_pText = (char*)&calling->params2;

			event.m_arg[4].m_dwState = EAV_IS_POINTER;
			event.m_arg[4].m_inf.m_pBin = (BYTE*)&calling->params3;

			event.m_arg[5].m_dwState = EAV_IS_POINTER;
			event.m_arg[5].m_inf.m_pText = (char*)&buf;

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
void aquarius_frame_getsource (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_dtDataType == _SDT_NULL || pArgInf[1].m_bool == FALSE){
		AQUA_ASYNC_CALLING asyncInfo = {0};
		asyncInfo.pRetData = pRetData;
		asyncInfo.pBi=NULL;
		asyncInfo.cmd = 0;
		AquaFrameGetSourceA(*pArgInf->m_ppCompoundData,OnOutputString,&asyncInfo,FALSE);
	}
	else {
		AQUA_ASYNC_CALLING *pAsyncInfo = new AQUA_ASYNC_CALLING;
		ZeroMemory(pAsyncInfo,sizeof(AQUA_ASYNC_CALLING));
		pAsyncInfo->pRetData = NULL;
		pAsyncInfo->cmd = 0;
		if((pArgInf[2].m_dtDataType & MAKELONG(10,0))){
			pAsyncInfo->pBi=*pArgInf[2].m_ppCompoundData;
			AquaAddRef(pAsyncInfo->pBi);
		}
		if(pArgInf[3].m_dtDataType != _SDT_NULL){
			pAsyncInfo->params1 = pArgInf[3].m_int;
		}
		if(pArgInf[4].m_dtDataType != _SDT_NULL){
			pAsyncInfo->params2 = COPYSTRING(pArgInf[4].m_pText,0);
		}
		if(pArgInf[5].m_dtDataType != _SDT_NULL){
			int len = *(INT*)&pArgInf[5].m_pBin[4];
			pAsyncInfo->params3 = COPYBIN(&pArgInf[5].m_pBin[8],len);
		}
		AquaFrameGetSourceA(*pArgInf->m_ppCompoundData,OnOutputString,pAsyncInfo,TRUE);
	}
}

extern "C"
void aquarius_frame_gettext (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_dtDataType == _SDT_NULL || pArgInf[1].m_bool == FALSE){
		AQUA_ASYNC_CALLING asyncInfo = {0};
		asyncInfo.pRetData = pRetData;
		asyncInfo.pBi=NULL;
		asyncInfo.cmd = 1;
		AquaFrameGetTextA(*pArgInf->m_ppCompoundData,OnOutputString,&asyncInfo,FALSE);
	}
	else {
		AQUA_ASYNC_CALLING *pAsyncInfo = new AQUA_ASYNC_CALLING;
		ZeroMemory(pAsyncInfo,sizeof(AQUA_ASYNC_CALLING));
		pAsyncInfo->pRetData = NULL;
		pAsyncInfo->cmd = 1;
		if((pArgInf[2].m_dtDataType & MAKELONG(10,0))){
			pAsyncInfo->pBi=*pArgInf[2].m_ppCompoundData;
			AquaAddRef(pAsyncInfo->pBi);
		}
		if(pArgInf[3].m_dtDataType != _SDT_NULL){
			pAsyncInfo->params1 = pArgInf[3].m_int;
		}
		if(pArgInf[4].m_dtDataType != _SDT_NULL){
			pAsyncInfo->params2 = COPYSTRING(pArgInf[4].m_pText,0);
		}
		if(pArgInf[5].m_dtDataType != _SDT_NULL){
			int len = *(INT*)&pArgInf[5].m_pBin[4];
			pAsyncInfo->params3 = COPYBIN(&pArgInf[5].m_pBin[8],len);
		}
		AquaFrameGetTextA(*pArgInf->m_ppCompoundData,OnOutputString,pAsyncInfo,TRUE);
	}
}

extern "C"
void aquarius_frame_loadurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(pArgInf[1].m_pText == NULL || strlen(pArgInf[1].m_pText) <= 0) {
		return ;
	}
	AquaFrameLoadURLA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

extern "C"
void aquarius_frame_loadstring (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	const char *backupURL = "about:blank";
	if(pArgInf[1].m_pText == NULL || strlen(pArgInf[1].m_pText) <= 0) {
		return ;
	}
	if((pArgInf[2].m_dtDataType & SDT_TEXT) && pArgInf[2].m_pText != NULL && strlen(pArgInf[2].m_pText) > 0) {
		backupURL = pArgInf[2].m_pText;
	}
	AquaFrameLoadStringA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,backupURL);
}

extern "C"
void aquarius_frame_executejavascript (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	const char *backupURL = "about:blank";
	if(pArgInf[1].m_pText == NULL || strlen(pArgInf[1].m_pText) <= 0) {
		return ;
	}
	if((pArgInf[2].m_dtDataType & SDT_TEXT) && pArgInf[2].m_pText != NULL && strlen(pArgInf[2].m_pText) > 0) {
		backupURL = pArgInf[2].m_pText;
	}
	AquaFrameExecuteJavaScriptA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,backupURL,pArgInf[3].m_int);
}

extern "C"
void aquarius_frame_ismain (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaFrameIsMain(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_isfocused (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaFrameIsFocused(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_getname (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaFrameGetNameA(*pArgInf->m_ppCompoundData,"",0);
	if(len > 0 ){
		pRetData->m_pText = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaFrameGetNameA(*pArgInf->m_ppCompoundData,pRetData->m_pText,len);
		pRetData->m_pText[len]='\0';
	}
}

extern "C"
void aquarius_frame_getid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int64 = AquaFrameGetIdentifier(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_frame_parent (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	LPVOID pFi= AquaFrameGetParent(*pArgInf->m_ppCompoundData);
	if(pFi!=NULL){
		*pRetData->m_ppCompoundData=pFi;
	}
}

extern "C"
void aquarius_frame_geturl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaFrameGetURLA(*pArgInf->m_ppCompoundData,"",0);
	if(len > 0 ){
		pRetData->m_pText = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaFrameGetURLA(*pArgInf->m_ppCompoundData,pRetData->m_pText,len);
		pRetData->m_pText[len]='\0';
	}
}

extern "C"
void aquarius_frame_getbrowser (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_ppCompoundData=(void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	LPVOID pBi= AquaFrameGetBrowser(*pArgInf->m_ppCompoundData);
	if(pBi!=NULL){
		*pRetData->m_ppCompoundData=pBi;
	}
}

extern "C"
void aquarius_frame_getdocument (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaAddRef(*pArgInf->m_ppCompoundData);
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = *pArgInf->m_ppCompoundData;
}

extern "C"
void aquarius_frame_loadrequest (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaFrameLoadRequest(PPTR,*pArgInf[1].m_ppCompoundData);
}

#endif