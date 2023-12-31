#include<iostream>
#include "ActionSave.h"
#include "..\Figures\CSquare.h"
//#include "..\Figures\CEllipse.h"
//#include "..\Figures\CHex.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionSave::ActionSave(ApplicationManager* pMan, int _force) :Action(pMan) {
	force = _force;
}

void ActionSave::Execute()
{
	if (force == 0)
		ReadParameters();
	else
		filename = "saver";

	GUI* pGui = pManager->GetGUI();
	ofstream outputfile((filename + ".txt"));
	if (outputfile.is_open())
	{
		outputfile << ColorToString(UI.DrawColor)
			<< "\t" << ColorToString(UI.FillColor)
			<< "\t" << ColorToString(UI.BkGrndColor)
			<< "\n";
//		pManager->SaveAll(outputfile);

		pGui->PrintMessage("Graph Saved successfully :)");

		outputfile.close();
	}
	/*if (outputfile.fail()) {
		pGui->PrintMessage("Wrong file name :(");
		return;
	}*/


}

void ActionSave::ReadParameters()
{
	GUI* Pgui = pManager->GetGUI();

	while (true)
	{
		Pgui->PrintMessage("Enter the file name you want to save :)");
		filename = Pgui->GetSrting();
		if (filename != "")
		{
			break;
		}
	}

}

string ActionSave::ColorToString(color c) {
	return "NO-FILL";
}