#pragma once

#include "operation.h"

class opChangeFullColor : public operation
{
public:
	opChangeFullColor(controller* pCont);
	virtual ~opChangeFullColor();

	virtual void Execute();
};