#pragma once
#include "Action.h"
class ActionAddRectangle : public Action
{
public:
	ActionAddRectangle(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();


};

