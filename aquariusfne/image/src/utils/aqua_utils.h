#ifndef AQUA_UTILS_H_
#define AQUA_UTILS_H_
#include <string.h>
#include <Windows.h>

#ifndef AQUAENTRY
	#ifdef AQUAINLINE
		#define AQUAENTRY(x,name)				x(__cdecl *Aqua##name)
		#define AQUAENTRYFULL(x,space,name)		x(__cdecl *Aqua##space##name)
	#else
		#define AQUAENTRY(x,name) extern "C" x __declspec(dllexport) Aqua##name
		#define AQUAENTRYFULL(x,space,name) extern "C" x _declspec(dllexport) Aqua##space##name
	#endif
#endif



class CefBaseRefCounted;

namespace AquaUtils {

	/******************************
	 *			引用计数
	 ******************************/	


	///
	//	对|object|对象增加一次引用计数。
	///
	AQUAENTRY(void, AddRef)(LPVOID object);

	///
	//	对|object|对象减少一次引用计数。
	///
	AQUAENTRY(bool, Release)(LPVOID object);

	///
	//	如果引用计数为1，则返回true。
	///
	AQUAENTRY(bool, HasOenRef)(LPVOID object);

	///
	//	返回当前适配器版本
	///
	AQUAENTRY(LPCSTR, GetAdapter)(void);

	///
	//	退出系统
	///
	AQUAENTRY(void, QuitProcess)(void);


	/******************************
	*			字符串数组
	******************************/

	///
	//	执行该方法后将会获得一个"String Vector"字符串向量副本,
	//	如何访问这个对象可以看看"StrVector"族中所提供的方法集合。
	///
	AQUAENTRYFULL(LPVOID, StrVector, Alloc)(void);

	///
	//	执行该方法后将会获得一个从|object|向量中拷贝的新副本对象,
	//	如果|object|不合法将返回一个NULL
	///
	AQUAENTRYFULL(LPVOID, StrVector, Copy)(LPVOID object);

	///
	//	执行该方法向|object|指向的"String Vector"字符串向量中
	//	追加字符串|text|
	///
	AQUAENTRYFULL(void, StrVector, AppendA)(LPVOID object,LPCSTR text);

	///
	//	执行该方法向|object|指向的"String Vector"字符串向量中
	//	追加字符串|text|
	///
	AQUAENTRYFULL(void, StrVector, AppendW)(LPVOID object, LPCWSTR text);

	///
	//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
	//	所关联的字符串值
	///
	AQUAENTRYFULL(void, StrVector, ReplaceA)(LPVOID object, int index,LPCSTR text);

	///
	//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
	//	所关联的字符串值
	///
	AQUAENTRYFULL(void, StrVector, ReplaceW)(LPVOID object, int index, LPCWSTR text);

	///
	//	执行该方法将会移除|object|指向的"String Vector"字符串向量中|index|所关联的字符串值
	///
	AQUAENTRYFULL(void, StrVector, Remove)(LPVOID object, int index);

	///
	//	执行该方法后将会清空|object|指向的"String Vector"字符串向量中的所有字符串值
	///
	AQUAENTRYFULL(void, StrVector, Clear)(LPVOID object);

	///
	//	返回数组边界
	///
	AQUAENTRYFULL(int, StrVector, GetBound)(LPVOID object);

	///
	//	获取成员数据,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度,|index|从0开始。
	///
	AQUAENTRYFULL(int, StrVector, GetElementA)(LPVOID object, int index, LPSTR buffer, int length);

	///
	//	获取成员数据,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度,|index|从0开始。
	///
	AQUAENTRYFULL(int, StrVector, GetElementW)(LPVOID object, int index, LPWSTR buffer, int length);

	///
	//	销毁字符串数组对象
	///
	AQUAENTRYFULL(void, StrVector, Destory)(LPVOID object);


	/******************************
	*			字符串字典
	******************************/

	///
	//	执行该方法将获得一个新的字典对象。
	///
	AQUAENTRYFULL(LPVOID, StrDict, Alloc)(void);

	///
	//	执行该方法将创建一个基于|object|的新副本对象。
	///
	AQUAENTRYFULL(LPVOID, StrDict, Copy)(LPVOID object);

	///
	//	执行该方法将插入一对键值到字典中。
	///
	AQUAENTRYFULL(void, StrDict, InsertA)(LPVOID object,LPCSTR key,LPCSTR val);

	///
	//	执行该方法将插入一对键值到字典中。
	///
	AQUAENTRYFULL(void, StrDict, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val);

	///
	//	在字典中寻找|key|所关联的键值数据。
	///
	AQUAENTRYFULL(int, StrDict, FindA)(LPVOID object,LPCSTR key,LPSTR buf,int len);

	///
	//	在字典中寻找|key|所关联的键值数据。
	///
	AQUAENTRYFULL(int, StrDict, FindW)(LPVOID object, LPCWSTR key, LPWSTR buf, int len);

	///
	//	返回字典边界
	///
	AQUAENTRYFULL(int, StrDict,GetBound)(LPVOID object);

	///
	//	执行该方法将会获得字典对象中的从首个成员开始算起的迭代器指针,如果字典为空将会返回NULL
	//	,使用完需要用Erase命令释放指针。
	///
	AQUAENTRYFULL(LPVOID, StrDict, GetFirst)(LPVOID object);

	///
	//	执行该方法会将|iter|指向下一个成员,如果到达尾部将会返回FALSE。
	///
	AQUAENTRYFULL(BOOL, StrDict, GetNext)(LPVOID object,LPVOID iter);

	///
	//	执行该方法将擦除|iter|指针。
	///
	AQUAENTRYFULL(void, StrDict, Erase)(LPVOID iter);

	///
	//	获取迭代器中的|key|键值内容。
	///
	AQUAENTRYFULL(int, StrDict, GetKeyA)(LPVOID iter,LPSTR buf,int len);

	///
	//	获取迭代器中的|key|键值内容。
	///
	AQUAENTRYFULL(int, StrDict, GetKeyW)(LPVOID iter, LPWSTR buf, int len);

	///
	//	获取迭代器中的|value|键值内容。
	///
	AQUAENTRYFULL(int, StrDict, GetValueA)(LPVOID iter, LPSTR buf, int len);

	///
	//	设置迭代器中的|value|键值内容。
	///
	AQUAENTRYFULL(int, StrDict, SetValueA)(LPVOID iter, LPCSTR value);

	///
	//	获取迭代器中的|value|键值内容。
	///
	AQUAENTRYFULL(int, StrDict, GetValueW)(LPVOID iter, LPSTR buf, int len);

	///
	//	删除|key|所关联的键值数据
	///
	AQUAENTRYFULL(void, StrDict,RemoveA)(LPVOID object,LPCSTR key);

	///
	//	删除|key|所关联的键值数据
	///
	AQUAENTRYFULL(void, StrDict, RemoveW)(LPVOID object, LPCWSTR key);

	///
	//	清空字典中的所有键值内容。
	///
	AQUAENTRYFULL(void, StrDict, Clear)(LPVOID object);

	///
	//	获取|key|字段指向的数据元素内容,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度。
	///
	AQUAENTRYFULL(int, StrDict, AtA)(LPVOID object,LPCSTR key,LPSTR valBuffer,int valLength);

	///
	//	获取|key|字段指向的数据元素内容,如果|length|为0,则不会将成员数据填充到|buffer|中,仅返回成员数据长度。
	///
	AQUAENTRYFULL(int, StrDict, AtW)(LPVOID object, LPCSTR key, LPSTR valBuffer, int valLength);

	///
	//	销毁字符串字典对象
	///
	AQUAENTRYFULL(void, StrDict, Destory)(LPVOID object);

	/******************************
	*		复合字符串字典
	******************************/

	///
	//	执行该方法将获得一个新的字典对象。
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, Alloc)(void);

	///
	//	执行该方法将创建一个基于|object|的新副本对象。
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, Copy)(LPVOID object);

	///
	//	执行该方法将插入一对键值到字典中。
	///
	AQUAENTRYFULL(void, StrDictEx, InsertA)(LPVOID object, LPCSTR key, LPCSTR val);

	///
	//	执行该方法将插入一对键值到字典中。
	///
	AQUAENTRYFULL(void, StrDictEx, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val);

	///
	//	在字典中寻找|key|所关联的键值数据,返回字符串向量对象
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, FindA)(LPVOID object, LPCSTR key,void **iter);

	///
	//	在字典中寻找|key|所关联的键值数据,返回字符串向量对象。
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, FindW)(LPVOID object, LPCWSTR key, void **iter);

	///
	//	替换迭代器中的内容
	///
	AQUAENTRYFULL(void, StrDictEx, ReplaceA)(LPVOID iter,LPCSTR val);

	///
	//	替换迭代器中的内容
	///
	AQUAENTRYFULL(void, StrDictEx, ReplaceW)(LPVOID iter, LPCWSTR val);

	///
	//	返回字典边界
	///
	AQUAENTRYFULL(int, StrDictEx, GetBound)(LPVOID object);

	///
	//	执行该方法将会获得字典对象中的从首个成员开始算起的迭代器指针,如果字典为空将会返回NULL
	//	,使用完需要用Erase命令释放指针。
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, GetFirst)(LPVOID object);

	///
	//	执行该方法会将|iter|指向下一个成员,如果到达尾部将会返回FALSE。
	///
	AQUAENTRYFULL(BOOL, StrDictEx, GetNext)(LPVOID object, LPVOID iter);

	///
	//	执行该方法将擦除|iter|指针。
	///
	AQUAENTRYFULL(void, StrDictEx, Erase)(LPVOID iter);

	///
	//	获取迭代器中的|key|键值内容。
	///
	AQUAENTRYFULL(int, StrDictEx, GetKeyA)(LPVOID iter, LPSTR buf, int len);

	///
	//	获取迭代器中的|key|键值内容。
	///
	AQUAENTRYFULL(int, StrDictEx, GetKeyW)(LPVOID iter, LPWSTR buf, int len);

	///
	//	获取迭代器中的|value|键值内容。
	///
	AQUAENTRYFULL(int, StrDictEx, GetValueA)(LPVOID iter, LPSTR buf, int len);

	///
	//	设置迭代器中的|value|键值内容。
	///
	AQUAENTRYFULL(int, StrDictEx, SetValueA)(LPVOID iter, LPCSTR value);

	///
	//	获取迭代器中的|value|键值内容。
	///
	AQUAENTRYFULL(int, StrDictEx, GetValueW)(LPVOID iter, LPSTR buf, int len);

	///
	//	删除|key|所关联的键值数据
	///
	AQUAENTRYFULL(void, StrDictEx, RemoveA)(LPVOID object, LPCSTR key);

	///
	//	删除|key|所关联的键值数据
	///
	AQUAENTRYFULL(void, StrDictEx, RemoveW)(LPVOID object, LPCWSTR key);

	///
	//	清空字典中的所有键值内容。
	///
	AQUAENTRYFULL(void, StrDictEx, Clear)(LPVOID object);

	///
	//	销毁字符串字典对象
	///
	AQUAENTRYFULL(void, StrDictEx, Destory)(LPVOID object);


	/******************************
	*			Int64数组
	******************************/

	///
	//	执行该方法后将会获得一个"String Vector"字符串向量副本,
	//	如何访问这个对象可以看看"StrVector"族中所提供的方法集合。
	///
	AQUAENTRYFULL(LPVOID, Int64Vector, Alloc)(void);

	///
	//	执行该方法后将会获得一个从|object|向量中拷贝的新副本对象,
	//	如果|object|不合法将返回一个NULL
	///
	AQUAENTRYFULL(LPVOID, Int64Vector, Copy)(LPVOID object);

	///
	//	执行该方法向|object|指向的"String Vector"字符串向量中
	//	追加字符串|text|
	///
	AQUAENTRYFULL(void, Int64Vector, Append)(LPVOID object, __int64 value);

	///
	//	执行该方法将用|text|替换|object|指向的"String Vector"字符串向量中|index|
	//	所关联的字符串值
	///
	AQUAENTRYFULL(void, Int64Vector, Replace)(LPVOID object, int index, __int64 value);

	///
	//	执行该方法将会移除|object|指向的"String Vector"字符串向量中|index|所关联的字符串值
	///
	AQUAENTRYFULL(void, Int64Vector, Remove)(LPVOID object, int index);

	///
	//	执行该方法后将会清空|object|指向的"String Vector"字符串向量中的所有字符串值
	///
	AQUAENTRYFULL(void, Int64Vector, Clear)(LPVOID object);

	///
	//	返回数组边界
	///
	AQUAENTRYFULL(int, Int64Vector, GetBound)(LPVOID object);

	///
	//	返回数组成员数据,|index|从0开始。
	///
	AQUAENTRYFULL(__int64, Int64Vector, GetElement)(LPVOID object,int index);

	///
	//	销毁Int64数组对象
	///
	AQUAENTRYFULL(void, Int64Vector, Destory)(LPVOID object);
}


#endif