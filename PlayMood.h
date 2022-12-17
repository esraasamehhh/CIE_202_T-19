#pragma once
#include "operation.h"

//delete shape operation class
class PlayMood : public operation
{
public:
	PlayMood(controller* pCont);
	virtual ~PlayMood();

	//delete shape to the controller
	virtual void Execute();

};

