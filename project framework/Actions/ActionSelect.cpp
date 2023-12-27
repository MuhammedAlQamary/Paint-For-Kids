#include "ActionSelect.h" // Include the header file for ActionSelect class
#include <iostream> // Include the standard input/output stream library
#include "..\ApplicationManager.h" // Include the header file for ApplicationManager class
#include <string> // Include the string library
#include <iostream> // Include the standard input/output stream library again

int ActionSelect::selectedEllipses = 0; // Initialize the static member variable selectedEllipses to 0
int ActionSelect::selectedHexagons = 0; // Initialize the static member variable selectedHexagons to 0
int ActionSelect::selectedSquares = 0; // Initialize the static member variable selectedSquares to 0

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp) ///constructor chaining
{

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
	
	

