#include "aqua_callback.h"
#include "include\cef_auth_callback.h"
#include <codecvt>

using namespace AquaCef;

AQUAENTRYFULL(void, AuthCallback, Continue)(LPVOID object,LPCSTR username, LPCSTR password) {
	if (object) {
		auto p = reinterpret_cast<CefAuthCallback*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v1 = conv.from_bytes(username);
		auto v2 = conv.from_bytes(password);
		p->AddRef();
		p->Continue(v1, v2);
		p->Release();
	}
}

AQUAENTRYFULL(void, AuthCallback, Cancel)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefAuthCallback*>(object);
		p->AddRef();
		p->Cancel();
		p->Release();
	}
}