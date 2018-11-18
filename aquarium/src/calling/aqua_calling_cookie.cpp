#include "aqua_calling_cookie.h"
#include "cpprest\http_client.h"
#include <stdio.h>
#include <tchar.h>

AquaCallCookie::AquaCallCookie(std::vector<CefCookie> *receive, LPVOID notify) {
	m_pCookies = receive;
	m_notify = notify;
}

AquaCallCookie::~AquaCallCookie() {
	reinterpret_cast<pplx::task_completion_event<void>*>(m_notify)->set();
}

bool AquaCallCookie::Visit(const CefCookie& cookie, int count, int total,
	bool& deleteCookie) {
	if (m_pCookies) {
		m_pCookies->push_back(cookie);
	}
	return true;
}

AquaCallSetCookie::AquaCallSetCookie() {

}

AquaCallSetCookie::~AquaCallSetCookie() {

}

void AquaCallSetCookie::OnComplete(bool success) {
	if (success) {
		MessageBox(NULL, L"³É¹¦!", NULL, NULL);
	}
	else {
		MessageBox(NULL, L"Ê§°Ü!", NULL, NULL);
	}
}