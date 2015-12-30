/**
* @file Cgraph_table.h
*
* \author Paul Fayoux
*
*
*/

#pragma once
#include "stdafx.h"
#define ERROR_REALLOCATION_MEMORY 40

//! Cgraph_table Class
class Cgraph_table
{

private:
	Cgraph ** ppGRTgraph_table;
	unsigned int uiGRTnb_graph;
public:

	/*!
	* Cgraph_table() - create a new Cgraph_table with null value
	*
	*\brief Purpose:
	*       create a new Cgraph_table with null value
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph_table();

	/*!
	* Cgraph_table(const Cgraph_table & Cgraph_table_to_copy) - create a new Cgraph_table with the value of the one in parameter
	*
	*\brief Purpose:
	*        create a new Cgraph_table with the value of the one in parameter
	*
	*@param
	*       const Cgraph_table & Cgraph_table_to_copy	-	the graph to copy
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph_table(const Cgraph_table & Cgraph_table_to_copy);

	/*!
	* ~Cgraph_table() - delete correctly a Cgraph_table
	*
	*\brief Purpose:
	*       delete correctly a Cgraph_table
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	~Cgraph_table();

	/*!
	* void GRTempty_table() - remove all the Graph in the Cgraph_table
	*
	*\brief Purpose:
	*       remove all the Graph in the Cgraph_table
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRTempty_table();

	/*!
	* Cgraph * GRTget_graph_table() - get the table of graph at the index
	*
	*\brief Purpose:
	*		get the table of graph
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph ** GRTget_graph_table();

	/*!
	* Cgraph * GRTget_graph(unsigned int uiIndex) - get the graph at the index 
	*
	*\brief Purpose:
	*		get the graph at the index in the table
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph * GRTget_graph(unsigned int uiIndex);

	/*!
	* unsigned int GRTget_nb_graph() -	get the number of graph in the table
	*
	*\brief Purpose:
	*       get the number of graph in the table
	*
	*@param
	*       unsigned int uiIndex	-	the index of the graph to get
	*
	*@return
	*		unsigned int	-	the number of graph
	*
	*******************************************************************************/
	unsigned int GRTget_nb_graph();

	/*!
	* void GRTadd_graph(Cgraph * pGraph) - add a graph to the table
	*
	*\brief Purpose:
	*       add a graph to the table
	*
	*@param
	*       Cgraph * pGraph	-	the graph to add
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void GRTadd_graph(Cgraph * pGraph);

	/*delete graph at index, insert graph, modify graph, etc are function not essential for the purpose of the project but are function who could be interesting to add for that class*/

	/*!
	* Cgraph * Cgraph_table::GRT_delete_graph_at_index(unsigned int uiIndex) - delete a graph at the specified position
	*
	*\brief Purpose:
	*       delete a graph at the specified position
	*
	*@param
	*		unsigned int uiIndex	-	index of the graph to be removed
	*
	*@return
	*		Cgraph *	-	the graph who will be removed
	*
	*\throws	Throw an exception if index is outofbound
	*
	*******************************************************************************/
	Cgraph * GRT_delete_graph_at_index(unsigned int uiIndex);

	/*!
	* void Cgraph_table::GRT_insert_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add) - insert a graph at the position in parameter
	*
	*\brief Purpose:
	*       insert a graph at the position in parameter
	*
	*@param
	*		unsigned int uiIndex	-	index of the graph to be inserted
	*		Cgraph * pGraph	-	graph to set
	*
	*@return
	*		Cgraph *	-	the graph who will be removed
	*
	*\throws
	*		Throw an exception if index is outofbound
	*
	*******************************************************************************/
	void GRT_insert_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add);

	/*!
	* Cgraph * Cgraph_table::GRT_replace_graph_at_index(unsigned int uiIndex, Cgraph * pGraph) - replace the graph at the index by the one in parameter
	*
	*\brief Purpose:
	*       replace the graph at the index by the one in parameter
	*
	*@param
	*		unsigned int uiIndex	-	index of the graph to be replaced
	*		Cgraph * pGraph	-	graph to set
	*
	*@return
	*		Cgraph *	-	the graph who will be removed, null if the index is outofbound
	*
	*******************************************************************************/
	Cgraph * GRT_replace_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add);

	/*!
	* void GRTprint() - print the independant sets
	*
	*\brief Purpose:
	*       print the independant sets
	*
	*@param
	* none
	*
	*@return
	*		none
	*
	*******************************************************************************/

	void GRTprint();

	/*!
	*Cgraph & Cgraph_table::operator=(const Cgraph &graph_to_copy) - set the value of a graph table with equal operator
	*
	*\brief Purpose:
	*       set the value of a graph table with equal operator
	*
	*@param
	*		const Cgraph &	graph_table_to_copy	-	the graph table to copy (use to set the value)
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cgraph_table & operator=(const Cgraph_table &graph_table_to_copy);

	/*!
	*bool Cgraph_table::operator==(Cgraph &graphToCompare)const - compare two graph table
	*
	*\brief Purpose:
	*       compare two graph table
	*
	*@param
	*		Cgraph_table &	graph_table_to_compare	-	the graph table to compare
	*
	*@return
	*		true	-	if the two graphe_table are equal
	*
	*******************************************************************************/
	bool operator==(Cgraph_table &graph_table_to_compare)const;

	/*!
	*bool Cgraph_table::operator!=(Cgraph &graphToCompare)const - compare two graph table
	*
	*\brief Purpose:
	*       compare two graph table
	*
	*@param
	*		Cgraph_table &	graph_table_to_compare	-	the graph table to compare
	*
	*@return
	*		true	-	if the two graph_table are different
	*
	*******************************************************************************/
	bool operator!=(Cgraph_table &graph_table_to_compare)const;



};

