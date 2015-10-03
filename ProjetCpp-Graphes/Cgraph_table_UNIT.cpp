#include "stdafx.h"


void Cgraph_table_UNIT::TEST_UNIT_Cgraph_table()
{

	printf("\n - UNIT_TEST constructor Cgraph_table :\n\n");
	printf("Test : initialisation of Cgraph_table \n");
	Cgraph_table * pGraph_table = new Cgraph_table();

	assert(pGraph_table->GRTget_nb_graph() == 0);
	assert(pGraph_table->GRTget_graph_table() == NULL);

	printf("Test : adding graph to the table \n");

	Cgraph * pGraph1 = new Cgraph(INPUT_FILE2);
	Cgraph * pGraph2 = new Cgraph(INPUT_FILE1);

	pGraph_table->GRTadd_graph(pGraph1);
	pGraph_table->GRTadd_graph(pGraph2);

	assert(pGraph_table->GRTget_nb_graph() == 2);
	assert(*pGraph_table->GRTget_graph(0) == *pGraph1);
	assert(*pGraph_table->GRTget_graph(1) == *pGraph2);

}


void Cgraph_table_UNIT::TEST_UNIT_GRTempty_table()
{

	printf("\n - UNIT_TEST GRTempty_table() :\n\n");
	printf("Test : all the graph has been removed of the table \n");

	Cgraph_table * pGraph_table = new Cgraph_table();
	Cgraph * pGraph1 = new Cgraph(INPUT_FILE2);
	Cgraph * pGraph2 = new Cgraph(INPUT_FILE1);

	pGraph_table->GRTadd_graph(pGraph1);
	pGraph_table->GRTadd_graph(pGraph2);

	pGraph_table->GRTempty_table();

	assert(pGraph_table->GRTget_graph_table() == NULL);
	assert(pGraph_table->GRTget_nb_graph() == 0);
}

void Cgraph_table_UNIT::TEST_UNIT_GRT_delete_graph_at_index(){

	printf("\n - UNIT_TEST GRT_delete_graph_at_index() :\n\n");
	printf("Test : the graph as been correctly deleted \n");
	Cgraph_table * pGraph_table = new Cgraph_table();
	Cgraph * pGraph1 = new Cgraph(INPUT_FILE2);
	Cgraph * pGraph2 = new Cgraph(INPUT_FILE1);

	pGraph_table->GRTadd_graph(pGraph1);
	pGraph_table->GRTadd_graph(pGraph2);

	pGraph_table->GRT_delete_graph_at_index(0);

	assert(pGraph_table->GRTget_nb_graph() == 1);

}

void Cgraph_table_UNIT::TEST_UNIT_GRT_insert_graph_at_index(){
	printf("\n - UNIT_TEST GRT_insert_graph_at_index() :\n\n");
	printf("Test : the graph as been correctly inserted \n");
	Cgraph_table * pGraph_table = new Cgraph_table();
	Cgraph * pGraph1 = new Cgraph(INPUT_FILE2);
	Cgraph * pGraph2 = new Cgraph(INPUT_FILE1);
	Cgraph * pGraph3 = new Cgraph(INPUT_FILE1);

	pGraph_table->GRTadd_graph(pGraph1);

	pGraph_table->GRT_insert_graph_at_index(0, pGraph2);
	pGraph_table->GRT_insert_graph_at_index(2, pGraph3);

	assert(pGraph_table->GRTget_nb_graph() == 3);
	assert(*pGraph_table->GRTget_graph(0) == *pGraph_table->GRTget_graph(2));//test if graph at position 0 is same as position 2 that should be the case
}

void Cgraph_table_UNIT::TEST_UNIT_GRT_replace_graph_at_index(){
	printf("\n - UNIT_TEST GRT_replace_graph_at_index() :\n\n");
	printf("Test : the graph as been correctly replaced \n");
	Cgraph_table * pGraph_table = new Cgraph_table();
	Cgraph * pGraph1 = new Cgraph(INPUT_FILE2);
	Cgraph * pGraph2 = new Cgraph(INPUT_FILE1);
	Cgraph * pGraph3 = new Cgraph(INPUT_FILE1);

	pGraph_table->GRTadd_graph(pGraph1);
	pGraph_table->GRTadd_graph(pGraph2);
	
	pGraph_table->GRT_replace_graph_at_index(0, pGraph3);

	assert(*pGraph_table->GRTget_graph(0) == *pGraph3);
}