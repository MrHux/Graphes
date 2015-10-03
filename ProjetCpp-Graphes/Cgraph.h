#pragma once
#include "stdafx.h"
#ifndef PROJETCPP2_CGRAPH_H
#define PROJETCPP2_CGRAPH_H

#define ERROR_INDEX_OUT_OF_BOUND 30
#define ERROR_NULL_POINTER 31
#define ERROR_UNEXPECTED_TOKEN_READ 32

class Cvertex;

class Cgraph
{
private:

	Cvertex** ppGRAlist_vertex;

	unsigned int uiGRAnb_vertex;


public:

	/***
	* Cgraph() - create a new Cgraph with null value
	*
	*Purpose:
	*       create a new Cgraph with null value
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph();

	/***
	* Cgraph(Cvertex** ppList_vertex, unsigned int uiNb_vertex) - create a new Cgraph with param values
	*
	*Purpose:
	*       create a new Cgraph with param values
	*
	*Entry:
	*       Cvertex**	ppList_vertex	-	the list of vertex to set
	*		unsigned	int uiNb_vertex	-	the number of vertex in the list
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph(Cvertex** ppList_vertex, unsigned int uiNb_vertex);

	/***
	* Cgraph(const char* pcFile_to_import) - create a new Cgraph with the content of a file
	*
	*Purpose:
	*       create a new Cgraph with the content of a file
	*
	*Entry:
	*       const char*		pcFile_to_import	-	the path to the file
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph(const char* pcFile_to_import) throw (Cexception);

	/***
	* Cgraph(const Cgraph &graph_to_copy) - create a Cgraph with the value of another Cgraph
	*
	*Purpose:
	*       create a Cgraph with the value of another Cgraph
	*
	*Entry:
	*       const Cgraph &	graph_to_copy	-	the graph to copy
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph(const Cgraph &graph_to_copy);

	/***
	* Cgraph~() - delete a Cgraph correctly
	*
	*Purpose:
	*       delete a Cgraph correctly
	*
	*Entry:
	*       const Cgraph &	graph_to_copy	-	the graph to copy
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	~Cgraph();

	/***
	* GRAget_nb_vertex() - get the number of vertex of the graph
	*
	*Purpose:
	*       get the number of vertex of the graph
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	unsigned int GRAget_nb_vertex();

	/***
	* GRAget_vertices() - get the list of vertex of the graph
	*
	*Purpose:
	*       get the list of vertex of the graph
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cvertex** GRAget_vertices();

	/***
	* GRAget_index_vertex(unsigned int uiId_vertex) - get the index of the vertex in the list of the graph
	*
	*Purpose:
	*       get the index of the vertex designed by the uiId_vertex in the list of the graph
	*
	*Entry:
	*       unsigned int	uiId_vertex	-	the id of the vertex to find
	*
	*Return:
	*		unsigned int	-	if the vertex is in the graph return his own index in the list of vertex, otherwise return the maximun number who can be set in an unsigned int
	*
	*******************************************************************************/
	unsigned int GRAget_index_vertex(unsigned int uiId_vertex);

	/***
	* GRAget_index_vertex(Cvertex * pVertex) - get the index of the vertex in the list of the graph
	*
	*Purpose:
	*       get the index of the vertex pointed by pVertex in the list of the graph
	*
	*Entry:
	*       Cvertex *	pVertex	-	a pointer on a Vertex to find
	*
	*Return:
	*		unsigned int	-	if the vertex is in the graph return his own index in the list of vertex, otherwise return the maximun number who can be set in an unsigned int
	*
	*******************************************************************************/
	unsigned int GRAget_index_vertex(Cvertex * pVertex) ;

	/***
	* GRAget_vertex(unsigned int uiIndex_vertex) - get the vertex at the index in param
	*
	*Purpose:
	*       get the vertex at the index in param
	*
	*Entry:
	*       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to get
	*
	*Return:
	*		Cvertex *	-	the vertex
	*
	*Throw:
	throw an exception if the index is higher than the number of vertex in the graph
	*******************************************************************************/
	Cvertex * GRAget_vertex(unsigned int uiId_vertex) throw (Cexception);


	/***
	* GRAget_vertex(unsigned int uiIndex_vertex) - get the vertex at the id in param
	*
	*Purpose:
	*       get the vertex at the id in param
	*
	*Entry:
	*       unsigned int	uiVertex_id	-	the id of the vertex
	*
	*Return:
	*		Cvertex *	-	the vertex
	*
	*******************************************************************************/
	Cvertex * GRAget_vertex_from_vertex_id(unsigned int uiVertex_id);

	/***
	* GRAadd_vertex(Cvertex* pVertex) - add a vertex to the graph
	*
	*Purpose:
	*       add a vertex to the graph (if the vertex is already there it's not added, but it's position is returned)
	*
	*Entry:
	*       Cvertex*	pVertex	-	the vertex to add
	*
	*Return:
	*		unsigned int	-	the position of the vertex
	*
	*******************************************************************************/
	unsigned int GRAadd_vertex(Cvertex* pVertex);

	/***
	* GRAremove_vertex_from_index(unsigned int uiIndex_vertex) - remove a vertex of the graph
	*
	*Purpose:
	*       remove a vertex of the graph
	*
	*Entry:
	*       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to delete
	*
	*Return:
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*Throw:
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*
	*******************************************************************************/
	Cvertex* GRAremove_vertex_from_vertex_id(unsigned int uiId_vertex);

	/***
	*GRAremove_vertex_from_vertex_id(unsigned int uiId_vertex) - remove a vertex of the graph
	*
	*Purpose:
	*       remove a vertex of the graph
	*
	*Entry:
	*       unsigned int	uiId_vertex	-	the id of the vertex to delete
	*
	*Return:
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*Throw:
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*
	*******************************************************************************/
	Cvertex* GRAremove_vertex_from_index(unsigned int uiIndex_vertex) throw (Cexception);

	/***
	*GRAupdate_vertex_from_index(unsigned int uiIndex_vertex, Cvertex* pCvertex) - update a vertex of the graph
	*
	*Purpose:
	*       update a vertex of the graph
	*
	*Entry:
	*       unsigned int	uiIndex_vertex	-	the index (in the list in the graph) of the vertex to update
	*		Cvertex*		pCvertex		-	a pointer on the vertex to set
	*
	*Return:
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*Throw:
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*		Throw an exception if the pCvertex is NULL
	*
	*******************************************************************************/
	void GRAupdate_vertex_from_index(unsigned int uiIndex_vertex, Cvertex* pVertex);

	/***
	*GRAupdate_vertex_from_vertex_id(unsigned int uiId_vertex, Cvertex* pVertex) - update a vertex of the graph
	*
	*Purpose:
	*       update a vertex of the graph
	*
	*Entry:
	*       unsigned int	uiIndex_vertex	-	the id of the vertex to update
	*		Cvertex*		pCvertex		-	a pointer on the vertex to set
	*
	*Return:
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*Throw:
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*		Throw an exception if the pCvertex is NULL
	*
	*******************************************************************************/
	void GRAupdate_vertex_from_vertex_id(unsigned int uiId_vertex, Cvertex* pVertex);

	/***
	*GRAprint() - print to screen the graph
	*
	*Purpose:
	*       print to screen the graph
	*
	*Entry:
	*		none
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	void GRAprint();

	/***
	*GRAremove_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) - remove an edge in the graph
	*
	*Purpose:
	*       remove an edge in the graph
	*
	*Entry:
	*		unsigned int	uiIndex_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge
	*
	*Return:
	*		none
	*
	*Throw:
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAremove_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) throw (Cexception);

	/***
	*GRAupdate_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) - update an edge in the graph
	*
	*Purpose:
	*       update an edge in the graph
	*
	*Entry:
	*		unsigned int uiIndex_vertex_out		-	the index (in the list of the graph) of the vertex in entry of the edge to be remove
	*		unsigned int uiIndex_vertex_in		-	the index (in the list of the graph) of the vertex in exit of the edge to be remove
	*		unsigned int uiIndex_new_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge to be add
	*		unsigned int uiIndex_new_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge to be add
	*
	*Return:
	*		none
	*
	*Throw:
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAupdate_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in);

	/***
	*GRAadd_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) - add an edge in the graph
	*
	*Purpose:
	*       add an edge in the graph
	*
	*Entry:
	*		unsigned int	uiIndex_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge
	*
	*Return:
	*		none
	*
	*Throw:
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAadd_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in);

	/***
	*GRAremove_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) - remove an edge in the graph
	*
	*Purpose:
	*       remove an edge in the graph
	*
	*Entry:
	*		unsigned int	uiIndex_vertex_out	-	the id of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the id of the vertex in exit of the edge
	*
	*Return:
	*		none
	*
	*Throw:
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAremove_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in);

	/***
	*GRAupdate_edge_from_vertex_id(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) - update an edge in the graph
	*
	*Purpose:
	*       update an edge in the graph
	*
	*Entry:
	*		unsigned int uiIndex_vertex_out		-	the id of the vertex in entry of the edge to be remove
	*		unsigned int uiIndex_vertex_in		-	the id of the vertex in exit of the edge to be remove
	*		unsigned int uiIndex_new_vertex_out	-	the id of the vertex in entry of the edge to be add
	*		unsigned int uiIndex_new_vertex_in	-	the id of the vertex in exit of the edge to be add
	*
	*Return:
	*		none
	*
	*Throw:
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAupdate_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in, unsigned int uiId_new_vertex_out, unsigned int uiId_new_vertex_in);

	/***
	*GRAadd_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) - add an edge in the graph
	*
	*Purpose:
	*       add an edge in the graph
	*
	*Entry:
	*		unsigned int	uiIndex_vertex_out	-	the id of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the id of the vertex in exit of the edge
	*
	*Return:
	*		none
	*
	*Throw:
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAadd_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in);

	/***
	*GRAinvert_all_edges()	- invert all edges in the graph
	*
	*Purpose:
	*       invert all edges in the graph
	*
	*Entry:
	*		none
	*
	*Return:
	*		Cgraph *	-	a new graph who is exactly the inverse of the original graph
	*
	*******************************************************************************/
	Cgraph * GRAinvert_all_edges();

	/***
	*GRAdelete_vertex_pointed_by(unsigned int uiVertex_id) - delete the vertex pointed by the one in parameter
	*
	*Purpose:
	*       Remove all the vertex who share a common edge goind out of the vertex who has the id in parameter. 
	*
	*Entry:
	*		unsigned int uiVertex_id	-	the id of the vertex who start the edge(s) 
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void GRAdelete_vertex_pointed_by(unsigned int uiVertex_id);

	/***
	*void GRAdelete_vertex_who_point(unsigned int uiVertex_id) -	delete all the vertex who share an edge going to the one in parameter
	*
	*Purpose:
	*		Remove all the vertex who share a common edge who point the vertex who has the id in parameter
	*
	*Entry:
	*		unsigned int uiVertex_id	-	the id of the vertex who end the edge(s)
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void GRAdelete_vertex_who_point(unsigned int uiVertex_id);

	/***
	*void GRAorder_by_degree() -	order the vertices of the graph by their degree
	*
	*Purpose:
	*		order the vertices of the graph by their degree
	*
	*Entry:
	*		none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void GRAorder_by_degree();

	/***
	*operator=(const Cgraph &graph_to_copy) - set the value of a graph with equal operator
	*
	*Purpose:
	*       set the value of a graph with equal operator
	*
	*Entry:
	*		const Cgraph &	graph_to_copy	-	the graph to copy (use to set the value)
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	Cgraph & operator=(const Cgraph &graphToCopy);

	/***
	*operator==(Cgraph &graphToCompare) - compare two graph
	*
	*Purpose:
	*       compare two graph
	*
	*Entry:
	*		Cgraph &	graphToCompare	-	the graph to compare
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	bool operator==(Cgraph &graphToCompare)const;

	/***
	*operator!=(Cgraph &graphToCompare) - compare two graph
	*
	*Purpose:
	*       compare two graph
	*
	*Entry:
	*		Cgraph &	graphToCompare	-	the graph to compare
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	bool operator!=(Cgraph &graphToCompare)const;
};
#endif
