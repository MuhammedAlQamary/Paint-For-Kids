#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"
// #include "ActionDelete.h"
//Add Select Action class
class ActionSelect :  public Action
{
public:
	static int selectedSquares;
	static int selectedHexagons;
	static int selectedEllipses;
	ActionSelect(ApplicationManager* pApp);

	//Add Select to the ApplicationManager
	virtual void Execute();
	
	
};
#endif
