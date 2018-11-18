#include "aqua_calling_browser.h"
#include "handler\aqua_handler_renderer.h"
#include "utils\aqua_conv.h"
#include "include\cef_v8.h"
#include "include\cef_app.h"

namespace Local {
	CefRefPtr<AquaCallBrowser> handler;
}

CefRefPtr<AquaCallBrowser> AquaCallBrowser::GetInterface(void) {
	return Local::handler;
}

AquaCallBrowser::AquaCallBrowser() {
	Local::handler = this;
	m_closed = FALSE;

}

AquaCallBrowser::~AquaCallBrowser() {
	Local::handler = NULL;
}

bool AquaCallBrowser::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
	CefProcessId source_process,
	CefRefPtr<CefProcessMessage> message) {
	return false;
}

void AquaCallBrowser::OnAddressChange(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	const CefString& url) {
	if (AquaHandler::renderInterface.OnAddressChange && url.length()>0) {
		aqua_convert conv;
		std::string ansiUrl;
		if (url.length() > 0) {
			ansiUrl = conv.to_bytes(url.c_str());
		}
		browser->AddRef();
		frame->AddRef();
		AquaHandler::renderInterface.OnAddressChange(browser.get(), frame.get(), ansiUrl.c_str());
		frame->Release();
		browser->Release();
	}
}

void AquaCallBrowser::OnTitleChange(CefRefPtr<CefBrowser> browser,
	const CefString& title){
	if (AquaHandler::renderInterface.OnTitleChange  && title.length()>0) {
		aqua_convert conv;
		std::string ansiTitle;
		if (title.length() > 0) {
			try{
				ansiTitle = conv.to_bytes(title.c_str());
			}
			catch (const std::exception &ex){
				// ??? 转码失败
				int len = WideCharToMultiByte(CP_ACP, 0, title.c_str(), title.length(), NULL, NULL, NULL, NULL);
				char *buf = new char[len + 1];
				WideCharToMultiByte(CP_ACP, 0, title.c_str(), title.length(), buf, len, NULL, NULL);
				buf[len] = 0;
				ansiTitle = buf;
				delete[]buf;
			}
		}
		browser->AddRef();
		AquaHandler::renderInterface.OnTitleChange(browser.get(), ansiTitle.c_str());
		browser->Release();
	}
}

void AquaCallBrowser::OnFaviconURLChange(CefRefPtr<CefBrowser> browser,
	const std::vector<CefString>& icon_urls) {
	if (AquaHandler::renderInterface.OnFaviconURLChange) {
		browser->AddRef();
		AquaHandler::renderInterface.OnFaviconURLChange(browser.get(), (LPVOID)&icon_urls);
		browser->Release();
	}
}

void AquaCallBrowser::OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
	bool fullscreen) {
	if (AquaHandler::renderInterface.OnFullscreenModeChange) {
		browser->AddRef();
		AquaHandler::renderInterface.OnFullscreenModeChange(browser.get(), fullscreen);
		browser->Release();
	}
}

bool AquaCallBrowser::OnTooltip(CefRefPtr<CefBrowser> browser, CefString& text) {
	if (AquaHandler::renderInterface.OnStatusMessage && text.length()>0) {
		aqua_convert conv;
		std::string ansiVal;
		if (text.length() > 0) {
			try
			{
				ansiVal = conv.to_bytes(text.c_str());
			}
			catch (const std::exception &ex)
			{
				int len = WideCharToMultiByte(CP_ACP, 0, text.c_str(), text.length(), NULL, NULL, NULL, NULL);
				char *buf = new char[len + 1];
				WideCharToMultiByte(CP_ACP, 0, text.c_str(), text.length(), buf, len, NULL, NULL);
				buf[len] = 0;
				ansiVal = buf;
				delete[]buf;
			}
		}
		browser->AddRef();
		AquaHandler::renderInterface.OnStatusMessage(browser.get(), ansiVal.c_str());
		browser->Release();
	}
	return false;
}

void AquaCallBrowser::OnStatusMessage(CefRefPtr<CefBrowser> browser,
	const CefString& value) {
	if (AquaHandler::renderInterface.OnStatusMessage && value.length()>0) {
		aqua_convert conv;
		std::string ansiVal;
		if (value.length() > 0) {
			try
			{
				ansiVal = conv.to_bytes(value.c_str());
			}
			catch (const std::exception&)
			{
				int len = WideCharToMultiByte(CP_ACP, 0, value.c_str(), value.length(), NULL, NULL, NULL, NULL);
				char *buf = new char[len + 1];
				WideCharToMultiByte(CP_ACP, 0, value.c_str(), value.length(), buf, len, NULL, NULL);
				buf[len] = 0;
				ansiVal = buf;
				delete[]buf;
			}
		}
		browser->AddRef();
		AquaHandler::renderInterface.OnStatusMessage(browser.get(), ansiVal.c_str());
		browser->Release();
	}
}

#ifdef _AQUA_CEF2623_ADAPTER

bool AquaCallBrowser::OnConsoleMessage(CefRefPtr<CefBrowser> browser,
	const CefString& message,
	const CefString& source,
	int line) {
	bool result = false;
	if (AquaHandler::renderInterface.OnConsoleMessage && message.length()>0) {
		aqua_convert conv;
		std::string ansiMessage;
		try
		{
			ansiMessage = conv.to_bytes(message.c_str());
		}
		catch (const std::exception&)
		{
			int len = WideCharToMultiByte(CP_ACP, 0, message.c_str(), message.length(), NULL, NULL, NULL, NULL);
			char *buf = new char[len + 1];
			WideCharToMultiByte(CP_ACP, 0, message.c_str(), message.length(), buf, len, NULL, NULL);
			buf[len] = 0;
			ansiMessage = buf;
			delete[]buf;
		}
		std::string ansiSource = "about:blank";
		if (source.length() > 0) {
			auto text = conv.to_bytes(source.c_str());
			ansiSource = text.c_str();
		}
		browser->AddRef();
		result = AquaHandler::renderInterface.OnConsoleMessage(browser.get(), -1, ansiMessage.c_str(), ansiSource.c_str(), line);
		browser->Release();
	}
	return result;
}

#else

bool AquaCallBrowser::OnConsoleMessage(CefRefPtr<CefBrowser> browser,
	cef_log_severity_t level,
	const CefString& message,
	const CefString& source,
	int line) {
	bool result = false;
	if (AquaHandler::renderInterface.OnConsoleMessage && message.length()>0) {
		aqua_convert conv;
		std::string ansiMessage;
		try
		{
			ansiMessage = conv.to_bytes(message.c_str());
		}
		catch (const std::exception&)
		{
			int len = WideCharToMultiByte(CP_ACP, 0, message.c_str(), message.length(), NULL, NULL, NULL, NULL);
			char *buf = new char[len + 1];
			WideCharToMultiByte(CP_ACP, 0, message.c_str(), message.length(), buf, len, NULL, NULL);
			buf[len] = 0;
			ansiMessage = buf;
			delete[]buf;
		}
		std::string ansiSource = "about:blank";
		if (source.length() > 0) {
			auto text = conv.to_bytes(source.c_str());
			ansiSource = text.c_str();
		}
		browser->AddRef();
		result = AquaHandler::renderInterface.OnConsoleMessage(browser.get(), -1, ansiMessage.c_str(), ansiSource.c_str(), line);
		browser->Release();
	}
	return result;
}

#endif

 bool AquaCallBrowser::OnBeforePopup(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	const CefString& target_url,
	const CefString& target_frame_name,
	CefLifeSpanHandler::WindowOpenDisposition target_disposition,
	bool user_gesture,
	const CefPopupFeatures& popupFeatures,
	CefWindowInfo& windowInfo,
	CefRefPtr<CefClient>& client,
	CefBrowserSettings& settings,
	bool* no_javascript_access) {
	 //browser->AddRef();
	 //m_pm.push_back(browser);

	 bool result = false;
	 if (AquaHandler::renderInterface.OnBeforePopup) {
		 aqua_convert conv;
		 std::string tempUrl;
		 if (target_url.length() > 0) {
			 tempUrl = conv.to_bytes(target_url.c_str());
		 }
		 std::string tempFrameName;
		 if (target_frame_name.length() > 0) {
			 tempFrameName = conv.to_bytes(target_frame_name.c_str());
		 }
		 browser->AddRef();
		 frame->AddRef();
		 result = AquaHandler::renderInterface.OnBeforePopup(browser.get(), frame.get(),
			 tempUrl.c_str(), tempFrameName.c_str(), (int)target_disposition, user_gesture,
			 (LPVOID)&popupFeatures, (LPVOID)&windowInfo,(LPVOID)&settings, no_javascript_access);
		 frame->Release();
		 browser->Release();
	 }
	 //if (result) {
		// int max = m_pm.size();
		// CefRefPtr<CefBrowserHost> host = NULL;
		// for (size_t i = 0; i < max; i++)
		// {
		//	 if (m_pm[i]->IsSame(browser)) {
		//		 m_pm[i]->Release();
		//		 m_pm.erase(m_pm.begin() + i);
		//		 break;
		//	 }
		// }
	 //}
	 return result;
}

 void AquaCallBrowser::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
	 browser->AddRef();
	 m_pm.push_back(browser);
	 if (AquaHandler::renderInterface.OnAfterCreated) {
		 browser->AddRef();
		 AquaHandler::renderInterface.OnAfterCreated(browser.get());
		 browser->Release();
	 }
}

 bool AquaCallBrowser::DoClose(CefRefPtr<CefBrowser> browser) {
	 bool result = false;
	 if (AquaHandler::renderInterface.DoClose) {
		 browser->AddRef();
		 result = AquaHandler::renderInterface.DoClose(browser.get());
		 browser->Release();
	 }
	 if (result == false) {
		 HWND hWnd = browser->GetHost()->GetWindowHandle();
		 ShowWindow(hWnd, SW_HIDE);
		 SetParent(hWnd, NULL);
	 }
	 return result;
}

 void AquaCallBrowser::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
	 if (AquaHandler::renderInterface.OnBeforeClose) {
		 browser->AddRef();
		 AquaHandler::renderInterface.OnBeforeClose(browser.get());
		 browser->Release();
	 }
	 int max = m_pm.size();
	 for (size_t i = 0; i < max; i++)
	 {
		 if (m_pm[i]->GetIdentifier() == browser->GetIdentifier()) {
			 m_pm[i]->Release();
			 m_pm.erase(m_pm.begin() + i);
			 break;
		 }
	 }
}

 bool AquaCallBrowser::OnFileDialog(CefRefPtr<CefBrowser> browser,
	 FileDialogMode mode,
	 const CefString& title,
	 const CefString& default_file_path,
	 const std::vector<CefString>& accept_filters,
	 int selected_accept_filter,
	 CefRefPtr<CefFileDialogCallback> callback) {
	 bool result = false;
	 if (AquaHandler::renderInterface.OnFileDialog) {
		 std::string tit, defpath;
		 aqua_convert conv;
		 if (title.length() > 0) {
			 tit = conv.to_bytes(title.c_str());
		 }
		 if (default_file_path.length() > 0) {
			 defpath = conv.to_bytes(default_file_path.c_str());
		 }
		 browser->AddRef();
		 callback->AddRef();
		 result = AquaHandler::renderInterface.OnFileDialog(browser.get(), (int)mode, tit.c_str(), defpath.c_str(), (LPVOID)&accept_filters, selected_accept_filter, callback.get());
		 callback->Release();
		 browser->Release();
	 }
	 return result;
 }

 void AquaCallBrowser::OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
	 bool isLoading,
	 bool canGoBack,
	 bool canGoForward) {
	 if (AquaHandler::renderInterface.OnLoadingStateChange) {
		 browser->AddRef();
		 AquaHandler::renderInterface.OnLoadingStateChange(browser.get(), isLoading, canGoBack, canGoForward);
		 browser->Release();
	 }
 }

#ifdef _AQUA_CEF2623_ADAPTER

 void AquaCallBrowser::OnLoadStart(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame) {

	 if (AquaHandler::renderInterface.OnLoadStart) {
		 browser->AddRef();
		 frame->AddRef();
		 AquaHandler::renderInterface.OnLoadStart(browser.get(), frame.get(), NULL);
		 frame->Release();
		 browser->Release();
	 }
 }
#else

 void AquaCallBrowser::OnLoadStart(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 TransitionType transition_type) {
	 if (AquaHandler::renderInterface.OnLoadStart) {
		 browser->AddRef();
		 frame->AddRef();
		 AquaHandler::renderInterface.OnLoadStart(browser.get(), frame.get(), transition_type);
		 frame->Release();
		 browser->Release();
	 }
 }


#endif

 void AquaCallBrowser::OnLoadEnd(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 int httpStatusCode) {
	 if (AquaHandler::renderInterface.OnLoadEnd) {
		 browser->AddRef();
		 frame->AddRef();
		 AquaHandler::renderInterface.OnLoadEnd(browser.get(), frame.get(), httpStatusCode);
		 frame->Release();
		 browser->Release();
	 }
 }

 void AquaCallBrowser::OnLoadError(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 ErrorCode errorCode,
	 const CefString& errorText,
	 const CefString& failedUrl) {
	 if (errorCode == ERR_ABORTED)
		 return;


	 if (AquaHandler::renderInterface.OnLoadError) {
		 aqua_convert conv;
		 const char *er = NULL;
		 const char *fr = NULL;
		 if (errorText.length() > 0) {
			 auto ansiErrorText = conv.to_bytes(errorText);
			 er = ansiErrorText.c_str();
		 }
		 if (failedUrl.length() > 0) {
			 auto ansiFailedUrl = conv.to_bytes(failedUrl);
			 fr = ansiFailedUrl.c_str();
		 }
		 browser->AddRef();
		 frame->AddRef();
		 AquaHandler::renderInterface.OnLoadError(browser.get(), frame.get(), (int)errorCode, er, fr);
		 frame->Release();
		 browser->Release();
	 }
 }

 void AquaCallBrowser::CloseAllBrowser(void) {
	 int max = m_pm.size();
	 for (size_t i = 0; i < max; i++)
	 {
		 m_pm[i]->GetHost()->CloseBrowser(false);
	 }
 }

 AquaCallBrowser::ReturnValue AquaCallBrowser::OnBeforeResourceLoad(
	 CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefRequest> request,
	 CefRefPtr<CefRequestCallback> callback) {
	 // 资源载入开始
	 if (AquaHandler::renderInterface.OnBeforeResourceLoad) {
		 bool result = true;
		 BOOL isCoped = FALSE;
		 browser->AddRef();
		 frame->AddRef();
		 request->AddRef();
		 result = AquaHandler::renderInterface.OnBeforeResourceLoad(browser.get(), frame.get(), request.get(), &isCoped);
		 request->Release();
		 frame->Release();
		 browser->Release();
		 if (isCoped) {
			 m_requests.push_back(new AquaCallResponseFilter(request->GetIdentifier()));
		 }
		 if (result == false) {
			 return RV_CANCEL;
		 }
	 }
	 return RV_CONTINUE;
}

 void CALLBACK OnRedirect(LPCSTR url, LPVOID params) {
	 if (url != NULL && params != NULL) {
		 CefString *org = reinterpret_cast<CefString*>(params);
		 aqua_convert conv;
		 (*org) = conv.from_bytes(url);
	 }
 }

#ifdef _AQUA_CEF2623_ADAPTER
 void AquaCallBrowser::OnResourceRedirect(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefRequest> request,
	 CefString& new_url) {
	 // 资源重定向
	 if (AquaHandler::renderInterface.OnResourceRedirect) {
		 browser->AddRef();
		 frame->AddRef();
		 request->AddRef();
		 AquaHandler::renderInterface.OnResourceRedirect(browser.get(), frame.get(), request.get(), OnRedirect, &new_url);
		 request->Release();
		 frame->Release();
		 browser->Release();
	 }
 }
#else
 void AquaCallBrowser::OnResourceRedirect(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefRequest> request,
	 CefRefPtr<CefResponse> response,
	 CefString& new_url) {
	 if (AquaHandler::renderInterface.OnResourceRedirect) {
		 browser->AddRef();
		 frame->AddRef();
		 request->AddRef();
		 AquaHandler::renderInterface.OnResourceRedirect(browser.get(), frame.get(), request.get(), OnRedirect, &new_url);
		 request->Release();
		 frame->Release();
		 browser->Release();
	 }
 }
#endif

 CefRefPtr<CefResponseFilter> AquaCallBrowser::GetResourceResponseFilter(
	 CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefRequest> request,
	 CefRefPtr<CefResponse> response) {
	 if (m_requests.empty() == false) {
		 auto vid = request->GetIdentifier();
		 for (size_t i = 0; i < m_requests.size(); i++)
		 {
			 if (m_requests[i]->GetRequestId() == vid) {
				 return m_requests[i].get();
			 }
		 }
	 }
	 return NULL;
 }

 void AquaCallBrowser::OnResourceLoadComplete(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefRequest> request,
	 CefRefPtr<CefResponse> response,
	 URLRequestStatus status,
	 int64 received_content_length) {
	 // 资源载入结束
	 BYTE *pAddr = NULL;
	 if (m_requests.empty() == false) {
		 auto vid = request->GetIdentifier();
		 for (size_t i = 0; i < m_requests.size(); i++)
		 {
			 if (m_requests[i]->GetRequestId() == vid) {
				 if (m_requests[i]->GetSize() > 0) {
					 pAddr = (BYTE*)VirtualAlloc(NULL, m_requests[i]->GetSize() + sizeof(int)*2, MEM_COMMIT, PAGE_READWRITE);
					 *(int*)&pAddr[0] = 1;
					 *(int*)&pAddr[4] = m_requests[i]->GetSize();
					 m_requests[i]->SetPayload(&pAddr[8], m_requests[i]->GetSize());
				 }
				 m_requests.erase(m_requests.begin() + i);
				 break;
			 }
		 }
	 }

	 if (AquaHandler::renderInterface.OnResourceLoadComplete) {
		 browser->AddRef();
		 frame->AddRef();
		 request->AddRef();
		 response->AddRef();
		 AquaHandler::renderInterface.OnResourceLoadComplete(browser.get(), frame.get(), request.get(), response.get(), (int)status, received_content_length, pAddr);
		 response->Release();
		 request->Release();
		 frame->Release();
		 browser->Release();
		 if (pAddr) VirtualFree(pAddr, MEM_RELEASE, 0);
	 }
}

#ifdef _AQUA_CEF2623_ADAPTER

bool AquaCallBrowser::OnJSDialog(CefRefPtr<CefBrowser> browser,
	 const CefString& origin_url,
	 const CefString& accept_lang,
	 JSDialogType dialog_type,
	 const CefString& message_text,
	 const CefString& default_prompt_text,
	 CefRefPtr<CefJSDialogCallback> callback,
	 bool& suppress_message) {
	bool result = false;
	if (AquaHandler::renderInterface.OnJSDialog) {
		std::string org, lang, msg, defInput;
		aqua_convert conv;
		if (origin_url.length() > 0) {
			org = conv.to_bytes(origin_url.c_str());
		}
		if (accept_lang.length() > 0) {
			lang = conv.to_bytes(accept_lang.c_str());
		}
		if (message_text.length() > 0) {
			msg = conv.to_bytes(message_text.c_str());
		}
		if (default_prompt_text.length() > 0) {
			defInput = conv.to_bytes(default_prompt_text.c_str());
		}
		browser->AddRef();
		callback->AddRef();
		result = AquaHandler::renderInterface.OnJSDialog(browser.get(), org.c_str(), lang.c_str(), (int)dialog_type, msg.c_str(), defInput.c_str(), callback.get());
		callback->Release();
		browser->Release();
	}
	return result;
 }

#else

bool AquaCallBrowser::OnJSDialog(CefRefPtr<CefBrowser> browser,
	const CefString& origin_url,
	JSDialogType dialog_type,
	const CefString& message_text,
	const CefString& default_prompt_text,
	CefRefPtr<CefJSDialogCallback> callback,
	bool& suppress_message) {
	bool result = false;
	if (AquaHandler::renderInterface.OnJSDialog) {
		std::string org, lang, msg, defInput;
		aqua_convert conv;
		if (origin_url.length() > 0) {
			org = conv.to_bytes(origin_url.c_str());
		}
		if (message_text.length() > 0) {
			msg = conv.to_bytes(message_text.c_str());
		}
		if (default_prompt_text.length() > 0) {
			defInput = conv.to_bytes(default_prompt_text.c_str());
		}
		browser->AddRef();
		callback->AddRef();
		result = AquaHandler::renderInterface.OnJSDialog(browser.get(), org.c_str(), lang.c_str(), (int)dialog_type, msg.c_str(), defInput.c_str(), callback.get());
		callback->Release();
		browser->Release();
	}
	return result;
}

#endif


bool AquaCallBrowser::OnPreKeyEvent(CefRefPtr<CefBrowser> browser,
	const CefKeyEvent& event,
	CefEventHandle os_event,
	bool* is_keyboard_shortcut) {
	bool result = false;
	if (AquaHandler::renderInterface.OnPreKeyEvent) {
		_cef_key_event_t v;
		v.type = event.type;
		v.modifiers = event.modifiers;
		v.windows_key_code = event.windows_key_code;
		v.character = event.character;
		v.native_key_code = event.native_key_code;
		v.unmodified_character = event.unmodified_character;
		v.is_system_key = event.is_system_key;
		v.focus_on_editable_field = event.focus_on_editable_field;
		browser->AddRef();
		result = AquaHandler::renderInterface.OnPreKeyEvent(browser.get(), (LPVOID)&v, is_keyboard_shortcut);
		browser->Release();
	}
	return result;
}

bool AquaCallBrowser::OnKeyEvent(CefRefPtr<CefBrowser> browser,
	const CefKeyEvent& event,
	CefEventHandle os_event) {

	return false;
}

void AquaCallBrowser::OnBeforeDownload(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefDownloadItem> download_item,
	const CefString& suggested_name,
	CefRefPtr<CefBeforeDownloadCallback> callback) {
	if (AquaHandler::renderInterface.OnBeforeDownload) {
		aqua_convert conv;
		std::string name;
		if (suggested_name.length() > 0) {
			name = conv.to_bytes(suggested_name.c_str());
		}
		browser->AddRef();
		download_item->AddRef();
		callback->AddRef();
		AquaHandler::renderInterface.OnBeforeDownload(browser.get(), download_item.get(), name.c_str(), callback.get());
		callback->Release();
		download_item->Release();
		browser->Release();
	}
}

void AquaCallBrowser::OnDownloadUpdated(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefDownloadItem> download_item,
	CefRefPtr<CefDownloadItemCallback> callback) {
	if (AquaHandler::renderInterface.OnBeforeDownload) {
		browser->AddRef();
		download_item->AddRef();
		callback->AddRef();
		AquaHandler::renderInterface.OnDownloadUpdated(browser.get(), download_item.get(), callback.get());
		callback->Release();
		download_item->Release();
		browser->Release();
	}
}

bool AquaCallBrowser::RunContextMenu(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefContextMenuParams> params,
	CefRefPtr<CefMenuModel> model,
	CefRefPtr<CefRunContextMenuCallback> callback) {
	bool result = false;
	if (AquaHandler::renderInterface.RunContextMenu) {
		browser->AddRef();
		frame->AddRef();
		result = AquaHandler::renderInterface.RunContextMenu(browser.get(), frame.get(), params->GetXCoord(), params->GetYCoord());
		frame->Release();
		browser->Release();
	}
	return result;
}

bool AquaCallBrowser::GetAuthCredentials(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	bool isProxy,
	const CefString& host,
	int port,
	const CefString& realm,
	const CefString& scheme,
	CefRefPtr<CefAuthCallback> callback) {
	bool result = false;
	if (AquaHandler::renderInterface.GetAuthCredentials) {
		browser->AddRef();
		frame->AddRef();
		callback->AddRef();
		std::string v1, v2, v3;
		aqua_convert conv;
		if (host.length() > 0) {
			v1 = conv.to_bytes(host.c_str());
		}
		if (scheme.length() > 0) {
			v2 = conv.to_bytes(realm.c_str());
		}
		if (scheme.length() > 0) {
			v3 = conv.to_bytes(realm.c_str());
		}
		result = AquaHandler::renderInterface.GetAuthCredentials(browser.get(), frame.get(), isProxy, v1.c_str(), port, v2.c_str(), v3.c_str(), callback.get());
		callback->Release();
		frame->Release();
		browser->Release();
	}
	return result;
}