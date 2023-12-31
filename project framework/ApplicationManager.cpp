#include "ApplicationManager.h"
#include "Actions/ActionAddLine.h"
#include "Actions/ActionAddSquare.h"
#include "Actions/ActionAddRectangle.h"
#include "Actions/ActionAddEllipse.h"
#include "Actions/ActionAddCircle.h"
#include "Actions/ActionAddTringle.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionSave.h"

//Figures
#include "Figures/CFigure.h"
#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CEllipse.h"
#include "Figures/CCircle.h"
#include "Figures/CTringle.h"

#include <fstream>
using namespace std;

//Constructor
ApplicationManager::ApplicationManager() : mode(0)
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
	selectedFigCount = 0;
	PlayModePlace = 0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_LINE:
			newAct = new ActionAddLine(this);
			break;

		case DRAW_RECTANGLE:
			newAct = new ActionAddRectangle(this);
			break;

		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			///create AddLineAction here
			newAct = new ActionAddEllipse(this);
			break;

		case DRAW_CIRC:
			newAct = new ActionAddCircle(this);
			break;

		case DRAW_TRI:
			newAct = new ActionAddTringle(this);
			break;

		case EXIT:
			///create ExitAction here
			newAct = new ActionExit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//void ApplicationManager::SaveAll(ofstream &outputfile) {
//	// Figure save Functions Run
//	if (outputfile.is_open())
//	{
//		outputfile << to_string(FigCount) << "\n";
//		for (int i = 0; i < FigCount; i++)
//		{
//			FigList[i]->Save(outputfile);
//		}
//	}
//
//}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//void ApplicationManager::AddSelectedFigure(CFigure* pFig)
//{
//	set<CFigure*>::iterator it = SelectedFigList.find(pFig);
//	if (SelectedFigCount < MaxFigCount && it == SelectedFigList.end()) {
//		SelectedFigList.insert(pFig);
//		SelectedFigCount++;
//	}
//	else if (it != SelectedFigList.end()) {
//		SelectedFigList.erase(pFig);
//		pFig->SetSelected(false);
//		SelectedFigCount--;
//	}
//}
//
//void ApplicationManager::UnSelectFigures()
//{
//	for (set<CFigure*>::iterator it = SelectedFigList.begin(); it != SelectedFigList.end(); it++)
//		(*it)->SetSelected(false);
//	SelectedFigList.clear();
//	SelectedFigCount = 0;
//}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
