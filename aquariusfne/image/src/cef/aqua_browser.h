#ifndef AQUA_BROWSER_REFER_H_
#define AQUA_BROWSER_REFER_H_
#include "utils\aqua_utils.h"

/**
  * 用于表示浏览器窗口的类。 在浏览器进程中使用时
  * 除非另有说明，否则可以在任何线程上调用此类的方法
  * 在评论中指出。 在渲染过程中使用的方法
  * 这个类只能在主线程中调用。
  * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	返回浏览器主机对象。 此方法只能在浏览器进程中调用。
	///
	AQUAENTRYFULL(LPVOID, Browser, GetHost)(LPVOID object);

	///
	//	如果浏览器可以向后导航，则返回true。
	///
	AQUAENTRYFULL(BOOL, Browser, CanGoBack)(LPVOID object);

	///
	//	向后导航。
	///
	AQUAENTRYFULL(void, Browser, GoBack)(LPVOID object);

	///
	//	如果浏览器可以向前导航，则返回true。
	///
	AQUAENTRYFULL(BOOL, Browser, CanGoForward)(LPVOID object);

	///
	//	向前导航。
	///
	AQUAENTRYFULL(void, Browser, GoForward)(LPVOID object);

	///
	//	如果浏览器正在加载，则返回true。
	///
	AQUAENTRYFULL(BOOL, Browser, IsLoading)(LPVOID object);

	///
	//	重新加载当前页面。
	///
	AQUAENTRYFULL(void, Browser, Reload)(LPVOID object);

	///
	//	重新加载当前页面，忽略任何缓存的数据。
	///
	AQUAENTRYFULL(void, Browser, ReloadIgnoreCache)(LPVOID object);

	///
	//	停止加载页面。
	///
	AQUAENTRYFULL(void, Browser, StopLoad)(LPVOID object);

	///
	//	返回此浏览器的全局唯一标识符。 该值也用作扩展API的tabId。
	///
	AQUAENTRYFULL(int, Browser, GetIdentifier)(LPVOID object);

	///
	//	如果此对象指向与| that |相同的句柄，则返回true 目的。
	///
	AQUAENTRYFULL(BOOL, Browser, IsSame)(LPVOID object,LPVOID that);

	///
	//	如果窗口是一个弹出窗口，则返回true。
	///
	AQUAENTRYFULL(BOOL, Browser, IsPopup)(LPVOID object);

	///
	//	如果文档已被加载到浏览器中，则返回true。
	///
	AQUAENTRYFULL(BOOL, Browser, HasDocument)(LPVOID object);

	///
	//	返回浏览器窗口的主（顶级）框架。
	///
	AQUAENTRYFULL(LPVOID, Browser, GetMainFrame)(LPVOID object);

	///
	//	返回浏览器窗口的焦点框。
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFocusedFrame)(LPVOID object);

	///
	//	返回具有指定标识符的Frame，如果未找到，则返回NULL。
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameFromId)(LPVOID object,__int64 identify);

	///
	//	返回具有指定名称的Frame，如果未找到，则返回NULL。
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameA)(LPVOID object, LPCSTR name);

	///
	//	返回具有指定名称的Frame，如果未找到，则返回NULL。
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameW)(LPVOID object, LPCWSTR name);

	///
	//	返回当前存在的帧数。
	///
	AQUAENTRYFULL(int, Browser, GetFrameCount)(LPVOID object);

	///
	//	返回所有现有Frame的标识符。
	//	返回Int64数组,访问方法参见"Int64Vector"类别函数集
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameIdentifiers)(LPVOID object);

	///
	//	返回所有现有Frame的名称。
	//	返回字符串数组,访问方法参见"StrVector"类别函数集
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameNames)(LPVOID object);

	///
	//	发送消息到指定的| target_process |。 如果消息已成功发送，则返回true。
	///
	AQUAENTRYFULL(BOOL, Browser, SendProcessMessageA)(LPVOID object, int target_process,LPCSTR message,char *payload,int length);

}


#endif