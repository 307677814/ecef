#ifndef AQUA_CALLING_QUIT_H_
#define AQUA_CALLING_QUIT_H_

#include "include\cef_task.h"

class AquaCallQuitTask : public CefTask 
{
public:
	AquaCallQuitTask();
	~AquaCallQuitTask();

public:
	void Execute() OVERRIDE;

public:
	IMPLEMENT_REFCOUNTING(AquaCallQuitTask);
};

#endif