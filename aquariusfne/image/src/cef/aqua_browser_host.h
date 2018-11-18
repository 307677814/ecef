#ifndef AQUA_BROWSER_HOST_REFER_H_
#define AQUA_BROWSER_HOST_REFER_H_
#include "utils\aqua_utils.h"
#include "cef\aqua_window.h"

/**
  * 用于表示浏览器窗口的浏览器进程方面的类。该
  * 这个类的方法只能在浏览器进程中调用。 他们可能是
  * 在该进程中的任何线程上调用，除非另有说明
  * 注释。
  * * * * * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	使用指定的窗口参数创建一个新的浏览器窗口
	//	 | windowInfo |。所有值将在内部复制，并在实际窗口中复制
	//	将在UI线程上创建，如果| request_context |为空
	//	将使用全局请求上下文。
	//	浏览器进程线程并不会阻塞。
	///
	AQUAENTRYFULL(BOOL, BrowserHost, CreateBrowserA)(LPCSTR url, LPVOID windowInfo,LPVOID settings,LPVOID rcs);

	///
	//	使用指定的窗口参数创建一个新的浏览器窗口
	//	 | windowInfo |。所有值将在内部复制，并在实际窗口中复制
	//	将在UI线程上创建，如果| request_context |为空
	//	将使用全局请求上下文。
	//	浏览器进程线程并不会阻塞。
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, CreateBrowserW)(LPCWSTR url, LPVOID windowInfo, LPVOID settings, LPVOID rcs);

	///
	//	返回托管浏览器对象。
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, GetBrowser)(LPVOID object);

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
	AQUAENTRYFULL(void, BrowserHost, CloseBrowser)(LPVOID object,BOOL force_close);

	///
	//	关闭浏览器的Helper从顶层窗口调用这个方法
	//	close处理程序，如果关闭了，在内部调用CloseBrowser（false）
	//	尚未启动，当关闭时，此方法返回false
	//	等待并在关闭完成后返回true。请参阅CloseBrowser（）和
	//	CefLifeSpanHandler :: DoClose（）文档以获取更多用法
	//	information。这个方法必须在浏览器进程UI线程上调用。
	///
	AQUAENTRYFULL(void, BrowserHost, TryCloseBrowser)(LPVOID object);

	///
	//	设置浏览器是否给与焦点。
	///
	AQUAENTRYFULL(void, BrowserHost, SetFocus)(LPVOID object,BOOL focus);

	///
	//	为此检索窗口句柄。如果这个浏览器被包装了
	//	一个CefBrowserView应该在浏览器进程UI上调用这个方法
	//	线程，它将返回顶级本机窗口的句柄。
	///
	AQUAENTRYFULL(HWND, BrowserHost, GetWindowHandle)(LPVOID object);

	///
	//	获取当前缩放级别。默认缩放级别为0.0。此方法可以
	//	只能在UI线程中调用。
	///
	AQUAENTRYFULL(double, BrowserHost, GetZoomLevel)(LPVOID object);

	///
	//	将缩放级别更改为指定值。指定0.0以重置
	//	缩放级别，如果在UI线程上调用，则会应用更改
	//	立即，否则，更改将被异步应用于
	//	UI线程。
	///
	AQUAENTRYFULL(void, BrowserHost, SetZoomLevel)(LPVOID object,double zoomLevel);

	///
	//	使用CefDownloadHandler在 | url | 下载文件。
	///
	AQUAENTRYFULL(void, BrowserHost, StartDownloadA)(LPVOID object,LPCSTR url);

	///
	//	使用CefDownloadHandler在 | url | 下载文件。
	///
	AQUAENTRYFULL(void, BrowserHost, StartDownloadW)(LPVOID object, LPCSTR url);

	///
	//	打印当前的浏览器内容。
	///
	AQUAENTRYFULL(void, BrowserHost, Print)(LPVOID object);

	///
	//	在自己的浏览器中打开开发工具（DevTools），DevTools浏览器
	//	将继续与这个浏览器相关联，如果DevTools浏览器是
	//	已经打开，那么它将被聚焦，在这种情况下| windowInfo |，
	//	如果 | inspect_element_at | ，// | client |和| settings |参数将被忽略
	//	非空，那么指定（x，y）位置的元素将会是
	//	检查。如果此浏览器是| windowInfo |参数将被忽略
	//	包装在CefBrowserView中。
	///
	AQUAENTRYFULL(void, BrowserHost, ShowDevTools)(LPVOID object,LPVOID windowInfo,LPVOID settings,int x,int y);

	///
	//	明确关闭相关的DevTools浏览器（如果有的话）。
	///
	AQUAENTRYFULL(void, BrowserHost, CloseDevTools)(LPVOID object);

	///
	//	如果此浏览器当前具有关联的DevTools浏览器，则返回true。
	//	必须在浏览器进程UI线程上调用。
	///
	AQUAENTRYFULL(BOOL, BrowserHost, HasDevTools)(LPVOID object);

	///
	//	设置或鼠标光标更改被禁用。
	///
	AQUAENTRYFULL(void, BrowserHost, SetMouseCursorChangeDisabled)(LPVOID object, bool disabled);

	///
	//	如果禁用鼠标光标更改，则返回true。
	///
	AQUAENTRYFULL(BOOL, BrowserHost, IsMouseCursorChangeDisabled)(LPVOID object);

	///
	//	如果禁用窗口渲染，则返回true。
	///
	AQUAENTRYFULL(BOOL, BrowserHost, IsWindowRenderingDisabled)(LPVOID object);

	///
	//	通知浏览器小部件已被调整大小，浏览器首先
	//	调用CefRenderHandler :: GetViewRect获取新的大小然后调用
	//	 CefRenderHandler :: OnPaint与更新区域异步
	//	方法仅在禁用窗口渲染时使用。
	///
	AQUAENTRYFULL(void, BrowserHost, WasResized)(LPVOID object);

	///
	//	通知浏览器它已被隐藏或显示
	//	CefRenderHandler :: OnPaint通知将在浏览器停止时停止
	//	hidden。这个方法只在禁用窗口渲染时使用。
	///
	AQUAENTRYFULL(void, BrowserHost, WasHidden)(LPVOID object, bool hidden);

	///
	//	向浏览器发送屏幕信息已更改的通知。
	//	浏览器会调用CefRenderHandler :: GetScreenInfo来更新
	//	使用这个新值来显示信息。这模拟移动webview
	//	从一个显示窗口到另一个显示窗口，或者改变窗口的属性
	//	当前显示，该方法仅在窗口渲染时使用
	//	禁用。
	///
	AQUAENTRYFULL(void, BrowserHost, NotifyScreenInfoChanged)(LPVOID object);

	///
	//	使视图无效，浏览器将调用CefRenderHandler :: OnPaint
	//	异步。此方法仅在窗口呈现时使用
	//	禁用。
	///
	AQUAENTRYFULL(void, BrowserHost, Invalidate)(LPVOID object,int status);

	///
	//	将焦点事件发送到浏览器。
	///
	AQUAENTRYFULL(void, BrowserHost, SendFocusEvent)(LPVOID object, bool setFocus);

	///
	//	向浏览器发送捕获丢失事件。
	///
	AQUAENTRYFULL(void, BrowserHost, SendCaptureLostEvent)(LPVOID object);

	///
	//	通知浏览器托管它的窗口即将被移动或移动
	//	调整大小，此方法仅用于Windows和Linux。
	///
	AQUAENTRYFULL(void, BrowserHost, NotifyMoveOrResizeStarted)(LPVOID object);

	///
	//	以每秒帧数（fps）返回最大速率CefRenderHandler ::
	//	OnPaint将被邀请用于无窗口浏览器，实际的fps可能是
	//	如果浏览器无法按请求的速率生成帧，则降低。
	//	最小值为1，最大值为60（默认值为30）
	//	只能在UI线程中调用。
	///
	AQUAENTRYFULL(int, BrowserHost, GetWindowlessFrameRate)(LPVOID object);

	///
	//	设置每秒帧数（fps）的最大速率CefRenderHandler ::
	//	OnPaint将被邀请用于无窗口浏览器，实际的fps可能是
	//	如果浏览器无法按请求的速率生成帧，则降低。
	//	最小值是1，最大值是60（默认30）。也可以是
	//	通过CefBrowserSettings.windowless_frame_rate创建浏览器。
	///
	AQUAENTRYFULL(void, BrowserHost, SetWindowlessFrameRate)(LPVOID object, int frame_rate);

	///
	//	将关键事件发送到浏览器。
	///
	AQUAENTRYFULL(void, BrowserHost, SendKeyEvent)(LPVOID object,LPVOID event);

	///
	//	将鼠标单击事件发送到浏览器。 | x | 和| y | 坐标是视图的左上角。
	///
	AQUAENTRYFULL(void, BrowserHost, SendMouseClickEvent)(LPVOID object, LPVOID event, int type, bool mouseUp, int clickCount);

	///
	//	将鼠标移动事件发送到浏览器。 | x | 和| y | 坐标相对于视图的左上角。
	///
	AQUAENTRYFULL(void, BrowserHost, SendMouseMoveEvent)(LPVOID object, LPVOID event, bool mouseLeave);

	///
	//	将鼠标滚轮事件发送到浏览器。 | x | 和| y | 坐标是
	//	相对于视图的左上角。 | deltaX | 和 | deltaY |
	//	值分别表示X和Y方向上的运动增量。
	//	为了在禁用窗口渲染的情况下滚动内部选择弹出窗口
	//	应该正确实现CefRenderHandler::GetScreenPoint。
	///
	AQUAENTRYFULL(void, BrowserHost, SendMouseWheelEvent)(LPVOID object, LPVOID event, int deltaX, int deltaY);

	///
	//	移动或调整在管理器中的浏览器窗口位置及大小,|parent|不为NULL时,仅调整该窗口下的所有子浏览器窗口
	//	否则将调整所有窗口。
	///
	AQUAENTRYFULL(void, Manager, MoveOrResized)(HWND parent, int x, int y, int width, int height);

	///
	//	设置主显示浏览器
	///
	AQUAENTRYFULL(void, Manager, SetMainHeroine)(HWND parent,HWND child);

	///
	//	查询管理器中与|id|进行关联的浏览器对象,当返回NULL时则意味着找不到其所关联的东西
	///
	AQUAENTRYFULL(LPVOID, Manager, QueryActor)(HWND id);

	///
	//	获取管理器中的浏览器数量
	///
	AQUAENTRYFULL(int, Manager, GetCount)(void);

	///
	//	关闭所有浏览器
	///
	AQUAENTRYFULL(void, Manager, CloseAllBrowser)(void);

	///
	//	获取浏览器所关联的会话管理对象。
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, GetCookieManager)(LPVOID object);

	///
	//	处理JS对话框
	///
	AQUAENTRYFULL(void, JSDialog, Continue)(LPVOID object,bool success, LPCSTR input);

	///
	//	处理文件对话框
	///
	AQUAENTRYFULL(void, FileDialog, Continue)(LPVOID object,int selection,LPVOID file_paths);

	///
	//	处理文件对话框
	///
	AQUAENTRYFULL(void, FileDialog, Cancel)(LPVOID object);


}


#endif