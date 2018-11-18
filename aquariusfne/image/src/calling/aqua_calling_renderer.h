#ifndef AQUA_RENDERER_H_
#define AQUA_RENDERER_H_
#include "include\cef_app.h"
#include "handler\aqua_handler_renderer.h"
#include "include\cef_v8.h"
#include <map>


#ifdef _DEBUG
#pragma comment(lib,"libcef_dll_wrapper_ud.lib")
#else
#pragma comment(lib,"libcef_dll_wrapper.lib")
#endif
#pragma comment(lib,"libcef.lib")
#pragma comment(lib,"user32.lib")

class AquaCallRenderer;

class AquaCallRenderer : public CefApp,
	public CefBrowserProcessHandler,
	public CefRenderProcessHandler
{
public:
	AquaCallRenderer();
	~AquaCallRenderer();

	CefRefPtr<AquaCallRenderer> static GetInterface();

	CefRefPtr<CefV8Context> GetV8(void) { return m_pV8Context; }

private:
	CefRefPtr<CefV8Context> m_pV8Context;

public:
	virtual void OnBeforeCommandLineProcessing(
		const CefString& process_type,
		CefRefPtr<CefCommandLine> command_line) OVERRIDE;

	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE {
		return this;
	}

	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE {
		return this;
	}

public:
	virtual void OnContextInitialized() OVERRIDE;

	virtual void OnBeforeChildProcessLaunch(
		CefRefPtr<CefCommandLine> command_line) OVERRIDE;

	virtual void OnRenderProcessThreadCreated(
		CefRefPtr<CefListValue> extra_info) OVERRIDE;

public:
	virtual void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) OVERRIDE;

	virtual void OnWebKitInitialized() OVERRIDE;

	virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual void OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE;

	virtual void OnContextReleased(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE;

	virtual void OnUncaughtException(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context,
		CefRefPtr<CefV8Exception> exception,
		CefRefPtr<CefV8StackTrace> stackTrace) OVERRIDE;

	virtual void OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefDOMNode> node) OVERRIDE;

	virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) OVERRIDE;

protected:
	IMPLEMENT_REFCOUNTING(AquaCallRenderer);
};

#endif