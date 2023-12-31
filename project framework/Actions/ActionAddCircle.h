#pragma once
#include "Action.h"
class ActionAddCircle : public Action
{
public:
	ActionAddCircle(ApplicationManager* pApp);

	//Add Circle to the ApplicationManager
	virtual void Execute();


};


