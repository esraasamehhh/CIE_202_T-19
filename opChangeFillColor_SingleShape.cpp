#include "opChangeFillColor_SingleShape.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChangeFillColor_SingleShape::opChangeFillColor_SingleShape(controller * pCont):operation(pCont)
{}
opChangeFillColor_SingleShape::~opChangeFillColor_SingleShape()
{} 

//Execute the operation

void opChangeFillColor_SingleShape::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* graph = pControl->getGraph();


	pUI->PrintMessage("enter number from 1 to 5");

	int num = stoi(pUI->GetSrting());
	pUI->PrintMessage("Select shape");

	int x, y;
	pUI->GetPointClicked(x, y);

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
		newColor = LAVENDER;
		break;
	case 4:
		newColor = HONEYDEW;
		break;
	case 5:
		newColor = CHOCOLATE;
		break;

	}

	pUI->ClearStatusBar();
	shape* s = graph->Getshape(x, y);

	graph->setBordercolor_Single(newColor, s);

}