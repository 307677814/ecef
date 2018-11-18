#include "aqua_callback.h"
#include "include\cef_auth_callback.h"
#include "utils\aqua_conv.h"

using namespace AquaCef;

AQUAENTRYFULL(void, AuthCallback, Continue)(LPVOID object,LPCSTR username, LPCSTR password) {
	if (object) {
		auto p = reinterpret_cast<CefAuthCallback*>(object);
		aqua_convert conv;
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