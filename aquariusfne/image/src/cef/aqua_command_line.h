#ifndef AQUA_COMMAND_LINE_REFER_H_
#define AQUA_COMMAND_LINE_REFER_H_
#include "utils\aqua_utils.h"

/**
  * 用于创建和/或解析命令行参数的类。 与...的争论
  * ' - '，' - '，在Windows上，'/'前缀被视为交换机。开关
  * 将始终在没有切换前缀的任何参数之前。 开关可以
  * 可选地具有使用'='分隔符指定的值（例如，
  * “-switch = value”）。 “ - ”的参数将终止所有的交换机解析
  * 随后的令牌，不管前缀，被解释为非开关
  * 参数。 交换机名称被视为不区分大小写。 这个班可以
  * 在调用CefInitialize（）之前使用。
  * * * * * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	创建一个新的CefCommandLine实例。
	///
	AQUAENTRY(LPVOID, CreateCommandLine)(void);

	///
	//	返回单例全局CefCommandLine对象。 返回的对象将是只读的。
	///
	AQUAENTRY(LPVOID, GetGlobalCommandLine)(void);

	///
	//	如果此对象有效，则返回true。 如果此函数返回false，则不要调用任何其他方法。
	///
	AQUAENTRYFULL(BOOL, CommandLine, IsValid)(LPVOID object);

	///
	//	如果此对象的值是只读的，则返回true。 一些API可能会公开只读对象。
	///
	AQUAENTRYFULL(BOOL, CommandLine, IsReadOnly)(LPVOID object);

	///
	//	返回此对象的可写副本。
	///
	AQUAENTRYFULL(LPVOID, CommandLine, Copy)(LPVOID object);

	///
	//	用指定的| argc |初始化命令行 和| argv |值。 第一个参数必须是程序的名称。
	//	此方法仅在非Windows平台上受支持。
	///
	AQUAENTRYFULL(void, CommandLine, InitFromArgv)(LPVOID object,int argc, const char* const* argv);

	///
	//	用通过调用GetCommandLineA（）返回的字符串初始化命令行。 此方法仅在Windows上受支持。
	///
	AQUAENTRYFULL(void, CommandLine, InitFromStringA)(LPVOID object, LPCSTR command_line);

	///
	//	用通过调用GetCommandLineA（）返回的字符串初始化命令行。 此方法仅在Windows上受支持。
	///
	AQUAENTRYFULL(void, CommandLine, InitFromStringW)(LPVOID object, LPCWSTR command_line);

	///
	//	重置命令行开关和参数，但保持程序组件不变。
	///
	AQUAENTRYFULL(void, CommandLine, Reset)(LPVOID object);

	///
	//	检索原始命令行字符串作为字符串的向量。
	//	argv数组：{program，[（ - | - | /）switch [= value]] *，[ - ]，[argument] *}
	//	返回字符串数组,访问方法参见"StrVector"类别函数集
	///
	AQUAENTRYFULL(LPVOID, CommandLine, GetArgv)(LPVOID object);

	///
	//	构造并返回表示的命令行字符串。 谨慎使用此方法，因为报价行为不清楚。
	//	如果|length|为0,则不会将成员数据填充到|buffer|中。
	///
	AQUAENTRYFULL(int, CommandLine, GetCommandLineStringA)(LPVOID object,LPSTR buffer,int length);

	///
	//	构造并返回表示的命令行字符串。 谨慎使用此方法，因为报价行为不清楚。
	//	如果|length|为0,则不会将成员数据填充到|buffer|中。
	///
	AQUAENTRYFULL(int, CommandLine, GetCommandLineStringW)(LPVOID object, LPWSTR buffer, int length);

	///
	//	获取程序部分的命令行字符串（第一项）。
	//	如果|length|为0,则不会将成员数据填充到|buffer|中。
	///
	AQUAENTRYFULL(int, CommandLine, GetProgramA)(LPVOID object, LPSTR buffer, int length);

	///
	//	获取程序部分的命令行字符串（第一项）。
	//	如果|length|为0,则不会将成员数据填充到|buffer|中。
	///
	AQUAENTRYFULL(int, CommandLine, GetProgramW)(LPVOID object, LPSTR buffer, int length);

	///
	//	设置命令行字符串的程序部分（第一项）。
	///
	AQUAENTRYFULL(void, CommandLine, SetProgramA)(LPVOID object,LPCSTR value);

	///
	//	设置命令行字符串的程序部分（第一项）。
	///
	AQUAENTRYFULL(void, CommandLine, SetProgramW)(LPVOID object, LPCWSTR value);

	///
	//	如果命令行有开关，则返回true。
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasSwitches)(LPVOID object);

	///
	//	如果命令行包含给定的开关，则返回true。
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasSwitchA)(LPVOID object,LPCSTR name);

	///
	//	如果命令行包含给定的开关，则返回true。
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasSwitchW)(LPVOID object, LPCWSTR name);

	///
	//	返回与给定开关关联的值。 如果开关没有值或不存在，则此方法返回空字符串。
	//	如果|length|为0,则不会将成员数据填充到|buffer|中。
	///
	AQUAENTRYFULL(int, CommandLine, GetSwitchValueA)(LPVOID object,LPCSTR name, LPSTR buffer, int length);

	///
	//	返回与给定开关关联的值。 如果开关没有值或不存在，则此方法返回空字符串。
	//	如果|length|为0,则不会将成员数据填充到|buffer|中。
	///
	AQUAENTRYFULL(int, CommandLine, GetSwitchValueW)(LPVOID object, LPCWSTR name, LPWSTR buffer, int length);

	///
	//	返回开关名称和值的映射。 如果一个开关没有值，则返回一个空字符串。
	//	返回字符串字典,访问方法参见"StrDict"类别函数集
	///
	AQUAENTRYFULL(LPVOID, CommandLine, GetSwitches)(LPVOID object);

	///
	//	将一个开关添加到命令行的末尾。 如果开关没有值传递一个空值字符串。
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchA)(LPVOID object,LPCSTR name);

	///
	//	将一个开关添加到命令行的末尾。 如果开关没有值传递一个空值字符串。
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchW)(LPVOID object, LPCWSTR name);

	///
	//	将具有指定值的开关添加到命令行的末尾。
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueA)(LPVOID object, LPCSTR name,LPCSTR value);

	///
	//	将具有指定值的开关添加到命令行的末尾。
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueW)(LPVOID object, LPCSTR name, LPCSTR value);

	///
	//	如果有剩余的命令行参数，则为真。
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasArguments)(LPVOID object);

	///
	//	获取其余的命令行参数。
	//	返回字符串数组,访问方法参见"StrVector"类别函数集
	///
	AQUAENTRYFULL(LPVOID, CommandLine, GetArguments)(LPVOID object);

	///
	//	在命令行的末尾添加一个参数。
	///
	AQUAENTRYFULL(void, CommandLine ,AppendArgumentA)(LPVOID object, LPCSTR value);

	///
	//	在命令行的末尾添加一个参数。
	///
	AQUAENTRYFULL(void, CommandLine, AppendArgumentW)(LPVOID object, LPCSTR value);

	///
	//	在当前命令之前插入一条命令。 通常用于调试器，如“valgrind”或“gdb --args”。
	///
	AQUAENTRYFULL(void, CommandLine, PrependWrapperA)(LPVOID object, LPCSTR wapper);

	///
	//	在当前命令之前插入一条命令。 通常用于调试器，如“valgrind”或“gdb --args”。
	///
	AQUAENTRYFULL(void, CommandLine, PrependWrapperW)(LPVOID object, LPCSTR wapper);
}

#endif