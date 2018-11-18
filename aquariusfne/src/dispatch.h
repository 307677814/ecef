#ifndef DISPATCH_H_
#define DISPATCH_H_

#include "lib2.h"

namespace dispEventer{

	extern void OnInitial(LPVOID pUnit,LPCSTR package);

	extern void OnResized(LPVOID pUnit);

	extern void OnDestory(void);
}

#endif