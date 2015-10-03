#pragma once
#ifndef PROJETCPP2_CEDGES_H
#define PROJETCPP2_CEDGES_H
#include "stdafx.h"

class Cedges
{
private:
	unsigned int uiCEDid_vertex_in;


public:

	/***
	* Cedges() - create a new Cedges with null value
	*
	*Purpose:
	*       create a new Cedges with null value
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cedges();

	/***
	* Cedges(const Cedges &edgeToCopy) - create a new Cedges with the value of another edge
	*
	*Purpose:
	*       create a new Cedges with the value of another edge
	*
	*Entry:
	*       const Cedges &	edgeToCopy	-	the edges to copy
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cedges(const Cedges &edgeToCopy);

	/***
	* Cedges(unsigned int uiId_vertex_in) - create a new Cedges with the param
	*
	*Purpose:
	*       create a new Cedges with the param
	*
	*Entry:
	*       unsigned int	uiId_vertex_in	-	the id of the vertex
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cedges(unsigned int uiId_vertex_in);

	/***
	* ~Cedges() - delete correctly a Cedges
	*
	*Purpose:
	*       delete correctly a Cedges
	*
	*Entry:
	*       const Cedges &	edgeToCopy	-	the edges to copy
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	~Cedges();

	/***
	* EDGset_id_vertex_in(unsigned int uiId_vertex_in) - set the id of the vertex of the Cedges
	*
	*Purpose:
	*       set the id of the vertex of the Cedges
	*
	*Entry:
	*       unsigned int	uiId_vertex_in	the id to set
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void EDGset_id_vertex_in(unsigned int uiId_vertex_in);

	/***
	* EDGget_id_vertex_in(unsigned int uiId_vertex_in) - get the id of the vertex of the Cedges
	*
	*Purpose:
	*       get the id of the vertex of the Cedges
	*
	*Entry:
	*       none
	*
	*Return:
	*		unsigned int	-	the id of the vertex of the Cedges
	*
	*******************************************************************************/
	unsigned int EDGget_id_vertex_in();

	/***
	* Cedges &Cedges::operator=(const Cedges &edgeToCopy) - set the id of the vertex of the Cedges
	*
	*Purpose:
	*       set the id of the vertex of the Cedges
	*
	*Entry:
	*       const Cedges &	edgeToCopy	-	the edge to copy
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cedges &operator=(const Cedges &edgeToCopy);

	/***
	* operator==(Cedges &edgeToCompare) - compare two Cedges
	*
	*Purpose:
	*       compare two Cedges
	*
	*Entry:
	*       Cedges &	edgeToCompare	-	the edge to compare
	*
	*Return:
	*		bool	-	true if the two Cedges are equal, false otherwise
	*
	*******************************************************************************/
	bool operator==(Cedges &edgeToCompare);

	/***
	* operator==(Cedges &edgeToCompare) - compare two Cedges
	*
	*Purpose:
	*       compare two Cedges
	*
	*Entry:
	*       Cedges &	edgeToCompare	-	the edge to compare
	*
	*Return:
	*		bool	-	false if the two Cedges are equal, true otherwise
	*
	*******************************************************************************/
	bool operator!=(Cedges &edgeToCompare);

};

#endif
