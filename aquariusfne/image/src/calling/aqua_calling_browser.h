#ifndef AQUA_CENTENT_H_
#define AQUA_CENTENT_H_
#include "include\cef_client.h"
#include "include\cef_drag_data.h"
#include "include\cef_drag_handler.h"
#include "calling\auqa_response_filter.h"
#include <vector>
#include <map>
#include <list>

class AquaCallBrowser : public CefClient,
	public CefDialogHandler,
	public CefDisplayHandler,
	public CefDownloadHandler,
	public CefDragHandler,
	public CefFindHandler,
	public CefFocusHandler,
	public CefJSDialogHandler,
	public CefKeyboardHandler,
	public CefLifeSpanHandler,
	public CefRequestHandler,
	public CefLoadHandler,
	public CefContextMenuHandler
{
public:
	AquaCallBrowser();
	~AquaCallBrowser();

	CefRefPtr<AquaCallBrowser> static GetInterface(void);

private:
	std::vector<CefBrowser*> m_pm;
	BOOL m_closed;

	std::vector<CefRefPtr<AquaCallResponseFilter>> m_requests;
public:
	std::vector<CefBrowser*> *GetManager() { return &m_pm; }
	
public:

	virtual CefRefPtr<CefDialogHandler> GetDialogHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefDragHandler> GetDragHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefFindHandler> GetFindHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefFocusHandler> GetFocusHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE { return this; }

	virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() { return this; }

public:
	virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) OVERRIDE;

public:
	virtual bool OnFileDialog(CefRefPtr<CefBrowser> browser,
		FileDialogMode mode,
		const CefString& title,
		const CefString& default_file_path,
		const std::vector<CefString>& accept_filters,
		int selected_accept_filter,
		CefRefPtr<CefFileDialogCallback> callback) OVERRIDE;

#ifdef _AQUA_CEF2623_ADAPTER
	virtual bool OnJSDialog(CefRefPtr<CefBrowser> browser,
		const CefString& origin_url,
		const CefString& accept_lang,
		JSDialogType dialog_type,
		const CefString& message_text,
		const CefString& default_prompt_text,
		CefRefPtr<CefJSDialogCallback> callback,
		bool& suppress_message) OVERRIDE;
#else
	virtual bool OnJSDialog(CefRefPtr<CefBrowser> browser,
		const CefString& origin_url,
		JSDialogType dialog_type,
		const CefString& message_text,
		const CefString& default_prompt_text,
		CefRefPtr<CefJSDialogCallback> callback,
		bool& suppress_message) OVERRIDE;
#endif

public:
	virtual void OnAddressChange(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		const CefString& url) OVERRIDE;

	virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,
		const CefString& title) OVERRIDE;

	virtual void OnFaviconURLChange(CefRefPtr<CefBrowser> browser,
		const std::vector<CefString>& icon_urls) OVERRIDE;

	virtual void OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
		bool fullscreen) OVERRIDE;

	virtual bool OnTooltip(CefRefPtr<CefBrowser> browser, CefString& text) OVERRIDE;

	virtual void OnStatusMessage(CefRefPtr<CefBrowser> browser,
		const CefString& value) OVERRIDE;

#ifdef _AQUA_CEF2623_ADAPTER

	virtual bool OnConsoleMessage(CefRefPtr<CefBrowser> browser,
		const CefString& message,
		const CefString& source,
		int line) OVERRIDE;

#else

	virtual bool OnConsoleMessage(CefRefPtr<CefBrowser> browser,
		cef_log_severity_t level,
		const CefString& message,
		const CefString& source,
		int line) OVERRIDE;

#endif

public:

	virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		const CefString& target_url,
		const CefString& target_frame_name,
		CefLifeSpanHandler::WindowOpenDisposition target_disposition,
		bool user_gesture,
		const CefPopupFeatures& popupFeatures,
		CefWindowInfo& windowInfo,
		CefRefPtr<CefClient>& client,
		CefBrowserSettings& settings,
		bool* no_javascript_access) OVERRIDE;

	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

public:
	virtual void OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
		bool isLoading,
		bool canGoBack,
		bool canGoForward) OVERRIDE;

#ifdef _AQUA_CEF2623_ADAPTER

	virtual void OnLoadStart(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame) OVERRIDE;
#else

	virtual void OnLoadStart(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		TransitionType transition_type) OVERRIDE;

#endif

	virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		int httpStatusCode) OVERRIDE;

	virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		ErrorCode errorCode,
		const CefString& errorText,
		const CefString& failedUrl) OVERRIDE;

	virtual ReturnValue OnBeforeResourceLoad(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request,
		CefRefPtr<CefRequestCallback> callback) OVERRIDE;

#ifdef _AQUA_CEF2623_ADAPTER
	virtual void OnResourceRedirect(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request,
		CefString& new_url) OVERRIDE;
#else
	virtual void OnResourceRedirect(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request,
		CefRefPtr<CefResponse> response,
		CefString& new_url) OVERRIDE;
#endif

	virtual CefRefPtr<CefResponseFilter> GetResourceResponseFilter(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request,
		CefRefPtr<CefResponse> response) OVERRIDE;

	virtual void OnResourceLoadComplete(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request,
		CefRefPtr<CefResponse> response,
		URLRequestStatus status,
		int64 received_content_length) OVERRIDE;

	virtual bool OnPreKeyEvent(CefRefPtr<CefBrowser> browser,
		const CefKeyEvent& event,
		CefEventHandle os_event,
		bool* is_keyboard_shortcut) OVERRIDE;

	virtual bool OnKeyEvent(CefRefPtr<CefBrowser> browser,
		const CefKeyEvent& event,
		CefEventHandle os_event) OVERRIDE;

	virtual void OnBeforeDownload(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDownloadItem> download_item,
		const CefString& suggested_name,
		CefRefPtr<CefBeforeDownloadCallback> callback) OVERRIDE;

	virtual void OnDownloadUpdated(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDownloadItem> download_item,
		CefRefPtr<CefDownloadItemCallback> callback) OVERRIDE;

	virtual bool RunContextMenu(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefContextMenuParams> params,
		CefRefPtr<CefMenuModel> model,
		CefRefPtr<CefRunContextMenuCallback> callback) OVERRIDE;

	virtual bool GetAuthCredentials(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		bool isProxy,
		const CefString& host,
		int port,
		const CefString& realm,
		const CefString& scheme,
		CefRefPtr<CefAuthCallback> callback) OVERRIDE;

public:
	void CloseAllBrowser(void);

protected:
	IMPLEMENT_REFCOUNTING(AquaCallBrowser);
};


#endif