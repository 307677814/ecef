#include "calling\auqa_response_filter.h"

AquaCallResponseFilter::AquaCallResponseFilter(uint64 vid):
	m_requestId(vid)
{
	m_writeTotal = 0;
	m_buf = NULL;
	m_dataTotal = 0;
}

AquaCallResponseFilter::~AquaCallResponseFilter() {
	if (m_buf) {
		VirtualFree(m_buf, MEM_RELEASE, 0);
	}
	for (auto v:m_payload)
	{
		VirtualFree(v, MEM_RELEASE, 0);
	}
	m_buf = NULL;
	m_payload.clear();
}

void AquaCallResponseFilter::SetPayload(BYTE *data, int size) {
	if (m_dataTotal == 0) return;
	DWORD p = 0;
	for (auto v:m_payload){
		memmove(&data[p], v, 0x8000);
		p += 0x8000;
	}
	if (m_buf) {
		memmove(&data[p], m_buf, m_writeTotal);
		p += m_writeTotal;
	}
}

bool AquaCallResponseFilter::InitFilter() {
	return true;
}

AquaCallResponseFilter::FilterStatus AquaCallResponseFilter::Filter(void* data_in,
	size_t data_in_size,
	size_t& data_in_read,
	void* data_out,
	size_t data_out_size,
	size_t& data_out_written) {
	m_dataTotal += data_in_size;
	if (m_buf == NULL) {
		m_buf = (BYTE*)VirtualAlloc(NULL, 0x8000, MEM_COMMIT, PAGE_READWRITE);
		m_writeTotal = 0;
	}

	size_t v = 0x8000 - m_writeTotal;
	if (v >= data_in_size) {
		memmove(&m_buf[m_writeTotal], data_in, data_in_size);
		m_writeTotal += data_in_size;

		if (m_writeTotal >= 0x8000) {
			m_payload.push_back(m_buf);
			m_buf = NULL;
			m_writeTotal = 0;
		}
	}
	else {
		BYTE *dataIn = (BYTE*)data_in;
		memmove(&m_buf[m_writeTotal], dataIn, v);
		dataIn += v;
		m_payload.push_back(m_buf);
		m_buf = (BYTE*)VirtualAlloc(NULL, 0x8000, MEM_COMMIT, PAGE_READWRITE);
		m_writeTotal = 0;
		size_t k = data_in_size - v;
		memmove(&m_buf[m_writeTotal], &dataIn[v], data_in_size - v);
		m_writeTotal += k;
	}

	if (data_in_size > data_out_size) {
		data_in_read = data_out_size;
		data_out_written = data_out_size;
		memmove(data_out, data_in, data_out_size);
		return RESPONSE_FILTER_NEED_MORE_DATA;
	}
	else {
		data_in_read = data_in_size;
		data_out_written = data_in_size;
		memcpy(data_out, data_in, data_in_size);
		return RESPONSE_FILTER_DONE;
	}
}