#include "aqua_browser.h"
#include "utils\aqua_conv.h"
#include "include\cef_browser.h"

using namespace AquaCef;

///
//	返回浏览器主机对象。 此方法只能在浏览器进程中调用。
///
AQUAENTRYFULL(LPVOID, Browser, GetHost)(LPVOID object) {
	LPVOID result = NULL;
	char buf[100];
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefBrowserHost> host = pUnit->GetHost();
		if (host.get()) {
			host->AddRef();
			result = host.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	如果浏览器可以向后导航，则返回true。
///
AQUAENTRYFULL(BOOL, Browser, CanGoBack)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->CanGoBack();
		pUnit->Release();
	}
	return result;
}

///
//	向后导航。
///
AQUAENTRYFULL(void, Browser, GoBack)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->GoBack();
		pUnit->Release();
	}
}

///
//	如果浏览器可以向前导航，则返回true。
///
AQUAENTRYFULL(BOOL, Browser, CanGoForward)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->CanGoForward();
		pUnit->Release();
	}
	return result;
}

///
//	向前导航。
///
AQUAENTRYFULL(void, Browser, GoForward)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->GoForward();
		pUnit->Release();
	}
}

///
//	如果浏览器正在加载，则返回true。
///
AQUAENTRYFULL(BOOL, Browser, IsLoading)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->IsLoading();
		pUnit->Release();
	}
	return result;
}

///
//	重新加载当前页面。
///
AQUAENTRYFULL(void, Browser, Reload)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->Reload();
		pUnit->Release();
	}
}

///
//	重新加载当前页面，忽略任何缓存的数据。
///
AQUAENTRYFULL(void, Browser, ReloadIgnoreCache)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->ReloadIgnoreCache();
		pUnit->Release();
	}
}

///
//	停止加载页面。
///
AQUAENTRYFULL(void, Browser, StopLoad)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->StopLoad();
		pUnit->Release();
	}
}

///
//	返回此浏览器的全局唯一标识符。 该值也用作扩展API的tabId。
///
AQUAENTRYFULL(int, Browser, GetIdentifier)(LPVOID object) {
	int result = 0;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->GetIdentifier();
		pUnit->Release();
	}
	return result;
}

///
//	如果此对象指向与| that |相同的句柄，则返回true 目的。
///
AQUAENTRYFULL(BOOL, Browser, IsSame)(LPVOID object, LPVOID that) {
	BOOL result = FALSE;
	if (object && that) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		CefBrowser *pThat = reinterpret_cast<CefBrowser*>(that);
		pUnit->AddRef();
		pThat->AddRef();
		result = pUnit->IsSame(pThat);
		pUnit->Release();
		pThat->Release();
	}
	return result;
}

///
//	如果窗口是一个弹出窗口，则返回true。
///
AQUAENTRYFULL(BOOL, Browser, IsPopup)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->IsPopup();
		pUnit->Release();
	}
	return result;
}

///
//	如果文档已被加载到浏览器中，则返回true。
///
AQUAENTRYFULL(BOOL, Browser, HasDocument)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->HasDocument();
		pUnit->Release();
	}
	return result;
}

///
//	返回浏览器窗口的主（顶级）框架。
///
AQUAENTRYFULL(LPVOID, Browser, GetMainFrame)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetMainFrame();
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回浏览器窗口的焦点框。
///
AQUAENTRYFULL(LPVOID, Browser, GetFocusedFrame)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFocusedFrame();
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回具有指定标识符的Frame，如果未找到，则返回NULL。
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameFromId)(LPVOID object, int64 identify) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFrame(identify);
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回具有指定名称的Frame，如果未找到，则返回NULL。
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameA)(LPVOID object, LPCSTR name) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		aqua_convert conv;
		auto key = conv.from_bytes(name);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFrame(key);
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回具有指定名称的Frame，如果未找到，则返回NULL。
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameW)(LPVOID object, LPCWSTR name) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFrame(name);
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回当前存在的帧数。
///
AQUAENTRYFULL(int, Browser, GetFrameCount)(LPVOID object) {
	int result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->GetFrameCount();
		pUnit->Release();
	}
	return result;
}

///
//	返回所有现有Frame的标识符。
//	返回Int64数组,访问方法参见"Int64Vector"类别函数集
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameIdentifiers)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		std::vector<int64> *pInt64Vector = new std::vector<int64>;
		pUnit->AddRef();
		pUnit->GetFrameIdentifiers((*pInt64Vector));
		pUnit->Release();
		result = pInt64Vector;
	}
	return result;
}

///
//	返回所有现有Frame的名称。
//	返回字符串数组,访问方法参见"StrVector"类别函数集
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameNames)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		pUnit->AddRef();
		pUnit->GetFrameNames((*pStrVector));
		pUnit->Release();
		result = pStrVector;
	}
	return result;
}

///
//	发送消息到指定的| target_process |。 如果消息已成功发送，则返回true。
///
AQUAENTRYFULL(BOOL, Browser, SendProcessMessageA)(LPVOID object, int target_process, LPCSTR message, char *payload, int length) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		aqua_convert conv;
		auto name = conv.from_bytes(message);
		pUnit->AddRef();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create(name);
		CefRefPtr<CefListValue> argument = msg->GetArgumentList();
		CefRefPtr<CefBinaryValue> binary = CefBinaryValue::Create(payload, length);
		argument->SetSize(1);
		argument->SetBinary(0, binary);
		result = pUnit->SendProcessMessage((CefProcessId)target_process, msg);
		pUnit->Release();
	}
	return result;
}