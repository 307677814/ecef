#ifndef STRVECTORFUNC_H_
#define STRVECTORFUNC_H_

#include "lib2.h"
#include <windows.h>
#include "wapper.h"


///
//	StrVector 构造函数
///
extern "C"
void aquarius_strvector_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrVectorAlloc();
}

///
//	StrVector 复制构造函数
///
extern "C"
void aquarius_strvector_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrVectorCopy(*pArgInf[1].m_ppCompoundData);
}

///
//	StrVector 析构函数
///
extern "C"
void aquarius_strvector_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

///
//	执行该方法向|object|指向的"String Vector"字符串向量/数组对象中
//	追加字符串|text|
///
extern "C"
void aquarius_strvector_append (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorAppendA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
//	所关联的字符串值
///
extern "C"
void aquarius_strvector_replace(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorReplaceA(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,pArgInf[2].m_pText);
}

///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
//	所关联的字符串值
///
extern "C"
void aquarius_strvector_remove(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorRemove(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
}

///
//	执行该方法后将会清空|object|指向的"String Vector"字符串向量中的所有字符串值
///
extern "C"
void aquarius_strvector_clear(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorClear(*pArgInf->m_ppCompoundData);
}

///
//	返回数组边界
///
extern "C"
void aquarius_strvector_get_bound(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaStrVectorGetBound(*pArgInf->m_ppCompoundData);
}

///
//	获取成员数据,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度,|index|从0开始。
///
extern "C"
void aquarius_strvector_get_element(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaStrVectorGetElementA(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrVectorGetElementA(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

#endif