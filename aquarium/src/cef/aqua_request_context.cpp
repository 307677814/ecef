#include "aqua_request_context.h"
#include "include\cef_request_context.h"

using namespace AquaCef;

///
//	返回全局上下文对象。
///
AQUAENTRYFULL(LPVOID, RequestContext, GetGlobalContext)(void) {
	CefRefPtr<CefRequestContext> global = CefRequestContext::GetGlobalContext();
	global->AddRef();
	return global.get();
}