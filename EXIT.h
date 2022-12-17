#pragma once
#include "operation.h"

//delete shape operation class
class EXIT : public operation
{
public:
	EXIT(controller* pCont);
	virtual ~EXIT();

	//delete shape to the controller
	virtual void Execute();

};

