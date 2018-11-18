#ifndef COOKIEFUNC_H_
#define COOKIEFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_cookiemanager_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_cookiemanager_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData !=NULL){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_cookiemanager_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_cookiemanager_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData!=NULL){
		pRetData->m_bool = TRUE;
	}
	else {
		pRetData->m_bool = FALSE;
	}
}

extern "C"
void aquarius_cookiemanager_initfromglobal (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaCookieInitFromGlobal();
}

void CALLBACK OnCookieReceive(int total,LPCSTR name,LPCSTR value,LPCSTR domain,bool secure,bool httponly,bool has_expires,AQUA_TIME *tm,LPVOID params){
	AQUA_COOKIE_CALLING *calling = (AQUA_COOKIE_CALLING*)params;
	if(calling->pAddr == NULL){
		calling->total = 2;
		calling->pAddr = (LPINT)g_fnAquaNotifySys(NRS_MALLOC,sizeof(int)*(total+2),0);
		calling->pAddr[0] = 1;
		calling->pAddr[1] = total;
		if(total == 0) return;
	}
	AQUA_COOKIE *cookie = (AQUA_COOKIE*)g_fnAquaNotifySys(NRS_MALLOC,sizeof(AQUA_COOKIE),0);
	cookie->name=COPYSTRING(name,0);
	cookie->value=COPYSTRING(value,0);
	cookie->domain=COPYSTRING(domain,0);
	cookie->secure=secure;
	cookie->httponly=httponly;
	cookie->has_expires=has_expires;
	cookie->expires = (AQUA_TIME*)g_fnAquaNotifySys(NRS_MALLOC,sizeof(AQUA_TIME),0);
	memcpy(cookie->expires,tm,sizeof(AQUA_TIME));
	calling->pAddr[calling->total++]=(INT)cookie;
}

extern "C"
void aquarius_cookiemanager_getallcookies (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_COOKIE_CALLING calling = {0};
	calling.pRetData=pRetData;
	AquaCookieGetAllCookies(*pArgInf->m_ppCompoundData,OnCookieReceive,&calling);
	pRetData->m_pCompoundData = (void*)calling.pAddr;
}

extern "C"
void aquarius_cookiemanager_geturlcookies (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_COOKIE_CALLING calling = {0};
	calling.pRetData=pRetData;
	AquaCookieGetUrlCookies(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,pArgInf[2].m_bool,OnCookieReceive,&calling);
	pRetData->m_pCompoundData = (void*)calling.pAddr;
}

extern "C"
void aquarius_cookiemanager_setcookie (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_TIME tm = {0};
	if((pArgInf[7].m_dtDataType&MAKELONG(18,0))){
		memcpy(&tm,pArgInf[7].m_pCompoundData,sizeof(AQUA_TIME));
	}
	pRetData->m_bool = AquaCookieSetCookie(*pArgInf->m_ppCompoundData,pArgInf[2].m_pText,pArgInf[3].m_pText,pArgInf[1].m_pText,
		pArgInf[4].m_bool,pArgInf[5].m_bool,pArgInf[6].m_bool,&tm);
}

extern "C"
void aquarius_cookiemanager_deletecookie (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	LPCSTR url = NULL;
	LPCSTR name = NULL;
	if((pArgInf[1].m_dtDataType&SDT_TEXT)){
		url = pArgInf[1].m_pText;
	}
	if((pArgInf[2].m_dtDataType&SDT_TEXT)){
		name = pArgInf[2].m_pText;
	}
	pRetData->m_bool = AquaCookieDeleteCookie(*pArgInf->m_ppCompoundData,url,name);
}

extern "C"
void aquarius_cookiemanager_flushstore (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaCookieFlushStore(*pArgInf->m_ppCompoundData);
}

void CALLBACK OnCookieReceiveMeger(int total,LPCSTR name,LPCSTR value,LPCSTR domain,bool secure,bool httponly,bool has_expires,AQUA_TIME *tm,LPVOID params){
	AQUA_COOKIE_CALLING_MEGER *calling = (AQUA_COOKIE_CALLING_MEGER*)params;
	if(total == 0) return;
	calling->buf<<name<<"="<<value<<"; ";
}

extern "C"
void aquarius_cookiemanager_getcookiemerge (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AQUA_COOKIE_CALLING_MEGER calling;
	calling.pRetData=pRetData;
	if((pArgInf[1].m_dtDataType & SDT_TEXT)){
		AquaCookieGetUrlCookies(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,true,OnCookieReceiveMeger,&calling);
	}
	else {
		AquaCookieGetAllCookies(*pArgInf->m_ppCompoundData,OnCookieReceiveMeger,&calling);
	}
	const std::string &text = calling.buf.str();
	if (text.length()<=0)
	{
		return;
	}
	pRetData->m_pText = COPYSTRING(text.c_str(),text.length());
}


typedef void(CALLBACK *LPFN_COKIE)(LPCSTR name,LPCSTR value,LPVOID params);

void EnumCookies(LPCSTR cookies, LPFN_COKIE callback,LPVOID params) {
	char *buf = (char*)cookies;
	char *name_end = strstr(buf,"=");
	char *name = NULL;
	char *value_end = NULL;
	char *value = NULL;
	while (true)
	{
		if (name_end == NULL) return;
		name = buf;
		buf = name_end + 1;
		value_end = strstr(buf,";");
		if (value_end == NULL) return;
		value = buf;
		buf = value_end + 1;
		*name_end = '\0';
		*value_end = '\0';
		callback(name, value,params);
		*name_end = '=';
		*value_end = ';';
		while (*buf==' '){
			buf++;
		}
		if (*buf == '\0') return;
		name_end = strstr(buf, "=");
	}
}

void CALLBACK OnSetCookie(LPCSTR name,LPCSTR value,LPVOID params){
	AQUA_COOKIE_CALLING_SETCOOKIE *calling = (AQUA_COOKIE_CALLING_SETCOOKIE*)params;
	SYSTEMTIME tm = {0};
	AquaCookieSetCookie(calling->object,name,value,calling->domain,false,false,false,&tm);
}

extern "C"
void aquarius_cookiemanager_setcookiemerge (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	int len1 = strlen(pArgInf[1].m_pText);
	int len2 = strlen(pArgInf[2].m_pText);
	if(len1 <=0 || len2 <=0){
		pRetData->m_bool=FALSE;
		return;
	}
	AQUA_COOKIE_CALLING_SETCOOKIE calling = {0};
	calling.domain = pArgInf[1].m_pText;
	calling.object = *pArgInf->m_ppCompoundData;
	EnumCookies(pArgInf[2].m_pText,OnSetCookie,&calling);
	pRetData->m_bool=TRUE;
}

#endif