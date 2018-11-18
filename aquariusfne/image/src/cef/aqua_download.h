#ifndef AQUA_DOWNLOAD_H_
#define AQUA_DOWNLOAD_H_
#include "utils\aqua_utils.h"

namespace AquaCef {

	AQUAENTRYFULL(BOOL, Download, IsValid)(LPVOID object);

	AQUAENTRYFULL(BOOL, Download, IsInProgress)(LPVOID object);

	AQUAENTRYFULL(BOOL, Download, IsComplete)(LPVOID object);

	AQUAENTRYFULL(BOOL, Download, IsCanceled)(LPVOID object);

	AQUAENTRYFULL(__int64, Download, GetCurrentSpeed)(LPVOID object);

	AQUAENTRYFULL(int, Download, GetPercentComplete)(LPVOID object);

	AQUAENTRYFULL(__int64, Download, GetTotalBytes)(LPVOID object);

	AQUAENTRYFULL(__int64, Download, GetReceivedBytes)(LPVOID object);

	AQUAENTRYFULL(void, Download, GetStartTime)(LPVOID object, LPVOID time);

	AQUAENTRYFULL(void, Download, GetEndTime)(LPVOID object, LPVOID time);

	AQUAENTRYFULL(int, Download, GetFullPath)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(UINT, Download, GetId)(LPVOID object);

	AQUAENTRYFULL(int, Download, GetURL)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, Download, GetOriginalUrl)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, Download, GetSuggestedFileName)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, Download, GetContentDisposition)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, Download, GetMimeType)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(void, DownloadCallback, Continue)(LPVOID object, LPCSTR file_path, bool show_dialog);

	AQUAENTRYFULL(void, DownloadItemCallback, Cancel)(LPVOID object);

	AQUAENTRYFULL(void, DownloadItemCallback, Pause)(LPVOID object);

	AQUAENTRYFULL(void, DownloadItemCallback, Resume)(LPVOID object);
}

#endif