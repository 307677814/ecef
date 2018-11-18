#ifndef COMMANDLINEFUNC_H_
#define COMMANDLINEFUNC_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_commandline_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_commandline_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaCommandLineCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_commandline_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_commandline_attach (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData){
		AquaRelease(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData=(void*)pArgInf[1].m_int;
	if(*pArgInf->m_ppCompoundData){
		AquaAddRef(*pArgInf->m_ppCompoundData);
	}
}

extern "C"
void aquarius_commandline_isvalid (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		pRetData->m_bool = FALSE;
		return;
	}
	pRetData->m_bool = AquaCommandLineIsValid(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_commandline_isreadonly (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		pRetData->m_bool = FALSE;
		return;
	}
	pRetData->m_bool = !AquaCommandLineIsReadOnly(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_commandline_hasswitches (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		pRetData->m_bool = FALSE;
		return;
	}
	pRetData->m_bool = AquaCommandLineHasSwitches(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_commandline_hasSwitcha(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		pRetData->m_bool = FALSE;
		return;
	}
	pRetData->m_bool = AquaCommandLineHasSwitchA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

extern "C"
void aquarius_commandline_getswitchvaluea(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		return;
	}
	int len = AquaCommandLineGetSwitchValueA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaCommandLineGetSwitchValueA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_commandline_getswitches(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		return;
	}
	pRetData->m_pCompoundData = AquaCommandLineGetSwitches(*pArgInf->m_ppCompoundData);
}

extern "C"
void aquarius_commandline_appendswitcha(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		return;
	}
	AquaCommandLineAppendSwitchA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

extern "C"
void aquarius_commandline_appendswitchwithvaluea(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		return;
	}
	AquaCommandLineAppendSwitchWithValueA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText,pArgInf[2].m_pText);
}

extern "C"
void aquarius_commandline_getcommandlinestringa(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		return;
	}
	int len = AquaCommandLineGetCommandLineStringA(*pArgInf->m_ppCompoundData,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaCommandLineGetCommandLineStringA(*pArgInf->m_ppCompoundData,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

extern "C"
void aquarius_commandline_getglobalcommandline(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData != NULL){
		AquaRelease(*pArgInf->m_ppCompoundData);
	}
	*pArgInf->m_ppCompoundData = AquaGetGlobalCommandLine();
	
}

extern "C"
void aquarius_commandline_initfromstringa(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	if(*pArgInf->m_ppCompoundData == NULL){
		*pArgInf->m_ppCompoundData = AquaCreateCommandLine();
	}
	AquaCommandLineInitFromStringA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}
#endif