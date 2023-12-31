
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
	int* selectedFigCount = pManager->getSelectedFigCount(); // Get the pointer to the selected figure count from the ApplicationManager

		int cx;

		int cy;

		GUI* pGUI = pManager->GetGUI(); // Get the pointer to the GUI from the ApplicationManager

		pGUI->GetPointClicked(cx, cy); // Get the coordinates of the clicked point from the user
		//1-> Declared Function at ApplicationManager.cpp to get the figure at the clicked point
		CFigure* fig = pManager->GetFigure(cx, cy); // Get the figure at the clicked point from the ApplicationManager

		// Check if a figure is clicked
		if (fig != NULL) {

			// If the figure is already selected, deselect it
			if (fig->IsSelected()) {
				fig->SetSelected(false); // Set the figure as not selected
				*selectedFigCount = *selectedFigCount - 1; // Decrease the selected figure count by 1
				pGUI->ClearStatusBar(); // Clear the status bar of the GUI
			}
			else {
				fig->ChngDrawClr(CADETBLUE); // Change the drawing color of the figure to CADETBLUE
				fig->SetSelected(true); // Set the figure as selected
				*selectedFigCount = *selectedFigCount + 1; // Increase the selected figure count by 1
			}
		}
		else {
			// If no figure is clicked, deselect the previously selected figure
			CFigure* selectedFiguer = pManager->GetSelectedFigure(); // Get the pointer to the selected figure from the ApplicationManager
			if (selectedFiguer != NULL) {
				selectedFiguer->SetSelected(false); // Set the selected figure as not selected
				pGUI->ClearStatusBar(); // Clear the status bar of the GUI
			}
		}
	}
	
	

	ReadActionParameters();
	// pManager->UnSelectFigures()
	pManager->UpdateInterface();
}
