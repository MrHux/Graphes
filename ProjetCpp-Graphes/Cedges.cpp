#include "stdafx.h"

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
Cedges::Cedges()
{
	uiCEDid_vertex_in = 0;
}

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
Cedges::Cedges(const Cedges &edgeToCopy)
{
	if (&edgeToCopy != NULL){
		uiCEDid_vertex_in = edgeToCopy.uiCEDid_vertex_in;
	}
	else{
		uiCEDid_vertex_in = 0;
	}
}

/***
* Cedges(unsigned int uiId_vertex_out) - create a new Cedges with the param
*
*Purpose:
*       create a new Cedges with the param
*
*Entry:
*       unsigned int	uiId_vertex_out	-	the id of the vertex
*
*Return:
*		nothing
*
*******************************************************************************/
Cedges::Cedges(unsigned int uiId_vertex_in)
{
	uiCEDid_vertex_in = uiId_vertex_in;
}

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
Cedges::~Cedges()
{
	uiCEDid_vertex_in = 0;
}

/***
* EDGset_id_vertex_out(unsigned int uiId_vertex_out) - set the id of the vertex of the Cedges
*
*Purpose:
*       set the id of the vertex of the Cedges
*
*Entry:
*       unsigned int	uiId_vertex_in	-	the id to set
*
*Return:
*		nothing
*
*******************************************************************************/
void Cedges::EDGset_id_vertex_in(unsigned int uiId_vertex_in)
{
	uiCEDid_vertex_in = uiId_vertex_in;
}

/***
* EDGget_id_vertex_out(unsigned int uiId_vertex_out) - get the id of the vertex of the Cedges
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
unsigned int Cedges::EDGget_id_vertex_in()
{
	return uiCEDid_vertex_in;
}

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
Cedges &Cedges::operator=(const Cedges &edgeToCopy){
	if (&edgeToCopy != NULL){
		uiCEDid_vertex_in = edgeToCopy.uiCEDid_vertex_in;
	}
	else{
		uiCEDid_vertex_in = 0;
	}
	return *this;
}

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
bool Cedges::operator==(Cedges &edgeToCompare){
	if (&edgeToCompare == NULL && this == NULL){
		return true;
	}
	else if (&edgeToCompare == NULL || this == NULL){
		return false;
	}
	else{
		return (uiCEDid_vertex_in == edgeToCompare.uiCEDid_vertex_in);
	}
}

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
bool Cedges::operator!=(Cedges &edgeToCompare){
	if (&edgeToCompare == NULL && this == NULL){
		return false;
	}
	else if (&edgeToCompare == NULL || this == NULL){
		return true;
	}
	else{
		return (uiCEDid_vertex_in != edgeToCompare.uiCEDid_vertex_in);
	}
}