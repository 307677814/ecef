#pragma once
#include "include\cef_app.h"

#ifdef _DEBUG
#pragma comment(lib,"libcef_dll_wrapper_ud.lib")
#else
#pragma comment(lib,"libcef_dll_wrapper.lib")
#endif
#pragma comment(lib,"libcef.lib")

class PepperRenderer : public CefApp,
	public CefBrowserProcessHandler,
	public CefRenderProcessHandler
{
public:
	PepperRenderer();
	~PepperRenderer();

	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() {
		return this;
	}

	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() {
		return this;
	}

	virtual void OnBeforeCommandLineProcessing(
		const CefString& process_type,
		CefRefPtr<CefCommandLine> command_line) OVERRIDE;


public:
	IMPLEMENT_REFCOUNTING(PepperRenderer);
};

