#pragma once

#include "operation.h"

class opChangepenwidth : public operation
{
public:
	opChangepenwidth(controller* pCont);
	virtual ~opChangepenwidth();

	virtual void Execute();
};