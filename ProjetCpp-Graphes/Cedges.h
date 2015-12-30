/**
* @file Cedges.h
*
* \author Mathieu Boutolleau & Paul Fayoux
*
*
*/

#pragma once
#ifndef PROJETCPP2_CEDGES_H
#define PROJETCPP2_CEDGES_H
#include "stdafx.h"

 //! Cedges Class
class Cedges
{
private:
	unsigned int uiCEDid_vertex_in;


public:

	/*!
	* 
	* \brief Cedges() - create a new Cedges with null value
	*
	*\brief Purpose:
	*       create a new Cedges with null value
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cedges();

	/*!
	* Cedges(const Cedges &edgeToCopy) - create a new Cedges with the value of another edge
	*
	*\brief Purpose:
	*       create a new Cedges with the value of another edge
	*
	*@param
	*       const Cedges &	edgeToCopy	-	the edges to copy
	*
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cedges(const Cedges &edgeToCopy);

	/*!
	* Cedges(unsigned int uiId_vertex_in) - create a new Cedges with the param
	*
	*\brief Purpose:
	*       create a new Cedges with the param
	*
	*@param
	*       unsigned int	uiId_vertex_in	-	the id of the vertex
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cedges(unsigned int uiId_vertex_in);

	/*!
	* ~Cedges() - delete correctly a Cedges
	*
	*\brief Purpose:
	*       delete correctly a Cedges
	*
	*@param
	*       const Cedges &	edgeToCopy	-	the edges to copy
	*
	*@return
	*		none
	*
	*******************************************************************************/
	~Cedges();

	/*!
	* EDGset_id_vertex_in(unsigned int uiId_vertex_in) - set the id of the vertex of the Cedges
	*
	*\brief Purpose:
	*       set the id of the vertex of the Cedges
	*
	*@param
	*       unsigned int	uiId_vertex_in	the id to set
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void EDGset_id_vertex_in(unsigned int uiId_vertex_in);

	/*!
	* EDGget_id_vertex_in(unsigned int uiId_vertex_in) - get the id of the vertex of the Cedges
	*
	*\brief Purpose:
	*       get the id of the vertex of the Cedges
	*
	*@param
	*       none
	*
	*@return
	*		unsigned int	-	the id of the vertex of the Cedges
	*
	*******************************************************************************/
	unsigned int EDGget_id_vertex_in();

	/*!
	* Cedges &Cedges::operator=(const Cedges &edgeToCopy) - set the id of the vertex of the Cedges
	*
	*\brief Purpose:
	*       set the id of the vertex of the Cedges
	*
	*@param
	*       const Cedges &	edgeToCopy	-	the edge to copy
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cedges &operator=(const Cedges &edgeToCopy);

	/*!
	* operator==(Cedges &edgeToCompare) - compare two Cedges
	*
	*\brief Purpose:
	*       compare two Cedges
	*
	*@param
	*       Cedges &	edgeToCompare	-	the edge to compare
	*
	*@return
	*		bool	-	true if the two Cedges are equal, false otherwise
	*
	*******************************************************************************/
	bool operator==(Cedges &edgeToCompare);


	/*!
	* bool operator!=(Cedges &edgeToCompare);
	*
	*\brief Purpose:
	*       compare two Cedges
	*
	*@param
	*       Cedges &	edgeToCompare	-	the edge to compare
	*
	*@return
	*		bool	-	false if the two Cedges are equal, true otherwise
	*
	*******************************************************************************/
	bool operator!=(Cedges &edgeToCompare);

};

#endif
