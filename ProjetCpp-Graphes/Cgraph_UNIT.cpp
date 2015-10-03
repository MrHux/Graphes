#include "stdafx.h"

void Cgraph_UNIT::TEST_UNIT_Cgraph()
{
	printf("\n - UNIT_TEST constructor Cgraph :\n\n");
	printf("Test : null pointer in the copy constructor \n");

	Cgraph * graph = NULL;
	Cgraph * graph2 = new Cgraph(*graph);

	graph = new Cgraph();
	assert(*graph == *graph2);

	delete graph2;

	// ----------

	printf("Test : non null value in the copy constructor \n");

	Cedges * edge = new Cedges(1);
	Cvertex * vertex = new Cvertex(1, &edge, &edge, 1, 1);
	graph->GRAadd_vertex(vertex);

	graph2 = new Cgraph(*graph);
	assert(*graph == *graph2);

	delete graph2;

	// ----------

	printf("Test : value in constructor with param \n");

	graph2 = new Cgraph(&vertex,1);
	assert(*graph == *graph2);

	delete graph2;

	// ----------

	printf("Test : value in constructor with param \n");

	Cgraph *graph4 = new Cgraph(INPUT_FILE2);
	assert(NULL == graph4->GRAget_vertices());

	delete graph4;

	// ----------

	Cgraph *graph5 = new Cgraph(INPUT_FILE1);
	assert(3 == graph5->GRAget_nb_vertex());

	assert(1 == graph5->GRAget_vertex(0)->VERget_id_vertex());
	assert(2 == graph5->GRAget_vertex(1)->VERget_id_vertex());
	assert(3 == graph5->GRAget_vertex(2)->VERget_id_vertex());

	assert(1 == graph5->GRAget_vertex(0)->VERget_nb_edges_in());
	assert(3 == graph5->GRAget_vertex(0)->VERget_list_edges_in()[0]->EDGget_id_vertex_in());
	assert(2 == graph5->GRAget_vertex(0)->VERget_list_edges_out()[0]->EDGget_id_vertex_in());

	assert(1 == graph5->GRAget_vertex(1)->VERget_nb_edges_in());
	assert(1 == graph5->GRAget_vertex(1)->VERget_list_edges_in()[0]->EDGget_id_vertex_in());
	assert(3 == graph5->GRAget_vertex(1)->VERget_list_edges_out()[0]->EDGget_id_vertex_in());

	assert(1 == graph5->GRAget_vertex(2)->VERget_nb_edges_in());
	assert(2 == graph5->GRAget_vertex(2)->VERget_list_edges_in()[0]->EDGget_id_vertex_in());
	assert(1 == graph5->GRAget_vertex(2)->VERget_list_edges_out()[0]->EDGget_id_vertex_in());

	delete graph5;
}

void Cgraph_UNIT::TEST_UNIT_GRAinvert_all_edges()
{
	printf(" - UNIT_TEST GRAinvert_all_edges() :\n");
	printf("\n initial :\n\n");

	Cgraph * graph = new Cgraph();
	for (unsigned int indexOfVertex = 0; indexOfVertex < 5; indexOfVertex++){
		graph->GRAadd_vertex(new Cvertex(indexOfVertex, NULL, NULL, 0, 0));
	}

	srand((unsigned int) time(0));

	for (unsigned int indexOfVertex = 0; indexOfVertex < graph->GRAget_nb_vertex(); indexOfVertex++){
		for (unsigned int indexOfEdge = 0; indexOfEdge < (rand() % graph->GRAget_nb_vertex()) + 1; indexOfEdge++){
			graph->GRAadd_edge_from_index(indexOfVertex, indexOfEdge);//link every vertex with all other vertex
		}
	}

	graph->GRAprint();

	printf("\n inverted :\n\n");

	graph->GRAinvert_all_edges()->GRAprint();
}


void Cgraph_UNIT::TEST_UNIT_GRAorder_by_degree(){

	printf(" - TEST_UNIT_GRAorder_by_degree() :\n");
	printf("\n before :\n\n");
	Cgraph *pGraph = new Cgraph(INPUT_FILE3);

	pGraph->GRAprint();

	printf("\n after :\n\n");

	pGraph->GRAorder_by_degree();

	pGraph->GRAprint();
}