#ifndef AQUA_CALLING_COOKIE_H_
#define AQUA_CALLING_COOKIE_H_
#include "include\cef_cookie.h"
#include <vector>

typedef void(CALLBACK *LPFN_VISIT_COOKIE)(int total,LPCSTR name,LPCSTR value,LPCSTR url,bool secure,bool httponly,bool has_expires,LPVOID time,LPVOID params);
class AquaCallCookie : public CefCookieVisitor
{
public:
	AquaCallCookie(std::vector<CefCookie> *receive,LPVOID notify);
	~AquaCallCookie();

public:
	std::vector<CefCookie> *m_pCookies;
	LPVOID m_notify;
public:
	virtual bool Visit(const CefCookie& cookie, int count, int total,
		bool& deleteCookie) OVERRIDE;

protected:
	IMPLEMENT_REFCOUNTING(AquaCallCookie);
};

class AquaCallSetCookie : public CefSetCookieCallback
{
public:
	AquaCallSetCookie();
	~AquaCallSetCookie();

public:
	virtual void OnComplete(bool success) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(AquaCallSetCookie);
};


#endif