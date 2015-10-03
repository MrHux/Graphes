#include "stdafx.h"

Cexception::Cexception()
{
	uiEXCvalue = 0;
}

Cexception::Cexception(unsigned int value)
{
	uiEXCvalue = value;
}


Cexception::~Cexception()
{

}

unsigned int Cexception::EXCgetValue()
{
	return uiEXCvalue;
}

void Cexception::EXCsetValue(unsigned int value)
{
	uiEXCvalue = value;
}