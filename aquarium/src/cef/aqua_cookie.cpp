#include "cef\aqua_cookie.h"
#include "include\cef_cookie.h"
#include "calling\aqua_calling_cookie.h"
#include "utils\aqua_conv.h"
#include <map>
#include <vector>
#include "cpprest\http_client.h"

using namespace AquaCef;

///
//	返回全局cookie管理器。 
//	默认情况下，数据将存储在CefSettings.cache_path中（如果已指定），否则将存储在内存中。 
//	如果| callback | 非空，它将在管理器存储初始化后在IO线程上异步执行。 
//	使用此方法相当于调用CefRequestContext::GetGlobalContext（）->GetDefaultCookieManager（）。
///
AQUAENTRYFULL(LPVOID, Cookie, InitFromGlobal)(void) {
	CefRefPtr<CefCookieManager> manager = CefCookieManager::GetGlobalManager(NULL);
	manager->AddRef();
	return (LPVOID)manager.get();
}

///
//	访问IO线程上的Cookie子集。 
//	结果按给定的url方案，主机，域和路径进行过滤。 
//	如果| includeHttpOnly | 是真实的HTTP-only cookies也会包含在结果中。 
//	返回的cookies按最长路径排序，然后按最早创建日期排序。如果无法访问cookie，则返回false。
///
AQUAENTRYFULL(void, Cookie, GetUrlCookies)(LPVOID object, LPCSTR url, bool includeHttponly, LPVOID callback,LPVOID params) {
	if (object && url!=NULL && strlen(url) > 0) {
		std::vector<CefCookie> pvx;
		pplx::task_completion_event<void>  tce;
		auto calling = pplx::create_task(tce);
		auto p = reinterpret_cast<CefCookieManager*>(object);
		aqua_convert conv;
		auto fullUrl = conv.from_bytes(url);
		p->AddRef();
		p->VisitUrlCookies(fullUrl,includeHttponly,new AquaCallCookie(&pvx, &tce));
		p->Release();
		try
		{
			calling.wait();
		}
		catch (const std::exception&)
		{

		}
		
		std::string name, value, domain;
		int max = pvx.size();
		for (size_t i = 0; i < pvx.size(); i++)
		{
			const auto &v = pvx[i];
			if (v.name.length > 0) {
				name = conv.to_bytes(v.name.str);
			}
			if (v.value.length > 0) {
				value = conv.to_bytes(v.value.str);
			}
			if (v.domain.length > 0) {
				domain = conv.to_bytes(v.domain.str);
			}
			((LPFN_VISIT_COOKIE)callback)(max, name.c_str(), value.c_str(), domain.c_str(), v.secure, v.httponly, v.has_expires, (LPVOID)&v.expires, params);
		}
		pvx.clear();
	}
}

///
//	访问IO线程上的所有cookie。 返回的Cookie是按照最长的路径，然后按最早的创建日期。
//	如果cookie为false，则返回false无法访问。
///
AQUAENTRYFULL(void, Cookie, GetAllCookies)(LPVOID object, LPVOID callback, LPVOID params) {
	if (object) {
		std::vector<CefCookie> pvx;
		pplx::task_completion_event<void>  tce;
		auto calling = pplx::create_task(tce);
		auto p = reinterpret_cast<CefCookieManager*>(object);
		p->AddRef();
		p->VisitAllCookies(new AquaCallCookie(&pvx, &tce));
		p->Release();
		try
		{
			calling.wait();
		}
		catch (const std::exception&)
		{

		}
		
		aqua_convert conv;
		std::string name, value, domain;
		int max = pvx.size();
		for (size_t i = 0; i < pvx.size(); i++)
		{
			const auto &v = pvx[i];
			if (v.name.length > 0) {
				name = conv.to_bytes(v.name.str);
			}
			if (v.value.length > 0) {
				value = conv.to_bytes(v.value.str);
			}
			if (v.domain.length > 0) {
				domain = conv.to_bytes(v.domain.str);
			}
			((LPFN_VISIT_COOKIE)callback)(max,name.c_str(), value.c_str(), domain.c_str(), v.secure, v.httponly, v.has_expires, (LPVOID)&v.expires,params);
		}
		if (max == 0) {
			((LPFN_VISIT_COOKIE)callback)(max, NULL, NULL, NULL, false, false, false, NULL, params);
		}
		pvx.clear();
	}
}

///
//	给定一个有效的URL和显式的用户提供的cookie属性。 
//	这个函数期望每个属性都是格式良好的。 
//	它会检查不允许的字符（例如';'字符是不允许的
//	在cookie值属性中）并且在未设置cookie的情况下失败
//	这样的字符被找到。 
//	如果 | callback | 它是非NULL它将被执行在cookie被设置后，在IO线程上异步。
//	返回如果指定了无效的URL或无法访问Cookie，则返回false。
///
AQUAENTRYFULL(bool, Cookie, SetCookie)(LPVOID object, LPCSTR name, LPCSTR value, LPCSTR url, bool secure, bool httponly, bool has_expires, LPVOID expires) {
	bool result = false;
	if (object) {
		auto p = reinterpret_cast<CefCookieManager*>(object);
		aqua_convert conv;
		CefCookie cookie;
		CefString(&cookie.name) = name;
		CefString(&cookie.value) = value;
		cookie.secure = secure;
		cookie.httponly = httponly;
		cookie.has_expires = has_expires;
		memcpy(&cookie.expires, expires, sizeof(cef_time_t));
		p->AddRef();
		result = p->SetCookie(url, cookie, NULL);
		p->Release();
	}
	return result;
}

///
//	删除所有与指定参数匹配的cookie。 
//	如果| url | 和| cookie_name | 值被指定为所有主机和域名cookie匹配
//	两者都将被删除。 如果只有 | url | 是指定所有主机cookie（但不是
//	域名cookie），而不管路径将被删除。 如果 | url | 全部是空的
//	所有主机和域名的cookies将被删除。 如果 | callback | 是
//	非空它会在IO线程之后异步执行
//	Cookie已被删除。 如果非空的无效URL是，则返回false
//	指定或无法访问Cookie。 曲奇可以交替使用
//	使用Visit * Cookies（）方法删除。
///
AQUAENTRYFULL(bool, Cookie, DeleteCookie)(LPVOID object, LPCSTR url, LPCSTR cookie_name) {
	bool result = false;
	if (object) {
		auto p = reinterpret_cast<CefCookieManager*>(object);
		aqua_convert conv;
		p->AddRef();
		if (url != NULL && cookie_name != NULL) {
			result = p->DeleteCookies(url, cookie_name, NULL);
		}
		else if (url != NULL) {
			result = p->DeleteCookies(url, TEXT(""), NULL);
		}
		else {
			result = p->DeleteCookies(TEXT(""), TEXT(""), NULL);
		}
		p->Release();
	}
	return result;
}

///
//	设置将用于存储Cookie数据的目录路径。 如果
//	| 路径 | 是空的数据将只存储在内存中。 否则，数据将会
//	存储在指定的 | 路径 | 上。 坚持会话cookie（没有cookies
//	有效期限或有效期限）set | persist_session_cookies | 为真。
//	会话cookie通常旨在暂时和大多数Web
//	浏览器不会坚持他们。 如果 | callback | 它是非NULL它将被执行
//	在经理的存储已经完成之后，在IO线程上异步
//	初始化。 如果无法访问Cookie，则返回false。
///
AQUAENTRYFULL(void, Cookie, SetStoragePath)(LPVOID object, LPCSTR path, bool persist_session_cookies) {

}

///
//	将后备存储（如果有）冲洗到磁盘。 如果| callback | 它是非NULL的
//	在刷新完成后在IO线程上异步执行。
//	如果无法访问Cookie，则返回false。
///
AQUAENTRYFULL(void, Cookie, FlushStore)(LPVOID object) {
	
	if (object) {
		auto p = reinterpret_cast<CefCookieManager*>(object);
		p->AddRef();
		p->FlushStore(NULL);
		p->Release();
	}
}

///
//	返回特定domain下的所有cookie子集并将以HTTP格式组合成一个字符串。
///
AQUAENTRYFULL(void, Cookie, GetCookieMerge)(LPVOID object, LPCSTR url) {

}

///
//	将一个HTTP形式的cookie子集字符串存储到当前cookie管理器中,并与domain关联。
///
AQUAENTRYFULL(void, Cookie, SetCookieMerge)(LPVOID object, LPCSTR url, LPCSTR items) {

}