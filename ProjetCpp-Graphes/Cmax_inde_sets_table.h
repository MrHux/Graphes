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

class Cmax_inde_sets_table : public Cgraph_table {
private:
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

    /***
     * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
     *
     *Purpose:
     *       search all the maximum independant sets of a graph
     *		This method begin to search a solution by taking the vertex who as the less edges.
     *
     *Entry:
     *       Cgraph * pGraph				-		a graph , to determine independant sets
     *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
     *
     *Return:
     *		nothing
     *
     *******************************************************************************/
    void MITenum_max_inde_set2(Cgraph * pGraph, Cgraph * pIndependant_sets);

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
    void MITenum_max_inde_set3(Cgraph * pGraph, Cgraph * pIndependant_sets);

    /***
     * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
     *
     *Purpose:
     *       search the Stable maximum of a graph, by removing the vertex with the higher number of egdes until there are only :
     * 	- vertices who are not connected to other vertex
     * 	- group of vertices connected to each other
     *
     *Entry:
     *
     *       Cgraph * pGraph				-		a graph , to determine independant sets
     *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
     *
     *Return:
     *		nothing
     *******************************************************************************/
    void MITenum_max_inde_set4(Cgraph * pGraph);


    /***
     * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - Heuristic that search ONE maximum independant set of a graph
     *
     *Purpose:
     *       search ONE maximum independant set of a graph
     *
     *Entry:
     *       Cgraph * pGraph				-		a graph , to determine independant sets
     *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
     *
     *Return:
     *		nothing
     *
     *******************************************************************************/
    void MITenum_max_inde_set5(Cgraph * pGraph, Cgraph * pIndependant_sets);

    /***
     * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
     *
     *Purpose:
     *       search the Stable maximum of a graph, by enumering all the combinations
     *
     *Entry:
     *       Cgraph * pGraph				-		a graph , to determine independant sets
     *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
     *
     *Return:
     *		nothing
     *
     *******************************************************************************/
    void MITenum_max_inde_set6(Cgraph * pGraph, unsigned int uiIndex_current_vertex);
    /***
     * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
     *
     *Purpose:
     *       search the Stable maximum of a graph, DIVIDE TO CONQUER
     *
     *Entry:
     *       Cgraph * pGraph				-		a graph , to determine independant sets
     *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
     *
     *Return:
     *		nothing
     *
     *******************************************************************************/
    void MITenum_max_inde_set8(Cgraph * pGraph, Cgraph * pIndependant_sets);
    /***
     * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
     *
     *Purpose:
     *       search the Stable maximum of a graph
     *
     *Entry:
     *       Cgraph * pGraph				-		a graph , to determine independant sets
     *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
     *
     *Return:
     *		nothing            
     *
     *******************************************************************************/
    void MITenum_max_inde_set7(Cgraph * pGraph);

    /***
     *bool MITtest_if_solution_exist(Cgraph * pGraph_to_compare) - test if the solution is already present in the table of stable
     *
     *Purpose:
     *       test if the solution is already present in the table of stable
     *
     *Entry:
     *       Cgraph * pGraph_to_compare -   the solution to find
     *
     *Return:
     *      bool    True if the solution is found in the table  , false either   
     *
     *******************************************************************************/
    bool MITtest_if_solution_exist(Cgraph * pGraph_to_compare);

};

