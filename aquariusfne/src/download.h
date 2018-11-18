#ifndef DOWNLOAD_H_
#define DOWNLOAD_H_
#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtDownloadElemnet[]={
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

INT s_nDownloadElementCmdIndex[]={
	258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277
};

static LIB_DATA_TYPE_ELEMENT s_dtDownloadCallbackElemnet[]={
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

INT s_nDownloadCallbackElementCmdIndex[]={
	278,279,280,281,282
};

static LIB_DATA_TYPE_ELEMENT s_dtDownloadItemCallbackElemnet[]={
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

INT s_nDownloadItemCallbackElementCmdIndex[]={
	283,284,285,286,287,288,289
};

#endif

#endif