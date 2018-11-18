#include "aqua_browser_host.h"
#include "include\cef_browser.h"
#include "calling\aqua_calling_browser.h"
#include "utils\aqua_conv.h"
#include "include\cef_jsdialog_handler.h"
#include "calling\aqua_calling_request_context_handler.h"

using namespace AquaCef;

///
//	使用指定的窗口参数创建一个新的浏览器窗口
//	 | windowInfo |。所有值将在内部复制，并在实际窗口中复制
//	将在UI线程上创建，如果| request_context |为空
//	将使用全局请求上下文。
//	浏览器进程线程并不会阻塞。
///
AQUAENTRYFULL(BOOL, BrowserHost, CreateBrowserA)(LPCSTR url, LPVOID windowInfo, LPVOID settings, LPVOID rcs) {
	CefWindowInfo *pWi = reinterpret_cast<CefWindowInfo*>(windowInfo);
	CefBrowserSettings *pBs = reinterpret_cast<CefBrowserSettings*>(settings);
	CefBrowserSettings initBsConf;
	CefRefPtr<CefRequestContext> pRequestConf = NULL;
	aqua_convert conv;
	std::wstring fullUrl = conv.from_bytes(url);
	if (pBs == NULL) pBs = &initBsConf;
	if (pWi) {
		CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
		if (handler.get() == NULL) {
			handler = new AquaCallBrowser();
		}
		
		if (rcs != NULL) {
			auto pRequestInitial = reinterpret_cast<CefRequestContextSettings*>(rcs);
			//CefRefPtr<CefCookieManager> manager = CefCookieManager::CreateManager(pRequestInitial->cache_path.str, true, NULL);
			//new AquaRequestContextHandler(manager.get())
			pRequestConf = CefRequestContext::CreateContext((*pRequestInitial), NULL);
		}
		
		return CefBrowserHost::CreateBrowser((*pWi), handler, fullUrl, (*pBs), pRequestConf.get());
	}
	return FALSE;
}

///
//	使用指定的窗口参数创建一个新的浏览器窗口
//	 | windowInfo |。所有值将在内部复制，并在实际窗口中复制
//	将在UI线程上创建，如果| request_context |为空
//	将使用全局请求上下文。
//	浏览器进程线程并不会阻塞。
///
AQUAENTRYFULL(BOOL, BrowserHost, CreateBrowserW)(LPCWSTR url, LPVOID windowInfo, LPVOID settings, LPVOID rcs) {
	CefWindowInfo *pWi = reinterpret_cast<CefWindowInfo*>(windowInfo);
	CefBrowserSettings *pBs = reinterpret_cast<CefBrowserSettings*>(settings);
	CefRefPtr<CefRequestContext> request = NULL;
	if (pWi && pBs) {
		CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
		if (handler.get() == NULL) {
			handler = new AquaCallBrowser();
		}
		if (rcs) {
			auto pRcs = reinterpret_cast<CefRequestContextSettings*>(rcs);
			request = CefRequestContext::CreateContext(*pRcs, NULL);
		}
		return CefBrowserHost::CreateBrowser((*pWi), handler, url, (*pBs), request.get());
	}
	return FALSE;
}

///
//	返回托管浏览器对象。
///
AQUAENTRYFULL(LPVOID, BrowserHost, GetBrowser)(LPVOID object) {
	LPVOID result = NULL;
	CefRefPtr<CefBrowser> b = NULL;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		b = pHost->GetBrowser();
		b->AddRef();
		result = b.get();
		pHost->Release();
	}
	return result;
}

///
//	请求浏览器关闭，JavaScript'onbeforeunload'事件将会发生
//	被解雇，如果| force_close |为false，事件处理器（如果有的话）将会是
//	允许提示用户，用户可以选择取消关闭。
//	如果| force_close |为true，则不会显示提示并关闭
//	将继续，如果是，则调用CefLifeSpanHandler :: DoClose（）
//	事件处理程序允许close或if | force_close |为true
//	CefLifeSpanHandler :: DoClose（）文档以获取更多用法
//	信息。
///
AQUAENTRYFULL(void, BrowserHost, CloseBrowser)(LPVOID object, BOOL force_close) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->CloseBrowser(force_close);
		pHost->Release();
	}
}

///
//	关闭浏览器的Helper从顶层窗口调用这个方法
//	close处理程序，如果关闭了，在内部调用CloseBrowser（false）
//	尚未启动，当关闭时，此方法返回false
//	等待并在关闭完成后返回true。请参阅CloseBrowser（）和
//	CefLifeSpanHandler :: DoClose（）文档以获取更多用法
//	information。这个方法必须在浏览器进程UI线程上调用。
///
AQUAENTRYFULL(void, BrowserHost, TryCloseBrowser)(LPVOID object) {
#ifndef _AQUA_CEF2623_ADAPTER
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->TryCloseBrowser();
		pHost->Release();
	}
#endif
}

///
//	设置浏览器是否给与焦点。
///
AQUAENTRYFULL(void, BrowserHost, SetFocus)(LPVOID object, BOOL focus) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetFocus(focus);
		pHost->Release();
	}
}

///
//	为此检索窗口句柄。如果这个浏览器被包装了
//	一个CefBrowserView应该在浏览器进程UI上调用这个方法
//	线程，它将返回顶级本机窗口的句柄。
///
AQUAENTRYFULL(HWND, BrowserHost, GetWindowHandle)(LPVOID object) {
	HWND result = NULL;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->GetWindowHandle();
		pHost->Release();
	}
	return result;
}

///
//	获取当前缩放级别。默认缩放级别为0.0。此方法可以
//	只能在UI线程中调用。
///
AQUAENTRYFULL(double, BrowserHost, GetZoomLevel)(LPVOID object) {
	double zoom = 0.0f;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		zoom = pHost->GetZoomLevel();
		pHost->Release();
	}
	return zoom;
}

///
//	将缩放级别更改为指定值。指定0.0以重置
//	缩放级别，如果在UI线程上调用，则会应用更改
//	立即，否则，更改将被异步应用于
//	UI线程。
///
AQUAENTRYFULL(void, BrowserHost, SetZoomLevel)(LPVOID object, double zoomLevel) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetZoomLevel(zoomLevel);
		pHost->Release();
	}
}

///
//	使用CefDownloadHandler在 | url | 下载文件。
///
AQUAENTRYFULL(void, BrowserHost, StartDownloadA)(LPVOID object, LPCSTR url) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		aqua_convert conv;
		auto addr = conv.from_bytes(url);
		pHost->StartDownload(addr);
		pHost->Release();
	}
}

///
//	使用CefDownloadHandler在 | url | 下载文件。
///
AQUAENTRYFULL(void, BrowserHost, StartDownloadW)(LPVOID object, LPCSTR url) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->StartDownload(url);
		pHost->Release();
	}
}

///
//	打印当前的浏览器内容。
///
AQUAENTRYFULL(void, BrowserHost, Print)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->Print();
		pHost->Release();
	}
}

///
//	在自己的浏览器中打开开发工具（DevTools），DevTools浏览器
//	将继续与这个浏览器相关联，如果DevTools浏览器是
//	已经打开，那么它将被聚焦，在这种情况下| windowInfo |，
//	如果 | inspect_element_at | ，// | client |和| settings |参数将被忽略
//	非空，那么指定（x，y）位置的元素将会是
//	检查。如果此浏览器是| windowInfo |参数将被忽略
//	包装在CefBrowserView中。
///
AQUAENTRYFULL(void, BrowserHost, ShowDevTools)(LPVOID object, LPVOID windowInfo, LPVOID settings, int x, int y) {
	if (object && windowInfo && settings) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		auto pWi = reinterpret_cast<CefWindowInfo*>(windowInfo);
		auto pBs = reinterpret_cast<CefBrowserSettings*>(settings);
		CefPoint pt(x, y);
		pHost->AddRef();
		pHost->ShowDevTools((*pWi),AquaCallBrowser::GetInterface(), (*pBs),pt);
		pHost->Release();
	}
}

///
//	明确关闭相关的DevTools浏览器（如果有的话）。
///
AQUAENTRYFULL(void, BrowserHost, CloseDevTools)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->CloseDevTools();
		pHost->Release();
	}
}

///
//	如果此浏览器当前具有关联的DevTools浏览器，则返回true。
//	必须在浏览器进程UI线程上调用。
///
AQUAENTRYFULL(BOOL, BrowserHost, HasDevTools)(LPVOID object) {
	BOOL result = FALSE;
#ifndef _AQUA_CEF2623_ADAPTER
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->HasDevTools();
		pHost->Release();
	}
#endif
	return result;
}

///
//	设置或鼠标光标更改被禁用。
///
AQUAENTRYFULL(void, BrowserHost, SetMouseCursorChangeDisabled)(LPVOID object, bool disabled) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetMouseCursorChangeDisabled(disabled);
		pHost->Release();
	}
}

///
//	如果禁用鼠标光标更改，则返回true。
///
AQUAENTRYFULL(BOOL, BrowserHost, IsMouseCursorChangeDisabled)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->IsMouseCursorChangeDisabled();
		pHost->Release();
	}
	return result;
}

///
//	如果禁用窗口渲染，则返回true。
///
AQUAENTRYFULL(BOOL, BrowserHost, IsWindowRenderingDisabled)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->IsWindowRenderingDisabled();
		pHost->Release();
	}
	return result;
}

///
//	通知浏览器小部件已被调整大小，浏览器首先
//	调用CefRenderHandler :: GetViewRect获取新的大小然后调用
//	 CefRenderHandler :: OnPaint与更新区域异步
//	方法仅在禁用窗口渲染时使用。
///
AQUAENTRYFULL(void, BrowserHost, WasResized)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->WasResized();
		pHost->Release();
	}
}

///
//	通知浏览器它已被隐藏或显示
//	CefRenderHandler :: OnPaint通知将在浏览器停止时停止
//	hidden。这个方法只在禁用窗口渲染时使用。
///
AQUAENTRYFULL(void, BrowserHost, WasHidden)(LPVOID object, bool hidden) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->WasHidden(hidden);
		pHost->Release();
	}
}

///
//	向浏览器发送屏幕信息已更改的通知。
//	浏览器会调用CefRenderHandler :: GetScreenInfo来更新
//	使用这个新值来显示信息。这模拟移动webview
//	从一个显示窗口到另一个显示窗口，或者改变窗口的属性
//	当前显示，该方法仅在窗口渲染时使用
//	禁用。
///
AQUAENTRYFULL(void, BrowserHost, NotifyScreenInfoChanged)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->NotifyScreenInfoChanged();
		pHost->Release();
	}
}

///
//	使视图无效，浏览器将调用CefRenderHandler :: OnPaint
//	异步。此方法仅在窗口呈现时使用
//	禁用。
///
AQUAENTRYFULL(void, BrowserHost, Invalidate)(LPVOID object, int status) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->Invalidate((CefBrowserHost::PaintElementType)status);
		pHost->Release();
	}
}

///
//	将焦点事件发送到浏览器。
///
AQUAENTRYFULL(void, BrowserHost, SendFocusEvent)(LPVOID object, bool setFocus) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SendFocusEvent(setFocus);
		pHost->Release();
	}
}

///
//	向浏览器发送捕获丢失事件。
///
AQUAENTRYFULL(void, BrowserHost, SendCaptureLostEvent)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SendCaptureLostEvent();
		pHost->Release();
	}
}

///
//	通知浏览器托管它的窗口即将被移动或移动
//	调整大小，此方法仅用于Windows和Linux。
///
AQUAENTRYFULL(void, BrowserHost, NotifyMoveOrResizeStarted)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->NotifyMoveOrResizeStarted();
		pHost->Release();
	}
}

///
//	以每秒帧数（fps）返回最大速率CefRenderHandler ::
//	OnPaint将被邀请用于无窗口浏览器，实际的fps可能是
//	如果浏览器无法按请求的速率生成帧，则降低。
//	最小值为1，最大值为60（默认值为30）
//	只能在UI线程中调用。
///
AQUAENTRYFULL(int, BrowserHost, GetWindowlessFrameRate)(LPVOID object) {
	int result = 0;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->GetWindowlessFrameRate();
		pHost->Release();
	}
	return result;
}

///
//	将关键事件发送到浏览器。
///
AQUAENTRYFULL(void, BrowserHost, SendKeyEvent)(LPVOID object, LPVOID event) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_key_event_t*>(event);
		CefKeyEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendKeyEvent(key);
		p->Release();
	}
}

///
//	将鼠标单击事件发送到浏览器。 | x | 和| y | 坐标是视图的左上角。
///
AQUAENTRYFULL(void, BrowserHost, SendMouseClickEvent)(LPVOID object, LPVOID event, int type, bool mouseUp, int clickCount) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_mouse_event_t*>(event);
		CefMouseEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendMouseClickEvent(key, (cef_mouse_button_type_t)type, mouseUp, clickCount);
		p->Release();
	}
}

///
//	将鼠标移动事件发送到浏览器。 | x | 和| y | 坐标相对于视图的左上角。
///
AQUAENTRYFULL(void, BrowserHost, SendMouseMoveEvent)(LPVOID object, LPVOID event, bool mouseLeave) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_mouse_event_t*>(event);
		CefMouseEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendMouseMoveEvent(key, mouseLeave);
		p->Release();
	}
}

///
//	将鼠标滚轮事件发送到浏览器。 | x | 和| y | 坐标是
//	相对于视图的左上角。 | deltaX | 和 | deltaY |
//	值分别表示X和Y方向上的运动增量。
//	为了在禁用窗口渲染的情况下滚动内部选择弹出窗口
//	应该正确实现CefRenderHandler::GetScreenPoint。
///
AQUAENTRYFULL(void, BrowserHost, SendMouseWheelEvent)(LPVOID object, LPVOID event, int deltaX, int deltaY) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_mouse_event_t*>(event);
		CefMouseEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendMouseWheelEvent(key,deltaX,deltaY);
		p->Release();
	}
}

///
//	设置每秒帧数（fps）的最大速率CefRenderHandler ::
//	OnPaint将被邀请用于无窗口浏览器，实际的fps可能是
//	如果浏览器无法按请求的速率生成帧，则降低。
//	最小值是1，最大值是60（默认30）。也可以是
//	通过CefBrowserSettings.windowless_frame_rate创建浏览器。
///
AQUAENTRYFULL(void, BrowserHost, SetWindowlessFrameRate)(LPVOID object, int frame_rate) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetWindowlessFrameRate(frame_rate);
		pHost->Release();
	}
}

///
//	移动或调整在管理器中的浏览器窗口位置及大小,|parent|不为NULL时,仅调整该窗口下的所有子浏览器窗口
//	否则将调整所有窗口。
///
AQUAENTRYFULL(void, Manager, MoveOrResized)(HWND parent, int x, int y, int width, int height) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get()) {
		auto mgr = handler->GetManager();
		int max = mgr->size();
		CefRefPtr<CefBrowserHost> host;
		HWND child = NULL;
		for (size_t i = 0; i < max; i++)
		{
			host = mgr->at(i)->GetHost();
			child = host->GetWindowHandle();
			if (parent != NULL) {
				if (GetParent(child) == parent) {
					SetWindowPos(child, NULL, x, y, width, height, SWP_NOACTIVATE | SWP_NOZORDER);
					host->NotifyMoveOrResizeStarted();
					host->NotifyScreenInfoChanged();
				}
			}
			else {
				host->NotifyMoveOrResizeStarted();
				host->NotifyScreenInfoChanged();
				SetWindowPos(child, NULL, x, y, width, height, SWP_NOACTIVATE | SWP_NOZORDER);
			}
		}
	}
}

///
//	设置主显示浏览器
///
AQUAENTRYFULL(void, Manager, SetMainHeroine)(HWND parent, HWND child) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get() && IsWindow(child)) {
		auto mgr = handler->GetManager();
		int max = mgr->size();
		CefRefPtr<CefBrowserHost> host;
		HWND manaChild = NULL;
		for (size_t i = 0; i < max; i++)
		{
			host = mgr->at(i)->GetHost();
			manaChild = host->GetWindowHandle();
			if (GetParent(manaChild) == parent) {
				if (manaChild == child) {
					ShowWindow(manaChild, SW_SHOW);
				}
				else {
					ShowWindow(manaChild, SW_HIDE);
				}
			}
		}
	}
}

///
//	查询管理器中与|id|进行关联的浏览器对象,当返回NULL时则意味着找不到其所关联的东西
///
AQUAENTRYFULL(LPVOID, Manager, QueryActor)(HWND id) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get() && IsWindow(id)) {
		auto mgr = handler->GetManager();
		int max = mgr->size();
		CefRefPtr<CefBrowserHost> host;
		HWND manaChild = NULL;
		for (size_t i = 0; i < max; i++)
		{
			host = mgr->at(i)->GetHost();
			manaChild = host->GetWindowHandle();
			if (manaChild == id) {
				CefBrowser *actor = mgr->at(i);
				actor->AddRef();
				return actor;
			}
		}
	}
	return NULL;
}

///
//	获取管理器中的浏览器数量
///
AQUAENTRYFULL(int, Manager, GetCount)(void) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get()) {
		return handler->GetManager()->size();
	}
	return 0;
}

///
//	关闭所有浏览器
///
AQUAENTRYFULL(void, Manager, CloseAllBrowser)(void) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get()) {
		handler->CloseAllBrowser();
	}
}

///
//	获取浏览器所关联的会话管理对象。
///
AQUAENTRYFULL(LPVOID, BrowserHost, GetCookieManager)(LPVOID object) {
	CefRefPtr<CefCookieManager> manager = NULL;
	if (object) {
		CefBrowserHost *host = reinterpret_cast<CefBrowserHost*>(object);
		host->AddRef();
		manager = host->GetRequestContext()->GetDefaultCookieManager(NULL);
		if (manager.get()) {
			manager->AddRef();
		}
		host->Release();
	}
	return manager.get();
}

///
//	处理JS对话框
///
AQUAENTRYFULL(void, JSDialog, Continue)(LPVOID object, bool success, LPCSTR input) {
	if (object) {
		auto p = reinterpret_cast<CefJSDialogCallback*>(object);
		std::wstring v;
		if (input != NULL && strlen(input) > 0) {
			aqua_convert conv;
			v = conv.from_bytes(input);
		}
		p->AddRef();
		p->Continue(success, v);
		p->Release();
	}
}

///
//	处理文件对话框
///
AQUAENTRYFULL(void, FileDialog, Continue)(LPVOID object, int selection, LPVOID file_paths) {
	if (object && file_paths) {
		auto p = reinterpret_cast<CefFileDialogCallback*>(object);
		auto v = reinterpret_cast<std::vector<CefString>*>(file_paths);
		p->AddRef();
		p->Continue(selection, (*v));
		p->Release();
	}
}

///
//	处理文件对话框
///
AQUAENTRYFULL(void, FileDialog, Cancel)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefFileDialogCallback*>(object);
		p->AddRef();
		p->Cancel();
		p->Release();
	}
}

///
//	取Request上下文
///
AQUAENTRYFULL(LPVOID, BrowserHost, GetRequestContext)(LPVOID object) {
	//CefRefPtr<CefBrowserHost> context = NULL;
	//if (object) {
	//	CefBrowserHost *host = reinterpret_cast<CefBrowserHost*>(object);
	//	host->AddRef();
	//	context = host->GetRequestContext();
	//	if (context.get()) {
	//		context->AddRef();
	//	}
	//	host->Release();
	//}
	//return context.get();
	return NULL;
}