/**
* @file Cexception.h
*
* \author Mathieu Boutolleau & Paul Fayoux
*
*
*/

#pragma once
#include "stdafx.h"

//! Cexception Class
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
