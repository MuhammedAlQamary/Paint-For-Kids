#pragma once
#include "Action.h"
class ActionAddLine : public Action
{
public:
	ActionAddLine(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

