/**
 * \file Cgraph.cpp
 *
 * \author 
 */

#include "stdafx.h"

/***
 * Cgraph() - create a new Cgraph with null value
 *
 *Purpose:
 *       create a new Cgraph with null value
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph::Cgraph() : Cgraph(NULL, 0) {

}

/***
 * Cgraph(Cvertex** ppList_vertex, unsigned int uiNb_vertex) - create a new Cgraph with param values
 *
 *Purpose:
 *       create a new Cgraph with param values
 *
 *Entry:
 *       Cvertex**	ppList_vertex	-	the list of vertex to set
 *		unsigned	int uiNb_vertex	-	the number of vertex in the list
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph::Cgraph(Cvertex** ppList_vertex, unsigned int uiNb_vertex) {
    if ((ppList_vertex == NULL) && uiNb_vertex != 0) {
        Cexception exc(ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL);
        throw exc;
    } else if (ppList_vertex != NULL && uiNb_vertex == 0) {
        Cexception exc(ERROR_LIST_NOT_NULL);
        throw exc;
    } else {
        uiGRAnb_vertex = uiNb_vertex;
        ppGRAlist_vertex = NULL;
        if (ppList_vertex != NULL) {
            ppGRAlist_vertex = new Cvertex*[uiGRAnb_vertex];
            for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
                ppGRAlist_vertex[indexOfVertex] = new Cvertex(*ppList_vertex[indexOfVertex]);
            }
        }
    }
}

/***
 * Cgraph(const char* pcFile_to_import) - create a new Cgraph with the content of a file
 *
 *Purpose:
 *       create a new Cgraph with the content of a file
 *
 *Entry:
 *       const char*		pcFile_to_import	-	the path to the file
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph::Cgraph(const char * pcFile_to_import) throw (Cexception) {
    uiGRAnb_vertex = 0;
    ppGRAlist_vertex = NULL;

    char** ppValues_imported = NULL; // Table of cstring (char **) containing the values of a graph's file

    try {
        ppValues_imported = Cfile::FILparse_file(pcFile_to_import);
    } catch (Cexception exc) {
        printf("Error ! File no found");
    }
    unsigned int uiIndex_values_imported = 0; // Index on table ppValues_imported

    unsigned int uiNumber_vertices = 0;
    unsigned int uiNumber_edges = 0;

    unsigned int uiNumber_vertices_read = 0;
    unsigned int uiNumber_edges_read = 0;

    bool bReading_vertices = false;
    bool bReading_edges = false;

    while (ppValues_imported[uiIndex_values_imported] != NULL) {
        // Reading number of vertices
        if (strcmp(ppValues_imported[uiIndex_values_imported], CHARS_BEGIN_NUMBER_VERTICES) == 0) {
            uiNumber_vertices = atoi(ppValues_imported[uiIndex_values_imported + 1]);

            // Allocating the table of vertex
            //vertex_table = (Cvertex **) malloc(uiNumber_vertices * sizeof(Cvertex *));
        }

        // Reading number of edges
        if (strcmp(ppValues_imported[uiIndex_values_imported], CHARS_BEGIN_NUMBER_EDGES) == 0) {
            uiNumber_edges = atoi(ppValues_imported[uiIndex_values_imported + 1]);
        }

        // Reading a table beginning character
        if (strcmp(ppValues_imported[uiIndex_values_imported], CHAR_BEGIN_TABLE) == 0) {
            if (strcmp(ppValues_imported[uiIndex_values_imported - 1], CHARS_VERTICES) == 0) {
                // Start reading vertices
                bReading_vertices = true;
            } else if (strcmp(ppValues_imported[uiIndex_values_imported - 1], CHARS_EDGES) == 0) {
                // Start reading edges
                bReading_edges = true;
            } else {
                // Error : unexpected begin table char
                Cexception exc(ERROR_UNEXPECTED_TOKEN_READ);
                throw exc;
            }
        }

        // Reading a table ending character
        if (strcmp(ppValues_imported[uiIndex_values_imported], CHAR_END_TABLE) == 0) {
            if (bReading_vertices == true && bReading_edges == false) {
                // Stop reading vertices
                bReading_vertices = false;
            } else if (bReading_vertices == false && bReading_edges == true) {
                // Stop reading edges
                bReading_edges = false;
            } else {
                // Error : unexpected end table char
                Cexception exc(ERROR_UNEXPECTED_TOKEN_READ);
                throw exc;
            }
        }

        // Reading a vertex value
        if (strcmp(ppValues_imported[uiIndex_values_imported], CHARS_VALUE_VERTEX) == 0) {
            if (bReading_edges == false && bReading_vertices == true && uiNumber_vertices_read < uiNumber_vertices) {
                // Creating a new vertex with empty in and out edges lists
                Cvertex *vertex_read = new Cvertex(atoi(ppValues_imported[uiIndex_values_imported + 1]), NULL, NULL, 0, 0);

                // Add the new vertex to the graph
                GRAadd_vertex(vertex_read); // CRASH when calling GRAget_index_vertex : ppGRAlist_vertex[indexOfVertex (0)] is not defined.

                delete vertex_read;
                
                uiNumber_vertices_read++;
            } else {
                // Error : unexpected value
                Cexception exc(ERROR_UNEXPECTED_TOKEN_READ);
                throw exc;
            }
        }

        // Reading an edge value
        if (strcmp(ppValues_imported[uiIndex_values_imported], CHARS_VALUE_BEGIN_EDGE) == 0) {
            if (bReading_edges == true && bReading_vertices == false && uiNumber_edges_read < uiNumber_edges) {
                // Getting the id of the vertex concerned by the edge (edge, link between a vertex out and a vertex in)
                unsigned int uiId_vertex_out = atoi(ppValues_imported[uiIndex_values_imported + 1]);
                unsigned int uiId_vertex_in = atoi(ppValues_imported[uiIndex_values_imported + 3]);

                GRAadd_edge_from_vertex_id(uiId_vertex_out, uiId_vertex_in);

                uiNumber_edges_read++;
            } else {
                // Error : unexpected value
                Cexception exc(ERROR_UNEXPECTED_TOKEN_READ);
                throw exc;
            }
        }

        uiIndex_values_imported++;
    }

    uiIndex_values_imported = 0;

    //Free ppValues_imported memory
    while (ppValues_imported[uiIndex_values_imported] != NULL) {
        free(ppValues_imported[uiIndex_values_imported]);
        uiIndex_values_imported++;
    }
    free(ppValues_imported);
}

/***
 * Cgraph(const Cgraph &graph_to_copy) - create a Cgraph with the value of another Cgraph
 *
 *Purpose:
 *       create a Cgraph with the value of another Cgraph
 *
 *Entry:
 *       const Cgraph &	graph_to_copy	-	the graph to copy
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph::Cgraph(const Cgraph &graph_to_copy) {
    if (&graph_to_copy != NULL) {
        uiGRAnb_vertex = graph_to_copy.uiGRAnb_vertex;

        ppGRAlist_vertex = NULL;
        if (uiGRAnb_vertex != 0) {
            ppGRAlist_vertex = new Cvertex*[uiGRAnb_vertex];
            for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
                ppGRAlist_vertex[indexOfVertex] = new Cvertex(*graph_to_copy.ppGRAlist_vertex[indexOfVertex]);
            }
        }
    } else {
        uiGRAnb_vertex = 0;
        ppGRAlist_vertex = NULL;

    }
}

/***
 * Cgraph(const Cgraph &graph_to_copy) - create a random Cgraph under certain condition
 *
 *Purpose:
 *       create a Random Cgraph with the specified number of vertex and edge could be oriented or not as wanted.
 *
 *Entry:
 *       unsigned int uiNb_vertex	-	the number of vertex
 *		bool bIs_oriented			-	the kind of graph oriented or not
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph::Cgraph(unsigned int uiNb_vertex, bool bIs_oriented, unsigned int iNb_edges) {

    printf("Warning this function is not implemented yet ! Do not use it !");
    abort();
//    uiGRAnb_vertex = 0;
//    if (uiNb_vertex != 0) {
//
//        ppGRAlist_vertex = new Cvertex*[uiNb_vertex];
//        for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < uiNb_vertex; uiIndex_vertex++) {
//            Cvertex * pNew_vertex = new Cvertex(uiIndex_vertex, NULL, NULL, 0, 0);
//            GRAadd_vertex(pNew_vertex);
//            delete pNew_vertex;
//        }
//        uiGRAnb_vertex = uiNb_vertex; //set the new number of vertex
//
//        unsigned int uiNb_edges_to_distrib = iNb_edges;
//
//        if (uiNb_edges_to_distrib != 0) {//if number of edge to set is 0 do nothing
//
//            srand((unsigned int) time(0));
//
//            for (unsigned int indexOfVertex1 = 0; indexOfVertex1 < GRAget_nb_vertex(); indexOfVertex1++) {
//                if (uiNb_edges_to_distrib > 0) {
//
//                    unsigned int uiRandom_nb_edges = (rand() % (uiNb_edges_to_distrib));
//                    if (uiNb_edges_to_distrib == 1) uiRandom_nb_edges = 1;
//                    uiNb_edges_to_distrib = uiNb_edges_to_distrib - uiRandom_nb_edges;
//
//
//                    for (unsigned int indexOfEdges = 0; indexOfEdges < uiRandom_nb_edges; indexOfEdges++) {
//                        unsigned int indexOfVertex2 = indexOfVertex1;
//                        while (indexOfVertex2 == indexOfVertex1) {
//                            indexOfVertex2 = rand() % (GRAget_nb_vertex()); //index begin by 0
//                        }
//                        if (GRAadd_edge_from_index(indexOfVertex1, indexOfVertex2)) {//link every vertex with all other vertex
//                            indexOfEdges--; // if the edge was already existing we increment the count (to have the wanted amount of edge) 
//                        }
//                    }
//                }
//            }
//        }
//
//    } else {
//        ppGRAlist_vertex = NULL;
//    }

}

/***
 * Cgraph~() - delete a Cgraph correctly
 *
 *Purpose:
 *       delete a Cgraph correctly
 *
 *Entry:
 *       const Cgraph &	graph_to_copy	-	the graph to copy
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph::~Cgraph() {
    if (ppGRAlist_vertex != NULL) {
        for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
            if (ppGRAlist_vertex[indexOfVertex] != NULL) {
                delete ppGRAlist_vertex[indexOfVertex];
                ppGRAlist_vertex[indexOfVertex] = NULL;
            }
        }

        delete[] ppGRAlist_vertex;
        ppGRAlist_vertex = NULL;
    }
    uiGRAnb_vertex = 0;
}

/***
 * GRAget_nb_vertex() - get the number of vertex of the graph
 *
 *Purpose:
 *       get the number of vertex of the graph
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
unsigned int Cgraph::GRAget_nb_vertex() {
    return uiGRAnb_vertex;
}

/***
 * GRAget_vertices() - get the list of vertex of the graph
 *
 *Purpose:
 *       get the list of vertex of the graph
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cvertex** Cgraph::GRAget_vertices() {
    return ppGRAlist_vertex;
}

/***
 * GRAget_index_vertex(unsigned int uiId_vertex) - get the index of the vertex in the list of the graph
 *
 *Purpose:
 *       get the index of the vertex designed by the uiId_vertex in the list of the graph
 *
 *Entry:
 *       unsigned int	uiId_vertex	-	the id of the vertex to find
 *
 *Return:
 *		unsigned int	-	if the vertex is in the graph return his own index in the list of vertex, otherwise return the maximun number who can be set in an unsigned int
 *
 *******************************************************************************/
unsigned int Cgraph::GRAget_index_vertex(unsigned int uiId_vertex) {
    for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
        if (ppGRAlist_vertex[indexOfVertex]->VERget_id_vertex() == uiId_vertex) {
            return indexOfVertex;
        }
    }
    return UINT_MAX;
}

/***
 * GRAget_index_vertex(Cvertex * pVertex) - get the index of the vertex in the list of the graph
 *
 *Purpose:
 *       get the index of the vertex pointed by pVertex in the list of the graph
 *
 *Entry:
 *       Cvertex *	pVertex	-	a pointer on a Vertex to find
 *
 *Return:
 *		unsigned int	-	if the vertex is in the graph return his own index in the list of vertex, otherwise return the maximun number who can be set in an unsigned int
 *
 *******************************************************************************/
unsigned int Cgraph::GRAget_index_vertex(Cvertex * pVertex) {
    for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
        if (*ppGRAlist_vertex[indexOfVertex] == *pVertex) {
            return indexOfVertex;
        }
    }

    return UINT_MAX;
}

/***
 * GRAget_vertex(unsigned int uiIndex_vertex) - get the vertex at the index in param
 *
 *Purpose:
 *       get the vertex at the index in param, to get vertex with id of the vertex use get_index_vertex(unsigned int) 
 *
 *Entry:
 *       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to get
 *
 *Return:
 *		Cvertex *	-	the vertex 
 *
 *Throw:
                throw an exception if the index is higher than the number of vertex in the graph
 *******************************************************************************/
Cvertex * Cgraph::GRAget_vertex(unsigned int uiIndex_vertex)throw (Cexception) {
    if (uiIndex_vertex < uiGRAnb_vertex) {
        return ppGRAlist_vertex[uiIndex_vertex];
    } else {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    }
}

/***
 * GRAget_vertex(unsigned int uiIndex_vertex) - get the vertex at the index in param
 *
 *Purpose:
 *       get the vertex at the index in param, to get vertex with id of the vertex use get_index_vertex(unsigned int)
 *
 *Entry:
 *       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to get
 *
 *Return:
 *		Cvertex *	-	the vertex
 *
 *Throw:
throw an exception if the index is higher than the number of vertex in the graph
 *******************************************************************************/
Cvertex * Cgraph::GRAget_vertex_from_vertex_id(unsigned int uiVertex_id) {
    return GRAget_vertex(GRAget_index_vertex(uiVertex_id));
}

unsigned int Cgraph::GRAget_nb_edges() {
    unsigned int uiNb_edges = 0;

    if (uiGRAnb_vertex != 0) {
        for (unsigned int uiIndex = 0; uiIndex < uiGRAnb_vertex; uiIndex++) {
            uiNb_edges = uiNb_edges + ppGRAlist_vertex[uiIndex]->VERget_nb_edges_in();
        }
    }

    return uiNb_edges;
}

/***
 * GRAadd_vertex(Cvertex* pVertex) - add a vertex to the graph
 *
 *Purpose:
 *       add a vertex to the graph (if the vertex is already there it's not added, but it's position is returned)
 *
 *Entry:
 *       Cvertex*	pVertex	-	the vertex to add
 *
 *Return:
 *		unsigned int	-	the position of the vertex
 *
 *******************************************************************************/
unsigned int Cgraph::GRAadd_vertex(Cvertex* pVertex) {
    unsigned int uiIndex_vertex = GRAget_index_vertex(pVertex);
    if (uiIndex_vertex != UINT_MAX) {
        return uiIndex_vertex;
    } else {
        Cvertex ** ppListVertexConcat = new Cvertex*[uiGRAnb_vertex + 1];
        for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
            ppListVertexConcat[indexOfVertex] = new Cvertex(*ppGRAlist_vertex[indexOfVertex]);
        }
        ppListVertexConcat[uiGRAnb_vertex] = new Cvertex(*pVertex); //add new vertex

        if (ppGRAlist_vertex != NULL && uiGRAnb_vertex != 0) {
            for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
                delete ppGRAlist_vertex[indexOfVertex];
            }
            delete[] ppGRAlist_vertex;
        }

        ppGRAlist_vertex = ppListVertexConcat;
        uiGRAnb_vertex++; //increment number of vertex
        return uiGRAnb_vertex - 1; //return the index of the vertex who has just been inserted
    }
}

/***
 * GRAremove_vertex_from_index(unsigned int uiIndex_vertex) - remove a vertex of the graph
 *
 *Purpose:
 *       remove a vertex of the graph, all the attached edges will be removed too
 *
 *Entry:
 *       unsigned int	uiIndex_vertex	-	the index (in the list of the graph) of the vertex to delete
 *
 *Throw:
 *		Throw an exception if the index is out of the range of number of edge in the graph
 *
 *******************************************************************************/

void Cgraph::GRAremove_vertex_from_index(unsigned int uiIndex_vertex) throw (Cexception) {
    if (uiIndex_vertex > uiGRAnb_vertex) {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    } else {
        Cvertex ** ppListVertexConcat = NULL;

        //remove all the edge who exist with the removed vertex
        for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
            GRAremove_edge_from_vertex_id(ppGRAlist_vertex[uiIndex_vertex]->VERget_id_vertex(), ppGRAlist_vertex[indexOfVertex]->VERget_id_vertex());
            GRAremove_edge_from_vertex_id(ppGRAlist_vertex[indexOfVertex]->VERget_id_vertex(), ppGRAlist_vertex[uiIndex_vertex]->VERget_id_vertex());
        }

        //delete the vertex
        if (uiGRAnb_vertex >= 2) {

            ppListVertexConcat = new Cvertex*[uiGRAnb_vertex - 1];

            for (unsigned int indexOfVertex = 0; indexOfVertex < uiIndex_vertex; indexOfVertex++) {
                ppListVertexConcat[indexOfVertex] = new Cvertex(*ppGRAlist_vertex[indexOfVertex]);

            }

            for (unsigned int indexOfVertex = uiIndex_vertex + 1; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
                ppListVertexConcat[indexOfVertex - 1] = new Cvertex(*ppGRAlist_vertex[indexOfVertex]);
            }
        }
        //delete old list
        for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
            delete ppGRAlist_vertex[indexOfVertex];
            ppGRAlist_vertex[indexOfVertex] = NULL;
        }
        delete[] ppGRAlist_vertex;

        ppGRAlist_vertex = ppListVertexConcat;
        uiGRAnb_vertex--; //update new number of vertex

    }

}

/***
 *GRAremove_vertex_from_vertex_id(unsigned int uiId_vertex) - remove a vertex of the graph
 *
 *Purpose:
 *       remove a vertex of the graph, all the attached edges will be removed too
 *
 *Entry:
 *       unsigned int	uiId_vertex	-	the id of the vertex to delete
 *
 *Return:
 *		Cvertex *	-	a pointer to the Cvertex who has been removed
 *
 *Throw:
 *		Throw an exception if the index is out of the range of number of edge in the graph
 *
 *******************************************************************************/
void Cgraph::GRAremove_vertex_from_vertex_id(unsigned int uiId_vertex) {
    GRAremove_vertex_from_index(GRAget_index_vertex(uiId_vertex));
}

/***
 *GRAupdate_vertex_from_index(unsigned int uiIndex_vertex, Cvertex* pCvertex) - update a vertex of the graph
 *
 *Purpose:
 *       update a vertex of the graph
 *
 *Entry:
 *       unsigned int	uiIndex_vertex	-	the index (in the list in the graph) of the vertex to update	
 *		Cvertex*		pCvertex		-	a pointer on the vertex to set
 *
 *Return:
 *		Cvertex *	-	a pointer to the Cvertex who has been removed
 *
 *Throw:
 *		Throw an exception if the index is out of the range of number of edge in the graph
 *		Throw an exception if the pCvertex is NULL
 *
 *******************************************************************************/
void Cgraph::GRAupdate_vertex_from_index(unsigned int uiIndex_vertex, Cvertex* pCvertex) {
    if (pCvertex == NULL) {
        Cexception exc(ERROR_NULL_POINTER);
        throw exc;
    }
    if (uiIndex_vertex > uiGRAnb_vertex) {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    } else {
        delete ppGRAlist_vertex[uiIndex_vertex];
        *ppGRAlist_vertex[uiIndex_vertex] = *pCvertex;
    }
}

/***
 *GRAupdate_vertex_from_vertex_id(unsigned int uiId_vertex, Cvertex* pVertex) - update a vertex of the graph
 *
 *Purpose:
 *       update a vertex of the graph
 *
 *Entry:
 *       unsigned int	uiIndex_vertex	-	the id of the vertex to update
 *		Cvertex*		pCvertex		-	a pointer on the vertex to set
 *
 *Return:
 *		Cvertex *	-	a pointer to the Cvertex who has been removed
 *
 *Throw:
 *		Throw an exception if the index is out of the range of number of edge in the graph
 *		Throw an exception if the pCvertex is NULL
 *
 *******************************************************************************/
void Cgraph::GRAupdate_vertex_from_vertex_id(unsigned int uiId_vertex, Cvertex* pVertex) {
    GRAupdate_vertex_from_index(GRAget_index_vertex(uiId_vertex), pVertex);
}

/***
 *GRAprint() - print to screen the graph
 *
 *Purpose:
 *       print to screen the graph
 *
 *Entry:
 *		none
 *
 *Return:
 *		none
 *
 *******************************************************************************/
void Cgraph::GRAprint() {
    GRAprint(NULL);
}

/***
 *GRAprint() - print to screen the graph
 *
 *Purpose:
 *       print to screen the graph
 *
 *Entry:
 *		char * pOption	-	the option to print certain value of the graph 
 *							-id_ver		:	print the vertices ids
 *							-nb_edge	:	print the number of edge of the vertices
 *							-list_succ	:	print the list of successor of the vertices
 *							-list_pred	:	print the list of predecessor of the vertices
 *
 *Return:
 *		none
 *
 *******************************************************************************/
void Cgraph::GRAprint(char * pOption) {
    using namespace std;
    string * pStr_Opt;
    if (pOption == NULL) {
        pStr_Opt = new string();
    } else {
        pStr_Opt = new string(pOption);
    }


    for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {

        if (pStr_Opt->find("-id_ver") != string::npos || pOption == NULL) {
            printf("\n v : %d \n", GRAget_vertex(indexOfVertex)->VERget_id_vertex());
        }

        if (pStr_Opt->find("-nb_edg") != string::npos || pOption == NULL) {
            printf("\n nb edges : %d \n", GRAget_vertex(indexOfVertex)->VERget_nb_edges_in() + GRAget_vertex(indexOfVertex)->VERget_nb_edges_out());
        }

        for (unsigned int indexOfEdge = 0; indexOfEdge < ((GRAget_vertex(indexOfVertex)->VERget_nb_edges_out() > GRAget_vertex(indexOfVertex)->VERget_nb_edges_in()) ? GRAget_vertex(indexOfVertex)->VERget_nb_edges_out() : GRAget_vertex(indexOfVertex)->VERget_nb_edges_in()); indexOfEdge++) {
            if (pStr_Opt->find("-list_suc") != string::npos || pOption == NULL) {//if pStr_Opt contain -list_succ, npos == -1
                if (indexOfEdge < GRAget_vertex(indexOfVertex)->VERget_nb_edges_out()) {
                    printf(" -> v out : %d  ", GRAget_vertex(indexOfVertex)->VERget_list_edges_out()[indexOfEdge]->EDGget_id_vertex_in());
                } else {
                    printf("             ");
                }
            }
            if (pStr_Opt->find("-list_pred") != string::npos || pOption == NULL) {//if pStr_Opt contain -list_succ, npos == -1
                if (indexOfEdge < GRAget_vertex(indexOfVertex)->VERget_nb_edges_in()) {
                    printf("\t\t-> v in : %d \n", GRAget_vertex(indexOfVertex)->VERget_list_edges_in()[indexOfEdge]->EDGget_id_vertex_in());
                } else {
                    printf("\n");
                }
            }
        }
        printf("\n\n");

    }
    delete pStr_Opt;

}

/***
 *GRAremove_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) - remove an edge in the graph
 *
 *Purpose:
 *       remove an edge in the graph
 *
 *Entry:
 *		unsigned int	uiIndex_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge
 *		unsigned int	uiIndex_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge
 *
 *Return:
 *		none
 *
 *Throw:
 *		Throw an error if the value of the index are out of range of number of edge
 *
 *******************************************************************************/
void Cgraph::GRAremove_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in)throw (Cexception) {
    if (uiIndex_vertex_out > uiGRAnb_vertex || uiIndex_vertex_in > uiGRAnb_vertex) {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    } else {
        Cedges * pEdge_removed = NULL;
        //delete the edge who's going out of the vertex of index "uiIndex_vertex_out" , this edge contain vertex of index "uiIndex_vertex_in"
        pEdge_removed = ppGRAlist_vertex[uiIndex_vertex_out]->VERremove_edge_from_list_edges_out(ppGRAlist_vertex[uiIndex_vertex_in]->VERget_id_vertex());
        if (pEdge_removed != NULL) {
            delete pEdge_removed; //the edge is correctly removed
        }
        //delete the edge who's going in of the vertex of index "uiIndex_vertex_in" , this edge contain vertex of index "uiIndex_vertex_out"
        pEdge_removed = ppGRAlist_vertex[uiIndex_vertex_in]->VERremove_edge_from_list_edges_in(ppGRAlist_vertex[uiIndex_vertex_out]->VERget_id_vertex());
        if (pEdge_removed != NULL) {
            delete pEdge_removed; //the edge is correctly removed
        }
    }
}

/***
 *GRAupdate_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) - update an edge in the graph
 *
 *Purpose:
 *       update an edge in the graph
 *
 *Entry:
 *		unsigned int uiIndex_vertex_out		-	the index (in the list of the graph) of the vertex in entry of the edge to be remove
 *		unsigned int uiIndex_vertex_in		-	the index (in the list of the graph) of the vertex in exit of the edge to be remove
 *		unsigned int uiIndex_new_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge to be add
 *		unsigned int uiIndex_new_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge to be add
 *
 *Return:
 *		none
 *
 *Throw:
 *		Throw an error if the value of the index are out of range of number of edge
 *
 *******************************************************************************/
void Cgraph::GRAupdate_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) {
    GRAremove_edge_from_index(uiIndex_vertex_out, uiIndex_vertex_in);
    GRAadd_edge_from_index(uiIndex_new_vertex_out, uiIndex_new_vertex_in);
}

/***
 *GRAadd_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) - add an edge in the graph
 *
 *Purpose:
 *       add an edge in the graph
 *
 *Entry:
 *		unsigned int	uiIndex_vertex_out	-	the index (in the list of the graph) of the vertex in entry of the edge
 *		unsigned int	uiIndex_vertex_in	-	the index (in the list of the graph) of the vertex in exit of the edge
 *
 *Return:
 *		bool	-	a boolean if the edge was already there
 *
 *Throw:
 *		Throw an error if the value of the index are out of range of number of edge
 *
 *******************************************************************************/
bool Cgraph::GRAadd_edge_from_index(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in) {
    if (uiIndex_vertex_out > uiGRAnb_vertex || uiIndex_vertex_in > uiGRAnb_vertex) {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    } else {
        unsigned int uiIdOfVertexOut = ppGRAlist_vertex[uiIndex_vertex_out]->VERget_id_vertex();
        unsigned int uiIdOfVertexIn = ppGRAlist_vertex[uiIndex_vertex_in]->VERget_id_vertex();
        Cedges * newEdgeForVertexOut = new Cedges(uiIdOfVertexIn);
        Cedges * newEdgeForVertexIn = new Cedges(uiIdOfVertexOut);
        unsigned int uiNb_edges_in_old = ppGRAlist_vertex[uiIndex_vertex_in]->VERget_nb_edges_in();
        unsigned int uiNb_edges_out_old = ppGRAlist_vertex[uiIndex_vertex_out]->VERget_nb_edges_out();
        unsigned int uiIndex_edge_inserted_out = ppGRAlist_vertex[uiIndex_vertex_out]->VERadd_edge_to_list_edges_out(newEdgeForVertexOut);
        unsigned int uiIndex_edge_inserted_in = ppGRAlist_vertex[uiIndex_vertex_in]->VERadd_edge_to_list_edges_in(newEdgeForVertexIn);
        bool bIs_edge_not_existing = (ppGRAlist_vertex[uiIndex_vertex_out]->VERget_nb_edges_out() != uiNb_edges_out_old) && (ppGRAlist_vertex[uiIndex_vertex_in]->VERget_nb_edges_in() != uiNb_edges_in_old);
        
        delete newEdgeForVertexIn;
        delete newEdgeForVertexOut;
        
        return !bIs_edge_not_existing;
    }
}

/***
 *GRAremove_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) - remove an edge in the graph
 *
 *Purpose:
 *       remove an edge in the graph
 *
 *Entry:
 *		unsigned int	uiIndex_vertex_out	-	the id of the vertex in entry of the edge
 *		unsigned int	uiIndex_vertex_in	-	the id of the vertex in exit of the edge
 *
 *Return:
 *		none
 *
 *Throw:
 *		Throw an error if the value of the index are out of range of number of edge
 *
 *******************************************************************************/
void Cgraph::GRAremove_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) {
    GRAremove_edge_from_index(GRAget_index_vertex(uiId_vertex_out), GRAget_index_vertex(uiId_vertex_in));
}

/***
 *GRAupdate_edge_from_vertex_id(unsigned int uiIndex_vertex_out, unsigned int uiIndex_vertex_in, unsigned int uiIndex_new_vertex_out, unsigned int uiIndex_new_vertex_in) - update an edge in the graph
 *
 *Purpose:
 *       update an edge in the graph
 *
 *Entry:
 *		unsigned int uiIndex_vertex_out		-	the id of the vertex in entry of the edge to be remove
 *		unsigned int uiIndex_vertex_in		-	the id of the vertex in exit of the edge to be remove
 *		unsigned int uiIndex_new_vertex_out	-	the id of the vertex in entry of the edge to be add
 *		unsigned int uiIndex_new_vertex_in	-	the id of the vertex in exit of the edge to be add
 *
 *Return:
 *		none
 *
 *Throw:
 *		Throw an error if the value of the index are out of range of number of edge
 *
 *******************************************************************************/
void Cgraph::GRAupdate_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in, unsigned int uiId_new_vertex_out, unsigned int uiId_new_vertex_in) {
    GRAupdate_edge_from_index(GRAget_index_vertex(uiId_vertex_out), GRAget_index_vertex(uiId_vertex_in), GRAget_index_vertex(uiId_new_vertex_out), GRAget_index_vertex(uiId_new_vertex_in));
}

/***
 *GRAadd_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) - add an edge in the graph
 *
 *Purpose:
 *       add an edge in the graph
 *
 *Entry:
 *		unsigned int	uiIndex_vertex_out	-	the id of the vertex in entry of the edge
 *		unsigned int	uiIndex_vertex_in	-	the id of the vertex in exit of the edge
 *
 *Return:
 *		bool	-	a boolean if the edge was already there
 *
 *Throw:
 *		Throw an error if the value of the index are out of range of number of edge
 *
 *******************************************************************************/
bool Cgraph::GRAadd_edge_from_vertex_id(unsigned int uiId_vertex_out, unsigned int uiId_vertex_in) {
    return GRAadd_edge_from_index(GRAget_index_vertex(uiId_vertex_out), GRAget_index_vertex(uiId_vertex_in));
}

/***
 *GRAinvert_all_edges()	- invert all edges in the graph
 *
 *Purpose:
 *       invert all edges in the graph
 *
 *Entry:
 *		none
 *
 *Return:
 *		Cgraph *	-	a new graph who is exactly the inverse of the original graph
 *
 *******************************************************************************/
Cgraph * Cgraph::GRAinvert_all_edges() {

    Cgraph * pInvertedGraph = new Cgraph();

    for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
        Cvertex * pNew_vertex = new Cvertex(ppGRAlist_vertex[indexOfVertex]->VERget_id_vertex(), NULL, NULL, 0, 0);//create a new vertex who has the same id but empty list.
        pInvertedGraph->GRAadd_vertex(pNew_vertex);//add it to the graph
        delete pNew_vertex; //delete the new vertex
    }
    for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
        for (unsigned int indexOfEdge = 0; indexOfEdge < ppGRAlist_vertex[indexOfVertex]->VERget_nb_edges_in(); indexOfEdge++) {
            pInvertedGraph->GRAadd_edge_from_vertex_id(ppGRAlist_vertex[indexOfVertex]->VERget_list_edges_in()[indexOfEdge]->EDGget_id_vertex_in(), ppGRAlist_vertex[indexOfVertex]->VERget_id_vertex());
        }
    }
    return pInvertedGraph;
}

/***
 *GRAdelete_vertex_pointed_by(unsigned int uiVertex_id) -
 *
 *Purpose:
 *
 *
 *Entry:
 *
 *
 *Return:
 *		none
 *
 *******************************************************************************/
void Cgraph::GRAdelete_vertex_pointed_by(unsigned int uiVertex_id) {
    //delete all the vertex connected to pVertex by edges who go out pVertex and remove the edges attached to
    unsigned int uiNumber_of_edges = GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_nb_edges_in();
    for (unsigned int index = 0; index < uiNumber_of_edges; index++) {
        GRAremove_vertex_from_vertex_id(GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_list_edges_in()[index]->EDGget_id_vertex_in());

        //if an edge was removed by the operation we need to decrement the index to browse every edges of the list, and we need to set the new number of edge for the loop
        if (GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_nb_edges_in() < uiNumber_of_edges) {
            uiNumber_of_edges = GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_nb_edges_in();
            index--;
        }
    }
}

/***
 *void GRAdelete_vertex_who_point(unsigned int uiVertex_id) -	delete all the vertex who share an edge going to the one in parameter
 *
 *Purpose:
 *		Remove all the vertex who share a common edge who point the vertex who has the id in parameter
 *
 *Entry:
 *		unsigned int uiVertex_id	-	the id of the vertex who end the edge(s)
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cgraph::GRAdelete_vertex_who_point(unsigned int uiVertex_id) {
    //delete all the vertex connected to pVertex by edges who go in and remove the edges attached to
    unsigned int uiNumber_of_edges = GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_nb_edges_out();
    for (unsigned int index = 0; index < uiNumber_of_edges; index++) {
        GRAremove_vertex_from_vertex_id(GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_list_edges_out()[index]->EDGget_id_vertex_in());
        //if an edge was removed by the operation we need to decrement the index to browse every edges of the list, and we need to set the new number of edge for the loop
        if (GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_nb_edges_out() < uiNumber_of_edges) {
            uiNumber_of_edges = GRAget_vertex_from_vertex_id(uiVertex_id)->VERget_nb_edges_out();
            index--;
        }
    }
}

/***
 *void GRAorder_by_degree() -	order the vertices of the graph by their degree
 *
 *Purpose:
 *		order the vertices of the graph by their degree
 *
 *Entry:
 *		char cOption	-	an option to chose the way to sort (increasing or decreasing)
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cgraph::GRAorder_by_degree(char cOption) {
    /**
     ** The sorting algorithm used is Quick Sort
     **/
    //sort nb edge decreasing
    if (cOption == '<') {

        //browse all the graph
        for (unsigned int uiIndex = 0; uiIndex < uiGRAnb_vertex; uiIndex++) {
            unsigned uiIndex2 = uiIndex;
            Cvertex * pVertex = ppGRAlist_vertex[uiIndex];
            //look if predecessor in the table have less or more edge and sort them 
            while (uiIndex2 > 0 && (ppGRAlist_vertex[uiIndex2 - 1]->VERget_nb_edges_in() + ppGRAlist_vertex[uiIndex2 - 1]->VERget_nb_edges_out()) < (pVertex->VERget_nb_edges_in() + pVertex->VERget_nb_edges_out())) {
                ppGRAlist_vertex[uiIndex2] = ppGRAlist_vertex[uiIndex2 - 1];
                uiIndex2 = uiIndex2 - 1;
            }
            ppGRAlist_vertex[uiIndex2] = pVertex;
        }

    }//sort nd edge increasing
    else {

        //browse all the graph
        for (unsigned int uiIndex = 0; uiIndex < uiGRAnb_vertex; uiIndex++) {
            unsigned uiIndex2 = uiIndex;
            Cvertex * pVertex = ppGRAlist_vertex[uiIndex];
            //look if predecessor in the table have less or more edge and sort them 
            while (uiIndex2 > 0 && (ppGRAlist_vertex[uiIndex2 - 1]->VERget_nb_edges_in() + ppGRAlist_vertex[uiIndex2 - 1]->VERget_nb_edges_out()) > (pVertex->VERget_nb_edges_in() + pVertex->VERget_nb_edges_out())) {
                ppGRAlist_vertex[uiIndex2] = ppGRAlist_vertex[uiIndex2 - 1];
                uiIndex2 = uiIndex2 - 1;
            }
            ppGRAlist_vertex[uiIndex2] = pVertex;
        }
    }
}

/***
 *void GRAorder_by_degree() -	order the vertices of the graph by their degree (increasing sort)
 *
 *Purpose:
 *		order the vertices of the graph by their degree (increasing sort)
 *
 *Entry:
 *		none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cgraph::GRAorder_by_degree(void) {
    this->GRAorder_by_degree('>');
}

void Cgraph::GRAorder_by_id() {

    for (unsigned int uiIndex = 0; uiIndex < uiGRAnb_vertex; uiIndex++) {
        unsigned int uiIndex2 = uiIndex;
        Cvertex * pVertex = ppGRAlist_vertex[uiIndex];
        while (uiIndex2 > 0 && ppGRAlist_vertex[uiIndex2 - 1]->VERget_id_vertex() > pVertex->VERget_id_vertex()) {
            ppGRAlist_vertex[uiIndex2] = ppGRAlist_vertex[uiIndex2 - 1];
            uiIndex2 = uiIndex2 - 1;
        }
        ppGRAlist_vertex[uiIndex2] = pVertex;
    }
}

bool Cgraph::GRAis_graph_only_compose_of_comunity() {

    /**
     ** This function works well for any graph who are undirected (one edge link two vertices no more), and directed graph (one or more edge in any direction)
     **/

    //browse all vertex
    for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < uiGRAnb_vertex; uiIndex_vertex++) {

        //save the number of edge of the current vertex
        unsigned int uiNb_edges_current_vertex = ppGRAlist_vertex[uiIndex_vertex]->VERget_nb_edges_in() + ppGRAlist_vertex[uiIndex_vertex]->VERget_nb_edges_out();

        //if the vertex as no successor or predecessor, it means it has no edges
        if (uiNb_edges_current_vertex == 0) {
            //do nothing , that vertex is already a community by itself
        } else {
            //get the table of predecessor and successor of the vertex (this table is sorted by increasing id)
            unsigned int * pTable_pred_succ_vertex = ppGRAlist_vertex[uiIndex_vertex]->VERget_pred_succ();

            //browse every successor and predecessor and see if they are linked to the same other vertex
            for (unsigned int uiIndex_pred_succ = 0; uiIndex_pred_succ < uiNb_edges_current_vertex; uiIndex_pred_succ++) {
                //get the id of the predecessor or successor of the current vertex
                unsigned int uiId_pred_succ = pTable_pred_succ_vertex[uiIndex_pred_succ];

                //get the number of edges of this predecessor (or successor)
                unsigned int uiNb_edges_pred_and_succ = GRAget_vertex_from_vertex_id(uiId_pred_succ)->VERget_nb_edges_in() + GRAget_vertex_from_vertex_id(uiId_pred_succ)->VERget_nb_edges_out();

                //if the number of edges of the current vertex and the number of edges of his predecessor (or successor) are the same
                if (uiNb_edges_pred_and_succ == uiNb_edges_current_vertex) {

                    //get the table of predecessor and successor of the predecessor/successor  (this table is sorted by increasing id)
                    unsigned int * pTab_pred_succ_of_succ = GRAget_vertex_from_vertex_id(uiId_pred_succ)->VERget_pred_succ();

                    //browse the two table of pred and succ
                    for (unsigned int uiIndex = 0; uiIndex < uiNb_edges_pred_and_succ; uiIndex++) {

                        if (pTable_pred_succ_vertex[uiIndex] != pTab_pred_succ_of_succ[uiIndex] //if the two id present in the two table are not the same
                                //and the id present in the table of the vertex is different of the id of his succ/pred or
                                // if the id present in the table of the pred/succ is different of the id of the vertex
                                && (pTable_pred_succ_vertex[uiIndex] != uiId_pred_succ || pTab_pred_succ_of_succ[uiIndex] != ppGRAlist_vertex[uiIndex_vertex]->VERget_id_vertex())) {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            }
        }
    }

    return true;

}

unsigned int Cgraph::GRAcount_nb_edge_of_successor(unsigned int uiIndex_vertex) {
    //browse every successor of the vertex at index 0 and count the number of edge of his successors
    unsigned int uiNb_edges_of_successors = 0;
    for (unsigned int uiIndex_succ = 0; uiIndex_succ < this->GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_in(); uiIndex_succ++) {
        uiNb_edges_of_successors = uiNb_edges_of_successors + this->GRAget_vertex_from_vertex_id(this->GRAget_vertex(uiIndex_vertex)->VERget_list_edges_in()[uiIndex_succ]->EDGget_id_vertex_in())->VERget_nb_edges_in();
        uiNb_edges_of_successors = uiNb_edges_of_successors + this->GRAget_vertex_from_vertex_id(this->GRAget_vertex(uiIndex_vertex)->VERget_list_edges_in()[uiIndex_succ]->EDGget_id_vertex_in())->VERget_nb_edges_out();

    }
    for (unsigned int uiIndex_succ = 0; uiIndex_succ < this->GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_out(); uiIndex_succ++) {
        uiNb_edges_of_successors = uiNb_edges_of_successors + this->GRAget_vertex_from_vertex_id(this->GRAget_vertex(uiIndex_vertex)->VERget_list_edges_out()[uiIndex_succ]->EDGget_id_vertex_in())->VERget_nb_edges_in();
        uiNb_edges_of_successors = uiNb_edges_of_successors + this->GRAget_vertex_from_vertex_id(this->GRAget_vertex(uiIndex_vertex)->VERget_list_edges_out()[uiIndex_succ]->EDGget_id_vertex_in())->VERget_nb_edges_out();

    }
    return uiNb_edges_of_successors;
}

unsigned int Cgraph::GRAget_max_nb_edge_of_successor() {
    unsigned int uiMax_count_nb_edge_of_successor = 0;
    unsigned int uiNb_edges = 0;
    unsigned int uiCurrent_count = 0;
    for (unsigned int uiIndex_vertex = 0; uiIndex_vertex < GRAget_nb_vertex(); uiIndex_vertex++) {
        uiCurrent_count = GRAcount_nb_edge_of_successor(uiIndex_vertex); //number of edge of the successor of the current vertex

        uiNb_edges = GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_out() + GRAget_vertex(uiIndex_vertex)->VERget_nb_edges_in(); //number of edge of the current vertex

        if (uiNb_edges == 0)uiNb_edges = 1;

        if (uiMax_count_nb_edge_of_successor < (uiCurrent_count / uiNb_edges)) {
            uiMax_count_nb_edge_of_successor = uiCurrent_count / uiNb_edges;
        }
    }
    return uiMax_count_nb_edge_of_successor;
}

/***
 *operator=(const Cgraph &graph_to_copy) - set the value of a graph with equal operator
 *
 *Purpose:
 *       set the value of a graph with equal operator
 *
 *Entry:
 *		const Cgraph &	graph_to_copy	-	the graph to copy (use to set the value)
 *
 *Return:
 *		none
 *
 *******************************************************************************/
Cgraph & Cgraph::operator=(const Cgraph &graph_to_copy) {
    if (&graph_to_copy != NULL) {
        uiGRAnb_vertex = graph_to_copy.uiGRAnb_vertex;

        ppGRAlist_vertex = new Cvertex*[uiGRAnb_vertex];
        for (unsigned int indexOfVertex = 0; indexOfVertex < uiGRAnb_vertex; indexOfVertex++) {
            ppGRAlist_vertex[indexOfVertex] = new Cvertex(*graph_to_copy.ppGRAlist_vertex[indexOfVertex]);
        }
    } else {
        uiGRAnb_vertex = 0;
        ppGRAlist_vertex = NULL;

    }
    return *this;
}

/***
 *operator==(Cgraph &graphToCompare) - compare two graph
 *
 *Purpose:
 *       compare two graph
 *
 *Entry:
 *		Cgraph &	graphToCompare	-	the graph to compare
 *
 *Return:
 *		none
 *
 *******************************************************************************/
bool Cgraph::operator==(Cgraph &graphToCompare)const {
    if (this == NULL && &graphToCompare == NULL) {
        return true; //if both pointer are null they are equal
    } else if (this == NULL || &graphToCompare == NULL) {
        return false; //if one pointer is null and other one not , they are different
    } else {
        //test if number of vertex are the same
        if (graphToCompare.uiGRAnb_vertex == uiGRAnb_vertex) {
            //compare pointer on vertex list if the pointer are the same the graph are equal (that appear normally only if the two graph don't have NULL list of vertex)
            if (graphToCompare.ppGRAlist_vertex == ppGRAlist_vertex) {
                return true;
            } else {
                //test if content of vertex list are the same 
                for (unsigned int uiIndexVertex = 0; uiIndexVertex < uiGRAnb_vertex; uiIndexVertex++) {
                    if (*ppGRAlist_vertex[uiIndexVertex] != *graphToCompare.ppGRAlist_vertex[uiIndexVertex]) {
                        return false; //one element is different so they are not equal
                    }
                }
                return true; //the vertex list are the same in both graph so they are equal
            }
        } else {
            return false; //if number of vertex are not the same
        }
    }
}

/***
 *operator!=(Cgraph &graphToCompare) - compare two graph
 *
 *Purpose:
 *       compare two graph
 *
 *Entry:
 *		Cgraph &	graphToCompare	-	the graph to compare
 *
 *Return:
 *		none
 *
 *******************************************************************************/
bool Cgraph::operator!=(Cgraph &graphToCompare)const {
    return !(*this == graphToCompare);
}