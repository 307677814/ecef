#ifndef V8_H_
#define V8_H_

#include "utils\aqua_utils.h"
#include <string>

namespace AquaCef {
	struct V8VALUESTRUCT {
		int type;
		int index;
		BOOL v1;
		int v2;
		double v3;
		LPSTR v4;
		void(CALLBACK *free)(V8VALUESTRUCT *p);
	};

	///
	//	创建一个新的|V8Value|副本
	///
	AQUAENTRYFULL(LPVOID, V8Value, Alloc)(void);

	///
	//	从|object|上拷贝一个新的|V8Value|副本
	///
	AQUAENTRYFULL(LPVOID, V8Value, Copy)(LPVOID object);

	///
	//	销毁|object|副本
	///
	AQUAENTRYFULL(void, V8Value, Destory)(LPVOID object);

	///
	//	获取|index|所指向|object|对象中的数据成员类型。
	///
	AQUAENTRYFULL(int, V8Value, GetType)(LPVOID object,int index);

	///
	//	获取|object|对象中|index|处值
	///
	AQUAENTRYFULL(LPVOID, V8Value, GetValue)(LPVOID object, int index);

	///
	//	设置|object|对象中|index|处值
	///
	AQUAENTRYFULL(void, V8Value, SetValue)(LPVOID object,LPVOID value);

	///
	//	创建JS对象
	///
	AQUAENTRYFULL(LPVOID, V8Spec, CreateAccessor)(LPCSTR mainName);

	///
	//	注册JS变量
	///
	AQUAENTRYFULL(BOOL, V8Spec, RegisterVar)(LPVOID object, LPCSTR childName);

	///
	//	注册JS函数
	///
	AQUAENTRYFULL(BOOL, V8Spec, RegisterFunction)(LPVOID object, LPCSTR functionName);
}

#endif