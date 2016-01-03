#include "stdafx.h"

#ifndef NDEBUG

void Cedges_UNIT::TEST_UNIT_Cedges() {
    printf("\n - UNIT_TEST constructor Cedges :\n\n");
    printf("Test : null pointer in the copy constructor :\n");

    Cedges * edge = NULL;
    Cedges * edge2 = new Cedges(*edge);
    edge = new Cedges();

    assert(*edge == *edge2);

    delete edge2;

    printf("Test : an non null value in the copy constructor :\n");

    edge->EDGset_id_vertex_in(3);
    edge2 = new Cedges(*edge);

    assert(*edge == *edge2);

    delete edge;
    printf("Test : value in constructor with param :\n");

    edge = new Cedges(3);
    edge2->EDGset_id_vertex_in(3);

    assert(*edge == *edge2);
    
    delete edge;
    delete edge2;

}

void Cedges_UNIT::TEST_UNIT_OperatorEqual() {
    printf("\n - UNIT_TEST Operator= Cedges :\n\n");
    printf("Test : null pointer :\n");

    Cedges * edge = NULL;
    Cedges edge2 = *edge;
    edge = new Cedges();

    assert(*edge == edge2);

    printf("Test : integer in param :\n");

    edge->EDGset_id_vertex_in(3);
    edge2.EDGset_id_vertex_in(3);

    assert(*edge == edge2);
    
    delete edge;
}

void Cedges_UNIT::TEST_UNIT_OperatorEqualEqual() {
    printf("\n - UNIT_TEST Operator== Cedges :\n\n");
    printf("Test : NULL pointers in param :\n");

    Cedges * edge = NULL;
    Cedges * edge2 = NULL;

    assert(*edge == *edge2);

    printf("Test : two equal Cedges :\n");

    edge = new Cedges(3);
    edge2 = new Cedges(3);

    assert(*edge == *edge2);

    printf("Test : different Cedges :\n");

    edge2->EDGset_id_vertex_in(4);

    assert(!(*edge == *edge2));
    
    delete edge;
    delete edge2;
}

void Cedges_UNIT::TEST_UNIT_OperatorNotEqual() {
    printf("\n - UNIT_TEST Operator!= Cedges :\n\n");
    printf("Test : NULL pointers in param :\n");

    Cedges * edge = NULL;
    Cedges * edge2 = NULL;

    assert(!(*edge != *edge2));

    printf("Test : two equal Cedges :\n");

    edge = new Cedges(3);
    edge2 = new Cedges(3);

    assert(!(*edge != *edge2));

    printf("Test : different Cedges :\n");

    edge->EDGset_id_vertex_in(3);
    edge2->EDGset_id_vertex_in(4);

    assert(*edge != *edge2);
    
    delete edge;
    delete edge2;
}

#endif
