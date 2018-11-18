#ifndef AQUA_CALLING_V8_H_
#define AQUA_CALLING_V8_H_

#include "include\cef_v8.h"
#include "include\cef_task.h"

typedef void(CALLBACK *LPFN_V8_EVAL)(int type,LPCSTR string_val,bool bool_val,
	int int_val,double number_val,LPVOID params,LPCSTR exception);

class AquaCallV8Accessor : public CefV8Accessor
{
public:
	AquaCallV8Accessor();
	~AquaCallV8Accessor();

public:
	virtual bool Get(const CefString& name,
		const CefRefPtr<CefV8Value> object,
		CefRefPtr<CefV8Value>& retval,
		CefString& exception) OVERRIDE;

	virtual bool Set(const CefString& name,
		const CefRefPtr<CefV8Value> object,
		const CefRefPtr<CefV8Value> value,
		CefString& exception) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(AquaCallV8Accessor);
};

class AquaCallV8Handler : public CefV8Handler
{
public:
	AquaCallV8Handler();
	~AquaCallV8Handler();

public:
	virtual bool Execute(const CefString& name,
		CefRefPtr<CefV8Value> object,
		const CefV8ValueList& arguments,
		CefRefPtr<CefV8Value>& retval,
		CefString& exception) OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(AquaCallV8Handler);
};


#endif