#include "ActionExit.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../GUI/GUI.h"
#include "ActionSave.h"
#include <string>

#include <iostream>



ActionExit::ActionExit(ApplicationManager* pMan) :Action(pMan) {

}
void ActionExit::ReadActionParameters()
{}
void ActionExit::Execute() {
	GUI* pGui = pManager->GetGUI();
	pGui->PrintMessage("If you want to save you graph before exit write (Y) else write (N) ");
	string s = pGui->GetSrting();
	std::cout << s + "before";
	if (s == "Y" || s == "y") {
		std::cout << s + "'y'";
		Action* newAct = new ActionSave(pManager);
		pManager->ExecuteAction(newAct);
	}
	else {
		std::cout << s + "'else'";
		pGui->PrintMessage("See you next time");
		delete pGui;
	}
}