#include "stdafx.h"
#include "pepper_renderer.h"
#pragma comment(lib,"user32.lib")

PepperRenderer::PepperRenderer()
{
}


PepperRenderer::~PepperRenderer()
{
}

void PepperRenderer::OnBeforeCommandLineProcessing(
	const CefString& process_type,
	CefRefPtr<CefCommandLine> command_line) {
	//MessageBox(NULL, command_line->GetCommandLineString().c_str(), TEXT("xxx"), NULL);
}
