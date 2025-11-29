#pragma once
#include "Prerequisites.h"

class Strategy
{
public:
	
	virtual ~Strategy()=default;
	virtual int execute(int pago) = 0;
};


