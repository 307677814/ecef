#ifndef AQUA_TYPES_REFER_H_
#define AQUA_TYPES_REFER_H_
#include "utils\aqua_utils.h"

/**
  * 声明在框架中所使用到的数据结构
  * * * * * * * * * * * * * * * */

namespace AquaTypes {

	/******************************
	*		BrowserSettings
	******************************/

	///
	//	浏览器初始化设置。 指定NULL或0以获得建议
	//	默认值。 使用自定义值的后果可能不太好
	//	测试。 许多这些和其他设置也可以使用命令行配置，
	//	线路开关。
	///
	namespace BrowserSettings {

		typedef enum {
			///
			// Use the default state for the setting.
			///
			STATE_DEFAULT = 0,

			///
			// Enable or allow the setting.
			///
			STATE_ENABLED,

			///
			// Disable or disallow the setting.
			///
			STATE_DISABLED,
		} TypeBsStateType;

		///
		//	创建一个Bs对象
		///
		AQUAENTRYFULL(LPVOID, TypeBs, Create)(void);

		///
		//	拷贝一个Bs对象
		///
		AQUAENTRYFULL(LPVOID, TypeBs, Copy)(LPVOID object);

		///
		//	销毁一个Bs对象
		///
		AQUAENTRYFULL(void, TypeBs, Destoryed)(LPVOID object);

		///
		//	以每秒帧数（fps）表示CefRenderHandler :: OnPaint的最大速率
		//	将被称为无窗口浏览器。 实际的fps可能会更低
		//	浏览器无法按请求的速率生成帧。 最低
		//	值为1，最大值为60（默认为30）。 这个值也可以
		//	通过CefBrowserHost :: SetWindowlessFrameRate动态更改。
		///
		AQUAENTRYFULL(void, TypeBs, WindowlessFrameRate)(LPVOID conf,int value);

		//The below values map to WebPreferences settings.

		///
		// 字体设置.
		///
		AQUAENTRYFULL(void, TypeBs, StandardFontFamilyA)(LPVOID conf,LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, FixedFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, SerifFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, SansSerifFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, CursiveFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, FantasyFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, StandardFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, FixedFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, SerifFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, SansSerifFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, CursiveFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, FantasyFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, DefaultFontSize)(LPVOID conf, int value);
		AQUAENTRYFULL(void, TypeBs, DefaultFixedFontFize)(LPVOID conf, int value);
		AQUAENTRYFULL(void, TypeBs, MinimumFontSize)(LPVOID conf, int value);
		AQUAENTRYFULL(void, TypeBs, MinimumLogicalFontSize)(LPVOID conf, int value);

		///
		//	Web内容的默认编码。 如果将使用空的“ISO-8859-1”。 也
		//	使用“默认编码”命令行开关进行配置。
		///
		AQUAENTRYFULL(void, TypeBs, DefaultEncodingA)(LPVOID conf,LPCSTR value);

		///
		//	Web内容的默认编码。 如果将使用空的“ISO-8859-1”。 也
		//	使用“默认编码”命令行开关进行配置。
		///
		AQUAENTRYFULL(void, TypeBs, DefaultEncodingW)(LPVOID conf, LPCWSTR value);

		///
		//	控制从远程源加载字体。 也可以使用配置
		//	“disable-remote-fonts”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, RemoteFonts)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否可以执行JavaScript。 也可以使用
		//	“disable-javascript”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, JavaScript)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否可以使用JavaScript关闭不是的窗口
		//	通过JavaScript打开。 JavaScript仍然可以用来关闭那个窗口
		//	通过JavaScript打开或者没有后退/前进历史记录。 也
		//	使用“disable-javascript-close-windows”命令行进行配置
		//	开关。
		///
		AQUAENTRYFULL(void, TypeBs, JavaScriptCloseWindows)(LPVOID conf, TypeBsStateType value);

		///
		//	控制JavaScript是否可以访问剪贴板。 也可配置
		//	使用“disable-javascript-access-clipboard”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, JavascriptAccessClipboard)(LPVOID conf, TypeBsStateType value);

		///
		//	控制编辑器是否支持DOM粘贴
		//	execCommand（“paste”），|javascript_access_clipboard|设置也必须
		//	被启用。也可以使用“disable-javascript-dom-paste”
		//	命令行切换。
		///
		AQUAENTRYFULL(void, TypeBs, JavascriptDomPaste)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否加载任何插件。 也可以使用
		//	“disable-plugins”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, Plugins)(LPVOID conf, TypeBsStateType value);

		///
		//	控制文件URL是否可以访问所有URL。 也可配置
		//	使用“allow-universal-access-from-files”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, UniversalAccessFromFileUrls)(LPVOID conf, TypeBsStateType value);

		///
		//	控制文件URL是否可以访问其他文件URL。 也
		//	使用“allow-access-from-files”命令行开关进行配置。
		///
		AQUAENTRYFULL(void, TypeBs, FileAccessFromFileUrls)(LPVOID conf, TypeBsStateType value);

		///
		//	控制网络安全限制（同源策略）是否会
		//	强制执行。 不推荐使用此设置，因为这会带来风险
		//	安全行为，如跨站点脚本（XSS）。 也可配置
		//	使用“disable-web-security”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, WebSecurity)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否从网络加载图像URL。 一张缓存的图片
		//	如果有要求，仍然会呈现。 也可以使用
		//	“disable-image-loading”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, ImageLoading)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否缩小独立图像以适应页面。 也
		//	使用“image-shrink-standalone-to-fit”命令行进行配置
		//	开关。
		///
		AQUAENTRYFULL(void, TypeBs, ImageShrinkStandaloneToFit)(LPVOID conf, TypeBsStateType value);

		///
		//	控制文本区域是否可以调整大小。 也可以使用
		//	“disable-text-area-resize”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, TextAreaResize)(LPVOID conf, TypeBsStateType value);

		///
		//	控制Tab键是否可以将焦点提升到链接。 也可配置
		//	使用“disable-tab-to-links”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, TabToLinks)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否可以使用本地存储。 也可以使用
		//	“disable-local-storage”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, LocalStorage)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否可以使用数据库。 也可以使用
		//	“disable-databases”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, Databases)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否可以使用应用程序缓存。 也可以使用配置
		//	“disable-application-cache”命令行开关。
		///
		AQUAENTRYFULL(void, TypeBs, ApplicationCache)(LPVOID conf, TypeBsStateType value);

		///
		//	控制是否可以使用WebGL。 请注意，WebGL需要硬件
		//	支持，即使启用，也可能无法在所有系统上运行。 也
		//	使用“disable-webgl”命令行开关进行配置。
		///
		AQUAENTRYFULL(void, TypeBs, WebGL)(LPVOID conf, TypeBsStateType value);

		///
		//	在加载文档之前和之后，用于浏览器的背景颜色
		//	没有指定文档颜色。 alpha分量必须是完全的
		//	不透明（0xFF）或完全透明（0x00）。 如果alpha分量完全
		//	不透明，那么RGB组件将被用作背景颜色。 如果
		//	 alpha组件对于窗口化浏览器是完全透明的
		//	将使用CefSettings.background_color值。 如果alpha分量是
		//	对于无窗口（离屏）浏览器完全透明，然后透明
		//	绘画将被启用。
		///
		AQUAENTRYFULL(void, TypeBs, BackgroundColor)(LPVOID conf, DWORD value);

		///
		//	逗号分隔的有序的语言代码列表，没有任何空格
		//	将用于“Accept-Language”HTTP标头中。 可能在全球设置
		//	使用CefBrowserSettings.accept_language_list值。 如果两个值都是
		//	然后将使用“en-US,en”。
		///
		AQUAENTRYFULL(void, TypeBs, AcceptLanguageListA)(LPVOID conf, LPCSTR value);

		///
		//	逗号分隔的有序的语言代码列表，没有任何空格
		//	将用于“Accept-Language”HTTP标头中。 可能在全球设置
		//	使用CefBrowserSettings.accept_language_list值。 如果两个值都是
		//	然后将使用“en-US,en”。
		///
		AQUAENTRYFULL(void, TypeBs, AcceptLanguageListW)(LPVOID conf, LPCWSTR value);
	}


	/***********************************
	*		RequestContextSettings
	************************************/

	///
	//	请求上下文初始化设置。 指定NULL或0来获取
	//	推荐的默认值。
	///
	namespace RequestContextSettings {

		///
		//	创建一个Rcs对象
		///
		AQUAENTRYFULL(LPVOID, TypeRcs, Create)(void);

		///
		//	拷贝一个Rcs对象
		///
		AQUAENTRYFULL(LPVOID, TypeRcs, Copy)(LPVOID object);

		///
		//	销毁一个Rcs对象
		///
		AQUAENTRYFULL(void, TypeRcs, Destoryed)(LPVOID object);

		///
		//	缓存数据将存储在磁盘上的位置。 如果是空的话
		//	浏览器将在内置缓存所在的“隐身模式”下创建
		//	用于存储并且没有数据被保存到磁盘。 HTML5等数据库
		//	localStorage只会在缓存路径存在的情况下持续存在于会话中
		//	指定。 共享全局浏览器缓存和相关配置集
		//	此值匹配CefSettings.cache_path值。
		///
		AQUAENTRYFULL(void, TypeRcs, CachePathA)(LPVOID conf, LPCSTR value);

		///
		//	缓存数据将存储在磁盘上的位置。 如果是空的话
		//	浏览器将在内置缓存所在的“隐身模式”下创建
		//	用于存储并且没有数据被保存到磁盘。 HTML5等数据库
		//	localStorage只会在缓存路径存在的情况下持续存在于会话中
		//	指定。 共享全局浏览器缓存和相关配置集
		//	此值匹配CefSettings.cache_path值。
		///
		AQUAENTRYFULL(void, TypeRcs, CachePathW)(LPVOID conf, LPCWSTR value);

		///
		//	保持会话cookie（没有到期日或有效期的cookie
		//	间隔）默认情况下使用全局cookie管理器将此值设置为
		//	true（1）。 会话cookie通常是短暂的，而且大部分都是
		//	Web浏览器不会持续它们。 可以用全局设置
		//	CefSettings.persist_session_cookies值。 如果这个值将被忽略
		//	| cache_path | 是空的，或者它与CefSettings.cache_path值匹配。
		///
		AQUAENTRYFULL(void, TypeRcs, PersistSessionCookies)(LPVOID conf, BOOL enabled);

		///
		//	将用户首选项保存为缓存路径目录集中的JSON文件
		//	这个值为真（1）。 可以用全局设置
		//	CefSettings.persist_user_preferences值。 如果这个值将被忽略
		//	| cache_path | 是空的，或者它与CefSettings.cache_path值匹配。
		///
		AQUAENTRYFULL(void, TypeRcs, PersistUserPreferences)(LPVOID conf, BOOL enabled);

		///
		//	设置为true（1）忽略与无效SSL证书相关的错误。
		//	启用此设置可能会导致潜在的安全漏洞
		//	“中间人”攻击。 从中加载内容的应用程序
		//	互联网不应该启用此设置。 可以用全局设置
		//	CefSettings.ignore_certificate_errors值。 如果这个值将被忽略
		//	| cache_path | 匹配CefSettings.cache_path值。
		///
		AQUAENTRYFULL(void, TypeRcs, IgnoreCertificateErrors)(LPVOID conf, BOOL enabled);

		///
		//	设置为true（1）以启用内置网络的基于日期的到期
		//	安全信息（即证书透明度日志，HSTS预加载
		//	和固定信息）。 启用此选项可提高网络安全性
		//	但使用CEF二进制文件时，可能会导致HTTPS加载失败
		//	过去10周 请参阅https://www.certificate-transparency.org/和
		//	https://www.chromium.org/hsts了解详情。 可以用全局设置
		//	CefSettings.enable_net_security_expiration值。
		///
		AQUAENTRYFULL(void, TypeRcs, EnableNetSecurityExpiration)(LPVOID conf, BOOL enabled);

		///
		//	逗号分隔的有序的语言代码列表，没有任何空格
		//	将用于“Accept-Language”HTTP标头中。 可以在全球设置
		//	使用CefSettings.accept_language_list值或在per-
		//	使用CefBrowserSettings.accept_language_list值的浏览器基础。 如果
		//	所有值都是空的，那么将使用“en-US，en”。 这个值将会是
		//	如果| cache_path |被忽略 匹配CefSettings.cache_path值。
		///
		AQUAENTRYFULL(void, TypeRcs, AcceptLanguageListA)(LPVOID conf, LPCSTR value);

		///
		//	逗号分隔的有序的语言代码列表，没有任何空格
		//	将用于“Accept-Language”HTTP标头中。 可以在全球设置
		//	使用CefSettings.accept_language_list值或在per-
		//	使用CefBrowserSettings.accept_language_list值的浏览器基础。 如果
		//	所有值都是空的，那么将使用“en-US，en”。 这个值将会是
		//	如果| cache_path |被忽略 匹配CefSettings.cache_path值。
		///
		AQUAENTRYFULL(void, TypeRcs, AcceptLanguageListW)(LPVOID conf, LPCWSTR value);
	}

	/******************************
	*		CefPopupFeatures
	******************************/
	namespace PopupFeatures {

		AQUAENTRYFULL(void,TypePf, SetFeatures)(LPVOID conf,int x,int xSet,int y,int ySet,int width,int widthSet,int height,int heightSet,
			int menuBarVisible,int statusBarVisible,int toolBarVisible,int scrollbarsVisible);
	}
}

#endif