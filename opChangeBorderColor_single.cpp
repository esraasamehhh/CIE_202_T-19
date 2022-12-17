#include "opChangeBorderColor_single.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChangeBorderColor_single::opChangeBorderColor_single(controller * pCont):operation(pCont)
{}
opChangeBorderColor_single::~opChangeBorderColor_single()
{} 

//Execute the operation
void opChangeBorderColor_single::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* graph =pControl->getGraph();


	pUI->PrintMessage("Select color");

	int num = stoi(pUI->GetSrting());
	pUI->PrintMessage("Select shape");
	 
	int x, y;
	pUI->GetPointClicked(x,y);

	color newColor;

	switch (num)
	{ 
	case 1:
		newColor = GREEN;
		break;
	case 2:
		newColor = BLACK;
		break;
	case 3:
		newColor = ORANGE;
		break;
	case 4:
		newColor = NAVY;
		break;
	}
	
	pUI->ClearStatusBar();
	shape* s = graph->Getshape(x, y);

	graph->setBordercolor_Single(newColor, s);

}
