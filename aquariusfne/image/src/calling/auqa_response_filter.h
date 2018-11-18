#ifndef AQUA_RESPONSE_FILTER_H_
#define AQUA_RESPONSE_FILTER_H_
#include "include\cef_response_filter.h"
#include "include\cef_app.h"
#include <vector>


class AquaCallResponseFilter : public CefResponseFilter
{
public:
	AquaCallResponseFilter(uint64 vid);
	~AquaCallResponseFilter();

private:
	uint64 m_requestId;
	std::vector<LPVOID> m_payload;
	DWORD m_writeTotal;
	BYTE *m_buf;
	DWORD m_dataTotal;

public:
	uint64 GetRequestId(void) { return m_requestId; }
	size_t GetSize(void) { return m_dataTotal; }

	void SetPayload(BYTE *data,int size);

public:
	virtual bool InitFilter() OVERRIDE;

	virtual FilterStatus Filter(void* data_in,
		size_t data_in_size,
		size_t& data_in_read,
		void* data_out,
		size_t data_out_size,
		size_t& data_out_written) OVERRIDE;
public:
	IMPLEMENT_REFCOUNTING(AquaCallResponseFilter);
};

#endif