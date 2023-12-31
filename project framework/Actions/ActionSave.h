#pragma once
#include "Action.h"
#include<string>
#include<fstream>

class ActionSave : public Action
{
private: 
	int force;
	string filename;
public:
	ActionSave(ApplicationManager* pApp, int _force = 0);
	virtual void Execute();
	void ReadParameters();
	string ColorToString(color c);
};

