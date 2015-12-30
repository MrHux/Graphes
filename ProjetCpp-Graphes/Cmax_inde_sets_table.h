/**
 * \file Cmax_inde_sets_table.h
 *
 * \author Paul Fayoux & Valerian Menin
 *
 * 
 */

#pragma once
#include "stdafx.h"

class Cgraph_table;

//! Cmax_inde_sets_table Class
class Cmax_inde_sets_table : public Cgraph_table
{

private :
	unsigned int uiMITsize_max;
public:
	/*!
	* Cmax_inde_sets_table() - create a new Cmax_inde_sets_table with null value
	*
	*\brief Purpose:
	*       create a new Cmax_inde_sets_table with null value
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	Cmax_inde_sets_table();

	/*!
	* ~Cmax_inde_sets_table() - delete correctly a Cmax_inde_sets_table object
	*
	*\brief Purpose:
	*       delete a Cmax_inde_sets_table object , it remove all independant set in the list a free the object
	*
	*@param
	*       none
	*
	*@return
	*		none
	*
	*******************************************************************************/
	~Cmax_inde_sets_table();

	/*!
	* unsigned int MITget_size_max()	-	get the maximum size of the independant set
	*
	*\brief Purpose:
	*       get the maximum size of the independant set of the list.
	*
	*@param
	*       none
	*
	*@return
	*		unsigned int	-	the maximum size of the independant set
	*
	*******************************************************************************/
	unsigned int MITget_size_max();

	/*!
	* void GRTempty_table() - empty the table of independant sets
	*
	*\brief Purpose:
	*       delete all the independant sets inside the table, and set the uiMITsize_max to 0
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
	* void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
	*
	*


	*       search all the maximum independant sets of a graph
	*
	*@param
	*       Cgraph * pGraph				-		a graph , to determine independant sets
	*		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
	*
	*@return
	*		none
	*
	*******************************************************************************/
	void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets);
	void MITenum_max_inde_set2(Cgraph * pGraph, Cgraph * pIndependant_sets);
	void MITenum_max_inde_set3(Cgraph * pGraph, Cgraph * pIndependant_sets);
	void MITenum_max_inde_set4(Cgraph * pGraph);
	void MITenum_max_inde_set5(Cgraph * pGraph);
	void MITenum_max_inde_set6(Cgraph * pGraph, unsigned int uiIndex_current_vertex);
	void MITenum_max_inde_set7(Cgraph * pGraph, unsigned int &uiNb_call);
	void MITenum_max_inde_set8(Cgraph * pGraph, Cgraph * pIndependant_sets);
	void MITenum_max_inde_set7(Cgraph * pGraph, Cgraph * pIndependant_sets);

	bool MITtest_if_solution_exist(Cgraph * pGraph_to_compare);

};

