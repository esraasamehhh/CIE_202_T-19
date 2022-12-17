#pragma once
#include "operation.h"

//delete shape operation class
class DRAWMood : public operation
{
public:
	DRAWMood(controller* pCont);
	virtual ~DRAWMood();

	//delete shape to the controller
	virtual void Execute();

};

