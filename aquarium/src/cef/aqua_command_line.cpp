#include "aqua_command_line.h"
#include "utils\aqua_conv.h"
#include "include\cef_command_line.h"

using namespace AquaCef;

///
//	创建一个新的CefCommandLine实例。
///
AQUAENTRY(LPVOID, CreateCommandLine)(void) {
	CefRefPtr<CefCommandLine> object = CefCommandLine::CreateCommandLine();
	object->AddRef();
	return (LPVOID)object.get();
}

///
//	返回单例全局CefCommandLine对象。 返回的对象将是只读的。
///
AQUAENTRY(LPVOID, GetGlobalCommandLine)(void) {
	CefRefPtr<CefCommandLine> object = CefCommandLine::GetGlobalCommandLine();
	object->AddRef();
	return (LPVOID)object.get();
}

///
//	如果此对象有效，则返回true。 如果此函数返回false，则不要调用任何其他方法。
///
AQUAENTRYFULL(BOOL, CommandLine, IsValid)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		BOOL result = FALSE;
		pUnit->AddRef();
		result = pUnit->IsValid();
		pUnit->Release();
		return result;
	}
	return FALSE;
}

///
//	如果此对象的值是只读的，则返回true。 一些API可能会公开只读对象。
///
AQUAENTRYFULL(BOOL, CommandLine, IsReadOnly)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		BOOL result = FALSE;
		pUnit->AddRef();
		result = pUnit->IsReadOnly();
		pUnit->Release();
		return result;
	}
	return FALSE;
}

///
//	返回此对象的可写副本。
///
AQUAENTRYFULL(LPVOID, CommandLine, Copy)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		LPVOID result = NULL;
		pUnit->AddRef();
		CefRefPtr<CefCommandLine> newCopyer = pUnit->Copy();
		newCopyer->AddRef();
		result = newCopyer.get();
		pUnit->Release();
		return result;
	}
	return NULL;
}

///
//	用指定的| argc |初始化命令行 和| argv |值。 第一个参数必须是程序的名称。
//	此方法仅在非Windows平台上受支持。
///
AQUAENTRYFULL(void, CommandLine, InitFromArgv)(LPVOID object, int argc, const char* const* argv) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->InitFromArgv(argc, argv);
		pUnit->Release();
		return ;
	}
	return ;
}

///
//	用通过调用GetCommandLineA（）返回的字符串初始化命令行。 此方法仅在Windows上受支持。
///
AQUAENTRYFULL(void, CommandLine, InitFromStringA)(LPVOID object, LPCSTR command_line) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto cmd = conv.from_bytes(command_line);
		pUnit->InitFromString(cmd);
		pUnit->Release();
	}
}

///
//	用通过调用GetCommandLineA（）返回的字符串初始化命令行。 此方法仅在Windows上受支持。
///
AQUAENTRYFULL(void, CommandLine, InitFromStringW)(LPVOID object, LPCWSTR command_line) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->InitFromString(command_line);
		pUnit->Release();
	}
}

///
//	检索原始命令行字符串作为字符串的向量。
//	argv数组：{program，[（ - | - | /）switch [= value]] *，[ - ]，[argument] *}
///
AQUAENTRYFULL(LPVOID, CommandLine, GetArgv)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		LPVOID result = NULL;
		std::vector<CefString> *pArgvs = new std::vector<CefString>;
		pUnit->AddRef();
		pUnit->GetArgv((*pArgvs));
		pUnit->Release();
		return pArgvs;
	}
	return NULL;
}

///
//	构造并返回表示的命令行字符串。 谨慎使用此方法，因为报价行为不清楚。
//	如果|length|为0,则不会将成员数据填充到|buffer|中。
///
AQUAENTRYFULL(int, CommandLine, GetCommandLineStringA)(LPVOID object, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetCommandLineString();
		auto text = conv.to_bytes(cmd.c_str());
		if (length == 0) {
			result = text.length();
		}
		else {
			memmove(buffer, text.c_str(), text.length());
			result = text.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	构造并返回表示的命令行字符串。 谨慎使用此方法，因为报价行为不清楚。
//	如果|length|为0,则不会将成员数据填充到|buffer|中。
///
AQUAENTRYFULL(int, CommandLine, GetCommandLineStringW)(LPVOID object, LPWSTR buffer, int length) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetCommandLineString();
		if (length == 0) {
			result = cmd.length();
		}
		else {
			memmove(buffer, cmd.c_str(), cmd.length());
			result = cmd.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	获取程序部分的命令行字符串（第一项）。
//	如果|length|为0,则不会将成员数据填充到|buffer|中。
///
AQUAENTRYFULL(int, CommandLine, GetProgramA)(LPVOID object, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetProgram();
		auto text = conv.to_bytes(cmd.c_str());
		if (length == 0) {
			result = text.length();
		}
		else {
			memmove(buffer, text.c_str(), text.length());
			result = text.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	获取程序部分的命令行字符串（第一项）。
//	如果|length|为0,则不会将成员数据填充到|buffer|中。
///
AQUAENTRYFULL(int, CommandLine, GetProgramW)(LPVOID object, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetProgram();
		if (length == 0) {
			result = cmd.length();
		}
		else {
			memmove(buffer, cmd.c_str(), cmd.length());
			result = cmd.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	设置命令行字符串的程序部分（第一项）。
///
AQUAENTRYFULL(void, CommandLine, SetProgramA)(LPVOID object, LPCSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		aqua_convert conv;
		pUnit->AddRef();
		auto cmd = conv.from_bytes(value);
		pUnit->SetProgram(cmd);
		pUnit->Release();
	}
}

///
//	设置命令行字符串的程序部分（第一项）。
///
AQUAENTRYFULL(void, CommandLine, SetProgramW)(LPVOID object, LPCWSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->SetProgram(value);
		pUnit->Release();
	}
}

///
//	如果命令行有开关，则返回true。
///
AQUAENTRYFULL(BOOL, CommandLine, HasSwitches)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		result = pUnit->HasSwitches();
		pUnit->Release();
	}
	return result;
}

///
//	如果命令行包含给定的开关，则返回true。
///
AQUAENTRYFULL(BOOL, CommandLine, HasSwitchA)(LPVOID object,LPCSTR name) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		result = pUnit->HasSwitch(key);
		pUnit->Release();
	}
	return result;
}

///
//	如果命令行包含给定的开关，则返回true。
///
AQUAENTRYFULL(BOOL, CommandLine, HasSwitchW)(LPVOID object, LPCWSTR name) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		result = pUnit->HasSwitch(name);
		pUnit->Release();
	}
	return result;
}

///
//	返回与给定开关关联的值。 如果开关没有值或不存在，则此方法返回空字符串。
//	如果|length|为0,则不会将成员数据填充到|buffer|中。
///
AQUAENTRYFULL(int, CommandLine, GetSwitchValueA)(LPVOID object, LPCSTR name, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		const auto &value = pUnit->GetSwitchValue(key);
		auto text = conv.to_bytes(value.c_str());
		if (length == 0) {
			result = text.length();
		}
		else {
			memmove(buffer, text.c_str(), text.length());
			result = text.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回与给定开关关联的值。 如果开关没有值或不存在，则此方法返回空字符串。
//	如果|length|为0,则不会将成员数据填充到|buffer|中。
///
AQUAENTRYFULL(int, CommandLine, GetSwitchValueW)(LPVOID object, LPCWSTR name, LPWSTR buffer, int length) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &value = pUnit->GetSwitchValue(name);
		if (length == 0) {
			result = value.length();
		}
		else {
			memmove(buffer, value.c_str(), value.length());
			result = value.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	返回开关名称和值的映射。 如果一个开关没有值，则返回一个空字符串。
//	返回字符串字典,访问方法参见"StrMap"类别函数集
///
AQUAENTRYFULL(LPVOID, CommandLine, GetSwitches)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		LPVOID result = NULL;
		std::map<CefString,CefString> *pStrMap = new std::map<CefString, CefString>;
		pUnit->AddRef();
		pUnit->GetSwitches((*pStrMap));
		pUnit->Release();
		return pStrMap;
	}
	return NULL;
}

///
//	将一个开关添加到命令行的末尾。 如果开关没有值传递一个空值字符串。
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchA)(LPVOID object, LPCSTR name) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		pUnit->AppendSwitch(key);
		pUnit->Release();
	}
}

///
//	将一个开关添加到命令行的末尾。 如果开关没有值传递一个空值字符串。
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchW)(LPVOID object, LPCWSTR name) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendSwitch(name);
		pUnit->Release();
	}
}

///
//	将具有指定值的开关添加到命令行的末尾。
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueA)(LPVOID object, LPCSTR name, LPCSTR value) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		auto text = conv.from_bytes(value);
		pUnit->AppendSwitchWithValue(key,text);
		pUnit->Release();
	}
}

///
//	将具有指定值的开关添加到命令行的末尾。
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueW)(LPVOID object, LPCSTR name, LPCSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendSwitchWithValue(name, value);
		pUnit->Release();
	}
}

///
//	如果有剩余的命令行参数，则为真。
///
AQUAENTRYFULL(BOOL, CommandLine, HasArguments)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		result = pUnit->HasArguments();
		pUnit->Release();
	}
	return result;
}

///
//	获取其余的命令行参数。
//	返回字符串数组,访问方法参见"StrVector"类别函数集
///
AQUAENTRYFULL(LPVOID, CommandLine, GetArguments)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		pUnit->AddRef();
		pUnit->GetArguments((*pStrVector));
		pUnit->Release();
		result = pStrVector;
	}
	return result;
}

///
//	在命令行的末尾添加一个参数。
///
AQUAENTRYFULL(void, CommandLine, AppendArgumentA)(LPVOID object, LPCSTR value) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto text = conv.from_bytes(value);
		pUnit->AppendArgument(text);
		pUnit->Release();
	}
}

///
//	在命令行的末尾添加一个参数。
///
AQUAENTRYFULL(void, CommandLine, AppendArgumentW)(LPVOID object, LPCSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendArgument(value);
		pUnit->Release();
	}
}

///
//	在当前命令之前插入一条命令。 通常用于调试器，如“valgrind”或“gdb --args”。
///
AQUAENTRYFULL(void, CommandLine, PrependWrapperA)(LPVOID object, LPCSTR wapper) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto text = conv.from_bytes(wapper);
		pUnit->PrependWrapper(text);
		pUnit->Release();
	}
}

///
//	在当前命令之前插入一条命令。 通常用于调试器，如“valgrind”或“gdb --args”。
///
AQUAENTRYFULL(void, CommandLine, PrependWrapperW)(LPVOID object, LPCSTR wapper) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendArgument(wapper);
		pUnit->Release();
	}
}