#include "cef\aqua_schemes.h"
#include "include\cef_scheme.h"
#include "utils\aqua_conv.h"

using namespace AquaCef;

AQUAENTRYFULL(void, Schemes, AddCustomScheme)(LPVOID object,
	LPCSTR scheme_name,
	bool is_standard,
	bool is_local,
	bool is_display_isolated,
	bool is_secure,
	bool is_cors_enabled,
	bool is_csp_bypassing) {
	if (object) {
		//auto p = reinterpret_cast<CefSchemeRegistrar*>(object);
		//p->AddCustomScheme(scheme_name, is_standard, is_local, is_display_isolated, is_secure, is_cors_enabled, is_csp_bypassing);
	}
}