#include "stdafx.h"

#ifndef NDEBUG

void Cvertex_UNIT::TEST_UNIT_Cvertex() {
    printf("\n - UNIT_TEST constructor Cvertex :\n\n");
    printf("Test : null pointer in the copy constructor :\n");

    Cvertex * vertex = NULL;
    Cvertex * vertex2 = new Cvertex(*vertex);
    vertex = new Cvertex();

    assert(*vertex == *vertex2);

    delete vertex2;

    printf("Test : an non null value in the copy constructor :\n");

    Cedges * edge = new Cedges(1);

    vertex->VERset_id_vertex(1);
    vertex->VERset_list_edges_in(&edge, 1);
    vertex->VERset_list_edges_out(&edge, 1);

    vertex2 = new Cvertex(*vertex);

    assert(*vertex == *vertex2);

    delete vertex2;
    
    Cedges ** ppTable_edge = new Cedges*[3];
    for(unsigned int i = 0; i< 3; i++){
        ppTable_edge[i]=new Cedges((i+1)%3);
    }

    Cvertex * pVertex3 = new Cvertex(1,ppTable_edge,NULL, 3,0);
    
    Cvertex * pVertex4 = new Cvertex(*pVertex3);
    
    for(unsigned int i = 0; i<3; i++){
        delete ppTable_edge[i];
    }
    delete [] ppTable_edge;
    
    assert(*pVertex3==*pVertex4);
    
    delete pVertex3;
    delete pVertex4;
    
    printf("Test : value in constructor with param :\n");


    vertex2 = new Cvertex(1, &edge, &edge, 1, 1);

    assert(*vertex == *vertex2);

    delete vertex;
    delete vertex2;
    delete edge;

}

void Cvertex_UNIT::TEST_UNIT_VERset_list_edges_out() {
    printf("\n - UNIT_TEST VERset_list_edges_out() :\n\n");
    printf("Test : null param :\n");

    Cvertex * vertex = new Cvertex();
    vertex->VERset_list_edges_out(NULL, 0);

    assert(vertex->VERget_list_edges_out() == NULL && vertex->VERget_nb_edges_out() == 0);

    printf("Test : param not NULL :\n");

    Cedges ** ppTabEdge = new Cedges*[3];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);

    vertex->VERset_list_edges_out(ppTabEdge, 3);

    assert(vertex->VERget_nb_edges_out() == 3);

    for (unsigned int indexOfEdgesOut = 0; indexOfEdgesOut < vertex->VERget_nb_edges_out(); indexOfEdgesOut++) {
        assert(*vertex->VERget_list_edges_out()[indexOfEdgesOut] == *ppTabEdge[indexOfEdgesOut]);
    }

    
    delete ppTabEdge[0];
    delete ppTabEdge[1];
    delete ppTabEdge[2];
    delete [] ppTabEdge;
    
    printf("Test : nb_edges_in >0 but list_edges_in null :\n");

    bool testExceptionIsThrowed = false;
    try {
        vertex->VERset_list_edges_in(NULL, 3);
    } catch (Cexception exc) {
        testExceptionIsThrowed = true;
    }

    assert(testExceptionIsThrowed == true);

    printf("Test : initial list not null, list to set not null :\n");

    delete(vertex);
    vertex = new Cvertex();

    ppTabEdge = new Cedges*[3];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);

    vertex->VERset_list_edges_out(ppTabEdge, 3);

    //just verify if the vertex is correctly set
    assert(vertex->VERget_nb_edges_out() == 3);

    delete(ppTabEdge[0]);
    delete(ppTabEdge[1]);
    delete(ppTabEdge[2]);
    delete[](ppTabEdge);

    ppTabEdge = new Cedges*[4];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);
    ppTabEdge[3] = new Cedges(4);

    vertex->VERset_list_edges_out(ppTabEdge, 4);
    //test if the remplacement of the list worked well
    assert(vertex->VERget_nb_edges_out() == 4);

    delete(ppTabEdge[0]);
    delete(ppTabEdge[1]);
    delete(ppTabEdge[2]);
    delete(ppTabEdge[3]);

    delete[](ppTabEdge);
    
    delete vertex;
}

void Cvertex_UNIT::TEST_UNIT_VERset_list_edges_in() {
    printf("\n - UNIT_TEST VERset_list_edges_in() :\n\n");
    printf("Test : null param :\n");

    Cvertex * vertex = new Cvertex();
    vertex->VERset_list_edges_in(NULL, 0);

    assert(vertex->VERget_list_edges_in() == NULL && vertex->VERget_nb_edges_in() == 0);

    printf("Test : param not NULL :\n");

    Cedges ** ppTabEdge = new Cedges*[3];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);



    vertex->VERset_list_edges_in(ppTabEdge, 3);

    assert(vertex->VERget_nb_edges_in() == 3);

    for (unsigned int indexOfEdgesIn = 0; indexOfEdgesIn < vertex->VERget_nb_edges_in(); indexOfEdgesIn++) {
        assert(*vertex->VERget_list_edges_in()[indexOfEdgesIn] == *ppTabEdge[indexOfEdgesIn]);
    }

    printf("Test : nb_edges_in >0 but list_edges_in null :\n");

    bool testExceptionIsThrowed = false;
    try {
        vertex->VERset_list_edges_in(NULL, 3);
    } catch (Cexception exc) {
        testExceptionIsThrowed = true;
    }
    delete(ppTabEdge[1]);

    assert(testExceptionIsThrowed == true);

    delete(ppTabEdge[0]);
    delete(ppTabEdge[2]);


    delete[](ppTabEdge);
    
    delete vertex;
}

void Cvertex_UNIT::TEST_UNIT_VERoperatorEqual() {
    printf("\n - UNIT_TEST VERoperatorEqual() :\n\n");
    printf("Test : null pointer :\n");

    Cvertex * vertex = NULL;
    Cvertex vertex2 = *vertex;
    vertex = new Cvertex();

    assert(*vertex == vertex2);

    delete vertex;

    printf("Test : not null value :\n");

    Cedges ** ppTabEdge = new Cedges*[3];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);

    vertex = new Cvertex(1, ppTabEdge, ppTabEdge, 3, 3);

    vertex2 = *vertex;

    assert(*vertex == vertex2);
    
    
    delete ppTabEdge[0];
    delete ppTabEdge[1];
    delete ppTabEdge[2];
    delete [] ppTabEdge;
    
    delete vertex;

}

void Cvertex_UNIT::TEST_UNIT_VERoperatorEqualEqual() {
    printf("\n - UNIT_TEST VERoperatorEqualEqual() :\n\n");
    printf("Test : NULL pointers in param :\n");

    Cvertex * vertex = NULL;
    Cvertex * vertex2 = NULL;

    assert(*vertex == *vertex2);

    printf("Test : two equal Cvertex :\n");

    Cedges ** ppTabEdge = new Cedges*[3];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);

    vertex = new Cvertex(1, ppTabEdge, ppTabEdge, 3, 3);
    vertex2 = new Cvertex(1, ppTabEdge, ppTabEdge, 3, 3);

    assert(*vertex == *vertex2);

    delete vertex2;

   
    
    printf("Test : different Cvertex :\n");

    Cedges ** ppTabEdge2 = new Cedges*[3];
    ppTabEdge2[0] = new Cedges(5);
    ppTabEdge2[1] = new Cedges(4);
    ppTabEdge2[2] = new Cedges(6);
    vertex2 = new Cvertex(1, ppTabEdge, ppTabEdge2, 3, 3);

    assert(!(*vertex == *vertex2));
    
    delete ppTabEdge2[0];
    delete ppTabEdge2[1];
    delete ppTabEdge2[2];
    delete [] ppTabEdge2;
        
    delete ppTabEdge[0];
    delete ppTabEdge[1];
    delete ppTabEdge[2];
    delete [] ppTabEdge;
    
    delete vertex;
    delete vertex2;
}

void Cvertex_UNIT::TEST_UNIT_VERoperatorNotEqual() {
    printf("\n - UNIT_TEST VERoperatorEqualEqual() :\n\n");
    printf("Test : NULL pointers in param :\n");

    Cvertex * vertex = NULL;
    Cvertex * vertex2 = NULL;

    assert(!(*vertex != *vertex2));

    printf("Test : two equal Cvertex :\n");

    Cedges ** ppTabEdge = new Cedges*[3];
    ppTabEdge[0] = new Cedges(1);
    ppTabEdge[1] = new Cedges(2);
    ppTabEdge[2] = new Cedges(3);

    vertex = new Cvertex(1, ppTabEdge, ppTabEdge, 3, 3);
    vertex2 = new Cvertex(1, ppTabEdge, ppTabEdge, 3, 3);

    assert(!(*vertex != *vertex2));

        

    delete vertex2;

    printf("Test : different Cvertex :\n");

    Cedges ** ppTabEdge2 = new Cedges*[3];
    ppTabEdge2[0] = new Cedges(5);
    ppTabEdge2[1] = new Cedges(4);
    ppTabEdge2[2] = new Cedges(6);
    vertex2 = new Cvertex(1, ppTabEdge, ppTabEdge2, 3, 3);

    assert(*vertex != *vertex2);
    
    delete ppTabEdge[0];
    delete ppTabEdge[1];
    delete ppTabEdge[2];
    delete [] ppTabEdge;
        
    delete ppTabEdge2[0];
    delete ppTabEdge2[1];
    delete ppTabEdge2[2];
    delete [] ppTabEdge2;
;    
    delete vertex2;
    
    delete vertex;
}
#endif