#include "../Actions/ActionAddCircle.h"
#include "../Figures/CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo CircGfxInfo;
	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	CircGfxInfo.FillClr = pGUI->getCrntFillColor();
	CircGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Circle data from the user

	pGUI->PrintMessage("New Circle: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Circle: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar(); // Clear  All Text in Status Bar


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a Square with the parameters read from the user
	CCircle* C = new CCircle(topLeft, SideLength, CircGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(C);
}
