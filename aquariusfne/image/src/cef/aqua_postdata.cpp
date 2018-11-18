#include "aqua_postdata.h"
#include "include\cef_request.h"
#include <codecvt>

using namespace AquaCef;

AQUAENTRYFULL(LPVOID, PostData, Create)(void) {
	CefRefPtr<CefPostData> v = CefPostData::Create();
	v->AddRef();
	return v.get();
}

AQUAENTRYFULL(LPVOID, PostData, Copy)(LPVOID object) {
	return NULL;
}

AQUAENTRYFULL(void, PostData, Destory)(LPVOID object) {

}

AQUAENTRYFULL(BOOL, PostData, IsReadOnly)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefPostData*>(object);
		p->AddRef();
		result = p->IsReadOnly();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, PostData, HasExcludedElements)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefPostData*>(object);
		p->AddRef();
		result = p->HasExcludedElements();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, PostData, GetElementCount)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefPostData*>(object);
		p->AddRef();
		result = p->GetElementCount();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, PostData, GetElements)(LPVOID object, LPFN_ELEMENTS_CALLBACK callback, LPVOID params) {
	CefPostData::ElementVector elements;
	if (object) {
		CefPostData::ElementVector elements;
		auto p = reinterpret_cast<CefPostData*>(object);
		p->AddRef();
		p->GetElements(elements);
		p->Release();
		int max = elements.size();
		if (max <= 0) {
			callback(0, 0, NULL, NULL);
			return;
		}
		for (size_t i = 0; i < max; i++)
		{
			const auto &it = elements[i];
			it->AddRef();
			callback(max, i, it.get(),params);
		}
	}
}

AQUAENTRYFULL(BOOL, PostData, RemoveElement)(LPVOID object, LPVOID element) {
	BOOL result = FALSE;
	if (object && element) {
		auto p = reinterpret_cast<CefPostData*>(object);
		auto v = reinterpret_cast<CefPostDataElement*>(element);
		p->AddRef();
		v->AddRef();
		result = p->RemoveElement(v);
		v->Release();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, PostData, AddElement)(LPVOID object, LPVOID element) {
	BOOL result = FALSE;
	if (object && element) {
		auto p = reinterpret_cast<CefPostData*>(object);
		auto v = reinterpret_cast<CefPostDataElement*>(element);
		p->AddRef();
		v->AddRef();
		result = p->AddElement(v);
		v->Release();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, PostData, RemoveElements)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefPostData*>(object);
		p->AddRef();
		p->RemoveElements();
		p->Release();
	}
}

AQUAENTRYFULL(LPVOID, PostDataElement, Create)(void) {
	CefRefPtr<CefPostDataElement> v = CefPostDataElement::Create();
	v->AddRef();
	return v.get();
}

AQUAENTRYFULL(LPVOID, PostDataElement, Copy)(LPVOID object) {
	return NULL;
}

AQUAENTRYFULL(void, PostDataElement, Destory)(LPVOID object) {

}

AQUAENTRYFULL(BOOL, PostDataElement, IsReadOnly)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		result = p->IsReadOnly();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, PostDataElement, SetToEmpty)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		p->SetToEmpty();
		p->Release();
	}
}

AQUAENTRYFULL(void, PostDataElement, SetToFile)(LPVOID object, LPCSTR fileName) {
	if (object) {
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		p->SetToFile(conv.from_bytes(fileName));
		p->Release();
	}
}

AQUAENTRYFULL(void, PostDataElement, SetToBytes)(LPVOID object, size_t size, void *data) {
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		p->SetToBytes(size,data);
		p->Release();
	}
}

AQUAENTRYFULL(int, PostDataElement, GetType)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		result = (int)p->GetType();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, PostDataElement, GetFile)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		CefString fileName = p->GetFile();
		p->Release();
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto v = conv.to_bytes(fileName.c_str());
		if (len == 0) {
			return v.length();
		}
		else {
			memmove(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return result;
}

AQUAENTRYFULL(int, PostDataElement, GetBytes)(LPVOID object, size_t size, void *data) {
	size_t v;
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		v = p->GetBytes(size, data);
		p->Release();
	}
	return v;
}

AQUAENTRYFULL(int, PostDataElement, GetBytesCount)(LPVOID object) {
	int result = 0;
	if (object) {
		auto p = reinterpret_cast<CefPostDataElement*>(object);
		p->AddRef();
		result = p->GetBytesCount();
		p->Release();
	}
	return result;
}