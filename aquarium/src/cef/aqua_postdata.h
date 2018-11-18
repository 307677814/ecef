#ifndef AQUA_POSTDATA_H_
#define AQUA_POSTDATA_H_
#include "utils\aqua_utils.h"

namespace AquaCef {

	typedef void(CALLBACK *LPFN_ELEMENTS_CALLBACK)(int total, int index, LPVOID element, LPVOID params);

	AQUAENTRYFULL(LPVOID, PostData, Create)(void);

	AQUAENTRYFULL(LPVOID, PostData, Copy)(LPVOID object);

	AQUAENTRYFULL(void, PostData, Destory)(LPVOID object);

	AQUAENTRYFULL(BOOL, PostData, IsReadOnly)(LPVOID object);

	AQUAENTRYFULL(BOOL, PostData, HasExcludedElements)(LPVOID object);

	AQUAENTRYFULL(int, PostData, GetElementCount)(LPVOID object);

	AQUAENTRYFULL(void, PostData, GetElements)(LPVOID object, LPFN_ELEMENTS_CALLBACK callback,LPVOID params);

	AQUAENTRYFULL(BOOL, PostData, RemoveElement)(LPVOID object, LPVOID element);

	AQUAENTRYFULL(BOOL, PostData, AddElement)(LPVOID object, LPVOID element);

	AQUAENTRYFULL(void, PostData, RemoveElements)(LPVOID object);
}

namespace AquaCef {

	AQUAENTRYFULL(LPVOID, PostDataElement, Create)(void);

	AQUAENTRYFULL(LPVOID, PostDataElement, Copy)(LPVOID object);

	AQUAENTRYFULL(void, PostDataElement, Destory)(LPVOID object);

	AQUAENTRYFULL(BOOL, PostDataElement, IsReadOnly)(LPVOID object);

	AQUAENTRYFULL(void, PostDataElement, SetToEmpty)(LPVOID object);

	AQUAENTRYFULL(void, PostDataElement, SetToFile)(LPVOID object,LPCSTR fileName);

	AQUAENTRYFULL(void, PostDataElement, SetToBytes)(LPVOID object, size_t size,void *data);

	AQUAENTRYFULL(int, PostDataElement, GetType)(LPVOID object);

	AQUAENTRYFULL(int, PostDataElement, GetFile)(LPVOID object,LPSTR buf,int len);

	AQUAENTRYFULL(int, PostDataElement, GetBytes)(LPVOID object, size_t size, void *data);

	AQUAENTRYFULL(int, PostDataElement, GetBytesCount)(LPVOID object);
}

#endif