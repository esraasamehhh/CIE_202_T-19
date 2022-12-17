#include "opChangeBorderWidth_single.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChangeBorderWidth_single::opChangeBorderWidth_single(controller* pCont) :operation(pCont)
{}
opChangeBorderWidth_single::~opChangeBorderWidth_single()
{}

//Execute the operation
void opChangeBorderWidth_single::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* graph = pControl->getGraph();

	pUI->PrintMessage("enter number from 1 to 5 to choose width");
	pUI->PrintMessage("Select shape");

	int newWidth = stoi(pUI->GetSrting());

	int x, y;
	pUI->GetPointClicked(x, y);

	pUI->ClearStatusBar();
	shape* s = graph->Getshape(x, y);

	graph->setBorderWidth_Single(newWidth, s);

}
