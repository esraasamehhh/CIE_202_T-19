#include "DRAWMood.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

DRAWMood::DRAWMood(controller* pCont) :operation(pCont)
{}
DRAWMood::~DRAWMood()
{}

void DRAWMood::Execute()
{
	//Execute the operation
	GUI* pUI = pControl->GetUI();

	pUI->setDRAWMood();

}




	

	

	
