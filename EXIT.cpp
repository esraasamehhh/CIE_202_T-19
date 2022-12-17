#include "EXIT.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

EXIT::EXIT(controller* pCont) :operation(pCont)
{}
EXIT::~EXIT()
{}

//Execute the operation
void EXIT::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Ifyouwantsave");
	//if (pUI->GetSrting() == "yes")
		//call save function

		delete pControl;
}


