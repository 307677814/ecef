#include "aqua_request.h"
#include "include\cef_request.h"
#include <codecvt>
#include "include\cef_urlrequest.h"

using namespace AquaCef;

AQUAENTRYFULL(LPVOID, Request, Create)(void) {
	CefRefPtr<CefRequest> v = CefRequest::Create();
	v->AddRef();
	return v.get();
}

AQUAENTRYFULL(BOOL, Request, IsReadOnly)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		result = p->IsReadOnly();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, Request, GetURL)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		CefString url = p->GetURL();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(url);
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return result;
}

AQUAENTRYFULL(void, Request, SetURL)(LPVOID object, LPCSTR url) {
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		p->AddRef();
		p->SetURL(conv.from_bytes(url));
		p->Release();
	}
}

AQUAENTRYFULL(int, Request, GetMethod)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		CefString url = p->GetMethod();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(url);
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return result;
}

AQUAENTRYFULL(void, Request, SetMethod)(LPVOID object, LPCSTR method) {
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		p->AddRef();
		p->SetMethod(conv.from_bytes(method));
		p->Release();
	}
}

AQUAENTRYFULL(int, Request, GetReferrer)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		CefString url = p->GetReferrerURL();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(url);
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return result;
}

AQUAENTRYFULL(void, Request, setReferrerURL)(LPVOID object, LPCSTR referrer, int policy) {
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.from_bytes(referrer);
		p->AddRef();
		p->SetReferrer(v,(cef_referrer_policy_t)policy);
		p->Release();
	}
}

AQUAENTRYFULL(int, Request, GetReferrerPolicy)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		result = p->GetReferrerPolicy();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(LPVOID, Request, GetPostData)(LPVOID object) {
	CefRefPtr<CefPostData> result = NULL;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		result = p->GetPostData();
		if (result.get()) result->AddRef();
		p->Release();
	}
	return result.get();
}

AQUAENTRYFULL(void, Request, SetPostData)(LPVOID object, LPVOID postData) {
	if (object && postData) {
		auto p = reinterpret_cast<CefRequest*>(object);
		auto v = reinterpret_cast<CefPostData*>(postData);
		p->AddRef();
		p->SetPostData(v);
		p->Release();
	}
}

AQUAENTRYFULL(LPVOID, Request, GetHeaderMap)(LPVOID object) {
	CefRequest::HeaderMap *result = NULL;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		result = new CefRequest::HeaderMap;
		p->GetHeaderMap(*result);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, Request, SetHeaderMap)(LPVOID object, LPVOID map) {
	CefRequest::HeaderMap *vmap = reinterpret_cast<CefRequest::HeaderMap*>(map);
	if (object && vmap) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		p->SetHeaderMap(*vmap);
		p->Release();
	}
}

AQUAENTRYFULL(int, Request, GetFlags)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		result = p->GetFlags();
		
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, Request, SetFlags)(LPVOID object, int flags) {
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		p->SetFlags(flags);
		p->Release();
	}
}

AQUAENTRYFULL(int, Request, GetFirstPartyForCookies)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		CefString url = p->GetFirstPartyForCookies();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(url);
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return result;
}

AQUAENTRYFULL(void, Request, SetFirstPartyForCookies)(LPVOID object, LPSTR url) {
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		p->AddRef();
		p->SetFirstPartyForCookies(conv.from_bytes(url));
		p->Release();
	}
}

AQUAENTRYFULL(int, Request, GetResourceType)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefRequest*>(object);
		p->AddRef();
		result = (int)p->GetResourceType();
		p->Release();
	}
	return result;
}