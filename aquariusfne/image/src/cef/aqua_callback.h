#ifndef AQUA_CALLBACK_H_
#define AQUA_CALLBACK_H_
#include "utils\aqua_utils.h"

namespace AquaCef {

	AQUAENTRYFULL(void, AuthCallback, Continue)(LPVOID object,LPCSTR username,LPCSTR password);

	AQUAENTRYFULL(void, AuthCallback, Cancel)(LPVOID object);
}

#endif