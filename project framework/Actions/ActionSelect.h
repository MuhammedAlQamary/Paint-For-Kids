#pragma once
#include "Action.h"
class ActionSelect : public Action
{
	Point P;
	Point tempP;
public:
	ActionSelect(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

