#pragma once
#include "operation.h"

//delete shape operation class
class deleteShape : public operation
{
public:
	deleteShape(controller* pCont);
	virtual ~deleteShape();

	//delete shape to the controller
	virtual void Execute();

};

