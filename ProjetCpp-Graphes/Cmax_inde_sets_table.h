#pragma once
#include "stdafx.h"

class Cgraph_table;

class Cmax_inde_sets_table : public Cgraph_table
{

private :
	unsigned int uiMITsize_max;
public:
	/***
	* Cmax_inde_sets_table() - create a new Cmax_inde_sets_table with null value
	*
	*Purpose:
	*       create a new Cmax_inde_sets_table with null value
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	Cmax_inde_sets_table();

	/***
	* ~Cmax_inde_sets_table() - delete correctly a Cmax_inde_sets_table object
	*
	*Purpose:
	*       delete a Cmax_inde_sets_table object , it remove all independant set in the list a free the object
	*
	*Entry:
	*       none
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	~Cmax_inde_sets_table();

	/***
	* unsigned int MITget_size_max()	-	get the maximum size of the independant set
	*
	*Purpose:
	*       get the maximum size of the independant set of the list.
	*
	*Entry:
	*       none
	*
	*Return:
	*		unsigned int	-	the maximum size of the independant set
	*
	*******************************************************************************/
	unsigned int MITget_size_max();

	/***
	* void GRTempty_table() - empty the table of independant sets
	*
	*Purpose:
	*       delete all the independant sets inside the table, and set the uiMITsize_max to 0
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
	* void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
	*
	*Purpose:
	*       search all the maximum independant sets of a graph
	*
	*Entry:
	*       Cgraph * pGraph				-		a graph , to determine independant sets
	*		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
	*
	*Return:
	*		nothing
	*
	*******************************************************************************/
	void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets);
	
	void MITenum_max_inde_set2(Cgraph * pGraph, Cgraph * pIndependant_sets);
};

