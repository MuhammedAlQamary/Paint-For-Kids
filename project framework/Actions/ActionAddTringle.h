#pragma once
#include "Action.h"
class ActionAddTringle : public Action
{
public:
	ActionAddTringle(ApplicationManager* pApp);

	//Add Tringle to the ApplicationManager
	virtual void Execute();

};


