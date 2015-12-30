/**
 * @file Cgraph.h
 *
 * \author Mathieu Boutolleau & Paul Fayoux
 *
 * 
 */

#pragma once
#include "stdafx.h"
#ifndef PROJETCPP2_CGRAPH_H 
#define PROJETCPP2_CGRAPH_H

#define ERROR_INDEX_OUT_OF_BOUND 30
#define ERROR_NULL_POINTER 31
#define ERROR_UNEXPECTED_TOKEN_READ 32

//! Cgraph Class

class Cgraph
{
private:

	Cvertex** ppGRAlist_vertex;

	unsigned int uiGRAnb_vertex;


public:

	/*!
	* Cgraph() - create a new Cgraph with null value
	*
	*\brief Purpose:
	*       create a new Cgraph with null value
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph();

	/*!
	* Cgraph(Cvertex** ppList_vertex, unsigned int uiNb_vertex) - create a new Cgraph with param values
	*
	*\brief Purpose:
	*       create a new Cgraph with param values
	*
	*@param
	*       Cvertex**	ppList_vertex	-	the list of vertex to set
	*		unsigned	int uiNb_vertex	-	the number of vertex in the list
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph(Cvertex** ppList_vertex, unsigned int uiNb_vertex);

	/*!
	* Cgraph(const char* pcFile_to_import) - create a new Cgraph with the content of a file
	*
	*\brief Purpose:
	*       create a new Cgraph with the content of a file
	*
	*@param
	*       const char*		pcFile_to_import	-	the path to the file
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph(const char* pcFile_to_import)throw (Cexception);

	/*!
	* Cgraph(const Cgraph &graph_to_copy) - create a Cgraph with the value of another Cgraph
	*
	*\brief Purpose:
	*       create a Cgraph with the value of another Cgraph
	*
	*@param
	*       const Cgraph &	graph_to_copy	-	the graph to copy
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph(const Cgraph &graph_to_copy);

	/*!
	* Cgraph(const Cgraph &graph_to_copy) - create a random Cgraph under certain condition
	*
	*\brief Purpose:
	*       create a Random Cgraph with the specified number of vertex and edge could be oriented or not as wanted.
	*
	*@param
	*       unsigned int uiNb_vertex	-	the number of vertex
	*		bool bIs_oriented			-	the kind of graph oriented or not
	*
	*@return
	*		none
	*
	*******************************************************************************/
	explicit Cgraph(unsigned int uiNb_vertex, bool bIs_oriented, unsigned int iNb_edges);

	/*!
	* Cgraph~() - delete a Cgraph correctly
	*
	*\brief Purpose:
	*       delete a Cgraph correctly
	*
	*@param
	*       const Cgraph &	graph_to_copy	-	the graph to copy
	*
	*@return
	*		none
	*
	*******************************************************************************/

	~Cgraph();

	/*!
	* GRAget_nb_vertex() - get the number of vertex of the graph
	*
	*\brief Purpose:
	*       get the number of vertex of the graph
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	unsigned int GRAget_nb_vertex();

	/*!
	* GRAget_nb_edges() - get the number of edges of the graph
	*
	*\brief Purpose:
	*       get the number of edges of the graph
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	unsigned int GRAget_nb_edges();

	/*!
	* GRAget_vertices() - get the list of vertex of the graph
	*
	*\brief Purpose:
	*       get the list of vertex of the graph
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cvertex** GRAget_vertices();

	/*!
	* GRAget_index_vertex(unsigned int uiId_vertex) - get the index of the vertex in the list of the graph
	*
	*\brief Purpose:
	*       get the index of the vertex designed by the uiId_vertex in the list of the graph
	*
	*@param
	*       unsigned int	uiId_vertex	-	the id of the vertex to find
	*
	*@return
	*		unsigned int	-	if the vertex is in the graph return his own index in the list of vertex, otherwise return the maximun number who can be set in an unsigned int
	*
	*******************************************************************************/
	unsigned int GRAget_index_vertex(unsigned int uiId_vertex);

	/*!
	* GRAget_index_vertex(Cvertex * pVertex) - get the index of the vertex in the list of the graph
	*
	*\brief Purpose:
	*       get the index of the vertex pointed by pVertex in the list of the graph
	*
	*@param
	*       Cvertex *	pVertex	-	a pointer on a Vertex to find
	*
	*@return
	*		unsigned int	-	if the vertex is in the graph return his own index in the list of vertex, otherwise return the maximun number who can be set in an unsigned int
	*
	*******************************************************************************/
	unsigned int GRAget_index_vertex(Cvertex * pVertex);

	/*!
	* GRAget_vertex(unsigned int uiIndex_vertex) - get the vertex at the index in param
	*
	*\brief Purpose:
	*       get the vertex at the index in param
	*
	*@param
	*       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to get
	*
	*@return
	*		Cvertex *	-	the vertex
	*
	*\throws	throw an exception if the index is higher than the number of vertex in the graph
	*
	*
	*******************************************************************************/
	Cvertex * GRAget_vertex(unsigned int uiId_vertex) throw (Cexception);


	/*!
	* GRAget_vertex(unsigned int uiIndex_vertex) - get the vertex at the id in param
	*
	*\brief Purpose:
	*       get the vertex at the id in param
	*
	*@param
	*       unsigned int	uiVertex_id	-	the id of the vertex
	*
	*@return
	*		Cvertex *	-	the vertex
	*
	*******************************************************************************/
	Cvertex * GRAget_vertex_from_vertex_id(unsigned int uiVertex_id);

	/*!
	* GRAadd_vertex(Cvertex* pVertex) - add a vertex to the graph
	*
	*\brief Purpose:
	*       add a vertex to the graph (if the vertex is already there it's not added, but it's position is returned)
	*
	*@param
	*       Cvertex*	pVertex	-	the vertex to add
	*
	*@return
	*		unsigned int	-	the position of the vertex
	*
	*******************************************************************************/

	

	unsigned int GRAadd_vertex(Cvertex* pVertex);

	/*!
	* GRAremove_vertex_from_index(unsigned int uiIndex_vertex) - remove a vertex of the graph
	*
	*\brief Purpose:
	*       remove a vertex of the graph
	*
	*@param
	*       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to delete
	*
	*@return
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*\throws
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*
	*******************************************************************************/
	Cvertex* GRAremove_vertex_from_vertex_id(unsigned int uiId_vertex);

	/*!
	*GRAremove_vertex_from_vertex_id(unsigned int uiId_vertex) - remove a vertex of the graph
	*
	*\brief Purpose:
	*       remove a vertex of the graph
	*
	*@param
	*       unsigned int	uiId_vertex	-	the id of the vertex to delete
	*
	*@return
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*\throws
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*
	*******************************************************************************/
	void GRAremove_vertex_from_index(unsigned int uiIndex_vertex)throw (Cexception);

	/*!
	*GRAupdate_vertex_from_index(unsigned int uiIndex_vertex, Cvertex* pCvertex) - update a vertex of the graph
	*
	*\brief Purpose:
	*       update a vertex of the graph
	*
	*@param
	*       unsigned int	uiIndex_vertex	-	the index (in the list in the graph) of the vertex to update
	*		Cvertex*		pCvertex		-	a pointer on the vertex to set
	*
	*@return
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*\throws
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*		Throw an exception if the pCvertex is NULL
	*
	*******************************************************************************/
	void GRAupdate_vertex_from_index(unsigned int uiIndex_vertex, Cvertex* pVertex);

	/*!
	*GRAupdate_vertex_from_vertex_id(unsigned int uiId_vertex, Cvertex* pVertex) - update a vertex of the graph
	*
	*\brief Purpose:
	*       update a vertex of the graph
	*
	*@param
	*       unsigned int	uiIndex_vertex	-	the id of the vertex to update
	*		Cvertex*		pCvertex		-	a pointer on the vertex to set
	*
	*@return
	*		Cvertex *	-	a pointer to the Cvertex who has been removed
	*
	*\throws
	*		Throw an exception if the index is out of the range of number of edge in the graph
	*		Throw an exception if the pCvertex is NULL
	*
	*******************************************************************************/
	void GRAupdate_vertex_from_vertex_id(unsigned int uiId_vertex, Cvertex* pVertex);


	/*!
	*void Cgraph::GRAprint() - print to screen the graph
	*
	*\brief Purpose:
	*       print to screen the graph
	*
	*@param
	*		none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRAprint();


	/*!
	*void Cgraph::GRAprint(char * pOption) - print to screen the graph
	*
	*\brief Purpose:
	*       print to screen the graph, you can use option to have different view.
	*
	*@param
	*		char *	pOption	-	The string containing option to use.
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRAprint(char * pOption);

	/*!
	*GRAremove_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) - remove an edge in the graph
	*
	*\brief Purpose:
	*       remove an edge in the graph
	*
	*@param
	*		unsigned int	uiIndex_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge
	*
	*@return
	*		none
	*
	*\throws
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAremove_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in)throw (Cexception);

	/*!
	*GRAupdate_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) - update an edge in the graph
	*
	*\brief Purpose:
	*       update an edge in the graph
	*
	*@param
	*		unsigned int uiIndex_vertex_out		-	the index (in the list of the graph) of the vertex in entry of the edge to be remove
	*		unsigned int uiIndex_vertex_in		-	the index (in the list of the graph) of the vertex in exit of the edge to be remove
	*		unsigned int uiIndex_new_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge to be add
	*		unsigned int uiIndex_new_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge to be add
	*
	*@return
	*		none
	*
	*\throws
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAupdate_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in);

	/*!
	*GRAadd_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) - add an edge in the graph
	*
	*\brief Purpose:
	*       add an edge in the graph
	*
	*@param
	*		unsigned int	uiIndex_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge
	*
	*@return
	*		bool	-	a boolean if the edge was already there
	*
	*\throws
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	bool GRAadd_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in);

	/*!
	*GRAremove_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) - remove an edge in the graph
	*
	*\brief Purpose:
	*       remove an edge in the graph
	*
	*@param
	*		unsigned int	uiIndex_vertex_out	-	the id of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the id of the vertex in exit of the edge
	*
	*@return
	*		none
	*
	*\throws
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAremove_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in);

	/*!
	*GRAupdate_edge_from_vertex_id(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) - update an edge in the graph
	*
	*\brief Purpose:
	*       update an edge in the graph
	*
	*@param
	*		unsigned int uiIndex_vertex_out		-	the id of the vertex in entry of the edge to be remove
	*		unsigned int uiIndex_vertex_in		-	the id of the vertex in exit of the edge to be remove
	*		unsigned int uiIndex_new_vertex_out	-	the id of the vertex in entry of the edge to be add
	*		unsigned int uiIndex_new_vertex_in	-	the id of the vertex in exit of the edge to be add
	*
	*@return
	*		none
	*
	*\throws
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	void GRAupdate_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in, unsigned int uiId_new_vertex_out, unsigned int uiId_new_vertex_in);

	/*!
	*GRAadd_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) - add an edge in the graph
	*
	*\brief Purpose:
	*       add an edge in the graph
	*
	*@param
	*		unsigned int	uiIndex_vertex_out	-	the id of the vertex in entry of the edge
	*		unsigned int	uiIndex_vertex_in	-	the id of the vertex in exit of the edge
	*
	*@return
	*		bool	-	a boolean if the edge was already there
	*
	*\throws
	*		Throw an error if the value of the index are out of range of number of edge
	*
	*******************************************************************************/
	bool GRAadd_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in);

	/*!
	*GRAinvert_all_edges()	- invert all edges in the graph
	*
	*\brief Purpose:
	*       invert all edges in the graph
	*
	*@param
	*		none
	*
	*@return
	*		Cgraph *	-	a new graph who is exactly the inverse of the original graph
	*
	*******************************************************************************/
	Cgraph * GRAinvert_all_edges();

	/*!
	*GRAdelete_vertex_pointed_by(unsigned int uiVertex_id) - delete the vertex pointed by the one in parameter
	*
	*\brief Purpose:
	*       Remove all the vertex who share a common edge goind out of the vertex who has the id in parameter. 
	*
	*@param
	*		unsigned int uiVertex_id	-	the id of the vertex who start the edge(s) 
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRAdelete_vertex_pointed_by(unsigned int uiVertex_id);

	/*!
	*void GRAdelete_vertex_who_point(unsigned int uiVertex_id) -	delete all the vertex who share an edge going to the one in parameter
	*
	*\brief Purpose:
	*		Remove all the vertex who share a common edge who point the vertex who has the id in parameter
	*
	*@param
	*		unsigned int uiVertex_id	-	the id of the vertex who end the edge(s)
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRAdelete_vertex_who_point(unsigned int uiVertex_id);

	/*!
	*void GRAorder_by_degree() -	order the vertices of the graph by their degree
	*
	*\brief Purpose:
	*		order the vertices of the graph by their degree
	*
	*@param
	*		char cOption	-	an option to chose the way to sort (increasing or decreasing)
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRAorder_by_degree(char cOption);

	/*!
	*void GRAorder_by_degree() -	order the vertices of the graph by their degree (increasing sort)
	*
	*\brief Purpose:
	*		order the vertices of the graph by their degree (increasing sort)
	*
	*@param
	*		none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRAorder_by_degree();

	/*!
	*void GRAorder_by_id() -	order the vertices of the graph by their id (increasing sort)
	*
	*\brief Purpose:
	*		order the vertices of the graph by their id (increasing sort)
	*
	*@param
	*		none
	*
	*@return
	*		none
	*
	*******************************************************************************/

	void GRAorder_by_id();

	/*!
	*void bool GRAis_graph_only_compose_of_comunity() -	verify if a graph is only composed by community
	*
	*\brief Purpose:
	*		verify if a graph is only composed by community, a community is a set of vertex who can be
	*		split into strong connexe graph. for exemple :
	*			-	a vertex alone is a community by itself
	*			-	two vertices linked by an edge are a community
	*			-	n vertices linked each one with each one by ((n-1)*n)/2 edges are a community
	*
	*		 This function works well for any graph who are undirected (one edge link two vertices no more), and directed graph (one or more edge in any direction)
	*
	*@param
	*		none
	*
	*@return
	*		none
	*
	*******************************************************************************/

	bool GRAis_graph_only_compose_of_comunity();

	/*!
	*unsigned int GRAcount_nb_edge_of_successor(unsigned int uiIndex_vertex) - Count the number of edge of the successors of a vertex
	*
	*\brief Purpose:
	*        Count the number of edge of the successors of a vertex
	*
	*@param unsigned int uiIndex_vertex	-	index of the vertex we want to look at
	*
	*@return	unsigned int	-	the number of edge of the successors
	*
	*******************************************************************************/
	unsigned int GRAcount_nb_edge_of_successor(unsigned int uiIndex_vertex);

	/*!
	*Not used !
	*
	*******************************************************************************/
	unsigned int GRAget_max_nb_edge_of_successor();

	/*!
	*operator=(const Cgraph &graph_to_copy) - set the value of a graph with equal operator
	*
	*\brief Purpose:
	*       set the value of a graph with equal operator
	*
	*@param
	*		const Cgraph &	graph_to_copy	-	the graph to copy (use to set the value)
	*
	*@return
	*		Cgraph	-	the copy of the graph
	*
	*******************************************************************************/
	Cgraph & operator=(const Cgraph &graphToCopy);

	/*!
	*operator==(Cgraph &graphToCompare) - compare two graph
	*
	*\brief Purpose:
	*       compare two graph
	*
	*@param
	*		Cgraph &	graphToCompare	-	the graph to compare
	*
	*@return
	*		true	-	if the two graph are equal
	*
	*******************************************************************************/
	bool operator==(Cgraph &graphToCompare)const;

	/*!
	*operator!=(Cgraph &graphToCompare) - compare two graph
	*
	*
	*\brief Purpose: compare two graph
	*
	*@param
	*		Cgraph &	graphToCompare	-	the graph to compare
	*
	*
	*@return
	*		true	-	if the two graphs are different
	*
	*******************************************************************************/
	bool operator!=(Cgraph &graphToCompare)const;
};
#endif
