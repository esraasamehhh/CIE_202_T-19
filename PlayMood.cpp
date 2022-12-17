#include "PlayMood.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

PlayMood::PlayMood(controller* pCont) :operation(pCont)
{}
PlayMood::~PlayMood()
{}

void PlayMood::Execute()
{
	//Execute the operation
	GUI* pUI = pControl->GetUI();

	pUI->setPlayMood();

}




	

	

	
