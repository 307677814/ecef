#ifndef AQUA_CALLING_HTTPSERVER_H_
#define AQUA_CALLING_HTTPSERVER_H_

#ifndef _AQUA_CEF2623_ADAPTER

#include "include\cef_server.h"

class AquaCallHttpServerHandler : public CefServerHandler
{
public:
	AquaCallHttpServerHandler();
	~AquaCallHttpServerHandler();

public:
	virtual void OnServerCreated(CefRefPtr<CefServer> server) OVERRIDE;

	virtual void OnServerDestroyed(CefRefPtr<CefServer> server) OVERRIDE;

	virtual void OnClientConnected(CefRefPtr<CefServer> server,
		int connection_id) OVERRIDE;

	virtual void OnClientDisconnected(CefRefPtr<CefServer> server,
		int connection_id) OVERRIDE;

	virtual void OnHttpRequest(CefRefPtr<CefServer> server,
		int connection_id,
		const CefString& client_address,
		CefRefPtr<CefRequest> request) OVERRIDE;

	virtual void OnWebSocketRequest(CefRefPtr<CefServer> server,
		int connection_id,
		const CefString& client_address,
		CefRefPtr<CefRequest> request,
		CefRefPtr<CefCallback> callback) OVERRIDE {}


	virtual void OnWebSocketConnected(CefRefPtr<CefServer> server,
		int connection_id) OVERRIDE {}

	virtual void OnWebSocketMessage(CefRefPtr<CefServer> server,
		int connection_id,
		const void* data,
		size_t data_size) OVERRIDE {}
public:
	IMPLEMENT_REFCOUNTING(AquaCallHttpServerHandler);
};

#endif

#endif