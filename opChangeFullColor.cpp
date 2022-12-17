#include "opChangeFullColor.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChangeFullColor::opChangeFullColor(controller* pCont) :operation(pCont)
{}
opChangeFullColor::~opChangeFullColor()
{}

//Execute the operation
void opChangeFullColor::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Select ONE color");

	int num = stoi(pUI->GetSrting());

	color newColor;

	switch (num)
	{
	case 1:
		newColor = BLACK;
		break;
	case 2:
		newColor = BLUE;
	}

	pUI->ClearStatusBar();

	pUI->setFullColor(newColor);

}
