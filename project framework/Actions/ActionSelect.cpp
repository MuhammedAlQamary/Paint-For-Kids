#include "ActionSelect.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

ActionSelect :: ActionSelect(ApplicationManager* pApp) : Action(pApp)
{

}

void ActionSelect::ReadActionParameters()
{
	//Input* pIn = pManager->GetInput();
	//Output* pOut = pManager->GetOutput();
	

}

void ActionSelect::Execute()
{
	ReadActionParameters();
	// pManager->UnSelectFigures()
	pManager->UpdateInterface();
}