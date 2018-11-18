#ifndef STRDICT_H_
#define STRDICT_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtStrDictElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("内部指针"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("存放StrDict对象的指针"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

INT s_nStrDictElementCmdIndex[]={
	19,20,21,22,23,24,25,26,27,28,29,30,31,173
};

#endif
#endif