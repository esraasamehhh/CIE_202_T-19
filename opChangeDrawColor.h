#pragma once

#include "operation.h"

class opChangeDrawColor : public operation
{
public:
	opChangeDrawColor(controller *pCont);
	virtual ~opChangeDrawColor();
	
	virtual void Execute() ;
	
};

