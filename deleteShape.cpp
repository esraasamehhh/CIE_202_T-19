#include "deleteShape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

deleteShape::deleteShape(controller* pCont) :operation(pCont)
{}
deleteShape::~deleteShape()
{}

//Execute the operation
void deleteShape::Execute()
{
	Point P1;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage(" select ashape to delete ");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	
	

	

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	

}
