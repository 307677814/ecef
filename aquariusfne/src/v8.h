#ifndef V8T_H_
#define V8T_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtV8Elemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("内部指针"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("存放StrVector对象的指针"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

static LIB_DATA_TYPE_ELEMENT s_dtV8AccessorElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("内部指针"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("存放StrVector对象的指针"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

INT s_nV8CmdIndex[]={
	175,176,177,178,179,180,181
};

INT s_nV8AccessorCmdIndex[]={
	162,163,164,165
};

#endif

#endif