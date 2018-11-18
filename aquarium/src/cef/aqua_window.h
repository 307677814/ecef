#ifndef AQUA_WINDOW_REFER_H_
#define AQUA_WINDOW_REFER_H_
#include "utils\aqua_utils.h"


/**
  * 表示窗口信息的类。
  * * * * * * * * */

namespace AquaWindow {

	///
	//	返回一个新的窗口对象实例
	///
	AQUAENTRYFULL(LPVOID, Window, Create)(void);

	///
	//	复制一个窗口对象
	///
	AQUAENTRYFULL(LPVOID, Window, Copy)(LPVOID object);

	///
	//	创建浏览器作为子窗口。
	///
	AQUAENTRYFULL(void, Window, SetAsChild)(LPVOID object,HWND parent, int x, int y, int width, int height);

	///
	//	创建浏览器为一个弹出窗口。
	///
	AQUAENTRYFULL(void, Window, SetAsPopupA)(LPVOID object, HWND parent,LPCSTR title);

	///
	//	创建浏览器为一个弹出窗口。
	///
	AQUAENTRYFULL(void, Window, SetAsPopupW)(LPVOID object, HWND parent, LPCWSTR title);

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
	AQUAENTRYFULL(void, Window, SetAsWindowless)(LPVOID object, HWND parent);

	///
	//	更改窗口的样式信息。
	///
	AQUAENTRYFULL(void, Window, ModifyStyle)(LPVOID object,DWORD style,DWORD styleEx);


	///
	//	销毁一个窗口对象
	///
	AQUAENTRYFULL(void, Window, Destoryed)(LPVOID object);
}

#endif