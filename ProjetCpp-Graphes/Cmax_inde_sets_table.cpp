/**
 * \file Cmax_inde_sets_table.cpp
 *
 * \author 
 */

#include "stdafx.h"

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
Cmax_inde_sets_table::Cmax_inde_sets_table() {
    this->uiMITsize_max = 0;
}

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
Cmax_inde_sets_table::~Cmax_inde_sets_table() {
    GRTempty_table();
}

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
unsigned int Cmax_inde_sets_table::MITget_size_max() {
    return uiMITsize_max;
}

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
void Cmax_inde_sets_table::GRTempty_table() {
    Cgraph_table::GRTempty_table();
    this->uiMITsize_max = 0;
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *       search all the maximum independant sets of a graph
 *
 *Entry:
 *       Cgraph * pGraph    -   a graph , to determine independant sets
 *       Cgraph * pIndependant_sets -   an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) {

    Cgraph * pGraph_copy = new Cgraph(*pGraph); //copy the graph

    Cgraph * pCopy_independant_sets = new Cgraph(*pIndependant_sets); //make a copy of the current solution

    //save the solution if it's a maximum
    //if the graph is null , we have no more vertex to add to the current solution
    if (pGraph_copy->GRAget_nb_vertex() == 0) {

        delete pGraph_copy; //desallocate pGraph_copy
        pGraph_copy = NULL;

        //we verify if the current solution improve the current maximum
        if (pIndependant_sets->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pIndependant_sets);
            this->uiMITsize_max = pIndependant_sets->GRAget_nb_vertex();
        }//if it don't improve but are a maximum we save it
        else if (pIndependant_sets->GRAget_nb_vertex() == this->uiMITsize_max) {
            pIndependant_sets->GRAorder_by_id();
            // save the solution only if it don't exist already
            bool bSolution_exist = this->MITtest_if_solution_exist(pIndependant_sets);
            if (bSolution_exist == false) {
                this->GRTadd_graph(pIndependant_sets);
            }
        }//delete the solution because it's not a maximum
        else {
            delete pCopy_independant_sets;
            pCopy_independant_sets = NULL;
        }
    } else {
        /*browse the graph with index (position of vertex in the table) , index are different of vertex id
         * vertex of index 1 is the first vertex in the table
         */
        for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < pGraph_copy->GRAget_nb_vertex(); uiIndex_vertex++) {

            Cvertex * pVertex = pGraph_copy->GRAget_vertex(uiIndex_vertex); // get the vertex at index
            unsigned int uiVertex_id = pVertex->VERget_id_vertex(); //get the id of the vertex

            pCopy_independant_sets->GRAadd_vertex(pVertex); //add a copy of the vertex to the independant set
            //remove all vertex who has a shared edge


            pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
            pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
            pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex

            MITenum_max_inde_set(pGraph_copy, pCopy_independant_sets); //call the function on this new graph

            delete pGraph_copy; //delete old copy who lack some vertices
            pGraph_copy = NULL; //set pointer to NULL

            delete pCopy_independant_sets; //delete copy of independent set
            pCopy_independant_sets = NULL;

            pCopy_independant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
            pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
            pGraph_copy->GRAorder_by_degree();
        }

    }
    if (pCopy_independant_sets != NULL) {
        delete pCopy_independant_sets;
        pCopy_independant_sets = NULL;
    }

    if (pGraph_copy != NULL) {
        delete pGraph_copy;
    }


}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *      search all the maximum independant sets of a graph
 *      This method begin to search a solution by taking the vertex who as the less edges.
 *
 *Entry:
 *      Cgraph * pGraph     -   a graph , to determine independant sets
 *      Cgraph * pIndependant_sets	-       an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set2(Cgraph * pGraph, Cgraph * pIndependant_sets) {
    printf("TODO");

    //    Entrée : Un graphe : g
    //Un ensemble de Stable Maximum : s (tableau de graphe)
    //Degré des stables maximums contenus dans s : nbM ax
    //Pré-condition : le graphe g n’est pas nul
    //Sortie : cet algorithme retourne un tableau contenant les sommets permettant de
    //construire des solutions
    //Postcondition : t contient les listes de sommets qui permettent de construire des stables
    //les plus grands possibles
    //On cr é e un tableau t à une dimension pouvant contenir des listes de
    //sommets
    //Tant qu ’ il y a des sommets dans le graphe g
    //Prendre le sommet i ayant un nombre minimum d ’ ar ê tes
    //On ajoute i à t
    //Si il existe d ’ autres sommets ayant le m ê me nombre d ’ ar ê tes alors
    //Si ces sommets poss è dent les m ê mes successeurs que i , et sont
    //reli é s entre eux alors
    //On ajoute ces sommets dans t dans la m ê me liste ( case de
    //t ) que i
    //Sinon si ces sommets poss è dent les m ê mes successeurs que i
    //On ajoute ces sommets dans t dans des listes ( cases de t )
    //diff é rentes
    //Fin si
    //Fin si
    //Fin tant que
    //// il ne reste plus qu ’ à parcourir t pour construire les solutions
    //retourner t
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *       search all the maximum independant sets of a graph
 *
 *Entry:
 *      Cgraph * pGraph		-		a graph , to determine independant sets
 *      Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set3(Cgraph * pGraph, Cgraph * pIndependant_sets) {

    Cgraph * pGraph_copy = new Cgraph(*pGraph); //copy the graph

    Cgraph * pCopy_independant_sets = new Cgraph(*pIndependant_sets); //make a copy of the current solution

    //save the solution if it's a maximum
    //if the graph is null , we have no more vertex to add to the current solution
    if (pGraph_copy->GRAget_nb_vertex() == 0) {

        delete pGraph_copy; //desallocate pGraph_copy
        pGraph_copy = NULL;

        //we verify if the current solution improve the current maximum
        if (pIndependant_sets->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pIndependant_sets);
            this->uiMITsize_max = pIndependant_sets->GRAget_nb_vertex();
        }//if it don't improve but are a maximum we save it
        else if (pIndependant_sets->GRAget_nb_vertex() == this->uiMITsize_max) {
            pIndependant_sets->GRAorder_by_id();
            // save the solution only if it don't exist already
            bool bSolution_exist = this->MITtest_if_solution_exist(pIndependant_sets);
            if (bSolution_exist == false) {
                this->GRTadd_graph(pIndependant_sets);
            }
        }//delete the solution because it's not a maximum
        else {
            delete pCopy_independant_sets;
            pCopy_independant_sets = NULL;
        }
    } else {

        unsigned int uiMin_nb_edges = (pGraph_copy->GRAget_vertex(0)->VERget_nb_edges_out() + pGraph_copy->GRAget_vertex(0)->VERget_nb_edges_in());
        unsigned int uiCurrent_nb_edges = uiMin_nb_edges;



        /*browse the graph with index (position of vertex in the table) , index are different of vertex id
         * vertex of index 1 is the first vertex in the table
         */
        for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < pGraph_copy->GRAget_nb_vertex(); uiIndex_vertex++) {

            uiCurrent_nb_edges = (pGraph_copy->GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_out() + pGraph_copy->GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_in());

            if (uiCurrent_nb_edges <= uiMin_nb_edges + 1) {
                Cvertex * pVertex = pGraph_copy->GRAget_vertex(uiIndex_vertex); // get the vertex at index
                unsigned int uiVertex_id = pVertex->VERget_id_vertex(); //get the id of the vertex

                if ((pGraph_copy->GRAget_nb_vertex() - pVertex->VERget_nb_edges_in() - pVertex->VERget_nb_edges_out() + pIndependant_sets->GRAget_nb_vertex()) >= uiMITsize_max) {

                    pCopy_independant_sets->GRAadd_vertex(pVertex); //add a copy of the vertex to the independant set
                    //remove all vertex who has a shared edge


                    pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
                    pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
                    pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex

                    MITenum_max_inde_set(pGraph_copy, pCopy_independant_sets); //call the function on this new graph

                    delete pGraph_copy; //delete old copy who lack some vertices
                    pGraph_copy = NULL; //set pointer to NULL

                    delete pCopy_independant_sets; //delete copy of independent set
                    pCopy_independant_sets = NULL;

                    pCopy_independant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
                    pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
                    pGraph_copy->GRAorder_by_degree();
                }
            }
        }

    }
    if (pCopy_independant_sets != NULL) {
        delete pCopy_independant_sets;
        pCopy_independant_sets = NULL;
    }

    if (pGraph_copy != NULL) {
        delete pGraph_copy;
    }

}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph) - Heuristic that search some maximum independant set of a graph
 *
 *Purpose:
 *       search the Stable maximum of a graph, by removing the vertex with the higher number of egdes until there are only :
 * 	- isolated vertices
 * 	- group of vertices connected to each other
 *	list all vertices of the graph
 *
 *Entry:
 *       Cgraph * pGraph	-	a graph , to determine independant sets
 *
 *Return:
 *		nothing
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set4(Cgraph * pGraph) {
    Cgraph * pGraph_copy = new Cgraph(*pGraph);
    pGraph_copy->GRAorder_by_degree();

    unsigned int uiIndex_vertex = pGraph_copy->GRAget_nb_vertex() - 1;
    while ((!pGraph_copy->GRAis_graph_only_compose_of_comunity()) && (uiIndex_vertex > 0)) {
        pGraph_copy->GRAremove_vertex_from_index(uiIndex_vertex);
        uiIndex_vertex--;
    }

    pGraph_copy->GRAprint();
    delete pGraph_copy;
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - Heuristic that search ONE maximum independant set of a graph
 *
 *Purpose:
 *       search ONE maximum independant set of a graph
 *
 *Entry:
 *      Cgraph * pGraph		-		a graph , to determine independant sets
 *      Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set5(Cgraph * pGraph, Cgraph * pIndependant_sets) {
    Cgraph * pGraph_copy = new Cgraph(*pGraph);
    Cgraph * pIndependant_sets_copy = new Cgraph(*pIndependant_sets);
    pGraph_copy->GRAorder_by_degree();

    /*
    printf("\n\n \t\t Affichage du graphe entr�e dans la fonction : nb vertex %d", pGraph_copy->GRAget_nb_vertex());
    pGraph_copy->GRAprint();

    ICI on cherche une solution en prenant le sommet ayant un nombre minimum d'ar�tes.
    C'est une heuristique gloutonne et tr�s rapide mais qui ne donne qu'une unique solution
     */
    while (pGraph_copy->GRAget_nb_vertex() != 0) {
        /*get the 1st vertex of the graph (is has been ordered by increasing number of edge)
        add that vertex to the solution
        delete that vertex from the graph
        order the graph by number of edge
        --> return to the beginning of the while
         */
        Cvertex * pVertex = pGraph_copy->GRAget_vertex(0); // get the vertex at index 0
        unsigned int uiVertex_id = pVertex->VERget_id_vertex(); //get the id of the vertex

        pIndependant_sets_copy->GRAadd_vertex(pVertex); //add a copy of the vertex to the independant set
        //remove all vertex who has a shared edge
        pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
        pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
        pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex
    }

    this->GRTadd_graph(pIndependant_sets_copy);
    delete pGraph_copy;
    delete pIndependant_sets_copy;

}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, unsigned int uiIndex_current_vertex) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *      search the Stable maximum of a graph, by enumering all the combinations
 *		it checks if it's good to continue on that way or not
 *
 *Entry:
 *      Cgraph * pGraph			-		a graph , to determine independant sets
 *      unsigned int uiIndex_current_vertex	-		the id of the current vertex
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set6(Cgraph * pGraph, unsigned int uiIndex_current_vertex) {

    Cgraph * pGraph_Copy = new Cgraph(*pGraph);
    pGraph_Copy->GRAorder_by_degree('<');
    //when the graph has no edge we can set the solution if the solution is maximal
    if (pGraph_Copy->GRAget_nb_edges() == 0) {
        if (pGraph_Copy->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pGraph_Copy); //add the solution
            this->uiMITsize_max = pGraph_Copy->GRAget_nb_vertex();
        } else if (pGraph_Copy->GRAget_nb_vertex() == this->uiMITsize_max) {
            this->GRTadd_graph(pGraph_Copy); //add the solution
        }
    }

    //brows the graph and create all the combination of vertex 
    for (unsigned int uiIndex_vertex = 0 + uiIndex_current_vertex; uiIndex_vertex < pGraph_Copy->GRAget_nb_vertex(); uiIndex_vertex++) {


        pGraph_Copy->GRAremove_vertex_from_index(uiIndex_vertex); //remove the vertex

        if ((pGraph_Copy->GRAget_nb_vertex()) >= uiMITsize_max) {
            MITenum_max_inde_set6(pGraph_Copy, uiIndex_vertex); //appel recursif
        }

        delete pGraph_Copy;
        pGraph_Copy = new Cgraph(*pGraph); //retour au graph d'origine

    }
    delete pGraph_Copy;
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *       search the Stable maximum of a graph, DIVIDE TO CONQUER
 *
 *Entry:
 *       Cgraph * pGraph	-	a graph , to determine independant sets
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set7(Cgraph * pGraph) {

    Cgraph * pStable = new Cgraph();
    Cgraph * pGraph_copy = new Cgraph(*pGraph);

    while (pGraph_copy->GRAget_nb_vertex() != 0) {
        //sort graph by degree
        pGraph_copy->GRAorder_by_degree();
        //we look at first vertex in the table of vertex who has been sorted by degree
        if ((pGraph_copy->GRAget_vertex(0)->VERget_nb_edges_in())+(pGraph_copy->GRAget_vertex(0)->VERget_nb_edges_out()) == 0) {
            pStable->GRAadd_vertex(pGraph_copy->GRAget_vertex(0)); //if the vertex is of degree 0 we add it to the stable
            pGraph_copy->GRAremove_vertex_from_index(0); //remove the vertex of the graph
        } else if ((pGraph_copy->GRAget_vertex(0)->VERget_nb_edges_in())+(pGraph_copy->GRAget_vertex(0)->VERget_nb_edges_out()) <= 2) {
            pStable->GRAadd_vertex(pGraph_copy->GRAget_vertex(0)); //if the vertex is of degree 0 we add it to the stable
            //remove all the vertex connected to this one
            pGraph_copy->GRAdelete_vertex_pointed_by(pGraph_copy->GRAget_vertex(0)->VERget_id_vertex());
            pGraph_copy->GRAdelete_vertex_who_point(pGraph_copy->GRAget_vertex(0)->VERget_id_vertex());
            pGraph_copy->GRAremove_vertex_from_index(0); //remove the vertex of the graph
        }//vertex of degree >3
        else {
            pGraph_copy->GRAremove_vertex_from_index(0);
            MITenum_max_inde_set7(pGraph_copy); //call the algorithm to continue
        }

    }

    //if the graph is empty we look if the stable can be added to the solution
    if (pGraph_copy->GRAget_nb_vertex() == 0) {
        //if the stable improve the solution
        if (pStable->GRAget_nb_edges() > this->uiMITsize_max) {
            GRTempty_table();
            GRTadd_graph(pStable); //add a copy
            //if the stable don't improve but is equal as precedent stable found
        } else if (pStable->GRAget_nb_edges() == this->uiMITsize_max) {
            GRTadd_graph(pStable); //add a copy
        }
        //if the stable is not better or equal we do nothing
    }

    //delete allocated local graph
    delete pGraph_copy;
    delete pStable;
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *       search the Stable maximum of a graph
 *
 *Entry:
 *      Cgraph * pGraph		-		a graph , to determine independant sets
 *      Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing            
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set8(Cgraph * pGraph, Cgraph * pIndependant_sets) {
    Cgraph * pGraph_copy = new Cgraph(*pGraph); //copy the graph

    Cgraph * pCopy_independant_sets = new Cgraph(*pIndependant_sets); //make a copy of the current solution

    //save the solution if it's a maximum
    //if the graph is null , we have no more vertex to add to the current solution
    if (pGraph_copy->GRAget_nb_vertex() == 0) {

        delete pGraph_copy; //desallocate pGraph_copy
        pGraph_copy = NULL;

        //we verify if the current solution improve the current maximum
        if (pIndependant_sets->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pIndependant_sets);
            this->uiMITsize_max = pIndependant_sets->GRAget_nb_vertex();
        }//if it don't improve but are a maximum we save it
        else if (pIndependant_sets->GRAget_nb_vertex() == this->uiMITsize_max) {
            pIndependant_sets->GRAorder_by_id();
            // save the solution only if it don't exist already
            bool bSolution_exist = this->MITtest_if_solution_exist(pIndependant_sets);
            if (bSolution_exist == false) {
                this->GRTadd_graph(pIndependant_sets);
            }
        }//delete the solution because it's not a maximum
        else {
            delete pCopy_independant_sets;
            pCopy_independant_sets = NULL;
        }
    } else {
        /*browse the graph with index (position of vertex in the table) , index are different of vertex id
         * vertex of index 1 is the first vertex in the table
         */
        for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < pGraph_copy->GRAget_nb_vertex(); uiIndex_vertex++) {



            Cvertex * pVertex = pGraph_copy->GRAget_vertex(uiIndex_vertex); // get the vertex at index
            unsigned int uiVertex_id = pVertex->VERget_id_vertex(); //get the id of the vertex

            //if the solution can be a maximum independant set (if there is still enough 
            if (((int) pGraph_copy->GRAget_nb_vertex() - (int) pVertex->VERget_nb_edges_in() - (int) pVertex->VERget_nb_edges_out() + (int) pIndependant_sets->GRAget_nb_vertex()) >= (int) uiMITsize_max) {

                pCopy_independant_sets->GRAadd_vertex(pVertex); //add a copy of the vertex to the independant set
                //remove all vertex who has a shared edge


                pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
                pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
                pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex

                MITenum_max_inde_set(pGraph_copy, pCopy_independant_sets); //call the function on this new graph

                delete pGraph_copy; //delete old copy who lack some vertices
                pGraph_copy = NULL; //set pointer to NULL

                delete pCopy_independant_sets; //delete copy of independent set
                pCopy_independant_sets = NULL;

                pCopy_independant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
                pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
                pGraph_copy->GRAorder_by_degree();
            }

        }

    }
    if (pCopy_independant_sets != NULL) {
        delete pCopy_independant_sets;
        pCopy_independant_sets = NULL;
    }

    if (pGraph_copy != NULL) {
        delete pGraph_copy;
    }


}

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
bool Cmax_inde_sets_table::MITtest_if_solution_exist(Cgraph * pGraph_to_compare) {

    pGraph_to_compare->GRAorder_by_id();

    bool bSolution_exist = false;
    for (unsigned int uiIndex_solution = 0; uiIndex_solution < this->GRTget_nb_graph(); uiIndex_solution++) {

        this->GRTget_graph(uiIndex_solution)->GRAorder_by_id();
        if (this->GRTget_graph(uiIndex_solution) == NULL && pGraph_to_compare == NULL) {
            return true; //if both pointer are null they are equal
        } else if (this->GRTget_graph(uiIndex_solution) == NULL || pGraph_to_compare == NULL) {
            bSolution_exist = false; //if one pointer is null and other one not , they are different
        } else {
            //test if number of vertex are the same
            if (pGraph_to_compare->GRAget_nb_vertex() == uiMITsize_max) {
                //compare pointer on vertex list if the pointer are the same the graph are equal (but that should not appear)
                if (pGraph_to_compare->GRAget_vertices() == this->GRTget_graph(uiIndex_solution)->GRAget_vertices()) {
                    return true;
                } else {
                    bSolution_exist = true; //the vertex list are the same in both graph so they are equal
                    //test if content of vertex list are the same 
                    for (unsigned int uiIndexVertex = 0; uiIndexVertex < uiMITsize_max; uiIndexVertex++) {
                        if (this->GRTget_graph(uiIndex_solution)->GRAget_vertex(uiIndexVertex)->VERget_id_vertex() != pGraph_to_compare->GRAget_vertex(uiIndexVertex)->VERget_id_vertex()) {
                            bSolution_exist = false; //one element is different so they are not equal
                        }
                    }
                }
            } else {
                bSolution_exist = false; //if number of vertex are not the same
            }
        }
        if (bSolution_exist == true) return true;
    }

    return bSolution_exist;

}
