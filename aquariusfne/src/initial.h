#ifndef INITIAL_H_
#define INITIAL_H_
#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtInitialElemnet[]={
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("缓存路径"),
        /*m_szEgName*/          _T("cachePath"),
        /*m_szExplain*/         _T("指定存放缓存数据在磁盘上的存储位置。如果为空的话浏览器将使用内置缓存(\"隐身模式\"),"
									"并且不会把数据保存到磁盘上。HTML5 database 以及 localStorage 这些数据只会在"
									"缓存路径存在的情况下持续存在于指定会话中。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("用户数据路径"),
        /*m_szEgName*/          _T("userdata"),
        /*m_szExplain*/         _T("指定用户拼写检查字典文件等用户数据在磁盘上的存储位置。如果为空,将使用(Windows上的\""
										"Local Settings\\Application Data\\CEF\\User Data\")配置文件目录。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
		{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("离屏渲染模式"),
        /*m_szEgName*/          _T("windowslessRendering"),
        /*m_szExplain*/         _T("设置为真,以启用无窗口(离屏)渲染支持。如果应用程序不使用无窗口渲染则启用此值可能会降低某些系统的渲染性能。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("保持会话"),
        /*m_szEgName*/          _T("persistsessioncookies"),
        /*m_szExplain*/         _T("保持会话cookie(没有到期或有效的cookie间隔)默认情况下使用全局cookie管理器,将此值设置为真。"
									"通常情况下会话cookie是临时的,而且大部分的web浏览器都不会持续它们。在|缓存路径|中也必须是指定启用"
									"此功能。也可以使用\"persist-session-cokies\"命令行开关进行配置。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("保存用户首选项"),
        /*m_szEgName*/          _T("persistUserPreferences"),
        /*m_szExplain*/         _T("如果设置为TRUE,将用户首选项保存为缓存路径目中集中的JSON文件,即使配置了|缓存路径|也必须"
									"是指定启用此功能。也可以使用\"persist-user-preferences\"命令行开关,进行配置。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("用户代理标识符"),
        /*m_szEgName*/          _T("userAgent"),
        /*m_szExplain*/         _T("将作为User-Agent HTTP标头的返回的值。如果设置为空将使用默认的User-Agent字符串"
									"也可以使用\"user-agent\"命令行开关,进行配置。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("产品标识符"),
        /*m_szEgName*/          _T("productVersion"),
        /*m_szExplain*/         _T("将作为默认产品部分插入User-Agent的值。如果为空,则将使用Chromium产品版本，"
									"如果|用户代理标识符|已指定则此值将被忽略。也可使用\"product-version\"命令行开关进行配置。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("本地化语言"),
        /*m_szEgName*/          _T("locale"),
        /*m_szExplain*/         _T("将传递给WebKit的语言环境字符串。如果为空,将使用\"en-US\"的语言环境,"
									"也可使用\"lang\"命令行开关进行配置。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("远程调试端口"),
        /*m_szEgName*/          _T("remoteDebuggingPort"),
        /*m_szExplain*/         _T("设置为1024到65535直接的值以启用远程调试服务,例如: 如果8080被指定为远程调试端口"
									"则将是URL http://localhost:8080。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("忽略SSL证书错误"),
        /*m_szEgName*/          _T("ignoreCertificateErrors"),
        /*m_szExplain*/         _T("设置为真忽略与SSL证书相关的错误,启用此设置可能会导致潜在的安全漏洞,如\"中间人\"攻击"
									",从互联网家族内容的应用程序不应启用此设置,也可以使用\"ignore-certificate-errors\"命令行开关进行配置。"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("AcceptLanguage"),
        /*m_szEgName*/          _T("acceptLanguageList"),
        /*m_szExplain*/         _T("用逗号分隔的语言代码列表,没有任何将在\"Accept-Language\"HTTP标头中使用的空格。默认为\"en-US,en\""),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
};

#endif

#endif