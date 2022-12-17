#include "opChangeDrawColor.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChangeDrawColor::opChangeDrawColor(controller * pCont):operation(pCont)
{}
opChangeDrawColor::~opChangeDrawColor()
{} 

//Execute the operation
void opChangeDrawColor::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Select color");

	int num = stoi(pUI->GetSrting());

	color newColor;

	switch (num)
	{ 
	case 1:
		newColor = GREEN;
		break;
	case 2:
		newColor = BLACK;
	}

	pUI->ClearStatusBar();

	pUI->setDrawColor(newColor);

}
