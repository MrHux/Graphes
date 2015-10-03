#pragma once
#include "stdafx.h"
#define ERROR_REALLOCATION_MEMORY 40
class Cgraph_table
{

private:
	Cgraph ** ppGRTgraph_table;
	unsigned int uiGRTnb_graph;
public:

	/***
	* Cgraph_table() - create a new Cgraph_table with null value
	*
	*Purpose:
	*       create a new Cgraph_table with null value
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph_table();

	/***
	* Cgraph_table(const Cgraph_table & Cgraph_table_to_copy) - create a new Cgraph_table with the value of the one in parameter
	*
	*Purpose:
	*        create a new Cgraph_table with the value of the one in parameter
	*
	*Entry:
	*       const Cgraph_table & Cgraph_table_to_copy	-	the graph to copy
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph_table(const Cgraph_table & Cgraph_table_to_copy);

	/***
	* ~Cgraph_table() - delete correctly a Cgraph_table
	*
	*Purpose:
	*       delete correctly a Cgraph_table
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	~Cgraph_table();

	/***
	* void GRTempty_table() - remove all the Graph in the Cgraph_table
	*
	*Purpose:
	*       remove all the Graph in the Cgraph_table
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void GRTempty_table();

	/***
	* Cgraph * GRTget_graph_table() - get the table of graph at the index
	*
	*Purpose:
	*		get the table of graph
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph ** GRTget_graph_table();

	/***
	* Cgraph * GRTget_graph(unsigned int uiIndex) - get the graph at the index 
	*
	*Purpose:
	*		get the graph at the index in the table
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cgraph * GRTget_graph(unsigned int uiIndex);

	/***
	* unsigned int GRTget_nb_graph() -	get the number of graph in the table
	*
	*Purpose:
	*       get the number of graph in the table
	*
	*Entry:
	*       unsigned int uiIndex	-	the index of the graph to get
	*
	*Return:
	*		unsigned int	-	the number of graph
	*
	*******************************************************************************/
	unsigned int GRTget_nb_graph();

	/***
	* void GRTadd_graph(Cgraph * pGraph) - add a graph to the table
	*
	*Purpose:
	*       add a graph to the table
	*
	*Entry:
	*       Cgraph * pGraph	-	the graph to add
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void GRTadd_graph(Cgraph * pGraph);

	/*delete graph at index, insert graph, modify graph, etc are function not essential for the purpose of the project but are function who could be interesting to add for that class*/

	/***
	* Cgraph * Cgraph_table::GRT_delete_graph_at_index(unsigned int uiIndex) - delete a graph at the specified position
	*
	*Purpose:
	*       delete a graph at the specified position
	*
	*Entry:
	*		unsigned int uiIndex	-	index of the graph to be removed
	*
	*Return:
	*		Cgraph *	-	the graph who will be removed
	*
	*Throw:
	*		Throw an exception if index is outofbound
	*
	*******************************************************************************/
	Cgraph * GRT_delete_graph_at_index(unsigned int uiIndex);

	/***
	* void Cgraph_table::GRT_insert_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add) - insert a graph at the position in parameter
	*
	*Purpose:
	*       insert a graph at the position in parameter
	*
	*Entry:
	*		unsigned int uiIndex	-	index of the graph to be inserted
	*		Cgraph * pGraph	-	graph to set
	*
	*Return:
	*		Cgraph *	-	the graph who will be removed
	*
	*Throw:
	*		Throw an exception if index is outofbound
	*
	*******************************************************************************/
	void GRT_insert_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add);

	/***
	* Cgraph * Cgraph_table::GRT_replace_graph_at_index(unsigned int uiIndex, Cgraph * pGraph) - replace the graph at the index by the one in parameter
	*
	*Purpose:
	*       replace the graph at the index by the one in parameter
	*
	*Entry:
	*		unsigned int uiIndex	-	index of the graph to be replaced
	*		Cgraph * pGraph	-	graph to set
	*
	*Return:
	*		Cgraph *	-	the graph who will be removed, null if the index is outofbound
	*
	*******************************************************************************/
	Cgraph * GRT_replace_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add);

	/***
	* void GRTprint() - print the independant sets
	*
	*Purpose:
	*       print the independant sets
	*
	*Entry:
	* none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/

	void GRTprint();

	/***
	*Cgraph & Cgraph_table::operator=(const Cgraph &graph_to_copy) - set the value of a graph table with equal operator
	*
	*Purpose:
	*       set the value of a graph table with equal operator
	*
	*Entry:
	*		const Cgraph &	graph_table_to_copy	-	the graph table to copy (use to set the value)
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	Cgraph_table & operator=(const Cgraph_table &graph_table_to_copy);

	/***
	*bool Cgraph_table::operator==(Cgraph &graphToCompare)const - compare two graph table
	*
	*Purpose:
	*       compare two graph table
	*
	*Entry:
	*		Cgraph_table &	graph_table_to_compare	-	the graph table to compare
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	bool operator==(Cgraph_table &graph_table_to_compare)const;

	/***
	*bool Cgraph_table::operator!=(Cgraph &graphToCompare)const - compare two graph table
	*
	*Purpose:
	*       compare two graph table
	*
	*Entry:
	*		Cgraph_table &	graph_table_to_compare	-	the graph table to compare
	*
	*Return:
	*		none
	*
	*******************************************************************************/
	bool operator!=(Cgraph_table &graph_table_to_compare)const;



};

