#include "ActionAddTringle.h"
#include "..\Figures/CTringle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddTringle::ActionAddTringle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddTringle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo TriGfxInfo;
	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	TriGfxInfo.FillClr = pGUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Triangle data from the user

	pGUI->PrintMessage("New Tringle: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Tringle: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->PrintMessage("New Tringle: Click at third point");
	//Read 3nd point and store in point P3
	pGUI->GetPointClicked(P3.x, P3.y);

	pGUI->ClearStatusBar(); // Clear  All Text in Status Bar


	//Step 2 - prepare Triangle data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the Triangle
	//Point topLeft;
	//topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	//topLeft.y = P1.y < P2.y ? P1.y : P2.y;



	//2.2- Calcuate Triangle side legnth
	//The Triangle side length would be the longer distance between the two points coordinates
	//int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a Triangle with the parameters read from the user
	CTringle* T = new CTringle(P1, P2, P3, TriGfxInfo);

	//Step 4 - Add the Triangle to the list of figures
	pManager->AddFigure(T);
}
