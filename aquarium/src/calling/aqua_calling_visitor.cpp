#include "aqua_calling_visitor.h"
#include "cpprest\http_client.h"
#include "utils\aqua_conv.h"
#include "include\cef_app.h"

using namespace web;
using namespace web::http;
using namespace web::http::client;




AquaCallStringVisitor::AquaCallStringVisitor(LPVOID respBody):
	m_pRespBody(respBody)
{

}

AquaCallStringVisitor::~AquaCallStringVisitor() {

}

void AquaCallStringVisitor::Visit(const CefString& string) {
	auto pNotify = reinterpret_cast<pplx::task_completion_event<CefString>*>(m_pRespBody);
	if (pNotify) {
		pNotify->set(string);
		m_pRespBody = NULL;
	}

}

BOOL AquaCallStringVisitor::OutputString(CefRefPtr<CefFrame> frame, LPFN_STRING_OUTPUTA callback, LPVOID params, BOOL async, int cmd) {
	pplx::task_completion_event<CefString> *pResp = new pplx::task_completion_event<CefString>;
	CefRefPtr<AquaCallStringVisitor> visit = new AquaCallStringVisitor(pResp);
	auto notify = pplx::create_task(*pResp);
	if (cmd == 0) {
		frame->GetSource(visit);
	}
	else if (cmd == 1) {
		frame->GetText(visit);
	}
	if (CefCurrentlyOn(TID_RENDERER) || CefCurrentlyOn(TID_UI) || async) {
		notify.then([callback, params, pResp](CefString body) -> void {
			aqua_convert conv;
			std::string text;
			try
			{
				text = conv.to_bytes(body.c_str());
			}
			catch (const std::exception &ex)
			{
				int len = WideCharToMultiByte(CP_ACP, 0, body.c_str(), body.length(), NULL, NULL, NULL, NULL);
				char *buf = new char[len + 1];
				WideCharToMultiByte(CP_ACP, 0, body.c_str(), body.length(), buf, len, NULL, NULL);
				buf[len] = 0;
				text = buf;
				delete[]buf;
			}
			callback(text.c_str(), text.length(), params);
			delete pResp;

		}).then([pResp](pplx::task<void> t) -> void{
			try
			{
				t.get();
			}
			catch (const std::exception&)
			{
				delete pResp;
			}
		});
		return TRUE;
	}
	CefString result = notify.get();
	aqua_convert conv;
	std::string text;
	try
	{
		text = conv.to_bytes(result.c_str());
	}
	catch (const std::exception&)
	{
		int len = WideCharToMultiByte(CP_ACP, 0, result.c_str(), result.length(), NULL, NULL, NULL, NULL);
		char *buf = new char[len + 1];
		WideCharToMultiByte(CP_ACP, 0, result.c_str(), result.length(), buf, len, NULL, NULL);
		buf[len] = 0;
		text = buf;
		delete[]buf;
	}
	callback(text.c_str(), text.length(), params);
	delete pResp;
	return TRUE;
}