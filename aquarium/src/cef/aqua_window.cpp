#include "aqua_window.h"
#include "utils\aqua_conv.h"
#include "include\cef_browser.h"

///
//	返回一个新的窗口对象实例
///
AQUAENTRYFULL(LPVOID, Window, Create)(void) {
	return new CefWindowInfo;
}

///
//	创建浏览器作为子窗口。
///
AQUAENTRYFULL(void, Window, SetAsChild)(LPVOID object, HWND parent, int x, int y, int width, int height) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		pWindow->x = x;
		pWindow->y = y;
		pWindow->width = width;
		pWindow->height = height;
		pWindow->style = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_TABSTOP | WS_VISIBLE;
		pWindow->parent_window = parent;
	}
}

///
//	创建浏览器为一个弹出窗口。
///
AQUAENTRYFULL(void, Window, SetAsPopupA)(LPVOID object, HWND parent, LPCSTR title) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		aqua_convert conv;
		auto windowName = conv.from_bytes(title);
		pWindow->SetAsPopup(parent, windowName);
	}
}

///
//	创建浏览器为一个弹出窗口。
///
AQUAENTRYFULL(void, Window, SetAsPopupW)(LPVOID object, HWND parent, LPCWSTR title) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		pWindow->SetAsPopup(parent, title);
	}
}

///
//	使用无窗口（离屏）渲染创建浏览器。 没有窗户
//	将为浏览器创建，并且所有的渲染都将通过
//	CefRenderHandler接口。 |父| | 价值将被用于识别
//	监视信息并充当对话框，上下文菜单的父窗口，
//	如果| parent | 没有提供，那么主屏幕显示器将被使用
//	并且需要父窗口的某些功能可能无法运行
//	正确。 为了创建无窗口浏览器，
//	CefSettings.windowless_rendering_enabled值必须设置为true。
//	透明绘画默认启用，但可以通过设置禁用
//	CefBrowserSettings.background_color为不透明值。
///
AQUAENTRYFULL(void, Window, SetAsWindowless)(LPVOID object, HWND parent) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
#ifdef _AQUA_CEF2623_ADAPTER
		pWindow->SetAsWindowless(parent,true);
#else
		pWindow->SetAsWindowless(parent);
#endif
	}
}

///
//	更改窗口的样式信息。
///
AQUAENTRYFULL(void, Window, ModifyStyle)(LPVOID object, DWORD style, DWORD styleEx) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		pWindow->style = style;
		pWindow->ex_style = styleEx;
	}
}

///
//	销毁一个窗口对象
///
AQUAENTRYFULL(void, Window, Destoryed)(LPVOID object) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		delete pWindow;
	}
}

///
//	复制一个窗口对象
///
AQUAENTRYFULL(LPVOID, Window, Copy)(LPVOID object) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		CefWindowInfo *pRetVal = new CefWindowInfo(*pWindow);
		return pRetVal;
	}
	return NULL;
}