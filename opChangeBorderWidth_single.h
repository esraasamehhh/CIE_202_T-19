#pragma once

#include "operation.h"

class opChangeBorderWidth_single : public operation
{
public:
	opChangeBorderWidth_single(controller *pCont);
	virtual ~opChangeBorderWidth_single();
	
	virtual void Execute() ;
	
};

