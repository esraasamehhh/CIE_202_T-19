#pragma once

#include "operation.h"

class opChangeFillColor_SingleShape : public operation
{
public:
	opChangeFillColor_SingleShape(controller *pCont);
	virtual ~opChangeFillColor_SingleShape();
	
	virtual void Execute() ;
	
};

