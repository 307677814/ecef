#ifndef COOKIE_H_
#define COOKIE_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtCookieManagerElemnet[]={
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

INT s_nCookieManagerCmdIndex[]={
	161,162,163,164,165,166,167,168,169,170,171,172
};

static LIB_DATA_TYPE_ELEMENT s_dtCookieElemnet[]={
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("名称"),
        /*m_szEgName*/          _T("name"),
        /*m_szExplain*/         _T("The cookie name."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("值"),
        /*m_szEgName*/          _T("value"),
        /*m_szExplain*/         _T("The cookie value."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("域"),
        /*m_szEgName*/          _T("domain"),
        /*m_szExplain*/         _T("如果| domain | 是空的主机cookie将被创建而不是域cookie。"
								 "cookie与前缀\".\"存储在一起。 对子域可见，而主机cookie不可见。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("安全标记"),
        /*m_szEgName*/          _T("secure"),
        /*m_szExplain*/         _T("如果| secure | 为真，cookie将只发送给HTTPS请求。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("仅限内存访问"),
        /*m_szEgName*/          _T("httponly"),
        /*m_szExplain*/         _T("如果| httponly |为真,这个cookie只会被发送用于HTTP请求。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("是否过期"),
        /*m_szEgName*/          _T("has_expires"),
        /*m_szExplain*/         _T("cookie过期日期仅在|has_expires|为真时有效。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            MAKELONG(18,0),
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("过期时间"),
        /*m_szEgName*/          _T("expires"),
        /*m_szExplain*/         _T("cookie过期日期。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtTimeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("年"),
        /*m_szEgName*/          _T("year"),
        /*m_szExplain*/         _T("四位数年份\"2007\""),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("月"),
        /*m_szEgName*/          _T("month"),
        /*m_szExplain*/         _T("基于1的月份（值1 = 1月份等）"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("星期"),
        /*m_szEgName*/          _T("day_of_week"),
        /*m_szExplain*/         _T("基于0的星期几（0 =星期天等）"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("日"),
        /*m_szEgName*/          _T("day_of_month"),
        /*m_szExplain*/         _T("每月1日（1-31）"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("时"),
        /*m_szEgName*/          _T("hour"),
        /*m_szExplain*/         _T("当天的小时（0-23）"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("分"),
        /*m_szEgName*/          _T("minute"),
        /*m_szExplain*/         _T("当前小时内的分钟数（0-59）"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("秒"),
        /*m_szEgName*/          _T("second"),
        /*m_szExplain*/         _T("当前分钟内的秒数（0-59加闰秒，最多可达60秒）。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("毫秒"),
        /*m_szEgName*/          _T("millisecond"),
        /*m_szExplain*/         _T("当前秒内的毫秒数（0-999）"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
};


#endif

#endif