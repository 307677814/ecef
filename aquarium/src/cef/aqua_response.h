#ifndef AQUA_RESPONSE_H_
#define AQUA_RESPONSE_H_
#include "utils\aqua_utils.h"

namespace AquaCef {

	AQUAENTRYFULL(LPVOID, Response, Create)(void);

	AQUAENTRYFULL(BOOL, Response, IsReadOnly)(LPVOID object);

	AQUAENTRYFULL(int, Response, GetStatus)(LPVOID object);

	AQUAENTRYFULL(void, Response, SetStatus)(LPVOID object, int status);

	AQUAENTRYFULL(int, Response, GetStatusText)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, Response, SetStatusText)(LPVOID object, LPCSTR statusText);

	AQUAENTRYFULL(int, Response, GetMimeType)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, Response, SetMimeType)(LPVOID object, LPCSTR mimeType);

	AQUAENTRYFULL(LPVOID, Response, GetHeaderMap)(LPVOID object);

	AQUAENTRYFULL(void, Response, SetHeaderMap)(LPVOID object,LPVOID map);
}

#endif