#include "aqua_calling_renderer.h"
#include "aqua_calling_browser.h"
#include "utils\aqua_conv.h"
#include "cpprest\http_client.h"
#include <sstream>
#include "calling\aqua_calling_v8.h"

namespace Local {
	CefRefPtr<AquaCallRenderer> render;
}

CefRefPtr<AquaCallRenderer> AquaCallRenderer::GetInterface() {
	return Local::render;
}

AquaCallRenderer::AquaCallRenderer() {
	Local::render = this;
}

AquaCallRenderer::~AquaCallRenderer() {
	Local::render = NULL;
}

void AquaCallRenderer::OnBeforeCommandLineProcessing(
	const CefString& process_type,
	CefRefPtr<CefCommandLine> command_line) {
	if (AquaHandler::renderInterface.OnBeforeCommandLineProcessing) {
		command_line->AddRef();
		if (process_type.length() > 0) {
			aqua_convert conv;
			auto type = conv.to_bytes(process_type.c_str());
			AquaHandler::renderInterface.OnBeforeCommandLineProcessing(type.c_str(),command_line.get());
		}
		else {
			AquaHandler::renderInterface.OnBeforeCommandLineProcessing(NULL, command_line.get());
			//MessageBox(NULL, command_line->GetCommandLineString().c_str(), NULL, NULL);
		}
		command_line->Release();
	}
}

 void AquaCallRenderer::OnContextInitialized() {
	 if (AquaHandler::renderInterface.OnContextInitialized) {
		 AquaHandler::renderInterface.OnContextInitialized();
	 }
}

 void AquaCallRenderer::OnBeforeChildProcessLaunch(
	CefRefPtr<CefCommandLine> command_line) {

}

 void AquaCallRenderer::OnRenderProcessThreadCreated(
	CefRefPtr<CefListValue> extra_info) {

}

 void AquaCallRenderer::OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) {

 }

 void AquaCallRenderer::OnWebKitInitialized() {
	
 }

 void AquaCallRenderer::OnBrowserCreated(CefRefPtr<CefBrowser> browser) {

 }

 void AquaCallRenderer::OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) {

 }

 void AquaCallRenderer::OnContextCreated(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefV8Context> context) {
	 if (AquaHandler::renderInterface.OnContextCreated) {
		 m_pV8Context = context;
		 browser->AddRef();
		 AquaHandler::renderInterface.OnContextCreated(browser.get());
		 browser->Release();
		 m_pV8Context = NULL;
	 }
 }

 void AquaCallRenderer::OnContextReleased(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefV8Context> context) {
	 if (AquaHandler::renderInterface.OnContextRelease) {
		 browser->AddRef();
		 AquaHandler::renderInterface.OnContextRelease(browser.get());
		 browser->Release();
	 }
 }

 void AquaCallRenderer::OnUncaughtException(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefV8Context> context,
	 CefRefPtr<CefV8Exception> exception,
	 CefRefPtr<CefV8StackTrace> stackTrace) {
  }

 void AquaCallRenderer::OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
	 CefRefPtr<CefFrame> frame,
	 CefRefPtr<CefDOMNode> node) {
 }


 bool AquaCallRenderer::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
	 CefProcessId source_process,
	 CefRefPtr<CefProcessMessage> message) {
	 if (message->GetName() == TEXT("EVAL")) {
		 CefRefPtr<CefListValue> arg = message->GetArgumentList();
		 CefRefPtr<CefListValue> result = NULL;
		 auto id = arg->GetString(0);
		 auto code = arg->GetString(1);
		 auto url = arg->GetString(2);
		 int line = arg->GetInt(3);
		 auto listvalue =(pplx::task_completion_event<CefRefPtr<CefListValue>>*)arg->GetInt(4);
		 CefRefPtr<CefFrame> frame = id.length() <= 0 ? browser->GetMainFrame():browser->GetFrame(id);
		 CefRefPtr<CefV8Context> v8 = frame->GetV8Context();
		 CefRefPtr<CefV8Value> retval = NULL;
		 CefRefPtr<CefV8Exception> exp = NULL;
		 v8->Enter();

#ifdef _AQUA_CEF2623_ADAPTER
		 bool ret = v8->Eval(code, retval, exp);
#else
		 bool rret = v8->Eval(code, url, line, retval, exp);
#endif
		 if (ret) {
			 if (retval.get()) {
				 if (retval->IsString()) {
					 auto buf = retval->GetStringValue();
					 result = CefListValue::Create();
					 result->SetSize(2);

					 result->SetInt(0, 4);
					 result->SetString(1, buf);

					 listvalue->set(result);
				 }
				 else if (retval->IsBool()) {
					 result = CefListValue::Create();
					 result->SetSize(2);
					 result->SetInt(0, 1);
					 result->SetBool(1, retval->GetBoolValue());

					 listvalue->set(result);
				 }
				 else if (retval->IsInt()) {
					 result = CefListValue::Create();
					 result->SetSize(2);
					 result->SetInt(0, 2);
					 result->SetInt(1, retval->GetIntValue());

					 listvalue->set(result);
				 }
				 else if (retval->IsUInt()) {
					 result = CefListValue::Create();
					 result->SetSize(2);
					 result->SetInt(0, 2);
					 result->SetInt(1, retval->GetUIntValue());

					 listvalue->set(result);
				 }
				 else if (retval->IsDouble()) {
					 result = CefListValue::Create();
					 result->SetSize(2);
					 result->SetInt(0, 3);
					 result->SetDouble(1, retval->GetDoubleValue());

					 listvalue->set(result);
				 }
				 else {
					 result = CefListValue::Create();
					 result->SetSize(1);
					 result->SetInt(0, 0);

					 listvalue->set(result);
				 }
			 }
			 else {
				 result = CefListValue::Create();
				 result->SetSize(1);
				 result->SetInt(0, 0);

				 listvalue->set(result);
			 }
		 }
		 else {
			 result = CefListValue::Create();
			 result->SetSize(2);
			 result->SetInt(0, -1);
			 if (exp.get()) {
				 std::wstringstream buf;
				 TCHAR error[100];
				 _snwprintf_s(error, 100, TEXT(">:%s:%d:%d"), exp->GetSourceLine().c_str(),exp->GetStartColumn(),exp->GetEndColumn());
				 buf << exp->GetMessage().c_str() << "at <" << exp->GetScriptResourceName().c_str() << error;// << result->exception->GetSourceLine() <<
				 const auto &v1 = buf.str();
				 result->SetString(1, v1);
			 }
			 else {
				 result->SetString(1, L"NULL");
			 }
			 
			 listvalue->set(result);
		 }
		 v8->Exit();
	 }
	 return false;
  }