#include "aqua_calling_v8.h"
#include "cpprest\http_client.h"
#include "include\cef_app.h"
#include <codecvt>
#include <sstream>
#include <string>
#include "include\cef_app.h"
#include "handler\aqua_handler_renderer.h"

AquaCallV8Accessor::AquaCallV8Accessor() {

}

AquaCallV8Accessor::~AquaCallV8Accessor() {

}

bool AquaCallV8Accessor::Get(const CefString& name,
	const CefRefPtr<CefV8Value> object,
	CefRefPtr<CefV8Value>& retval,
	CefString& exception) {
	bool result = false;
	if (AquaHandler::renderInterface.OnV8AccessorGet && name.length()>0) {
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto childName = conv.to_bytes(name.c_str());
		CefRefPtr<CefV8Value> spec = object->GetValue(TEXT("__v8_spec_"));
		std::string mainName;
		if (spec.get()) {
			mainName = conv.to_bytes(spec->GetStringValue().c_str());
		}
		CefV8ValueList v1;
		result = AquaHandler::renderInterface.OnV8AccessorGet(mainName.c_str(), childName.c_str(), &v1);
		if (v1.empty() == false) {
			retval = v1[0];
			v1.clear();
		}
	}
	return result;
}

bool AquaCallV8Accessor::Set(const CefString& name,
	const CefRefPtr<CefV8Value> object,
	const CefRefPtr<CefV8Value> value,
	CefString& exception) {
	bool result = false;
	if (AquaHandler::renderInterface.OnV8AccessorSet && name.length()>0) {
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto childName = conv.to_bytes(name.c_str());
		CefRefPtr<CefV8Value> spec = object->GetValue(TEXT("__v8_spec_"));
		std::string mainName;
		if (spec.get()) {
			mainName = conv.to_bytes(spec->GetStringValue().c_str());
		}
		CefV8ValueList v1;
		v1.push_back(value);
		result = AquaHandler::renderInterface.OnV8AccessorSet(mainName.c_str(), childName.c_str(), &v1);
		v1.clear();
	}
	return result;
}

AquaCallV8Handler::AquaCallV8Handler() {

}

AquaCallV8Handler::~AquaCallV8Handler() {

}

bool AquaCallV8Handler::Execute(const CefString& name,
	CefRefPtr<CefV8Value> object,
	const CefV8ValueList& arguments,
	CefRefPtr<CefV8Value>& retval,
	CefString& exception) {
	bool result = false;
	if (AquaHandler::renderInterface.OnV8AccessorExecute && name.length() > 0) {
		std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>> conv(::new std::codecvt<wchar_t, char, mbstate_t>(".936"));
		auto childName = conv.to_bytes(name.c_str());
		CefRefPtr<CefV8Value> spec = object->GetValue(TEXT("__v8_spec_"));
		std::string mainName;
		if (spec.get()) {
			mainName = conv.to_bytes(spec->GetStringValue().c_str());
		}
		CefV8ValueList v1;
		result = AquaHandler::renderInterface.OnV8AccessorExecute(mainName.c_str(), childName.c_str(), arguments.size(), (LPVOID)&arguments, &v1);
		if (v1.empty() == false) {
			retval = v1[0];
			v1.clear();
		}
	}
	return result;
}