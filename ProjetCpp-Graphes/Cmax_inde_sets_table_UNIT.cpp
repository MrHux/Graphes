#include "stdafx.h"

void Cmax_inde_sets_table_UNIT::TEST_UNIT_Cmax_inde_sets_table_UNIT() {

    printf("\n - UNIT_TEST constructor Cmax_inde_sets_table :\n\n");
    printf("Test : initialisation \n");

    Cmax_inde_sets_table * pMax_inde_sets_table = new Cmax_inde_sets_table();

    assert(pMax_inde_sets_table->GRTget_nb_graph() == 0);
    assert(pMax_inde_sets_table->MITget_size_max() == 0);

    delete pMax_inde_sets_table;


}

void Cmax_inde_sets_table_UNIT::TEST_UNIT_GRTempty_table() {

    printf("\n - UNIT_TEST GRTempty_table() :\n\n");
    printf("Test : size of max independant sets is 0 \n");

    Cmax_inde_sets_table * pMax_inde_sets_table = new Cmax_inde_sets_table();

    Cgraph * pGraph1 = new Cgraph(INPUT_FILE1);
    Cgraph * pIndependant_set = new Cgraph();

    pMax_inde_sets_table->MITenum_max_inde_set(pGraph1 , pIndependant_set);

    
    pMax_inde_sets_table->GRTempty_table();

    assert(pMax_inde_sets_table->MITget_size_max() == 0);

    delete pIndependant_set;
    delete pMax_inde_sets_table;
    delete pGraph1;

}

void Cmax_inde_sets_table_UNIT::TEST_UNIT_MITenum_max_inde_set() {

    printf("\n - UNIT_TEST MITenum_max_inde_set() :\n\n");
    printf("Test : correct number of independant set is found \n");

    Cmax_inde_sets_table * pMax_inde_sets_table = new Cmax_inde_sets_table();

    Cgraph * pGraph1 = new Cgraph(INPUT_FILE1);
    Cgraph * pIndependant_set = new Cgraph();

    pGraph1->GRAprint();

    pMax_inde_sets_table->MITenum_max_inde_set(pGraph1, pIndependant_set);

    assert(pMax_inde_sets_table->GRTget_nb_graph() == 3);

    delete pIndependant_set;

    printf("Test : correct max independant sets size found \n");

    assert(pMax_inde_sets_table->MITget_size_max() == 1);

    Cgraph * pGraph2 = new Cgraph();
    pIndependant_set = new Cgraph();

    pMax_inde_sets_table->GRTempty_table();

    pMax_inde_sets_table->MITenum_max_inde_set(pGraph2, pIndependant_set);

    printf("Test : correct number of independant set is found \n");

    assert(pMax_inde_sets_table->GRTget_nb_graph() == 1);

    printf("Test : correct max independant sets size found \n");

    assert(pMax_inde_sets_table->MITget_size_max() == 0);


    //Cgraph * pGraph_alea = new Cgraph(10, 0, 16);

    //pMax_inde_sets_table->GRTempty_table();

    //pMax_inde_sets_table->MITenum_max_inde_set3(pGraph_alea, pIndependant_set);

    //pMax_inde_sets_table->GRTprint();



    delete pGraph1;

    delete pGraph2;

    delete pIndependant_set;

    delete pMax_inde_sets_table;


}
