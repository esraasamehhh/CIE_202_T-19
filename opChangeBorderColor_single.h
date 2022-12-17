#pragma once

#include "operation.h"

class opChangeBorderColor_single : public operation
{
public:
	opChangeBorderColor_single(controller *pCont);
	virtual ~opChangeBorderColor_single();
	
	virtual void Execute() ;
	
};

