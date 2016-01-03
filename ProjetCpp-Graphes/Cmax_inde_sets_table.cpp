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
 *       Cgraph * pGraph				-		a graph , to determine independant sets
 *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
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
        
        delete pGraph_copy;//desallocate pGraph_copy
        pGraph_copy=NULL;
                
        //we verify if the current solution improve the current maximum
        if (pIndependant_sets->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pIndependant_sets);
            this->uiMITsize_max = pIndependant_sets->GRAget_nb_vertex();
        }            //if it don't improve but are a maximum we save it
        else if (pIndependant_sets->GRAget_nb_vertex() == this->uiMITsize_max) {
            pIndependant_sets->GRAorder_by_id();
            // save the solution only if it don't exist already
            bool bSolution_exist = this->MITtest_if_solution_exist(pIndependant_sets);
            if (bSolution_exist == false) {
                this->GRTadd_graph(pIndependant_sets);
            }
        }            //delete the solution because it's not a maximum
        else {
            delete pCopy_independant_sets ;
            pCopy_independant_sets=NULL;
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
            pGraph_copy=NULL;//set pointer to NULL
            
            delete pCopy_independant_sets;//delete copy of independent set
            pCopy_independant_sets=NULL;
            
            pCopy_independant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
            pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
            pGraph_copy->GRAorder_by_degree();
        }
        
    }
    if (pCopy_independant_sets!=NULL) {
        delete pCopy_independant_sets;
        pCopy_independant_sets=NULL;
    }

    if(pGraph_copy!=NULL){
        delete pGraph_copy;
    }
   

}

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
void Cmax_inde_sets_table::MITenum_max_inde_set2(Cgraph * pGraph, Cgraph * pIndependant_sets) {
    printf("TODO");
    // "regarder si il y a des sommets equivalents"
    // recherche des sommets "equivalents"
    //cad les sommets qui quand ils sont enleves enlevent les memes autres sommets que qu'un autre.
    //ex :
    //	 /---\
	//	1--2--3
    //	 \ | / 
    //	   5
    // ici retirer 1, 2, 3 ou 5, c'est pareil !!

    //ex :
    //		 /---\
			//	    1--2--3
    //		|\ | /
    //		6--5--7
    // ici retirer 2 ou 3, c'est pareil !!

    //on va distinguer deux types de groupes:
    //	1: groupe d'exclusion/connexes/communaute --> ENSEMBLE INTERDEPENDANT
    //		si 1 sommet du groupe est pris alors on doit exclure tous les autres.
    //		Les solutions sont donc obtenue avec un remplacement de ce sommet par ceux du groupe a k sommets ( ==> k solutions diferentes)
    //	2: groupe de complementaires/parallelles --> ENSEMBLE EQUIVALENT
    //		si 1 sommet du groupe est pris, alors autant prendre tous les autres.
    //		On ajoute alors tous le groupe de k sommets a la solution ( ==> solution unique)

    /*============== ALGORITHM ==============
     * get the vertex to delete (min direct successors && max undirect successors) : V_delete
     *	list of V_delete's successors : L1
     *	for each element of L1
     *		get the list of vertex's successors : L2
     *		for each element of L2
     *			get the list of vertex's successors : L3
     *			if(L1 == L3)
     *				parrallel communauty
     *			else if((areLinked(V_delete, V_curent) == true) && (L1\link == L3\link)
     *				fortement connexe communauty
     */

    /*
     *	tant qu'il y a des sommets dans le graphe (while(pGraph_copy->GRAget_nb_vertex() != 0))
     *	1) prendre le sommet ayant un nombre minimum d'edge (et de successeurs ayants un maximum d'edges)
     *	2) regarder si ce somment fait partie d'un ensemble equivalent/interd�pendant ou non:
     *		y a-t-il des successeurs de successeurs qui ont les m�mes successeurs?
     *		pour tous les successeurs de successeurs : currentNode.listSuccessors == currentNode.successor.successor.listSuccessors ?
     *	pour 1 � n-i�me successeur du node courrent (suc_1)
     *		pour 1 � m-i�me successeur du node suc_1 (donc suc_2 pour successeur au 2�me degr�)
     *			si oui (il en existe au moins un) : (suc_2.listSuccessors == currentNode.listSuccessors)
     *				si le node courrent et le successeur de successeur sont reli�s (areLinked(suc_2, currentNode) == true)
     *					ajouter � liste groupe interd�pendant
     *					continuer la recherche (jusqu'� la fin de la liste des successeurs de successeurs de successeurs)
     *				sinon le node courrent et le successeur de successeur ne sont pas reli�s
     *					ajouter � la liste groupe �quivalent
     *					continuer la recherche (jusqu'� la fin de la liste des successeurs de successeurs de successeurs)
     *			sinon 
     *				ajouter le node � la solution puis supprimer le node et ses successeurs
     *				relancer la recherche sur la m�me fonction
     */

}

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
void Cmax_inde_sets_table::MITenum_max_inde_set3(Cgraph * pGraph, Cgraph * pIndependant_sets) {
    Cgraph * pGraph_copy = new Cgraph(*pGraph);
    pGraph_copy->GRAorder_by_degree();
    Cgraph * pCopy_independant_sets = new Cgraph(*pIndependant_sets);

    /*
    ICI on cherche les solutions en ajoutant � une solution le sommet avec le moins d'ar�te en priorit�, on s'ar�te des lors que les sommets � parcourir on un nombre d'ar�te > au nombre minimum + 2
     */

    if (pGraph_copy->GRAget_nb_vertex() == 0) {
        if (pIndependant_sets->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pIndependant_sets);
            this->uiMITsize_max = pIndependant_sets->GRAget_nb_vertex();
        } else if (pIndependant_sets->GRAget_nb_vertex() == this->uiMITsize_max) {
            pIndependant_sets->GRAorder_by_id();
            bool bSolution_exist = this->MITtest_if_solution_exist(pIndependant_sets);
            if (bSolution_exist == false) {
                this->GRTadd_graph(pIndependant_sets);
            }
        } else {
            delete(pCopy_independant_sets);
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

                //if this vertex can't lead to a stable maximum
                if ((pGraph_copy->GRAget_nb_vertex() - pVertex->VERget_nb_edges_in() - pVertex->VERget_nb_edges_out() + pIndependant_sets->GRAget_nb_vertex()) >= uiMITsize_max) {
                    pCopy_independant_sets->GRAadd_vertex(new Cvertex(*pVertex)); //add a copy of the vertex to the independant set
                    //remove all vertex who has a shared edge
                    pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
                    pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
                    pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex
                    MITenum_max_inde_set3(pGraph_copy, pCopy_independant_sets); //call the function on this new graph
                    delete(pGraph_copy); //delete old copy who lack some vertices
                    pCopy_independant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
                    pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
                    pGraph_copy->GRAorder_by_degree();
                }

            }

        }
    }
    
    delete pGraph_copy;
}

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


void Cmax_inde_sets_table::MITenum_max_inde_set4(Cgraph * pGraph) {

    Cgraph * pGraph_copy = new Cgraph(*pGraph);
    Cgraph * pGraph_copy2 = new Cgraph(*pGraph);
    pGraph_copy->GRAorder_by_degree();

    unsigned int uiIndex_vertex = pGraph_copy->GRAget_nb_vertex() - 1;
    while ((!pGraph_copy->GRAis_graph_only_compose_of_comunity()) && (uiIndex_vertex > 0)) {
        pGraph_copy->GRAremove_vertex_from_index(uiIndex_vertex);
        uiIndex_vertex--;
    }

    Cgraph * pIndependant_set = new Cgraph();

    uiIndex_vertex = 0;
    //while there is unconnected vertex we add it to the solution
    while ((pGraph_copy->GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_in() + pGraph_copy->GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_out()) == 0) {
        pIndependant_set->GRAadd_vertex(new Cvertex(*pGraph_copy->GRAget_vertex(uiIndex_vertex)));
        pGraph_copy2->GRAremove_vertex_from_vertex_id(pGraph_copy->GRAget_vertex(uiIndex_vertex)->VERget_id_vertex()); //remove the vertex of the graph
        pGraph_copy->GRAremove_vertex_from_index(uiIndex_vertex); //remove the vertex of the graph

        uiIndex_vertex++;
    }

    printf("\n grap 1 : \n");
    pGraph_copy->GRAprint();
    printf("\n grah 2 : \n");
    pGraph_copy2->GRAprint();
    printf("\n sol  : \n");
    pIndependant_set->GRAprint();

    //now we have the begining of a solution and a graph with only few vertex strongly connected
    //find the firsts maximal stable 
    MITenum_max_inde_set3(pGraph_copy, new Cgraph(*pIndependant_set)); //a copy of pIndependant_set is done so we can use it again

    MITenum_max_inde_set3(pGraph_copy2, new Cgraph(*pIndependant_set));

    delete(pIndependant_set);
    delete pGraph_copy2;
    delete pGraph_copy;
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *       search the Stable maximum of a graph, by removing the vertex with the higher number of egdes
 *
 *Entry:
 *
 *       Cgraph * pGraph				-		a graph , to determine independant sets
 *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set5(Cgraph * pGraph) {
    Cgraph * pGraph_copy = new Cgraph(*pGraph);
    pGraph_copy->GRAorder_by_degree();

    unsigned int uiIndex_vertex = pGraph_copy->GRAget_nb_vertex() - 1;
    while ((!pGraph_copy->GRAis_graph_only_compose_of_comunity()) && (uiIndex_vertex > 0)) {
        pGraph_copy->GRAremove_vertex_from_index(uiIndex_vertex);
        uiIndex_vertex--;
    }

    Cgraph * pIndependent_set = new Cgraph();
    MITenum_max_inde_set3(pGraph_copy, pIndependent_set);

    delete(pIndependent_set);
    delete pGraph_copy;
}

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
void Cmax_inde_sets_table::MITenum_max_inde_set7(Cgraph * pGraph, Cgraph * pIndependant_sets) {
//    Cgraph * pGraph_copy = new Cgraph(*pGraph);
//    pGraph_copy->GRAorder_by_degree();
//
//    /*
//    printf("\n\n \t\t Affichage du graphe entr�e dans la fonction : nb vertex %d", pGraph_copy->GRAget_nb_vertex());
//    pGraph_copy->GRAprint();
//
//    ICI on cherche une solution en prenant le sommet ayant un nombre minimum d'ar�tes.
//    C'est une heuristique gloutonne et tr�s rapide mais qui ne donne qu'une unique solution
//     */
//    std::cout << "pGraph_copy->GRAget_nb_vertex()\t" << pGraph_copy->GRAget_nb_vertex() << std::endl;
//    while (pGraph_copy->GRAget_nb_vertex() != 0) {
//        get the 1st vertex of the graph (is has been ordered by increasing number of edge)
//        add that vertex to the solution
//        delete that vertex from the graph
//        order the graph by number of edge
//        --> return to the beginning of the while
//
//        Cvertex * pVertex = pGraph_copy->GRAget_vertex(0); // get the vertex at index
//        unsigned int uiVertex_id = pVertex->VERget_id_vertex(); //get the id of the vertex
//        pIndependant_sets->GRAadd_vertex(new Cvertex(*pVertex)); //add a copy of the vertex to the independant set
//        remove all vertex who has a shared edge
//        pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
//        pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
//        pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex
//    }
//    order solution by increasing index
//    print solution
//    delete(pGraph_copy); //delete old copy who lack some vertices
//    pIndependant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
//    pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
//    pGraph_copy->GRAorder_by_degree();
    
}

/***
 * void MITenum_max_inde_set(Cgraph * pGraph, Cgraph * pIndependant_sets) - search all the maximum independant sets of a graph
 *
 *Purpose:
 *       search the Stable maximum of a graph, by enumering all the combinaison
 *
 *Entry:
 *       Cgraph * pGraph				-		a graph , to determine independant sets
 *		Cgraph * pIndependant_sets	-		an independant set of the graph, NULL if first call of the function.
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cmax_inde_sets_table::MITenum_max_inde_set6(Cgraph * pGraph, unsigned int uiIndex_current_vertex) {

    Cgraph * pGraph_Copy = new Cgraph(*pGraph);
    pGraph_Copy->GRAorder_by_degree('<');
    //when the graph has no edge we can set the if the solution is manximal
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
void Cmax_inde_sets_table::MITenum_max_inde_set7(Cgraph * pGraph, unsigned int &uiNb_call) {

    Cgraph * pGraph_copy1 = NULL;

    unsigned int uiIndex_middle = pGraph->GRAget_nb_vertex() / 2;
    unsigned int uiEcard_if_unpair = 0;
    if (pGraph->GRAget_nb_vertex() % 2 != 0) {
        uiEcard_if_unpair = 1;
    }

    printf("\n\n Appel nb : %d \n\n", uiNb_call);

    if (pGraph->GRAget_nb_vertex() > 1) {

        if (uiIndex_middle > 0) {

            pGraph_copy1 = new Cgraph(*pGraph);

            //remove first half part of the graph
            while (pGraph_copy1->GRAget_nb_vertex() > uiIndex_middle + uiEcard_if_unpair) {
                pGraph_copy1->GRAremove_vertex_from_index(0);
            }


            if (pGraph_copy1->GRAget_nb_vertex() != 0) {
                printf("Premi�re moitie : \n\n");
                pGraph_copy1->GRAprint("-id_ver");
                uiNb_call++;
                uiNb_call = uiNb_call + 10000;
                MITenum_max_inde_set7(pGraph_copy1, uiNb_call);
            }
            delete(pGraph_copy1);

        }
        if (uiIndex_middle < pGraph->GRAget_nb_vertex() - 1) {

            pGraph_copy1 = new Cgraph(*pGraph);
            //remove second half part of the graph
            while (pGraph_copy1->GRAget_nb_vertex() > uiIndex_middle) {
                pGraph_copy1->GRAremove_vertex_from_index(pGraph_copy1->GRAget_nb_vertex() - 1);
            }

            if (pGraph_copy1->GRAget_nb_vertex() != 0) {
                printf("Deuxi�me moitie : \n\n");
                pGraph_copy1->GRAprint("-id_ver");
                uiNb_call++;
                uiNb_call = uiNb_call + 10000000;
                MITenum_max_inde_set7(pGraph_copy1, uiNb_call);
            }
            delete(pGraph_copy1);
        }
    }

}

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
void Cmax_inde_sets_table::MITenum_max_inde_set8(Cgraph * pGraph, Cgraph * pIndependant_sets) {

    Cgraph * pGraph_copy = new Cgraph(*pGraph);
    pGraph_copy->GRAorder_by_degree();
    Cgraph * pCopy_independant_sets = new Cgraph(*pIndependant_sets);

    if (pGraph_copy->GRAget_nb_vertex() == 0) {
        if (pIndependant_sets->GRAget_nb_vertex() > uiMITsize_max) {
            this->GRTempty_table();
            this->GRTadd_graph(pIndependant_sets);
            this->uiMITsize_max = pIndependant_sets->GRAget_nb_vertex();
        } else if (pIndependant_sets->GRAget_nb_vertex() == this->uiMITsize_max) {
            pIndependant_sets->GRAorder_by_id();
            bool bSolution_exist = this->MITtest_if_solution_exist(pIndependant_sets);
            if (bSolution_exist == false) {
                this->GRTadd_graph(pIndependant_sets);
            }
        } else {
            delete(pCopy_independant_sets);
        }
    } else {
        /*browse the graph with index (position of vertex in the table) , index are different of vertex id
         * vertex of index 1 is the first vertex in the table
         */
        for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < pGraph_copy->GRAget_nb_vertex(); uiIndex_vertex++) {
            Cvertex * pVertex = pGraph_copy->GRAget_vertex(uiIndex_vertex); // get the vertex at index
            unsigned int uiVertex_id = pVertex->VERget_id_vertex(); //get the id of the vertex

            if (((int) pGraph_copy->GRAget_nb_vertex() - (int) pVertex->VERget_nb_edges_in() - (int) pVertex->VERget_nb_edges_out() + (int) pIndependant_sets->GRAget_nb_vertex()) >= (int) uiMITsize_max) {
                pCopy_independant_sets->GRAadd_vertex(new Cvertex(*pVertex)); //add a copy of the vertex to the independant set
                //remove all vertex who has a shared edge
                pGraph_copy->GRAdelete_vertex_pointed_by(uiVertex_id);
                pGraph_copy->GRAdelete_vertex_who_point(uiVertex_id);
                pGraph_copy->GRAremove_vertex_from_vertex_id(uiVertex_id); //remove the vertex
                MITenum_max_inde_set8(pGraph_copy, pCopy_independant_sets); //call the function on this new graph
                delete(pGraph_copy); //delete old copy who lack some vertices
                pCopy_independant_sets = new Cgraph(*pIndependant_sets); //get a new copy of the current independent set to be calculated
                pGraph_copy = new Cgraph(*pGraph); //get a new copy with all vertices
                pGraph_copy->GRAorder_by_degree();
            }
        }
    }
    delete pGraph_copy;
}

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