#include "aqua_download.h"
#include "include\cef_download_item.h"
#include "include\cef_download_handler.h"

#include <codecvt>

using namespace AquaCef;

AQUAENTRYFULL(BOOL, Download, IsValid)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->IsValid();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, Download, IsInProgress)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->IsInProgress();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, Download, IsComplete)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->IsComplete();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, Download, IsCanceled)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->IsCanceled();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(__int64, Download, GetCurrentSpeed)(LPVOID object) {
	__int64 result = 0;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->GetCurrentSpeed();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, Download, GetPercentComplete)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->GetPercentComplete();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(__int64, Download, GetTotalBytes)(LPVOID object) {
	__int64 result = 0;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->GetTotalBytes();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(__int64, Download, GetReceivedBytes)(LPVOID object) {
	__int64 result = 0;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->GetReceivedBytes();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, Download, GetStartTime)(LPVOID object, LPVOID time) {
	CefTime tm;
	_cef_time_t *org = (_cef_time_t*)time;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		tm = p->GetStartTime();
		p->Release();
		org->year = tm.year;
		org->month = tm.month;
		org->minute = tm.minute;
		org->hour = tm.hour;
		org->day_of_month = tm.day_of_month;
		org->day_of_week = tm.day_of_week;
		org->second = tm.second;
		org->millisecond = tm.millisecond;
	}
}

AQUAENTRYFULL(void, Download, GetEndTime)(LPVOID object, LPVOID time) {
	CefTime tm;
	_cef_time_t *org = (_cef_time_t*)time;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		tm = p->GetEndTime();
		p->Release();
		org->year = tm.year;
		org->month = tm.month;
		org->minute = tm.minute;
		org->hour = tm.hour;
		org->day_of_month = tm.day_of_month;
		org->day_of_week = tm.day_of_week;
		org->second = tm.second;
		org->millisecond = tm.millisecond;
	}
}

AQUAENTRYFULL(int, Download, GetFullPath)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		CefString path;
		p->AddRef();
		path = p->GetFullPath();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(UINT, Download, GetId)(LPVOID object) {
	UINT result = 0;
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		p->AddRef();
		result = p->GetId();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, Download, GetURL)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		CefString path;
		p->AddRef();
		path = p->GetURL();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, Download, GetOriginalUrl)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		CefString path;
		p->AddRef();
		path = p->GetOriginalUrl();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, Download, GetSuggestedFileName)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		CefString path;
		p->AddRef();
		path = p->GetSuggestedFileName();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, Download, GetContentDisposition)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		CefString path;
		p->AddRef();
		path = p->GetContentDisposition();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, Download, GetMimeType)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItem*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		CefString path;
		p->AddRef();
		path = p->GetMimeType();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(void, DownloadCallback, Continue)(LPVOID object, LPCSTR file_path, bool show_dialog) {
	if (object) {
		auto p = reinterpret_cast<CefBeforeDownloadCallback*>(object);
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		std::wstring path;
		if (file_path != NULL && strlen(file_path) > 0) {
			path = conv.from_bytes(file_path);
		}
		p->AddRef();
		p->Continue(path, show_dialog);
		p->Release();
	}
}

AQUAENTRYFULL(void, DownloadItemCallback, Cancel)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItemCallback*>(object);
		p->AddRef();
		p->Cancel();
		p->Release();
	}
}

AQUAENTRYFULL(void, DownloadItemCallback, Pause)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItemCallback*>(object);
		p->AddRef();
		p->Pause();
		p->Release();
	}
}

AQUAENTRYFULL(void, DownloadItemCallback, Resume)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefDownloadItemCallback*>(object);
		p->AddRef();
		p->Resume();
		p->Release();
	}
}
