#ifndef REQUEST_CONTEXTFUNC_H_
#define REQUEST_CONTEXTFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_typercs_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaTypeRcsCreate();
}

extern "C"
void aquarius_typercs_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaTypeRcsCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_typercs_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaTypeRcsDestoryed(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_typercs_cachepath (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaTypeRcsCachePathA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

extern "C"
void aquarius_typercs_persistsessioncookies (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaTypeRcsPersistSessionCookies(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
}

extern "C"
void aquarius_typercs_persistuserpreferences (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaTypeRcsPersistUserPreferences(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
}

extern "C"
void aquarius_typercs_ignorecertificateerrors (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaTypeRcsIgnoreCertificateErrors(*pArgInf->m_ppCompoundData,pArgInf[1].m_bool);
}


#endif