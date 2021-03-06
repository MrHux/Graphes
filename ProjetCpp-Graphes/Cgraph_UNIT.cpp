#include "stdafx.h"

#ifndef NDEBUG

void Cgraph_UNIT::TEST_UNIT_Cgraph() {
    printf("\n - UNIT_TEST constructor Cgraph :\n\n");
    printf("Test : null pointer in the copy constructor \n");

    Cgraph * graph = NULL;
    Cgraph * graph2 = new Cgraph(*graph);

    graph = new Cgraph();
    assert(*graph == *graph2);

    delete graph2;
    delete graph;

    // ----------

    printf("Test : non null value in the copy constructor \n");

    graph = new Cgraph();
    Cedges * edge = new Cedges(1);
    Cvertex * vertex = new Cvertex(1, &edge, &edge, 1, 1);
    graph->GRAadd_vertex(vertex);
    
    graph2 = new Cgraph(*graph);
    assert(*graph == *graph2);

    delete graph2;
    // ----------

    printf("Test : value in constructor with param \n");

    graph2 = new Cgraph(&vertex, 1);
    assert(*graph == *graph2);

    delete edge;
    delete vertex;
    delete graph2;
    delete graph;
    

    // ----------

    printf("Test : value in constructor with param \n");

    Cgraph *graph4 = new Cgraph(INPUT_FILE2);
    assert(NULL == graph4->GRAget_vertices());

    delete graph4;

    // ----------

    Cgraph *graph5 = new Cgraph(INPUT_FILE1);

    graph5->GRAprint();
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

    printf("Test : random graph - TODO : this function is not implemented ! \n");//this test is not yet implemented because the function is not too

    
//    Cgraph * pGraph6 = new Cgraph(10, 1, 10);
//
//    pGraph6->GRAprint();
//
//    assert(pGraph6->GRAget_nb_vertex() == 10);
//    printf("%d", pGraph6->GRAget_nb_edges());
//    assert(pGraph6->GRAget_nb_edges() == 10);
//
//    delete pGraph6;


}

void Cgraph_UNIT::TEST_UNIT_GRAinvert_all_edges() {
    printf(" - UNIT_TEST GRAinvert_all_edges() :\n");
    printf("\n initial :\n\n");

    Cgraph * graph = new Cgraph();
    for (unsigned int indexOfVertex = 0; indexOfVertex < 5; indexOfVertex++) {
        Cvertex * pNew_vertex = new Cvertex(indexOfVertex, NULL, NULL, 0, 0);
        graph->GRAadd_vertex(pNew_vertex);
        delete pNew_vertex;
    }

    srand((unsigned int) time(0));

    for (unsigned int indexOfVertex = 0; indexOfVertex < graph->GRAget_nb_vertex(); indexOfVertex++) {
        for (unsigned int indexOfEdge = 0; indexOfEdge < (rand() % graph->GRAget_nb_vertex()) + 1; indexOfEdge++) {
            graph->GRAadd_edge_from_index(indexOfVertex, indexOfEdge); //link every vertex with all other vertex
        }
    }

    graph->GRAprint();

    printf("\n inverted :\n\n");

    Cgraph * pInverted_graph;
    
    pInverted_graph = graph->GRAinvert_all_edges();
    
    pInverted_graph->GRAprint();
    
    delete pInverted_graph;
    delete graph;
}

void Cgraph_UNIT::TEST_UNIT_GRAorder_by_degree() {

    printf(" - TEST_UNIT_GRAorder_by_degree() :\n");
    printf("\n before :\n\n");
    Cgraph *pGraph = new Cgraph(INPUT_FILE3);

    pGraph->GRAprint();

    printf("\n after :\n\n");

    pGraph->GRAorder_by_degree();

    pGraph->GRAprint();
    
    delete pGraph;
}

static void TEST_UNIT_GRAdelete_vertex_pointed_by() {
    printf(" - TEST_UNIT_GRAdelete_vertex_pointed_by() :\n");
    printf("\n before :\n\n");

    printf("\n after :\n\n");
}

static void TEST_UNIT_GRAdelete_vertex_who_point() {
    printf(" - TEST_UNIT_GRAorder_by_degree() :\n");
    printf("\n before :\n\n");

    printf("\n after :\n\n");
}

static void TEST_UNIT_GRAis_graph_only_compose_of_comunity() {
    printf(" - TEST_UNIT_GRAis_graph_only_compose_of_comunity() :\n");
    printf("\n before :\n\n");

    printf("\n after :\n\n");
}

static void TEST_UNIT_GRAcount_nb_edge_of_successor() {
    printf(" - TEST_UNIT_GRAcount_nb_edge_of_successor() :\n");
    printf("\n before :\n\n");

    printf("\n after :\n\n");
}

static void TEST_UNIT_GRAget_max_nb_edge_of_successor() {
    printf(" - TEST_UNIT_GRAget_max_nb_edge_of_successor() :\n");
    printf("\n before :\n\n");
    printf("\n after :\n\n");
}
#endif