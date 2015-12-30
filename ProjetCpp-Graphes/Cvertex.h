/**
* @file Cvertex.h
*
* \author Mathieu Boutolleau & Paul Fayoux
*
*
*/
#pragma once
#include "stdafx.h"

#ifndef PROJETCPP2_CVERTEX_H
#define PROJETCPP2_CVERTEX_H
#define ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL 20
#define ERROR_DIFFERENTS_SIZE_IN_PARAMS 21
#define ERROR_LIST_NOT_NULL 22

//! Cvertex Class
class Cvertex
{
private:
	unsigned int uiVERid_vertex;

	Cedges ** ppVERlist_edges_out;

	Cedges ** ppVERlist_edges_in;

	unsigned int uiVERnb_edges_in;

	unsigned int uiVERnb_edges_out;


public:

	/*!
	* Cvertex() - allocate a new Cvertex and initialize it
	*
	*
	*\brief Purpose:
	*       allocate a new Cvertex and initialize it with null value
	*
	*@param none
	*
	*@return none
	*
	*******************************************************************************/
	Cvertex();

	/*!
	* Cvertex() - create a new Cvertex with the value of another one
	*
	*\brief Purpose:
	*       create a new Cvertex with the value of another one
	*
	*@param const Cvertex & vertex_to_copy  - the Cvertex to copy, if NULL do the same as default constructor
	*
	*@return none
	*
	*******************************************************************************/
	Cvertex(const Cvertex &vertex_to_copy);

	/*!
	* Cvertex() - create a new Cvertex with the value in parameters
	*
	*\brief Purpose:
	*       create a new Cvertex with the value in parameters
	*		ppList_edges_out, ppList_edges_in need to have a correct number of edge respectively in uiNb_edges_out, uiNb_edges_in
	*
	*@param      unsigned	int uiId_vertex		- the id of the vertex
	*@param		Cedges **	ppList_edges_out	- the list of edges who go out the vertex
	*@param		Cedges **	ppList_edges_in		- the list of edges who go in the vertex
	*@param		unsigned	int uiNb_edges_out	- number of edges who go out the vertex
	*@param		unsigned	int uiNb_edges_in	- number of edges who go in the vertex
	*
	*@return	none
	*
	*\throws	ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL	-	if one of the list in parameter is NULL and the number of edges associated is not 0
	*\throws	ERROR_LIST_NOT_NULL					-	if one of the list in parameter is not NULL and the number of edges associated is 0
	*
	*******************************************************************************/
	Cvertex(unsigned int uiId_vertex, Cedges** ppList_edges_out, Cedges** ppList_edges_in, unsigned int uiNb_edges_out, unsigned int uiNb_edges_in)throw (Cexception);
	
	/*!
	* ~Cvertex() - destroy a Cvertex correctly
	*
	*\brief Purpose:
	*       destroy a Cvertex correctly
	*
	*@param		none
	*
	*@return	none
	*
	*******************************************************************************/
	~Cvertex();

	/*!
	* VERset_id_vertex(unsigned int uiId) - set the id of a vertex
	*
	*\brief Purpose:
	*       set the id of a vertex
	*
	*@param		unsigned	int uiId	-	the id of the vertex
	*
	*@return	none
	*
	*******************************************************************************/
	void VERset_id_vertex(unsigned int uiId);

	/*!
	* VERset_list_edges_out(Cedges** ppList_edges_out, unsigned int uiNb_edges_out) - set the list of edge who go out the vertex
	*
	*\brief Purpose:
	*       set the list of edge who go out the vertex
	*		ppList_edges_out need to have a correct number of edge uiNb_edges_out
	*
	*@param		Cedges **	ppList_edges_out	- the list of edges who go out the vertex
	*@param		unsigned	int uiNb_edges_out	- number of edges who go out the vertex
	*
	*@return	none
	*
	*	rows
	*		ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL	-	if the list in parameter is NULL and the number of edges associated is not 0
	*		ERROR_LIST_NOT_NULL					-	if the list in parameter is not NULL and the number of edges associated is 0
	*
	*******************************************************************************/
	void VERset_list_edges_out(Cedges ** ppList_edges_out, unsigned int uiNb_edges_out)throw (Cexception);

	/*!
	* VERset_list_edges_in(Cedges** ppList_edges_in, unsigned int uiNb_edges_in) - set the list of edge who go in the vertex
	*
	*\brief Purpose:
	*       set the list of edge who go in of the vertex
	*		ppList_edges_in need to have a correct number of edge uiNb_edges_in
	*
	*@param	Cedges **	ppList_edges_in	- the list of edges who go in the vertex
	*@param	unsigned	int uiNb_edges_in	- number of edges who go in the vertex
	*
	*@return
	*		none
	*
	*\throws
	*		ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL	-	if the list in parameter is NULL and the number of edges associated is not 0
	*		ERROR_LIST_NOT_NULL					-	if the list in parameter is not NULL and the number of edges associated is 0
	*
	*******************************************************************************/
	void VERset_list_edges_in(Cedges ** ppList_edges_in, unsigned int uiNb_edges_in)throw (Cexception);

	/*!
	* VERadd_edge_to_list_edges_out(Cedges * pEdge_to_add) - add an edge to the list of edge who go out the vertex
	*
	*\brief Purpose:
	*       add an edge to the list of edge who go out the vertex
	*		if the edge is already in the list it's not added
	*
	*@param		Cedges *	 pEdge_to_add	- the edge to add to the list
	*
	*@return	unsigned int	-	the position of the edge in the list
	*
	*******************************************************************************/
	unsigned int VERadd_edge_to_list_edges_out(Cedges * pEdge_to_add);

	/*!
	* VERadd_edge_to_list_edges_in(Cedges * pEdge_to_add) - add an edge to the list of edge who go in the vertex
	*
	*\brief Purpose:
	*       add an edge to the list of edge who go in the vertex
	*		if the edge is already in the list it's not added
	*
	*@param Cedges *	 pEdge_to_add	- the edge to add to the list
	*
	*@return unsigned int	-	the position of the edge in the list
	*
	*******************************************************************************/
	unsigned int VERadd_edge_to_list_edges_in(Cedges * pEdge_to_add);

	/*!
	* VERremove_edge_from_list_edges_out(unsigned int uiId_vertex_out_edge_to_delete) - remove an edge of the list of edge who go out the vertex
	*
	*\brief Purpose:
	*       remove an edge of the list of edge who go out the vertex
	*		if the edge is not in the list that return NULL
	*
	*@param unsigned int	uiId_vertex_out_edge_to_delete	-	the Id of the vertex in the edge
	*
	*@return Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
	*
	*******************************************************************************/
	Cedges * VERremove_edge_from_list_edges_out(unsigned int uiId_vertex_out_edge_to_delete);

	/*!
	* VERremove_edge_from_list_edges_in(unsigned int uiId_vertex_in_edge_to_delete) - remove an edge of the list of edge who go in the vertex
	*
	*\brief Purpose:
	*       remove an edge of the list of edge who go in the vertex
	*		if the edge is not in the list that return NULL
	*
	*@param unsigned int	uiId_vertex_out_edge_to_delete	-	the Id of the vertex in the edge
	*
	*@return Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
	*
	*******************************************************************************/
	Cedges * VERremove_edge_from_list_edges_in(unsigned int uiId_vertex_out_edge_to_delete);

	/*!
	* VERremove_edge_from_list_edges_out(unsigned int uiId_vertex_out_edge_to_delete) - remove an edge of the list of edge who go out the vertex
	*
	*\brief Purpose:
	*       remove an edge of the list of edge who go out the vertex
	*		if the edge is not in the list that return NULL
	*
	*@param Cedges *	pEdge_to_delete	-	pointer on the Cedges to remove (this pointer don't need to be a pointer on the Cedges in the graph, but can be a copy of the Cedges)
	*
	*@return Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
	*
	*******************************************************************************/
	Cedges * VERremove_edge_from_list_edges_out(Cedges * pEdge_to_delete);

	/*!
	* VERremove_edge_from_list_edges_in(unsigned int uiId_vertex_in_edge_to_delete) - remove an edge of the list of edge who go in the vertex
	*
	*\brief Purpose:
	*       remove an edge of the list of edge who go in the vertex
	*		if the edge is not in the list that return NULL
	*
	*@param Cedges *	pEdge_to_delete	-	pointer on the Cedges to remove (this pointer don't need to be a pointer on the Cedges in the graph, but can be a copy of the Cedges)
	*
	*@return Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
	*
	*******************************************************************************/
	Cedges * VERremove_edge_from_list_edges_in(Cedges * pEdge_to_delete);

	/*!
	* VERfind_index_in_list_edge_out(Cedges * pEdge_to_find) - find the index of a Cedges in the list of edge who go out of the vertex
	*
	*\brief Purpose:
	*       find the index of a Cedges in the list of edge who go out of the vertex
	*
	*@param Cedges *	pEdge_to_find		- pointer on the edge to search
	*
	*@return unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
	*
	*
	*******************************************************************************/
	unsigned int VERfind_index_in_list_edge_out(Cedges * pEdge_to_find);

	/*!
	* VERfind_index_in_list_edge_in(Cedges * pEdge_to_find) - find the index of a Cedges in the list of edge who go in of the vertex
	*
	*\brief Purpose:
	*       find the index of a Cedges in the list of edge who go in of the vertex
	*
	*@param Cedges *	pEdge_to_find		- pointer on the edge to search
	*
	*@return unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
	*
	*
	*******************************************************************************/
	unsigned int VERfind_index_in_list_edge_in(Cedges * pEdge_to_find);

	/*!
	* VERfind_index_in_list_edge_out(unsigned int uiId_vertex_out_edge_to_find) - find the index of a Cedges in the list of edge who go out of the vertex
	*
	*\brief Purpose:
	*       find the index of a Cedges in the list of edge who go out of the vertex
	*
	*@param unsigned int	uiId_vertex_out_edge_to_find	- id of the vertex inside the edge to search
	*
	*@return unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
	*
	*
	*******************************************************************************/
	unsigned int VERfind_index_in_list_edge_out(unsigned int uiId_vertex_out_edge_to_find);

	/*!
	* VERfind_index_in_list_edge_in(unsigned int uiId_vertex_out_edge_to_find) - find the index of a Cedges in the list of edge who go in of the vertex
	*
	*\brief Purpose:
	*       find the index of a Cedges in the list of edge who go out of the vertex
	*
	*@param unsigned int	uiId_vertex_out_edge_to_find	- id of the vertex inside the edge to search
	*
	*@return unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
	*
	*
	*******************************************************************************/
	unsigned int VERfind_index_in_list_edge_in(unsigned int uiId_vertex_out_edge_to_find);

	/*!
	* VERget_id_vertex() - get the id of the vertex
	*
	*\brief Purpose:
	*       get the id of the vertex
	*
	*@param none
	*
	*@return unsigned in	-	the id of the vertex
	*
	*
	*******************************************************************************/
	unsigned int VERget_id_vertex();

	/*!
	* VERget_list_edges_out() - get the list of the edge who go out the vertex
	*
	*\brief Purpose:
	*       get the list of the edge who go out the vertex
	*
	*@param none
	*@return Cedges**	-	the list of edges
	*
	*
	*******************************************************************************/
	Cedges** VERget_list_edges_out();

	/*!
	* VERget_list_edges_out() - get the list of the edge who go in the vertex
	*
	*\brief Purpose:
	*       get the list of the edge who go in the vertex
	*
	*@return Cedges**	-	the list of edges
	*
	*
	*******************************************************************************/
	Cedges** VERget_list_edges_in();

	/*!
	* VERget_nb_edges_out() - get the number of edges who go out the vertex
	*
	*\brief Purpose:
	*       get the number of edges who go out the vertex
	*
	*@param
	*		Cedges *	pEdge_to_find		- the edge to search
	*
	*@return unsigned in	-	the number of edges of the list
	*
	*
	*******************************************************************************/
	unsigned int VERget_nb_edges_out();

	/*!
	* VERget_nb_edges_out() - get the number of edges who go in the vertex
	*
	*\brief Purpose:
	*       get the number of edges who go in the vertex
	*
	*@param Cedges *	pEdge_to_find		- the edge to search
	*
	*@return unsigned in	-	the number of edges of the list
	*
	*
	*******************************************************************************/
	unsigned int VERget_nb_edges_in();

	unsigned int * VERget_pred_succ();

	bool VERis_vertex_equivalent(Cvertex * pVertexToCompare);

	/*!
	* operator=(const Cvertex &vertex_to_copy) - equal operator
	*
	*\brief Purpose:
	*       enable the affectation of a Cvertex by another.
	*
	*@param const Cvertex &	vertex_to_copy	- the Cvertex to copy
	*
	*@return Cvertex  &	-	change the values of the object who call the operator
	*
	*******************************************************************************/
	Cvertex &operator=(const Cvertex &vertexToCopy);

	/*!
	* operator==(const Cvertex &vertex_to_copy) - compare two Cvertex
	*
	*\brief Purpose:
	*       compare two Cvertex
	*
	*@param Cvertex &	vertexToCompare	- the Cvertex to compare
	*
	*@return bool	-	true if the two Cvertex are equal (in term of value not address), false if they are differents.
	*
	*******************************************************************************/
	bool operator==(Cvertex &vertexToCompare);

	/*!
	* operator!=(const Cvertex &vertex_to_copy) - compare two Cvertex
	*
	*\brief Purpose:
	*       compare two Cvertex
	*
	*@param Cvertex &	vertexToCompare	- the Cvertex to compare
	*
	*@return bool	-	false if the two Cvertex are equal (in term of value not address), true if they are differents.
	*
	*******************************************************************************/
	bool operator!=(Cvertex &vertexToCompare);
};
#endif