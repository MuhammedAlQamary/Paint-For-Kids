#include "ActionAddLine.h"
#include "..\Figures\CLine.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddLine::ActionAddLine(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Line data from the user

	pGUI->PrintMessage("New Line: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Line: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar(); // Clear  All Text in Status Bar


	//Step 2 - prepare Line data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the Line
	Point topLeft;
	Point bottomRight;
	if (P1.x > P2.x) {
		topLeft.x	  = P1.x;
		bottomRight.x = P2.x;
	}
	else {
		topLeft.x	  = P1.x;
		bottomRight.x = P2.x;
	}
	if (P1.y > P2.y) {
		topLeft.y	  = P1.y;
		bottomRight.y = P2.y;
	}
	else {
		topLeft.y	  = P1.y;
		bottomRight.y = P2.y;
	}
	//topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	//topLeft.y = P1.y < P2.y ? P1.y : P2.y;
	/*
	bottomRight.x = P1.x < P2.x ? P1.x : P2.x;
	bottomRight.y = P1.y < P2.y ? P1.y : P2.y;
	*/

	//2.2- Calculate line length
	//The line length would be the longer distance between the two points coordinates
	int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a line with the parameters read from the user
	CLine* L = new CLine(topLeft, bottomRight, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(L);
}
