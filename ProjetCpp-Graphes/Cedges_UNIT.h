/**
* @file Cedges_UNIT.h
*
* \author Mathieu Boutolleau & Paul Fayoux
*
*
*/


#pragma once
#include "stdafx.h"
#ifndef PROJETCPP2_CEDGES_UNIT_H
#define PROJETCPP2_CEDGES_UNIT_H
#ifndef NDEBUG

//! Cedges_UNIT Class
class Cedges_UNIT
{
public:
	static void TEST_UNIT_Cedges();

	static void TEST_UNIT_OperatorEqual();

	static void TEST_UNIT_OperatorEqualEqual();

	static void TEST_UNIT_OperatorNotEqual();
};
#endif
#endif