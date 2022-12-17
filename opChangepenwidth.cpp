#include "opChangepenwidth.h"
#include "..\shapes\Rect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opChangepenwidth::opChangepenwidth(controller* pCont) :operation(pCont)
{}
opChangepenwidth::~opChangepenwidth()
{}

//Execute the operation
void opChangepenwidth::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("enter new width");

	int newWidth = stoi(pUI->GetSrting());

	pUI->ClearStatusBar();
	pUI->setPenWidth(newWidth);
}
