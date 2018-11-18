#include "aqua_httpserver.h"

#ifndef _AQUA_CEF2623_ADAPTER

#include "include\cef_server.h"
#include "calling\aqua_calling_httpserver.h"
#include "utils\aqua_conv.h"

using namespace AquaCef;

AQUAENTRYFULL(void, HttpServer, Create)(LPCSTR address, int port, int backlog) {
	if (address == NULL) return;
	CefServer::CreateServer(address, port, backlog,new AquaCallHttpServerHandler);
}

AQUAENTRYFULL(void, HttpServer, Shutdown)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefServer*>(object);
		p->AddRef();
		p->Shutdown();
		p->Release();
	}
}

AQUAENTRYFULL(BOOL, HttpServer, IsRunning)(LPVOID object) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefServer*>(object);
		p->AddRef();
		result = p->IsRunning();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, HttpServer, GetAddress)(LPVOID object, LPSTR buf, int len) {
	return 0;
}

AQUAENTRYFULL(BOOL, HttpServer, HasConnection)(LPVOID object) {
	return FALSE;
}

AQUAENTRYFULL(BOOL, HttpServer, IsValidConnection)(LPVOID object, int connectid) {
	return FALSE;
}

AQUAENTRYFULL(void, HttpServer, SendHttp200Response)(LPVOID object, LPCSTR content_type, void *data, size_t size) {

}

AQUAENTRYFULL(void, HttpServer, SendHttp404Response)(LPVOID object, int connectid) {

}

AQUAENTRYFULL(void, HttpServer, SendHttp500Response)(LPVOID object, int connectid, LPCSTR error_message) {

}

AQUAENTRYFULL(void, HttpServer, SendHttpResponse)(LPVOID object, int response_code, LPCSTR content_type, __int64 content_length, LPVOID headermap) {
	
}

AQUAENTRYFULL(void, HttpServer, SendRawData)(LPVOID object, int connectid, void *data, size_t size) {

}

AQUAENTRYFULL(void, HttpServer, CloseConnection)(LPVOID object, int connectid) {

}


#endif

