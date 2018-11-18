#ifndef INT64VECTORFUNC_H_
#define INT64VECTORFUNC_H_
#include "wapper.h"

#include "lib2.h"


extern "C"
void aquarius_int64vector_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaInt64VectorAlloc();
}

extern "C"
void aquarius_int64vector_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaInt64VectorCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_int64vector_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_int64vector_append (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorAppend(*pArgInf->m_ppCompoundData,pArgInf[1].m_int64);
}


///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
//	所关联的字符串值
///
extern "C"
void aquarius_int64vector_replace(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorReplace(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,pArgInf[2].m_int64);
}

///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
//	所关联的字符串值
///
extern "C"
void aquarius_int64vector_remove(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorRemove(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
}

///
//	执行该方法后将会清空|object|指向的"String Vector"字符串向量中的所有字符串值
///
extern "C"
void aquarius_int64vector_clear(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorClear(*pArgInf->m_ppCompoundData);
}

///
//	返回数组边界
///
extern "C"
void aquarius_int64vector_get_bound(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaInt64VectorGetBound(*pArgInf->m_ppCompoundData);
}

///
//	获取成员数据,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度,|index|从0开始。
///
extern "C"
void aquarius_int64vector_get_element(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int64 = AquaInt64VectorGetElement(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
}

#endif