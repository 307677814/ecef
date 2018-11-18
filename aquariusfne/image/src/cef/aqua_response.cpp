#include "aqua_response.h"
#include "include\cef_response.h"
#include <codecvt>

using namespace AquaCef;

AQUAENTRYFULL(LPVOID, Response, Create)(void) {
	CefRefPtr<CefResponse> v = CefResponse::Create();
	v->AddRef();
	return v.get();
}

AQUAENTRYFULL(BOOL, Response, IsReadOnly)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		p->AddRef();
		result = p->IsReadOnly();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, Response, GetStatus)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		p->AddRef();
		result = p->GetStatus();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, Response, SetStatus)(LPVOID object, int status) {
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		p->AddRef();
		p->SetStatus(status);
		p->Release();
	}
}

AQUAENTRYFULL(int, Response, GetStatusText)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		p->AddRef();
		CefString text = p->GetStatusText();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(text.c_str());
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return 0;
}

AQUAENTRYFULL(void, Response, SetStatusText)(LPVOID object, LPCSTR statusText) {
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		p->AddRef();
		p->SetStatusText(conv.from_bytes(statusText));
		p->Release();
	}
}

AQUAENTRYFULL(int, Response, GetMimeType)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		p->AddRef();
		CefString text = p->GetMimeType();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(text.c_str());
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return 0;
}

AQUAENTRYFULL(void, Response, SetMimeType)(LPVOID object, LPCSTR mimeType) {
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		p->AddRef();
		p->SetMimeType(conv.from_bytes(mimeType));
		p->Release();
	}
}

AQUAENTRYFULL(LPVOID, Response, GetHeaderMap)(LPVOID object) {
	CefResponse::HeaderMap *map = NULL;
	if (object) {
		auto p = reinterpret_cast<CefResponse*>(object);
		map = new CefResponse::HeaderMap;
		p->AddRef();
		p->GetHeaderMap(*map);
		p->Release();
	}
	return map;
}

AQUAENTRYFULL(void, Response, SetHeaderMap)(LPVOID object, LPVOID map) {
	CefResponse::HeaderMap *vmap = reinterpret_cast<CefResponse::HeaderMap*>(map);
	if (object && vmap) {
		auto p = reinterpret_cast<CefResponse*>(object);
		p->AddRef();
		p->SetHeaderMap(*vmap);
		p->Release();
	}
}