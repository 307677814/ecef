#ifndef AQUA_REQUEST_H_
#define AQUA_REQUEST_H_
#include "utils\aqua_utils.h"

namespace AquaCef {

	AQUAENTRYFULL(LPVOID, Request, Create)(void);

	AQUAENTRYFULL(BOOL, Request, IsReadOnly)(LPVOID object);

	AQUAENTRYFULL(int, Request, GetURL)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, Request, SetURL)(LPVOID object, LPCSTR url);

	AQUAENTRYFULL(int, Request, GetMethod)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, Request, SetMethod)(LPVOID object, LPCSTR method);

	AQUAENTRYFULL(int, Request, GetReferrer)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, Request, setReferrerURL)(LPVOID object, LPCSTR referrer,int policy);

	AQUAENTRYFULL(int, Request, GetReferrerPolicy)(LPVOID object);

	AQUAENTRYFULL(LPVOID, Request, GetPostData)(LPVOID object);

	AQUAENTRYFULL(void, Request, SetPostData)(LPVOID object,LPVOID postData);

	AQUAENTRYFULL(LPVOID, Request, GetHeaderMap)(LPVOID object);

	AQUAENTRYFULL(void, Request, SetHeaderMap)(LPVOID object, LPVOID map);

	AQUAENTRYFULL(int, Request, GetFlags)(LPVOID object);

	AQUAENTRYFULL(void, Request, SetFlags)(LPVOID object,int flags);

	AQUAENTRYFULL(int, Request, GetFirstPartyForCookies)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, Request, SetFirstPartyForCookies)(LPVOID object, LPSTR url);

	AQUAENTRYFULL(int, Request, GetResourceType)(LPVOID object);

}

#endif