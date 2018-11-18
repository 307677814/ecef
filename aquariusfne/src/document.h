#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtDocumentElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("内部指针"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("存放对象的指针"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

INT s_nDocumentElementCmdIndex[]={
	151,152,153,154,155,185
};

#endif

#endif