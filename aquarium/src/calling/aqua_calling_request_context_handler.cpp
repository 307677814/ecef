#include "aqua_calling_request_context_handler.h"
#include "include\cef_request_context.h"

#ifndef _AQUA_CEF2623_ADAPTER
void AquaRequestContextHandler::OnRequestContextInitialized(
	CefRefPtr<CefRequestContext> request_context) {
	m_manager = CefCookieManager::CreateManager(request_context->GetCachePath(), true, NULL);
}
#endif

CefRefPtr<CefCookieManager> AquaRequestContextHandler::GetCookieManager() {
	return NULL;
}

#ifndef _AQUA_CEF2623_ADAPTER
bool AquaRequestContextHandler::OnBeforePluginLoad(const CefString& mime_type,
	const CefString& plugin_url,
	bool is_main_frame,
	const CefString& top_origin_url,
	CefRefPtr<CefWebPluginInfo> plugin_info,
	PluginPolicy* plugin_policy) {
	return false;
}
#endif