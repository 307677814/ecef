#ifndef STRDICTEX_H_
#define STRDICTEX_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtStrDictExElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("内部指针"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("存放StrDictEx对象的指针"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

INT s_nStrDictExElementCmdIndex[]={
	32,33,34,35,36,37,38,39,40,41,42,43,44,174
};

#endif
#endif