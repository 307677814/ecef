#ifndef AQUA_SCHEMES_H_
#define AQUA_SCHEMES_H_
#include "utils\aqua_utils.h"

namespace AquaCef {

	AQUAENTRYFULL(void,Schemes, AddCustomScheme)(LPVOID object,
		LPCSTR scheme_name,
		bool is_standard,
		bool is_local,
		bool is_display_isolated,
		bool is_secure,
		bool is_cors_enabled,
		bool is_csp_bypassing);


}

#endif