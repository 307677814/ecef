#include "aqua_calling_quit.h"
#include "include\cef_app.h"

AquaCallQuitTask::AquaCallQuitTask() {

}


AquaCallQuitTask::~AquaCallQuitTask() {

}

void AquaCallQuitTask::Execute() {
	CefShutdown();

}