#pragma once
#include <string>

class aqua_convert {
public:
	aqua_convert();
	~aqua_convert();

public:
	std::string to_bytes(const std::wstring &v);
	std::wstring from_bytes(const std::string &v);

};