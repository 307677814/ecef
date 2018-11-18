#ifndef AQUA_REQUEST_CONTEXT_REFER_H_
#define AQUA_REQUEST_CONTEXT_REFER_H_
#include "utils\aqua_utils.h"
#include "include\cef_request_context.h"
#include "calling\aqua_calling_request_context_handler.h"

/**
  * 请求上下文为一组相关浏览器提供请求处理
  * 或URL请求对象。创建一个请求上下文可以被指定
  * 通过CefBrowserHost静态工厂方法创建一个新的浏览器
  * 通过CefURLRequest静态工厂方法创建新的URL请求。浏览器对象
  * 具有不同的请求上下文永远不会被托管在同一个呈现器中
  * 进程。具有相同请求上下文的浏览器对象可能是也可能不是
  * 根据流程模型在相同的渲染过程中托管。浏览器
  * 通过JavaScript window.open函数或者间接创建的对象
  * 有针对性的链接将共享相同的渲染过程和相同的请求
  * 上下文作为源浏览器。在单进程模式下运行时有
  * 只有一个渲染进程（主进程）以及所有浏览器创建
  * 在单进程模式下将共享相同的请求上下文。这将是
  * 将第一个请求上下文传递给CefBrowserHost静态工厂方法和
  * 所有其​​他请求上下文对象将被忽略。
  * * * * * * * * * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {
	CefRequestContext;

	///
	//	返回全局上下文对象。
	///
	AQUAENTRYFULL(LPVOID, RequestContext, GetGlobalContext)(void);

	///
	//	用指定的| settings |创建一个新的上下文对象 和可选的
	//	|handler|。
	///
	AQUAENTRYFULL(LPVOID, RequestContext, CreateContext)(LPVOID conf);

	///
	//	如果此对象指向与| that |相同的上下文，则返回true
	//	对象。
	///
	AQUAENTRYFULL(BOOL, RequestContext, IsSame)(LPVOID object,LPVOID target);

	///
	//	返回此对象的缓存路径。 如果清空“隐身模式”
	//	正在使用内存中缓存。
	//	如果|length|为0,则不会填充数据到|buffer|中
	///
	AQUAENTRYFULL(int, RequestContext, GetCachePathA)(LPVOID object,LPSTR buffer,int length);

	///
	//	返回此对象的缓存路径。 如果清空“隐身模式”
	//	正在使用内存中缓存。
	//	如果|length|为0,则不会填充数据到|buffer|中
	///
	AQUAENTRYFULL(int, RequestContext, GetCachePathW)(LPVOID object, LPWSTR buffer, int length);

	///
	//	返回此对象的默认cookie管理器。 这将是全球性的
	//	如果此对象是全局请求上下文，则为Cookie管理器。 除此以外，
	//	这将是此请求上下文所使用的默认cookie管理器
	//	没有通过CefRequestContextHandler :: GetCookieManager（）接收到值。 如果
	//	|callback|它是非NULL的，它将在IO线程上异步执行
	//	在经理的存储被初始化后。
	///
	AQUAENTRYFULL(LPVOID, RequestContext, GetDefaultCookieManager)(LPVOID object);

	///
	//	为指定的| scheme_name |注册一个模式处理程序工厂 和
	//	可选| domain_name |。 空的| domain_name | 标准方案的价值
	//	将使工厂匹配所有域名。 | domain_name | 值
	//	对于非标准方案将被忽略。 如果| scheme_name | 是一个内置的
	//	scheme |没有处理程序由| factory |返回 然后是内置的方案
	//	处理程序工厂将被调用。 如果| scheme_name | 是一个自定义计划
	//	你还必须在所有的实现CefApp :: OnRegisterCustomSchemes（）方法
	//	进程。 此功能可能会多次调用以更改或删除
	//	匹配指定的| scheme_name |的工厂 和可选的
	//	|domain_name|。如果发生错误，则返回false。 这个功能可能是
	//	在浏览器进程中调用任何线程。
	///
	AQUAENTRYFULL(LPVOID, RequestContext, RegisterSchemeHandlerFactoryA)(LPVOID object,LPCSTR scheme_name,LPCSTR domain_name);

	///
	//	为指定的| scheme_name |注册一个模式处理程序工厂 和
	//	可选| domain_name |。 空的| domain_name | 标准方案的价值
	//	将使工厂匹配所有域名。 | domain_name | 值
	//	对于非标准方案将被忽略。 如果| scheme_name | 是一个内置的
	//	scheme |没有处理程序由| factory |返回 然后是内置的方案
	//	处理程序工厂将被调用。 如果| scheme_name | 是一个自定义计划
	//	你还必须在所有的实现CefApp :: OnRegisterCustomSchemes（）方法
	//	进程。 此功能可能会多次调用以更改或删除
	//	匹配指定的| scheme_name |的工厂 和可选的
	//	|domain_name|。如果发生错误，则返回false。 这个功能可能是
	//	在浏览器进程中调用任何线程。
	///
	AQUAENTRYFULL(LPVOID, RequestContext, RegisterSchemeHandlerFactoryW)(LPVOID object, LPCWSTR scheme_name, LPCWSTR domain_name);

	///
	//	清除所有已注册的方案处理工厂。 错误返回false。 这个
	//	可以在浏览器进程中的任何线程上调用函数。
	///
	AQUAENTRYFULL(bool, RequestContext, ClearSchemeHandlerFactories)(LPVOID object);

	///
	//	尝试解析| origin | 到关联的IP地址列表。
	//	| callback | 将在完成后在UI线程上执行。
	///
	AQUAENTRYFULL(void, RequestContext, ResolveHostA)(LPVOID object, LPCSTR origin,LPVOID callback);

	///
	//	尝试解析| origin | 到关联的IP地址列表。
	//	| callback | 将在完成后在UI线程上执行。
	///
	AQUAENTRYFULL(void, RequestContext, ResolveHostW)(LPVOID object, LPCWSTR origin, LPVOID callback);

	///
	//	尝试解析| origin | 到使用的关联IP地址列表
	//	缓存的数据。| resolved_ips| 将填充已解析的IP列表
	//	地址或空，如果没有缓存的数据可用。 返回ERR_NONE
	//	成功。 必须在浏览器进程IO线程上调用此方法。
	///
	AQUAENTRYFULL(int, RequestContext, ResolveHostCachedA)(LPVOID object, LPCSTR origin,LPVOID resolved_ips);

	///
	//	尝试解析| origin | 到使用的关联IP地址列表
	//	缓存的数据。| resolved_ips| 将填充已解析的IP列表
	//	地址或空，如果没有缓存的数据可用。 返回ERR_NONE
	//	成功。 必须在浏览器进程IO线程上调用此方法。
	///
	AQUAENTRYFULL(int, RequestContext, ResolveHostCachedW)(LPVOID object, LPCWSTR origin, LPVOID resolved_ips);

	///
	//	加载一个扩展。
	//
	//	如果使用默认加载从磁盘读取扩展资源
	//	然后执行| root_directory |应该是绝对路径
	//	扩展资源目录和| manifest |应该是NULL。如果扩展
	//	资源将由客户端提供（例如，通过CefRequestHandler和/或
	//	CefExtensionHandler）then | root_directory |应该是一个路径组件
	//	对于扩展是唯一的（如果不是绝对的，这将在内部添加前缀
	//	带有PK_DIR_RESOURCES路径）和| manifest |应该包含内容
	//	否则会从磁盘上的“manifest.json”文件中读取。
	//
	//	加载的扩展将在共享相同的所有上下文中访问
	//	存储（HasExtension返回true）。但是，仅限于上下文
	//	调用这个方法被认为是加载器（DidLoadExtension返回
	//	true），只有加载器会收到CefRequestContextHandler回调
	//	用于扩展。
	//
	//	CefExtensionHandler :: OnExtensionLoaded将在加载成功或调用时被调用
	//	CefExtensionHandler :: OnExtensionLoadFailed将在加载失败时调用。
	//
	//	如果扩展名通过“背景”指定背景脚本，
	//	清单键然后CefExtensionHandler :: OnBeforeBackgroundBrowser会
	//	被调用来创建背景浏览器。请参阅附加的方法
	//	有关后台脚本的信息。
	//
	//	对于可见的扩展视图，客户端应用程序应该评估
	//	清单来确定要加载的正确的扩展URL，然后传递它
	//	扩展后的CefBrowserHost :: CreateBrowser *函数的URL
	//	加载。例如，客户端可以查找“browser_action”清单
	//	如 https://developer.chrome.com/extensions/browserAction所记录的那样 。
	//	扩展程序URL采用“chrome-extension：// <extension_id> / <路径>”的形式。
	//
	//	主机扩展与以下浏览器不同的浏览器：
	//	- 可以访问chrome。* JavaScript API（如果清单允许）。访问
	//	chrome：// extensions-支持当前扩展API的列表
	//	由CEF支持。
	//	- 主框架导航到非扩展内容被阻止。
	//	- 捏放大被禁用。
	//	- CefBrowserHost :: GetExtension返回托管扩展。
	//	- CefBrowserHost :: IsBackgroundHost对于后台主机返回true。
	//
	//	请参阅 https://developer.chrome.com/extensions 以获取扩展实现
	//	和使用文档。
	///
	AQUAENTRYFULL(void,RequestContext, LoadExtensionA)(LPVOID object,LPCSTR root_directory,LPVOID manifest,LPVOID handler);

	///
	//	加载一个扩展。
	//
	//	如果使用默认加载从磁盘读取扩展资源
	//	然后执行| root_directory |应该是绝对路径
	//	扩展资源目录和| manifest |应该是NULL。如果扩展
	//	资源将由客户端提供（例如，通过CefRequestHandler和/或
	//	CefExtensionHandler）then | root_directory |应该是一个路径组件
	//	对于扩展是唯一的（如果不是绝对的，这将在内部添加前缀
	//	带有PK_DIR_RESOURCES路径）和| manifest |应该包含内容
	//	否则会从磁盘上的“manifest.json”文件中读取。
	//
	//	加载的扩展将在共享相同的所有上下文中访问
	//	存储（HasExtension返回true）。但是，仅限于上下文
	//	调用这个方法被认为是加载器（DidLoadExtension返回
	//	true），只有加载器会收到CefRequestContextHandler回调
	//	用于扩展。
	//
	//	CefExtensionHandler :: OnExtensionLoaded将在加载成功或调用时被调用
	//	CefExtensionHandler :: OnExtensionLoadFailed将在加载失败时调用。
	//
	//	如果扩展名通过“背景”指定背景脚本，
	//	清单键然后CefExtensionHandler :: OnBeforeBackgroundBrowser会
	//	被调用来创建背景浏览器。请参阅附加的方法
	//	有关后台脚本的信息。
	//
	//	对于可见的扩展视图，客户端应用程序应该评估
	//	清单来确定要加载的正确的扩展URL，然后传递它
	//	扩展后的CefBrowserHost :: CreateBrowser *函数的URL
	//	加载。例如，客户端可以查找“browser_action”清单
	//	如 https://developer.chrome.com/extensions/browserAction所记录的那样 。
	//	扩展程序URL采用“chrome-extension：// <extension_id> / <路径>”的形式。
	//
	//	主机扩展与以下浏览器不同的浏览器：
	//	- 可以访问chrome。* JavaScript API（如果清单允许）。访问
	//	chrome：// extensions-支持当前扩展API的列表
	//	由CEF支持。
	//	- 主框架导航到非扩展内容被阻止。
	//	- 捏放大被禁用。
	//	- CefBrowserHost :: GetExtension返回托管扩展。
	//	- CefBrowserHost :: IsBackgroundHost对于后台主机返回true。
	//
	//	请参阅 https://developer.chrome.com/extensions 以获取扩展实现
	//	和使用文档。
	///
	AQUAENTRYFULL(void, RequestContext, LoadExtensionA)(LPVOID object, LPCSTR root_directory, LPVOID manifest, LPVOID handler);

	///
	//	加载一个扩展。
	//
	//	如果使用默认加载从磁盘读取扩展资源
	//	然后执行| root_directory |应该是绝对路径
	//	扩展资源目录和| manifest |应该是NULL。如果扩展
	//	资源将由客户端提供（例如，通过CefRequestHandler和/或
	//	CefExtensionHandler）then | root_directory |应该是一个路径组件
	//	对于扩展是唯一的（如果不是绝对的，这将在内部添加前缀
	//	带有PK_DIR_RESOURCES路径）和| manifest |应该包含内容
	//	否则会从磁盘上的“manifest.json”文件中读取。
	//
	//	加载的扩展将在共享相同的所有上下文中访问
	//	存储（HasExtension返回true）。但是，仅限于上下文
	//	调用这个方法被认为是加载器（DidLoadExtension返回
	//	true），只有加载器会收到CefRequestContextHandler回调
	//	用于扩展。
	//
	//	CefExtensionHandler :: OnExtensionLoaded将在加载成功或调用时被调用
	//	CefExtensionHandler :: OnExtensionLoadFailed将在加载失败时调用。
	//
	//	如果扩展名通过“背景”指定背景脚本，
	//	清单键然后CefExtensionHandler :: OnBeforeBackgroundBrowser会
	//	被调用来创建背景浏览器。请参阅附加的方法
	//	有关后台脚本的信息。
	//
	//	对于可见的扩展视图，客户端应用程序应该评估
	//	清单来确定要加载的正确的扩展URL，然后传递它
	//	扩展后的CefBrowserHost :: CreateBrowser *函数的URL
	//	加载。例如，客户端可以查找“browser_action”清单
	//	如 https://developer.chrome.com/extensions/browserAction所记录的那样 。
	//	扩展程序URL采用“chrome-extension：// <extension_id> / <路径>”的形式。
	//
	//	主机扩展与以下浏览器不同的浏览器：
	//	- 可以访问chrome。* JavaScript API（如果清单允许）。访问
	//	chrome：// extensions-支持当前扩展API的列表
	//	由CEF支持。
	//	- 主框架导航到非扩展内容被阻止。
	//	- 捏放大被禁用。
	//	- CefBrowserHost :: GetExtension返回托管扩展。
	//	- CefBrowserHost :: IsBackgroundHost对于后台主机返回true。
	//
	//	请参阅 https://developer.chrome.com/extensions 以获取扩展实现
	//	和使用文档。
	///
	AQUAENTRYFULL(void, RequestContext, LoadExtensionW)(LPVOID object, LPCWSTR root_directory, LPVOID manifest, LPVOID handler);

	///
	//	如果使用此上下文来加载标识的扩展，则返回true
	//	| extension_id |。 共享相同存储的其他上下文也将具有
	//	访问扩展（请参阅HasExtension）。 必须调用此方法
	//	浏览器进程UI线程。
	///
	AQUAENTRYFULL(void, RequestContext, DidLoadExtensionA)(LPVOID object,LPCSTR extension_id);

	///
	//	如果使用此上下文来加载标识的扩展，则返回true
	//	| extension_id |。 共享相同存储的其他上下文也将具有
	//	访问扩展（请参阅HasExtension）。 必须调用此方法
	//	浏览器进程UI线程。
	///
	AQUAENTRYFULL(void, RequestContext, DidLoadExtensionW)(LPVOID object, LPCWSTR extension_id);

	///
	//	如果此上下文有权访问由。标识的扩展，则返回true
	//	| extension_id |。 这可能不是用来加载的上下文
	//	扩展名（请参阅DidLoadExtension）。 该方法必须在浏览器上调用
	//	处理UI线程。
	///
	AQUAENTRYFULL(void, RequestContext, HasExtensionA)(LPVOID object, LPCWSTR extension_id);

	///
	//	如果此上下文有权访问由。标识的扩展，则返回true
	//	| extension_id |。 这可能不是用来加载的上下文
	//	扩展名（请参阅DidLoadExtension）。 该方法必须在浏览器上调用
	//	处理UI线程。
	///
	AQUAENTRYFULL(void, RequestContext, HasExtensionW)(LPVOID object, LPCWSTR extension_id);

	///
	//	检索此上下文有权访问的所有扩展的列表（请参阅
	//	HasExtension）。| extension_ids| 将填入扩展名列表
	//	ID值。 成功时返回true。 必须在该方法上调用此方法
	//	浏览器进程UI线程。
	///
	AQUAENTRYFULL(LPVOID, RequestContext, GetExtensions)(LPVOID object);
}

#endif