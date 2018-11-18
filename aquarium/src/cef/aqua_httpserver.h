#ifndef AQUA_HTTP_SERVER_H_
#define AQUA_HTTP_SERVER_H_

#include "utils\aqua_utils.h"

#ifndef _AQUA_CEF2623_ADAPTER
namespace AquaCef {

	AQUAENTRYFULL(void, HttpServer, Create)(LPCSTR address, int port, int backlog);

	AQUAENTRYFULL(void, HttpServer, Shutdown)(LPVOID object);

	AQUAENTRYFULL(BOOL, HttpServer, IsRunning)(LPVOID object);

	AQUAENTRYFULL(int, HttpServer, GetAddress)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(BOOL, HttpServer, HasConnection)(LPVOID object);

	AQUAENTRYFULL(BOOL, HttpServer, IsValidConnection)(LPVOID object, int connectid);

	AQUAENTRYFULL(void, HttpServer, SendHttp200Response)(LPVOID object, LPCSTR content_type, void *data, size_t size);

	AQUAENTRYFULL(void, HttpServer, SendHttp404Response)(LPVOID object, int connectid);

	AQUAENTRYFULL(void, HttpServer, SendHttp500Response)(LPVOID object, int connectid,LPCSTR error_message);

	AQUAENTRYFULL(void, HttpServer, SendHttpResponse)(LPVOID object, int response_code, LPCSTR content_type, __int64 content_length, LPVOID headermap);

	AQUAENTRYFULL(void, HttpServer, SendRawData)(LPVOID object, int connectid, void *data, size_t size);

	AQUAENTRYFULL(void, HttpServer, CloseConnection)(LPVOID object, int connectid);

	//AQUAENTRYFULL(void, HttpServer, SendWebSocketMessage)(LPVOID object, void *data, int size);
}
#endif

#endif