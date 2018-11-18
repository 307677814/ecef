#ifndef AQUA_CALLING_REQUEST_CONTEXT_H_
#define AQUA_CALLING_REQUEST_CONTEXT_H_
#include "include\cef_request_context_handler.h"

/**
  * 实现这个接口来提供处理程序实现。 处理程序
  * 直到所有与上下文相关的对象都有实例才会被释放
  * 被摧毁
  * * * * * * * * * * * * * * * * * * * * */

class AquaRequestContextHandler : public CefRequestContextHandler
{
public:
	AquaRequestContextHandler(CefRefPtr<CefCookieManager> manager) {
		m_manager = manager;
	}

	~AquaRequestContextHandler() {
		m_manager = NULL;
	}

private:

	CefRefPtr<CefCookieManager> m_manager;
public:


#ifndef _AQUA_CEF2623_ADAPTER

	virtual void OnRequestContextInitialized(
		CefRefPtr<CefRequestContext> request_context) OVERRIDE;
#endif
	virtual CefRefPtr<CefCookieManager> GetCookieManager() OVERRIDE;

#ifndef _AQUA_CEF2623_ADAPTER
	virtual bool OnBeforePluginLoad(const CefString& mime_type,
		const CefString& plugin_url,
		bool is_main_frame,
		const CefString& top_origin_url,
		CefRefPtr<CefWebPluginInfo> plugin_info,
		PluginPolicy* plugin_policy) OVERRIDE;
#endif

protected:
	IMPLEMENT_REFCOUNTING(AquaRequestContextHandler);
};

#endif