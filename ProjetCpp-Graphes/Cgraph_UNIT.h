/**
* @file Cgraph_UNIT.h
*
* \author Mathieu Boutolleau & Paul Fayoux
*
*
*/

#pragma once
#ifndef NDEBUG
#include "stdafx.h"
#ifndef PROJETCPP2_CGRAPH_UNIT_H
#define PROJETCPP2_CGRAPH_UNIT_H


//! Cgraph_UNIT Class
class Cgraph_UNIT
{
public:
	
	static void TEST_UNIT_Cgraph();

	static void TEST_UNIT_GRAinvert_all_edges();

	static void TEST_UNIT_GRAorder_by_degree();

	static void TEST_UNIT_GRAdelete_vertex_pointed_by();
	
	static void TEST_UNIT_GRAdelete_vertex_who_point();

	static void TEST_UNIT_GRAis_graph_only_compose_of_comunity();

	static void TEST_UNIT_GRAcount_nb_edge_of_successor();

	static void TEST_UNIT_GRAget_max_nb_edge_of_successor();
};
#endif
#endif
