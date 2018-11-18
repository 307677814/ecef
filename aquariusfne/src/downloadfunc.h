#ifndef DOWNLOADFUNC_H_
#define DOWNLOADFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_downloaditem_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_downloaditem_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_downloaditem_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_downloaditem_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = AquaDownloadIsValid(PPTR);
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_downloaditem_isinprogress (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaDownloadIsInProgress(PPTR);
}

extern "C"
void aquarius_downloaditem_iscomplete (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaDownloadIsComplete(PPTR);
}

extern "C"
void aquarius_downloaditem_iscanceled (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaDownloadIsCanceled(PPTR);
}

extern "C"
void aquarius_downloaditem_getcurrentspeed (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int64 = AquaDownloadGetCurrentSpeed(PPTR);
}

extern "C"
void aquarius_downloaditem_getpercentcomplete (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaDownloadGetPercentComplete(PPTR);
}

extern "C"
void aquarius_downloaditem_gettotalbytes (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int64 = AquaDownloadGetTotalBytes(PPTR);
}

extern "C"
void aquarius_downloaditem_getreceivebytes (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int64 = AquaDownloadGetReceivedBytes(PPTR);
}

extern "C"
void aquarius_downloaditem_getstarttime (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_TIME *tm = (AQUA_TIME*)g_fnAquaNotifySys(NRS_MALLOC,sizeof(AQUA_TIME),0);
	AquaDownloadGetStartTime(PPTR,tm);
	pRetData->m_pCompoundData = tm;
}

extern "C"
void aquarius_downloaditem_getendtime (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_TIME *tm = (AQUA_TIME*)g_fnAquaNotifySys(NRS_MALLOC,sizeof(AQUA_TIME),0);
	AquaDownloadGetEndTime(PPTR,tm);
	pRetData->m_pCompoundData = tm;
}

extern "C"
void aquarius_downloaditem_getfullpath (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaDownloadGetFullPath(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaDownloadGetFullPath(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_downloaditem_getid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaDownloadGetId(PPTR);
}

extern "C"
void aquarius_downloaditem_geturl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaDownloadGetURL(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaDownloadGetURL(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_downloaditem_getoriginalurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaDownloadGetOriginalUrl(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaDownloadGetOriginalUrl(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_downloaditem_getsuggestedfilename (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaDownloadGetSuggestedFileName(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaDownloadGetSuggestedFileName(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_downloaditem_getcontentdisposition (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaDownloadGetContentDisposition(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaDownloadGetContentDisposition(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_downloaditem_getmimetype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaDownloadGetMimeType(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaDownloadGetMimeType(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_beforedownloadcallback_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_beforedownloadcallback_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_beforedownloadcallback_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_beforedownloadcallback_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_beforedownloadcallback_continue (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaDownloadCallbackContinue(PPTR,pArgInf[1].m_pText,pArgInf[2].m_bool);
}

extern "C"
void aquarius_downloaditemcallback_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_downloaditemcallback_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_downloaditemcallback_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_downloaditemcallback_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_downloaditemcallback_cancel (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaDownloadItemCallbackCancel(PPTR);
}

extern "C"
void aquarius_downloaditemcallback_pause (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaDownloadItemCallbackPause(PPTR);
}

extern "C"
void aquarius_downloaditemcallback_resume (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaDownloadItemCallbackResume(PPTR);
}

#endif