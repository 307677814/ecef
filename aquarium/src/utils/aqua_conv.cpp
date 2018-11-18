#include "aqua_conv.h"
#include <Windows.h>

aqua_convert::aqua_convert() {

}

aqua_convert::~aqua_convert() {

}

std::string aqua_convert::to_bytes(const std::wstring &v) {
	int length = WideCharToMultiByte(CP_ACP, NULL, v.c_str(), v.length(), NULL, NULL, NULL, NULL);
	char *buf = new char[length + 1];
	WideCharToMultiByte(CP_ACP, NULL, v.c_str(), v.length(), buf, length, NULL, NULL);
	buf[length] = 0;
	std::string retval(buf);
	delete[]buf;
	return retval;
}

std::wstring aqua_convert::from_bytes(const std::string &v) {
	int length = MultiByteToWideChar(CP_ACP, NULL, v.c_str(), v.length(), NULL, NULL);
	wchar_t *buf = new wchar_t[length + 1];
	MultiByteToWideChar(CP_ACP, NULL, v.c_str(), v.length(), buf, length);
	buf[length] = 0;
	std::wstring retval(buf);
	delete[]buf;
	return retval;
}