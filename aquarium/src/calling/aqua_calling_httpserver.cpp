#include "aqua_calling_httpserver.h"

#ifndef _AQUA_CEF2623_ADAPTER


AquaCallHttpServerHandler::AquaCallHttpServerHandler() {

}

AquaCallHttpServerHandler::~AquaCallHttpServerHandler() {

}

void AquaCallHttpServerHandler::OnServerCreated(CefRefPtr<CefServer> server) {

}

void AquaCallHttpServerHandler::OnServerDestroyed(CefRefPtr<CefServer> server) {
}

void AquaCallHttpServerHandler::OnClientConnected(CefRefPtr<CefServer> server,
	int connection_id) {
}

void AquaCallHttpServerHandler::OnClientDisconnected(CefRefPtr<CefServer> server,
	int connection_id) {
}

void AquaCallHttpServerHandler::OnHttpRequest(CefRefPtr<CefServer> server,
	int connection_id,
	const CefString& client_address,
	CefRefPtr<CefRequest> request) {

}

#endif