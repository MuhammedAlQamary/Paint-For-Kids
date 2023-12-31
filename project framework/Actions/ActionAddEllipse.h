#pragma once
#include "Action.h"
class ActionAddEllipse : public Action
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	//Add Ellipse to the ApplicationManager
	virtual void Execute();

};

