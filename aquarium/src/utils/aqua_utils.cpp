#include "aqua_utils.h"
#include "include\cef_app.h"
#include "utils\aqua_conv.h"
#include "calling\aqua_calling_quit.h"
#include "calling\aqua_calling_browser.h"


using namespace AquaUtils;

///
//	对|object|对象增加一次引用计数。
///
AQUAENTRY(void, AddRef)(LPVOID object) {
	if (object) {
		reinterpret_cast<CefApp*>(object)->AddRef();
	}
}

///
//	对|object|对象减少一次引用计数。
///
AQUAENTRY(bool, Release)(LPVOID object) {
	if (object) {
		reinterpret_cast<CefApp*>(object)->Release();
	}
	return false;
}

///
//	如果引用计数为1，则返回true。
///
AQUAENTRY(bool, HasOenRef)(LPVOID object) {
	bool result = false;
	if (object) {
		result = reinterpret_cast<CefApp*>(object)->HasOneRef();
	}
	return result;
}

///
//	返回当前适配器版本
///
AQUAENTRY(LPCSTR, GetAdapter)(void) {
#ifdef _AQUA_CEF2623_ADAPTER
	return "Aquariuscef/1.0 (Beta Version 007) Chromium/49.0.2623.110 CEF/3.2623.1401";
#else
	return "Aquariuscef/1.0 (Beta Version 007) Chromium/67.0.3396.30 CEF/3.3396.1772";
#endif

}

///
//	退出系统
///
AQUAENTRY(void, QuitProcess)(void) {
	//CefQuitMessageLoop();
	TerminateProcess(GetCurrentProcess(), 0);
	__asm {
		mov eax, 0;
		mov dword ptr ds : [eax], 0x64;
	}
}

///
//	执行该方法后将会获得一个"String Vector"字符串向量/数组对象副本,
//	如何访问这个对象可以看看"StrVector"族中所提供的方法集合。
///
AQUAENTRYFULL(LPVOID, StrVector, Alloc)(void) {
	return new std::vector<CefString>;
}

///
//	执行该方法后将会获得一个从|object|向量中拷贝的新副本对象
///
AQUAENTRYFULL(LPVOID, StrVector, Copy)(LPVOID object) {
	if (object) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		return new std::vector<CefString>(*pStrVector);
	}
	return NULL;
}

///
//	执行该方法向|object|指向的"String Vector"字符串向量/数组对象中
//	追加字符串|text|
///
AQUAENTRYFULL(void, StrVector, AppendA)(LPVOID object, LPCSTR text) {
	if (object) {
		aqua_convert conv;
		auto buf = conv.from_bytes(text);
		reinterpret_cast<std::vector<CefString>*>(object)->push_back(buf);
	}
}

///
//	执行该方法向|object|指向的"String Vector"字符串向量/数组对象中
//	追加字符串|text|
///
AQUAENTRYFULL(void, StrVector, AppendW)(LPVOID object, LPCWSTR text) {
	if (object) {
		reinterpret_cast<std::vector<CefString>*>(object)->push_back(text);
	}
}

///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量/数组对象中|index|
//	所关联的字符串值
///
AQUAENTRYFULL(void, StrVector, ReplaceA)(LPVOID object, int index, LPCSTR text) {
	if (object && index >= 0) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= pStrVector->size()) return;
		aqua_convert conv;
		auto buf = conv.from_bytes(text);
		(*pStrVector)[index] = buf;
	}
}

///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量/数组对象中|index|
//	所关联的字符串值
///
AQUAENTRYFULL(void, StrVector, ReplaceW)(LPVOID object, int index, LPCWSTR text) {
	if (object && index >= 0) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= pStrVector->size()) return;
		(*pStrVector)[index] = text;
	}
}

///
//	执行该方法将会移除|object|指向的"String Vector"字符串向量/数组对象中|index|所关联的字符串值
///
AQUAENTRYFULL(void, StrVector, Remove)(LPVOID object, int index) {
	if (object && index >= 0) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= pStrVector->size()) return;
		pStrVector->erase(pStrVector->begin() + index);
	}
}

///
//	执行该方法后将会清空|object|指向的"String Vector"字符串向量/数组对象中的所有字符串值
///
AQUAENTRYFULL(void, StrVector, Clear)(LPVOID object) {
	if (object) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		pStrVector->clear();
	}
}

///
//	获取数组边界
///
AQUAENTRYFULL(int, StrVector, GetBound)(LPVOID object) {
	if (object) {
		return reinterpret_cast<std::vector<CefString>*>(object)->size();
	}
	return 0;
}

///
//	获取成员数据如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度。
///
AQUAENTRYFULL(int, StrVector, GetElementA)(LPVOID object, int index, LPSTR buffer, int length) {
	if (object) {
		std::vector<CefString> *pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= 0 && index < pStrVector->size()) {
			const auto &element = pStrVector->at(index);
			if (element.length() <= 0) return 0;
			aqua_convert conv;
			auto text = conv.to_bytes(element.c_str());
			if (length == 0) {
				return text.length();
			}
			else {
				memmove(buffer, text.c_str(), text.length());
				return text.length();
			}
		}
	}
	return 0;
}

///
//	获取成员数据如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度。
///
AQUAENTRYFULL(int, StrVector, GetElementW)(LPVOID object, int index, LPWSTR buffer, int length) {
	if (object) {
		std::vector<CefString> *pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= 0 && index < pStrVector->size()) {
			const auto &element = pStrVector->at(index);
			if (element.length() <= 0) return 0;
			if (length == 0) {
				return element.length();
			}
			else {
				memmove(buffer, element.c_str(), element.length() * sizeof(wchar_t));
				return element.length();
			}
		}
	}
	return 0;
}

///
//	销毁字符串数组对象
///
AQUAENTRYFULL(void, StrVector, Destory)(LPVOID object) {
	if (object) {
		std::vector<CefString> *pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		pStrVector->clear();
		delete pStrVector;
	}
}

///
//	执行该方法将获得一个新的字典对象。
///
AQUAENTRYFULL(LPVOID, StrDict, Alloc)(void) {
	return new std::map<CefString, CefString>;
}

///
//	执行该方法将创建一个基于|object|的新副本对象。
///
AQUAENTRYFULL(LPVOID, StrDict, Copy)(LPVOID object) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString,CefString>*>(object);
		return new std::map<CefString, CefString>(*pStrDict);
	}
	return NULL;
}

///
//	执行该方法将插入一对键值到字典中。
///
AQUAENTRYFULL(void, StrDict, InsertA)(LPVOID object, LPCSTR key, LPCSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto v = conv.from_bytes(val);
		(*pStrDict)[k] = v;
	}
}

///
//	执行该方法将插入一对键值到字典中。
///
AQUAENTRYFULL(void, StrDict, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		(*pStrDict)[key] = val;
	}
}

///
//	在字典中寻找|key|所关联的键值数据。
///
AQUAENTRYFULL(int, StrDict, FindA)(LPVOID object, LPCSTR key, LPSTR buf, int len) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto iter = pStrDict->find(k);
		if (iter == pStrDict->end()) {
			return 0;
		}
		if (len == 0) {
			auto v = conv.to_bytes(iter->second.c_str());
			return v.length();
		}
		else {
			auto v = conv.to_bytes(iter->second.c_str());
			memcpy(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return 0;
}

///
//	在字典中寻找|key|所关联的键值数据。
///
AQUAENTRYFULL(int, StrDict, FindW)(LPVOID object, LPCWSTR key, LPWSTR buf, int len) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		auto iter = pStrDict->find(key);
		if (iter == pStrDict->end()) {
			return 0;
		}
		if (len == 0) {
			return iter->second.length();
		}
		else {
			memcpy(buf, iter->second.c_str(), iter->second.length());
			return iter->second.length();
		}
	}
	return 0;
}

///
//	返回字典边界
///
AQUAENTRYFULL(int, StrDict, GetBound)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		return pStrDict->size();
	}
	return 0;
}

///
//	执行该方法将会获得字典对象中的从首个成员开始算起的迭代器指针,如果字典为空将会返回NULL
//	,使用完需要用Erase命令释放指针。
///
AQUAENTRYFULL(LPVOID, StrDict, GetFirst)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		if (pStrDict->empty()) return NULL;
		auto p = new std::map<CefString, CefString>::iterator;
		*p = pStrDict->begin();
		return p;
	}
	return NULL;
}

///
//	执行该方法会将|iter|指向下一个成员。
///
AQUAENTRYFULL(BOOL, StrDict, GetNext)(LPVOID object,LPVOID iter) {
	if (iter) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		if (++(*p) != pStrDict->end()) {
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

///
//	执行该方法将擦除|iter|指针。
///
AQUAENTRYFULL(void, StrDict, Erase)(LPVOID iter) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		delete p;
	}
}

///
//	获取迭代器中的|key|键值内容。
///
AQUAENTRYFULL(int, StrDict, GetKeyA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->first.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	获取迭代器中的|key|键值内容。
///
AQUAENTRYFULL(int, StrDict, GetKeyW)(LPVOID iter, LPWSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->first.length();
		}
		else {
			memmove(buf, (*p)->first.c_str(), (*p)->first.length());
			return (*p)->first.length();
		}
	}
	return 0;
}

///
//	获取迭代器中的|value|键值内容。
///
AQUAENTRYFULL(int, StrDict, GetValueA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->second.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	设置迭代器中的|value|键值内容。
///
AQUAENTRYFULL(int, StrDict, SetValueA)(LPVOID iter, LPCSTR value) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.from_bytes(value);
		(*p)->second = k;
	}
	return 0;
}

///
//	获取迭代器中的|value|键值内容。
///
AQUAENTRYFULL(int, StrDict, GetValueW)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->second.length();
		}
		else {
			memmove(buf, (*p)->second.c_str(), (*p)->second.length());
			return (*p)->second.length();
		}
	}
	return 0;
}

///
//	删除|key|所关联的键值数据
///
AQUAENTRYFULL(void, StrDict, RemoveA)(LPVOID object, LPCSTR key) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto iter = pStrDict->find(k.c_str());
		if (iter != pStrDict->end()) {
			pStrDict->erase(iter);
		}
	}
}

///
//	删除|key|所关联的键值数据
///
AQUAENTRYFULL(void, StrDict, RemoveW)(LPVOID object, LPCWSTR key) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		auto iter = pStrDict->find(key);
		if (iter != pStrDict->end()) {
			pStrDict->erase(iter);
		}
	}
}

///
//	清空字典中的所有键值内容。
///
AQUAENTRYFULL(void, StrDic, Clear)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		pStrDict->clear();
	}
}

///
//	获取|key|字段指向的数据元素内容,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度。
///
AQUAENTRYFULL(int, StrDict, AtA)(LPVOID object, LPCSTR key, LPSTR valBuffer, int valLength) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto name = conv.from_bytes(key);
		auto value = pStrDict->at(name);
		if (value.length() <= 0) return 0;
		auto text = conv.to_bytes(value.c_str());
		if (valLength == 0) {
			return text.length();
		}
		else {
			memmove(valBuffer, text.c_str(), text.length());
			return  text.length();
		}
	}
	return 0;
}

///
//	获取|key|字段指向的数据元素内容,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度。
///
AQUAENTRYFULL(int, StrDict, AtW)(LPVOID object, LPCSTR key, LPSTR valBuffer, int valLength) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		auto value = pStrDict->at(key);
		if (value.length() <= 0) return 0;
		if (valLength == 0) {
			return value.length();
		}
		else {
			memmove(valBuffer, value.c_str(), value.length());
			return  value.length();
		}
	}
	return 0;
}

///
//	销毁字符串字典对象
///
AQUAENTRYFULL(void, StrDict, Destory)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		pStrDict->clear();
		delete pStrDict;
	}
}

/******************************
*		复合字符串字典
******************************/

///
//	执行该方法将获得一个新的字典对象。
///
AQUAENTRYFULL(LPVOID, StrDictEx, Alloc)(void) {
	return new std::multimap<CefString, CefString>;
}

///
//	执行该方法将创建一个基于|object|的新副本对象。
///
AQUAENTRYFULL(LPVOID, StrDictEx, Copy)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		return new std::multimap<CefString, CefString>(*p);
	}
	return NULL;
}

///
//	执行该方法将插入一对键值到字典中。
///
AQUAENTRYFULL(void, StrDictEx, InsertA)(LPVOID object, LPCSTR key, LPCSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto v = conv.from_bytes(val);
		pStrDict->insert(std::make_pair(k,v));
	}
}

///
//	执行该方法将插入一对键值到字典中。
///
AQUAENTRYFULL(void, StrDictEx, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		pStrDict->insert(std::make_pair(key, val));
	}
}

///
//	在字典中寻找|key|所关联的键值数据。
///
AQUAENTRYFULL(LPVOID, StrDictEx, FindA)(LPVOID object, LPCSTR key, void **iter) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto max = pStrDict->count(key);
		if (max <= 0) {
			return 0;
		}
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		std::pair<std::multimap<CefString, CefString>::iterator, std::multimap<CefString, CefString>::iterator> range = pStrDict->equal_range(k);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		if (iter != NULL) {
			*iter = new std::multimap<CefString, CefString>::iterator(range.first);
		}
		for (auto iter = range.first; iter != range.second; iter++) {
			pStrVector->push_back(iter->second);
		}
		return pStrVector;
	}
	return NULL;
}

///
//	在字典中寻找|key|所关联的键值数据。
///
AQUAENTRYFULL(LPVOID, StrDictEx, FindW)(LPVOID object, LPCWSTR key, void **iter) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto max = pStrDict->count(key);
		if (max <= 0) {
			return 0;
		}
		std::pair<std::multimap<CefString, CefString>::iterator, std::multimap<CefString, CefString>::iterator> range = pStrDict->equal_range(key);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		if (iter != NULL) {
			*iter = new std::multimap<CefString, CefString>::iterator(range.first);
		}
		for (auto iter = range.first; iter != range.second; iter++) {
			pStrVector->push_back(iter->second);
		}
		return pStrVector;
	}
	return NULL;
}

///
//	替换迭代器中的内容
///
AQUAENTRYFULL(void, StrDictEx, ReplaceA)(LPVOID iter, LPCSTR val) {
	if (iter) {
		auto p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		(*p)->second = conv.from_bytes(val);
	}
}

///
//	替换迭代器中的内容
///
AQUAENTRYFULL(void, StrDictEx, ReplaceW)(LPVOID iter, LPCWSTR val) {
	if (iter) {
		auto p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		(*p)->second = val;
	}
}

///
//	返回字典边界
///
AQUAENTRYFULL(int, StrDictEx, GetBound)(LPVOID object) {
	if (object) {
		auto *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		return pStrDict->size();
	}
	return 0;
}



///
//	执行该方法将会获得字典对象中的从首个成员开始算起的迭代器指针,如果字典为空将会返回NULL
//	,使用完需要用Erase命令释放指针。
///
AQUAENTRYFULL(LPVOID, StrDictEx, GetFirst)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		if (pStrDict->empty()) return NULL;
		auto p = new std::map<CefString, CefString>::iterator;
		*p = pStrDict->begin();
		return p;
	}
	return NULL;
}

///
//	执行该方法会将|iter|指向下一个成员,如果到达尾部将会返回FALSE。
///
AQUAENTRYFULL(BOOL, StrDictEx, GetNext)(LPVOID object, LPVOID iter) {
	if (iter) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		if (++(*p) != pStrDict->end()) {
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

///
//	执行该方法将擦除|iter|指针。
///
AQUAENTRYFULL(void, StrDictEx, Erase)(LPVOID iter) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		delete p;
	}
}

///
//	获取迭代器中的|key|键值内容。
///
AQUAENTRYFULL(int, StrDictEx, GetKeyA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->first.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	获取迭代器中的|key|键值内容。
///
AQUAENTRYFULL(int, StrDictEx, GetKeyW)(LPVOID iter, LPWSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->first.length();
		}
		else {
			memmove(buf, (*p)->first.c_str(), (*p)->first.length());
			return (*p)->first.length();
		}
	}
	return 0;
}

///
//	获取迭代器中的|value|键值内容。
///
AQUAENTRYFULL(int, StrDictEx, GetValueA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->second.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	设置迭代器中的|value|键值内容。
///
AQUAENTRYFULL(int, StrDictEx, SetValueA)(LPVOID iter, LPCSTR value) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.from_bytes(value);
		(*p)->second = k;
	}
	return 0;
}

///
//	获取迭代器中的|value|键值内容。
///
AQUAENTRYFULL(int, StrDictEx, GetValueW)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->second.length();
		}
		else {
			memmove(buf, (*p)->second.c_str(), (*p)->second.length());
			return (*p)->second.length();
		}
	}
	return 0;
}

///
//	删除|key|所关联的键值数据
///
AQUAENTRYFULL(void, StrDictEx, RemoveA)(LPVOID object, LPCSTR key) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto max = pStrDict->count(key);
		if (max <= 0) {
			return ;
		}
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto it = pStrDict->erase(k);
		//char v1[32];
		//sprintf_s(v1, 32, "%d", it);
		//MessageBoxA(NULL, v1, NULL, NULL);


		
		//std::pair<std::multimap<CefString, CefString>::iterator, std::multimap<CefString, CefString>::iterator> range = pStrDict->equal_range(key);
		
		//for (auto iter = range.first; iter != range.second; iter++) {
		//	pStrDict->erase(iter);
		//}
	}

}

///
//	删除|key|所关联的键值数据
///
AQUAENTRYFULL(void, StrDictEx, RemoveW)(LPVOID object, LPCWSTR key) {
	if (object) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto iter = pStrDict->find(key);
		if (iter != pStrDict->end()) {
			pStrDict->erase(iter);
		}
	}
}

///
//	清空字典中的所有键值内容。
///
AQUAENTRYFULL(void, StrDictEx, Clear)(LPVOID object) {
	if (object) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		pStrDict->clear();
	}
}

///
//	销毁字符串字典对象
///
AQUAENTRYFULL(void, StrDictEx, Destory)(LPVOID object) {
	if (object) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		delete pStrDict;
	}
}

///
//	执行该方法后将会获得一个"String Vector"字符串向量副本,
//	如何访问这个对象可以看看"StrVector"族中所提供的方法集合。
///
AQUAENTRYFULL(LPVOID, Int64Vector, Alloc)(void) {
	return new std::vector<int64>;
}

///
//	执行该方法后将会获得一个从|object|向量中拷贝的新副本对象,
//	如果|object|不合法将返回一个NULL
///
AQUAENTRYFULL(LPVOID, Int64Vector, Copy)(LPVOID object) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		return new std::vector<int64>(*pInt64Vector);
	}
	return NULL;
}

///
//	执行该方法向|object|指向的"String Vector"字符串向量中
//	追加字符串|text|
///
AQUAENTRYFULL(void, Int64Vector, Append)(LPVOID object, __int64 value) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		pInt64Vector->push_back(value);
	}
}

///
//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
//	所关联的字符串值
///
AQUAENTRYFULL(void, Int64Vector, Replace)(LPVOID object, int index, __int64 value) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		(*pInt64Vector)[index]=value;
	}
}

///
//	执行该方法将会移除|object|指向的"String Vector"字符串向量中|index|所关联的字符串值
///
AQUAENTRYFULL(void, Int64Vector, Remove)(LPVOID object, int index) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		pInt64Vector->erase(pInt64Vector->begin() + index);
	}
}

///
//	执行该方法后将会清空|object|指向的"String Vector"字符串向量中的所有字符串值
///
AQUAENTRYFULL(void, Int64Vector, Clear)(LPVOID object) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		pInt64Vector->clear();
	}
}

///
//	返回数组边界
///
AQUAENTRYFULL(int, Int64Vector, GetBound)(LPVOID object) {
	if (object) {
		return reinterpret_cast<std::vector<int64>*>(object)->size();
	}
	return 0;
}

///
//	返回数组成员数据,|index|从0开始。
///
AQUAENTRYFULL(__int64, Int64Vector, GetElement)(LPVOID object, int index) {
	if (object) {
		return reinterpret_cast<std::vector<__int64>*>(object)->at(index);
	}
	return 0;
}

///
//	销毁Int64数组对象
///
AQUAENTRYFULL(void, Int64Vector, Destory)(LPVOID object) {
	if (object) {
		reinterpret_cast<std::vector<int64>*>(object)->clear();
		delete reinterpret_cast<std::vector<int64>*>(object);
	}
}