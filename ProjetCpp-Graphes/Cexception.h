#pragma once
#include "stdafx.h"

class Cexception
{
private:
	unsigned int uiEXCvalue; // the value of the exception risen

public:
	Cexception();

	Cexception(unsigned int value);

	~Cexception();



	unsigned int EXCgetValue();

	void EXCsetValue(unsigned int value);
};
