#ifndef AQUA_LAUNCH_H_
#define AQUA_LAUNCH_H_
#include "utils\aqua_utils.h"

namespace AquaLaunch {
	/**
	 *	系统初始化相关函数
	 */

	///
	//	初始化回调方法,在此方法中可以进行一些初始化设置,更多的设置参数可以通过命令行进行配置,
	//	使用带有Init签名的方法进行参数设置。
	///
	typedef void(CALLBACK *AquaInitCallback)(LPVOID conf);

	///
	//	缓存数据将存储在磁盘上的位置。如果是空的话浏览器将在内置缓存所在的“隐身模式”下创建
	//	用于存储并且没有数据被保存到磁盘。HTML5等数据库 localStorage只会在缓存路径存在
	//	的情况下持续存在于会话中指定。
	///
	AQUAENTRY(void, InitCachePathA)(LPVOID conf,LPCSTR path);

	///
	//	缓存数据将存储在磁盘上的位置。如果是空的话浏览器将在内置缓存所在的“隐身模式”下创建
	//	用于存储并且没有数据被保存到磁盘。HTML5等数据库 localStorage只会在缓存路径存在
	//	的情况下持续存在于会话中指定。
	///
	AQUAENTRY(void, InitCachePathW)(LPVOID conf, LPCWSTR path);

	///
	//	拼写检查字典文件等用户数据所在的位置存储在磁盘上。 如果为空，则为默认平台特定的用户数据
	//	将使用目录（Linux上的"~/.cef_user_data"目录，Mac OS X上的"~/Library/Application
	//	Support/CEF/User Data"目录，Windows 上的"Local Settings\Application Data\CEF
	//	\User Data"配置文件目录。
	///
	AQUAENTRY(void, InitUserDataA)(LPVOID conf, LPCSTR path);

	///
	//	拼写检查字典文件等用户数据所在的位置存储在磁盘上。 如果为空，则为默认平台特定的用户数据
	//	将使用目录（Linux上的"~/.cef_user_data"目录，Mac OS X上的"~/Library/Application
	//	Support/CEF/User Data"目录，Windows 上的"Local Settings\Application Data\CEF
	//	\User Data"配置文件目录。
	///
	AQUAENTRY(void, InitUserDataW)(LPVOID conf, LPCWSTR path);

	///
	//	设置为TRUE,以启用无窗口（离屏）渲染支持。如果应用程序不使用无窗口渲染则启用此值
	//	它可能会降低某些系统的渲染性能。
	///
	AQUAENTRY(void, InitWindowlessRenderingEnabled)(LPVOID conf,BOOL enabled);

	///
	//	保持会话cookie（没有到期日或有效期的cookie间隔）默认情况下使用全局cookie管理器
	//	将此值设置为TRUE,会话cookie通常是短暂的，而且大部分都是Web浏览器不会持续它们。
	//	即使配置了|cache_path|也必须是指定启用此功能。也可以使用“persist-session-cookies”命令行开关。
	//	进行配置。
	///
	AQUAENTRY(void, InitPersistSessionCookies)(LPVOID conf, BOOL enabled);

	///
	//	如果设置为TRUE,将用户首选项保存为缓存路径目录集中的JSON文件,即使配置了|cache_path|
	//	也必须是指定启用此功能。也可以使用"persist-user-preferences"命令行开关。进行配置。
	///
	AQUAENTRY(void, InitPersistUserPreferences)(LPVOID conf, BOOL enabled);

	///
	//	将作为User-Agent HTTP标头返回的值。如果清空了将使用默认的User-Agent字符串。
	//	也可以使用"user-agent"命令行开关,进行配置。
	///
	AQUAENTRY(void, InitUserAgentA)(LPVOID conf, LPCSTR value);

	///
	//	将作为User-Agent HTTP标头返回的值。如果清空了将使用默认的User-Agent字符串。
	//	也可以使用"user-agent"命令行开关,进行配置。
	///
	AQUAENTRY(void, InitUserAgentW)(LPVOID conf, LPCWSTR value);

	///
	//	将作为默认产品部分插入的值User-Agent字符串。字符串。如果为空，则将使用Chromium产品版本。
	//	如果| userAgent |指定此值将被忽略。也可配置"product-version"命令行开关。
	///
	AQUAENTRY(void, InitProductVersionA)(LPVOID conf, LPCSTR value);


	///
	//	将作为默认产品部分插入的值User-Agent字符串。字符串。如果为空，则将使用Chromium产品版本。
	//	如果| userAgent |指定此值将被忽略。也可配置"product-version"命令行开关。
	///
	AQUAENTRY(void, InitProductVersionW)(LPVOID conf, LPCWSTR value);

	///
	//	将传递给WebKit的语言环境字符串。如果清空默认值将使用“en-US”的语言环境。 
	//	在语言环境的Linux上，此值将被忽略使用优先顺序使用环境变量解析来确定：
	//	LANGUAGE，LC_ALL，LC_MESSAGES和LANG。还可以使用"lang"命令行来切换。
	///
	AQUAENTRY(void, InitLocaleA)(LPVOID conf, LPCSTR value);

	///
	//	将传递给WebKit的语言环境字符串。如果清空默认值将使用“en-US”的语言环境。 
	//	在语言环境的Linux上，此值将被忽略使用优先顺序使用环境变量解析来确定：
	//	LANGUAGE，LC_ALL，LC_MESSAGES和LANG。还可以使用"lang"命令行来切换。
	///
	AQUAENTRY(void, InitLocaleW)(LPVOID conf, LPCWSTR value);

	///
	//	初始化V8 JavaScript引擎时将使用的自定义标志。使用自定义标志的后果可能没有
	//	得到很好的测试。使用“js-flags”命令行开关进行配置。
	///
	AQUAENTRY(void, InitJavascriptFlagsA)(LPVOID conf, LPCSTR value);

	///
	//	初始化V8 JavaScript引擎时将使用的自定义标志。使用自定义标志的后果可能没有
	//	得到很好的测试。使用“js-flags”命令行开关进行配置。
	///
	AQUAENTRY(void, InitJavascriptFlagsW)(LPVOID conf, LPCWSTR value);

	///
	//	设置为true,禁用为资源和区域设置加载包文件。必须为浏览器和渲染提供资源包处理程序
	//	如果加载包文件，则通过CefApp :: GetResourceBundleHandler（）进行处理
	//	被禁用。 也可以使用“disable-pack-loading”命令进行配置线路切换。
	///
	AQUAENTRY(void, InitPackloadingDisabled)(LPVOID conf, BOOL enabled);

	///
	//	设置为1024到65535之间的值以启用远程调试指定的端口。 例如，如果8080被指定为远程调试URL
	//	将是http//localhost:8080。CEF可以从任何CEF或者远程调试Chrome浏览器窗口。 
	//	也可以使用"remote-debugging-port"命令行开关进行配置。
	///
	AQUAENTRY(void, InitRemoteDebuggingPort)(LPVOID conf, int value);

	///
	//	为未捕获的异常捕获的堆栈跟踪帧的数量。指定一个正值以启用CefRenderProcessHandler::OnUncaughtException()
	//	回调方法。指定0（默认值）则 OnUncaughtException（）不会被调用。 也可以使用
	//	"uncaught-exception-stack-size"命令行开关进行配置。
	///
	AQUAENTRY(void, InitUncaughtExceptionStackSize)(LPVOID conf,int value);

	///
	//	设置为true（1）忽略与无效SSL证书相关的错误。启用此设置可能会导致潜在的安全漏洞
	//	如"man in the middle"攻击,从互联网加载内容的应用程序不应启用此设置。
	//	也可以使用"ignore-certificate-errors"命令行开关进行配置。
	//	可以通过CefRequestContextSettings.ignore_certificate_errors值为单个CefRequestContext实例覆盖。
	///
	AQUAENTRY(void, InitIgnoreCertificateErrors)(LPVOID conf,BOOL enabled);

	///
	//	设置为true（1）以启用内置网络安全信息（即证书透明度日志，HSTS预加载和锁定信息）的基于日期的到期。
	//	启用此选项可提高网络安全性，但在使用过去10周内构建的CEF二进制文件时可能会导致HTTPS加载失败。
	//	请参阅 https://www.certificate-transparency.org/ 和 https://www.chromium.org/hsts 了解详情。
	///
	AQUAENTRY(void, InitEnableNetSecurityExpiration)(LPVOID conf, BOOL enabled);

	///
	//	加载文档之前以及未指定文档颜色时用于浏览器的背景颜色。alpha分量必须完全不透明（0xFF）或完全透明（0x00）。
	//	如果alpha分量完全不透明，那么RGB分量将用作背景颜色。alpha组件对于窗口化浏览器是完全透明的，然后使用不透明白色的默认值。
	//	如果alpha组件对于无窗口（离屏）浏览器完全透明，则透明绘画将被启用。
	///
	AQUAENTRY(void, InitBackgroundColor)(LPVOID conf,int value);

	///
	//	用逗号分隔的有序的语言代码列表，没有任何将在“Accept-Language”HTTP标头中使用的空格。
	//	可以使用CefBrowserSettings.accept_language_list值在每个浏览器基础上重写。
	//	如果两个值均为空，则将使用“en-US,en”。
	//	可以通过CefRequestContextSettings.accept_language_list值为单个CefRequestContext实例覆盖。
	///
	AQUAENTRY(void, InitAcceptLanguageListA)(LPVOID conf, LPCSTR value);

	///
	//	用逗号分隔的有序的语言代码列表，没有任何将在“Accept-Language”HTTP标头中使用的空格。
	//	可以使用CefBrowserSettings.accept_language_list值在每个浏览器基础上重写。
	//	如果两个值均为空，则将使用“en-US,en”。
	//	可以通过CefRequestContextSettings.accept_language_list值为单个CefRequestContext实例覆盖。
	///
	AQUAENTRY(void, InitAcceptLanguageListW)(LPVOID conf, LPCWSTR value);

	////////////////////////////////////////////////////////////////////////

	 ///
	 //	初始化方法,一般在"main"函数或者初始化代码中优先被调用,
	 //	在|init|回调方法中可以进行一些初始化设置。
	 ///
	AQUAENTRY(int, DoWinMain)(AquaInitCallback init);

	///
	//	消息循环
	///
	AQUAENTRY(int, DoMessageLoop)(void);


}
#endif