#ifndef AQUA_CALLING_VISITOR_H_
#define AQUA_CALLING_VISITOR_H_
#include "include\cef_string_visitor.h"
#include "include\cef_browser.h"

typedef void(__stdcall *LPFN_STRING_OUTPUTA)(LPCSTR text, int len, LPVOID params);

class AquaCallStringVisitor : public CefStringVisitor
{
public:
	AquaCallStringVisitor(LPVOID respBody);
	~AquaCallStringVisitor();

private:
	LPVOID m_pRespBody;

public:
	BOOL static OutputString(CefRefPtr<CefFrame> frame, LPFN_STRING_OUTPUTA callback,LPVOID params, BOOL async,int cmd);

public:
	virtual void Visit(const CefString& string) OVERRIDE;

protected:
	IMPLEMENT_REFCOUNTING(AquaCallStringVisitor);
};

#endif
