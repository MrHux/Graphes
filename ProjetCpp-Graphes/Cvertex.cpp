#include "stdafx.h"

/***
 * Cvertex() - allocate a new Cvertex and initialize it
 *
 *Purpose:
 *       allocate a new Cvertex and initialize it with null value
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cvertex::Cvertex() : Cvertex(0, NULL, NULL, 0, 0) {

}

/***
 * Cvertex() - create a new Cvertex with the value of another one
 *
 *Purpose:
 *       create a new Cvertex with the value of another one
 *
 *Entry:
 *       const Cvertex & vertex_to_copy  - the Cvertex to copy, if NULL do the same as default constructor
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cvertex::Cvertex(const Cvertex &vertex_to_copy) {
    if (&vertex_to_copy != NULL) {
        uiVERid_vertex = vertex_to_copy.uiVERid_vertex;
        uiVERnb_edges_in = vertex_to_copy.uiVERnb_edges_in;
        uiVERnb_edges_out = vertex_to_copy.uiVERnb_edges_out;

        if (uiVERnb_edges_in != 0) {
            ppVERlist_edges_in = new Cedges*[uiVERnb_edges_in];
            for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {
                ppVERlist_edges_in[indexOfEdgeIn] = new Cedges(*vertex_to_copy.ppVERlist_edges_in[indexOfEdgeIn]);
            }
        }
        else{
            ppVERlist_edges_in=NULL;
        }

        if (uiVERnb_edges_out != 0) {
            ppVERlist_edges_out = new Cedges*[uiVERnb_edges_out];
            for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {
                ppVERlist_edges_out[indexOfEdgeOut] = new Cedges(*vertex_to_copy.ppVERlist_edges_out[indexOfEdgeOut]);
            }
        }
        else{
            ppVERlist_edges_out=NULL;
        }

    } else {
        uiVERid_vertex = 0;
        uiVERnb_edges_in = 0;
        uiVERnb_edges_out = 0;
        ppVERlist_edges_in = NULL;
        ppVERlist_edges_out = NULL;

    }
}

/***
 * Cvertex() - create a new Cvertex with the value in parameters
 *
 *Purpose:
 *       create a new Cvertex with the value in parameters
 *		ppList_edges_out, ppList_edges_in need to have a correct number of edge respectively in uiNb_edges_out, uiNb_edges_in
 *
 *Entry:
 *       unsigned	int uiId_vertex		- the id of the vertex
 *		Cedges **	ppList_edges_out	- the list of edges who go out the vertex
 *		Cedges **	ppList_edges_in		- the list of edges who go in the vertex
 *		unsigned	int uiNb_edges_out	- number of edges who go out the vertex
 *		unsigned	int uiNb_edges_in	- number of edges who go in the vertex
 *
 *Return:
 *		nothing
 *
 *Throws:
 *		ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL	-	if one of the list in parameter is NULL and the number of edges associated is not 0
 *		ERROR_LIST_NOT_NULL					-	if one of the list in parameter is not NULL and the number of edges associated is 0
 *
 *******************************************************************************/
Cvertex::Cvertex(unsigned int uiId_vertex, Cedges** ppList_edges_out, Cedges** ppList_edges_in, unsigned int uiNb_edges_out, unsigned int uiNb_edges_in) throw (Cexception) {
    ppVERlist_edges_in = NULL;
    ppVERlist_edges_out = NULL;

    if ((uiNb_edges_in != 0 && ppList_edges_in == NULL) || (uiNb_edges_out != 0 && ppList_edges_out == NULL)) {
        Cexception exc(ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL);
        throw exc;
    } else if ((uiNb_edges_in == 0 && ppList_edges_in != NULL) || (uiNb_edges_out == 0 && ppList_edges_out != NULL)) {
        Cexception exc(ERROR_LIST_NOT_NULL);
        throw exc;
    } else {
        uiVERid_vertex = uiId_vertex;
        uiVERnb_edges_in = uiNb_edges_in;
        uiVERnb_edges_out = uiNb_edges_out;

        if (uiNb_edges_in != 0) {
            ppVERlist_edges_in = new Cedges*[uiVERnb_edges_in];

            for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {

                ppVERlist_edges_in[indexOfEdgeIn] = new Cedges(*ppList_edges_in[indexOfEdgeIn]);
            }
        }
        if (uiNb_edges_out != 0) {
            ppVERlist_edges_out = new Cedges*[uiVERnb_edges_out];
            if (uiNb_edges_out == 0) {
                ppVERlist_edges_out[0] = NULL;
            }
            for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {

                ppVERlist_edges_out[indexOfEdgeOut] = new Cedges(*ppList_edges_out[indexOfEdgeOut]);
            }
        }
    }
}

/***
 * ~Cvertex() - destroy a Cvertex correctly
 *
 *Purpose:
 *       destroy a Cvertex correctly
 *
 *Entry:
 *		none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cvertex::~Cvertex() {

    //delete the list of edge in
    if (ppVERlist_edges_in != NULL) {
        for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {
            if (ppVERlist_edges_in[indexOfEdgeIn] != NULL) {
                delete ppVERlist_edges_in[indexOfEdgeIn];
                ppVERlist_edges_in[indexOfEdgeIn] = NULL;
            }
        }
        delete[] ppVERlist_edges_in;
        ppVERlist_edges_in = NULL;

    }
    
    //delete the list of edge 
    if (ppVERlist_edges_out != NULL) {
        for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {
            if (ppVERlist_edges_out[indexOfEdgeOut] != NULL) {
                delete ppVERlist_edges_out[indexOfEdgeOut];
                ppVERlist_edges_out[indexOfEdgeOut] = NULL;
            }
        }
        delete[] ppVERlist_edges_out;
        ppVERlist_edges_out = NULL;
    }


    uiVERnb_edges_in = 0;
    uiVERnb_edges_out = 0;
}

/***
 * VERset_id_vertex(unsigned int uiId) - set the id of a vertex
 *
 *Purpose:
 *       set the id of a vertex
 *
 *Entry:
 *       unsigned	int uiId	-	the id of the vertex
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cvertex::VERset_id_vertex(unsigned int uiId) {
    uiVERid_vertex = uiId;
}

/***
 * VERset_list_edges_out(Cedges** ppList_edges_out, unsigned int uiNb_edges_out) - set the list of edge who go out the vertex
 *
 *Purpose:
 *       set the list of edge who go out the vertex
 *		ppList_edges_out need to have a correct number of edge uiNb_edges_out
 *
 *Entry:
 *		Cedges **	ppList_edges_out	- the list of edges who go out the vertex
 *		unsigned	int uiNb_edges_out	- number of edges who go out the vertex
 *
 *Return:
 *		nothing
 *
 *Throws
 *		ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL	-	if the list in parameter is NULL and the number of edges associated is not 0
 *		ERROR_LIST_NOT_NULL					-	if the list in parameter is not NULL and the number of edges associated is 0
 *
 *******************************************************************************/
void Cvertex::VERset_list_edges_out(Cedges** ppList_edges_out, unsigned int uiNb_edges_out) throw (Cexception) {
    if (ppList_edges_out == NULL && uiNb_edges_out != 0) {
        Cexception exc(ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL);
        throw exc;
    } else if (ppList_edges_out != NULL && uiNb_edges_out == 0) {
        Cexception exc(ERROR_LIST_NOT_NULL);
        throw exc;
    } else {
        if (uiVERnb_edges_out == 0) {
            uiVERnb_edges_out = uiNb_edges_out;
            //if the new list is null
            if (uiVERnb_edges_out == 0 && ppList_edges_out == NULL) {
                ppVERlist_edges_out = NULL;
            }//if the new list is not null
            else {
                ppVERlist_edges_out = new Cedges*[uiVERnb_edges_out];
                for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {
                    ppVERlist_edges_out[indexOfEdgeOut] = new Cedges(*ppList_edges_out[indexOfEdgeOut]);
                }
            }
        } else {
            //delete the old list
            for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {
                delete ppVERlist_edges_out[indexOfEdgeOut];
            }
            delete[] ppVERlist_edges_out;

            //set the new one
            uiVERnb_edges_out = uiNb_edges_out;
            ppVERlist_edges_out = new Cedges*[uiVERnb_edges_out];
            for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {
                ppVERlist_edges_out[indexOfEdgeOut] = new Cedges(*ppList_edges_out[indexOfEdgeOut]);
            }
        }
    }
}

/***
 * VERset_list_edges_in(Cedges** ppList_edges_in, unsigned int uiNb_edges_in) - set the list of edge who go in the vertex
 *
 *Purpose:
 *       set the list of edge who go in of the vertex
 *		ppList_edges_in need to have a correct number of edge uiNb_edges_in
 *
 *Entry:
 *		Cedges **	ppList_edges_in	- the list of edges who go in the vertex
 *		unsigned	int uiNb_edges_in	- number of edges who go in the vertex
 *
 *Return:
 *		nothing
 *
 *	rows
 *		ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL	-	if the list in parameter is NULL and the number of edges associated is not 0
 *		ERROR_LIST_NOT_NULL					-	if the list in parameter is not NULL and the number of edges associated is 0
 *
 *******************************************************************************/
void Cvertex::VERset_list_edges_in(Cedges** ppList_edges_in, unsigned int uiNb_edges_in) throw (Cexception) {
    if (ppList_edges_in == NULL && uiNb_edges_in != 0) {
        Cexception exc(ERROR_NULL_LIST_NB_ELEMENT_NOT_NULL);
        throw exc;
    } else if (ppList_edges_in != NULL && uiNb_edges_in == 0) {
        Cexception exc(ERROR_LIST_NOT_NULL);
        throw exc;
    } else {
        if (uiVERnb_edges_in == 0) {
            uiVERnb_edges_in = uiNb_edges_in;
            if (uiVERnb_edges_in == 0 && ppList_edges_in == NULL) {
                ppVERlist_edges_in = NULL;
            } else {
                ppVERlist_edges_in = new Cedges*[uiVERnb_edges_in];
                for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {
                    ppVERlist_edges_in[indexOfEdgeIn] = new Cedges(*ppList_edges_in[indexOfEdgeIn]);
                }
            }
        }//if initial list is not empty 
        else {
            for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {
                delete ppVERlist_edges_in[indexOfEdgeIn];
            }
            delete[] ppVERlist_edges_in;

            uiVERnb_edges_in = uiNb_edges_in;
            ppVERlist_edges_in = new Cedges*[uiVERnb_edges_in];
            for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {
                ppVERlist_edges_in[indexOfEdgeIn] = new Cedges(*ppList_edges_in[indexOfEdgeIn]);
            }
        }
    }
}

/***
 * VERadd_edge_to_list_edges_out(Cedges * pEdge_to_add) - add an edge to the list of edge who go out the vertex
 *
 *Purpose:
 *       add an edge to the list of edge who go out the vertex
 *		if the edge is already in the list it's not added
 *
 *Entry:
 *		Cedges *	 pEdge_to_add	- the edge to add to the list
 *
 *Return:
 *		unsigned int	-	the position of the edge in the list
 *
 *******************************************************************************/
unsigned int Cvertex::VERadd_edge_to_list_edges_out(Cedges * pEdge_to_add) {
    unsigned int uiIndexEdge = VERfind_index_in_list_edge_out(pEdge_to_add);
    //if the edge is found
    if (uiIndexEdge < uiVERnb_edges_out) {
        return uiIndexEdge;
    } else {
        Cedges ** ppListEdgeConcat = new Cedges*[uiVERnb_edges_out + 1];
        for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_out; indexOfEdge++) {
            ppListEdgeConcat[indexOfEdge] = new Cedges(*ppVERlist_edges_out[indexOfEdge]);
        }
        ppListEdgeConcat[uiVERnb_edges_out] = new Cedges(*pEdge_to_add); //add new edge

        if (ppVERlist_edges_out != NULL && uiVERnb_edges_out != 0) {
            for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_out; indexOfEdge++) {
                delete ppVERlist_edges_out[indexOfEdge];
                ppVERlist_edges_out[indexOfEdge] = NULL;
            }
            delete[] ppVERlist_edges_out;
        }

        ppVERlist_edges_out = ppListEdgeConcat;
        uiVERnb_edges_out++;
        return uiVERnb_edges_out - 1; //return the index of the vertex who has just been inserted
    }
}

/***
 * VERadd_edge_to_list_edges_in(Cedges * pEdge_to_add) - add an edge to the list of edge who go in the vertex
 *
 *Purpose:
 *       add an edge to the list of edge who go in the vertex
 *		if the edge is already in the list it's not added
 *
 *Entry:
 *		Cedges *	 pEdge_to_add	- the edge to add to the list
 *
 *Return:
 *		unsigned int	-	the position of the edge in the list
 *
 *******************************************************************************/
unsigned int Cvertex::VERadd_edge_to_list_edges_in(Cedges * pEdge_to_add) {
    unsigned int uiIndexEdge = VERfind_index_in_list_edge_in(pEdge_to_add);
    if (uiIndexEdge < uiVERnb_edges_in) {
        return uiIndexEdge;
    } else {
        Cedges ** ppListEdgeConcat = new Cedges*[uiVERnb_edges_in + 1];
        for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_in; indexOfEdge++) {
            ppListEdgeConcat[indexOfEdge] = new Cedges(*ppVERlist_edges_in[indexOfEdge]);
        }
        ppListEdgeConcat[uiVERnb_edges_in] = new Cedges(*pEdge_to_add); //add new edge

        if (ppVERlist_edges_in != NULL && uiVERnb_edges_in != 0) {
            for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_in; indexOfEdge++) {
                delete ppVERlist_edges_in[indexOfEdge];
                ppVERlist_edges_in[indexOfEdge] = NULL;
            }
            delete[] ppVERlist_edges_in; //bug free ne veut pas lib�rer la m�moire pour une raison pour le moment ind�termin�.
        }

        ppVERlist_edges_in = ppListEdgeConcat;
        uiVERnb_edges_in++;
        return uiVERnb_edges_in - 1; //return the index of thevertex who has just been inserted
    }
}

/***
 * VERremove_edge_from_list_edges_out(unsigned int uiId_vertex_out_edge_to_delete) - remove an edge of the list of edge who go out the vertex
 *
 *Purpose:
 *       remove an edge of the list of edge who go out the vertex
 *		if the edge is not in the list that return NULL
 *
 *Entry:
 *		unsigned int	uiId_vertex_out_edge_to_delete	-	the Id of the vertex in the edge
 *
 *Return:
 *		Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
 *
 *******************************************************************************/
Cedges * Cvertex::VERremove_edge_from_list_edges_out(unsigned int uiId_vertex_out_edge_to_delete) {
    unsigned int uiIndexOfEdgeToDelete = VERfind_index_in_list_edge_out(uiId_vertex_out_edge_to_delete);
    if (uiIndexOfEdgeToDelete > uiVERnb_edges_out) {
        return NULL;
    }
    return VERremove_edge_from_list_edges_out(ppVERlist_edges_out[uiIndexOfEdgeToDelete]);
}

/***
 * VERremove_edge_from_list_edges_in(unsigned int uiId_vertex_in_edge_to_delete) - remove an edge of the list of edge who go in the vertex
 *
 *Purpose:
 *       remove an edge of the list of edge who go in the vertex
 *		if the edge is not in the list that return NULL
 *
 *Entry:
 *		unsigned int	uiId_vertex_out_edge_to_delete	-	the Id of the vertex in the edge
 *
 *Return:
 *		Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
 *
 *******************************************************************************/
Cedges * Cvertex::VERremove_edge_from_list_edges_in(unsigned int uiId_vertex_out_edge_to_delete) {
    unsigned int uiIndexOfEdgeToDelete = VERfind_index_in_list_edge_in(uiId_vertex_out_edge_to_delete);
    //if the edge is not found
    if (uiIndexOfEdgeToDelete > uiVERnb_edges_in) {
        return NULL;
    }
    return VERremove_edge_from_list_edges_in(ppVERlist_edges_in[uiIndexOfEdgeToDelete]);
}

/***
 * VERremove_edge_from_list_edges_out(unsigned int uiId_vertex_out_edge_to_delete) - remove an edge of the list of edge who go out the vertex
 *
 *Purpose:
 *       remove an edge of the list of edge who go out the vertex
 *		if the edge is not in the list that return NULL
 *
 *Entry:
 *		Cedges *	pEdge_to_delete	-	pointer on the Cedges to remove (this pointer don't need to be a pointer on the Cedges in the graph, but can be a copy of the Cedges)
 *
 *Return:
 *		Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
 *
 *******************************************************************************/
Cedges * Cvertex::VERremove_edge_from_list_edges_out(Cedges * pEdge_to_delete) {
    unsigned int uiIndexOfEdgeToDelete = VERfind_index_in_list_edge_out(pEdge_to_delete);
    if (uiIndexOfEdgeToDelete < uiVERnb_edges_out) {
        Cedges * pOldEdgeToDelete = new Cedges(*ppVERlist_edges_out[uiIndexOfEdgeToDelete]);
        Cedges ** ppListEdgeConcat = NULL;

        if (uiVERnb_edges_out > 1) {
            ppListEdgeConcat = new Cedges*[uiVERnb_edges_out - 1];
            for (unsigned int indexOfEdge = 0; indexOfEdge < uiIndexOfEdgeToDelete; indexOfEdge++) {
                ppListEdgeConcat[indexOfEdge] = new Cedges(*ppVERlist_edges_out[indexOfEdge]);
            }

            for (unsigned int indexOfEdge = uiIndexOfEdgeToDelete + 1; indexOfEdge < uiVERnb_edges_out; indexOfEdge++) {
                ppListEdgeConcat[indexOfEdge - 1] = new Cedges(*ppVERlist_edges_out[indexOfEdge]);
            }
        }

        //delete old list
        for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_out; indexOfEdge++) {
            delete ppVERlist_edges_out[indexOfEdge];
        }
        delete[] ppVERlist_edges_out;

        ppVERlist_edges_out = ppListEdgeConcat;
        uiVERnb_edges_out--;

        return pOldEdgeToDelete;
    }
    return NULL;
}

/***
 * VERremove_edge_from_list_edges_in(unsigned int uiId_vertex_in_edge_to_delete) - remove an edge of the list of edge who go in the vertex
 *
 *Purpose:
 *       remove an edge of the list of edge who go in the vertex
 *		if the edge is not in the list that return NULL
 *
 *Entry:
 *		Cedges *	pEdge_to_delete	-	pointer on the Cedges to remove (this pointer don't need to be a pointer on the Cedges in the graph, but can be a copy of the Cedges)
 *
 *Return:
 *		Cedges *	-	if !NULL a pointer on the Cedges who has been successfully removed
 *
 *******************************************************************************/
Cedges * Cvertex::VERremove_edge_from_list_edges_in(Cedges * pEdge_to_delete) {
    //find the index of the edge we want to remove
    unsigned int uiIndexOfEdgeToDelete = VERfind_index_in_list_edge_in(pEdge_to_delete);
    //if the index of the edge we want to remove exist , if it don't exist then his value will be higher than uiVERnb_edges_in
    if (uiIndexOfEdgeToDelete < uiVERnb_edges_in) {

        //made a copy of the edge to delete, it will be returned by the function
        Cedges * pOldEdgeToDelete = new Cedges(*ppVERlist_edges_in[uiIndexOfEdgeToDelete]);
        //new list of the edge who remain
        Cedges ** ppListEdgeConcat = NULL;

        //if the number of edge in the list is higher than one , we need to create a new list without the edge we want to remove
        if (uiVERnb_edges_in > 1) {
            //allocate a new list with -1 edge
            ppListEdgeConcat = new Cedges*[uiVERnb_edges_in - 1];

            //copy the first part of the list until we reach the edge we want to remove
            for (unsigned int indexOfEdge = 0; indexOfEdge < uiIndexOfEdgeToDelete; indexOfEdge++) {
                ppListEdgeConcat[indexOfEdge] = new Cedges(*ppVERlist_edges_in[indexOfEdge]);
            }
            //continue to copy after the removed edge
            for (unsigned int indexOfEdge = uiIndexOfEdgeToDelete + 1; indexOfEdge < uiVERnb_edges_in; indexOfEdge++) {
                ppListEdgeConcat[indexOfEdge - 1] = new Cedges(*ppVERlist_edges_in[indexOfEdge]);
            }
        }
            //delete old list
            for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_in; indexOfEdge++) {
                delete ppVERlist_edges_in[indexOfEdge];
            }
            delete[] ppVERlist_edges_in;
        

        //put the new list without the removed edge
        ppVERlist_edges_in = ppListEdgeConcat;
        uiVERnb_edges_in--;
        //return the removed edge
        return pOldEdgeToDelete;
    }
    return NULL;
}

/***
 * VERfind_index_in_list_edge_out(Cedges * pEdge_to_find) - find the index of a Cedges in the list of edge who go out of the vertex
 *
 *Purpose:
 *       find the index of a Cedges in the list of edge who go out of the vertex
 *
 *Entry:
 *		Cedges *	pEdge_to_find		- pointer on the edge to search
 *
 *Return:
 *		unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
 *		
 *
 *******************************************************************************/
unsigned int Cvertex::VERfind_index_in_list_edge_out(Cedges * pEdge_to_find) {
    if (ppVERlist_edges_out != NULL && uiVERnb_edges_out != 0) {
        for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_out; indexOfEdge++) {
            if (pEdge_to_find->EDGget_id_vertex_in() == ppVERlist_edges_out[indexOfEdge]->EDGget_id_vertex_in()) {
                return indexOfEdge;
            }
        }
    }
    return UINT_MAX;
}

/***
 * VERfind_index_in_list_edge_in(Cedges * pEdge_to_find) - find the index of a Cedges in the list of edge who go in of the vertex
 *
 *Purpose:
 *       find the index of a Cedges in the list of edge who go in of the vertex
 *
 *Entry:
 *		Cedges *	pEdge_to_find		- pointer on the edge to search
 *
 *Return:
 *		unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
 *
 *
 *******************************************************************************/
unsigned int Cvertex::VERfind_index_in_list_edge_in(Cedges * pEdge_to_find) {
    if (ppVERlist_edges_in != NULL && uiVERnb_edges_in != 0) {
        for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_in; indexOfEdge++) {
            if (pEdge_to_find->EDGget_id_vertex_in() == ppVERlist_edges_in[indexOfEdge]->EDGget_id_vertex_in()) {
                return indexOfEdge;
            }
        }
    }
    return UINT_MAX;
}

/***
 * VERfind_index_in_list_edge_out(unsigned int uiId_vertex_out_edge_to_find) - find the index of a Cedges in the list of edge who go out of the vertex
 *
 *Purpose:
 *       find the index of a Cedges in the list of edge who go out of the vertex
 *
 *Entry:
 *		unsigned int	uiId_vertex_out_edge_to_find	- id of the vertex inside the edge to search
 *
 *Return:
 *		unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
 *
 *
 *******************************************************************************/
unsigned int Cvertex::VERfind_index_in_list_edge_out(unsigned int uiId_vertex_out_edge_to_find) {
    for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_out; indexOfEdge++) {
        if (ppVERlist_edges_out[indexOfEdge]->EDGget_id_vertex_in() == uiId_vertex_out_edge_to_find) {
            return indexOfEdge;
        }
    }
    return UINT_MAX;
}

/***
 * VERfind_index_in_list_edge_in(unsigned int uiId_vertex_out_edge_to_find) - find the index of a Cedges in the list of edge who go in of the vertex
 *
 *Purpose:
 *       find the index of a Cedges in the list of edge who go out of the vertex
 *
 *Entry:
 *		unsigned int	uiId_vertex_out_edge_to_find	- id of the vertex inside the edge to search
 *
 *Return:
 *		unsigned in	-	the index of the edge in the list, if the edge is not found return UINT_MAX
 *
 *
 *******************************************************************************/
unsigned int Cvertex::VERfind_index_in_list_edge_in(unsigned int uiId_vertex_out_edge_to_find) {
    for (unsigned int indexOfEdge = 0; indexOfEdge < uiVERnb_edges_in; indexOfEdge++) {
        if (ppVERlist_edges_in[indexOfEdge]->EDGget_id_vertex_in() == uiId_vertex_out_edge_to_find) {
            return indexOfEdge;
        }
    }
    return UINT_MAX;
}

/***
 * VERget_id_vertex() - get the id of the vertex
 *
 *Purpose:
 *       get the id of the vertex
 *
 *Return:
 *		unsigned in	-	the id of the vertex
 *
 *
 *******************************************************************************/
unsigned int Cvertex::VERget_id_vertex() {
    return uiVERid_vertex;
}

/***
 * VERget_list_edges_out() - get the list of the edge who go out the vertex
 *
 *Purpose:
 *       get the list of the edge who go out the vertex
 *
 *Return:
 *		Cedges**	-	the list of edges
 *
 *
 *******************************************************************************/
Cedges** Cvertex::VERget_list_edges_out() {
    return ppVERlist_edges_out;
}

/***
 * VERget_list_edges_out() - get the list of the edge who go in the vertex
 *
 *Purpose:
 *       get the list of the edge who go in the vertex
 *
 *Return:
 *		Cedges**	-	the list of edges
 *
 *
 *******************************************************************************/
Cedges** Cvertex::VERget_list_edges_in() {
    return ppVERlist_edges_in;
}

/***
 * VERget_nb_edges_out() - get the number of edges who go out the vertex
 *
 *Purpose:
 *       get the number of edges who go out the vertex
 *
 *Entry:
 *		Cedges *	pEdge_to_find		- the edge to search
 *
 *Return:
 *		unsigned in	-	the number of edges of the list
 *
 *
 *******************************************************************************/
unsigned int Cvertex::VERget_nb_edges_out() {
    return uiVERnb_edges_out;
}

/***
 * VERget_nb_edges_out() - get the number of edges who go in the vertex
 *
 *Purpose:
 *       get the number of edges who go in the vertex
 *
 *Entry:
 *		Cedges *	pEdge_to_find		- the edge to search
 *
 *Return:
 *		unsigned in	-	the number of edges of the list
 *
 *
 *******************************************************************************/
unsigned int Cvertex::VERget_nb_edges_in() {
    return uiVERnb_edges_in;
}

unsigned int * Cvertex::VERget_pred_succ() {

    unsigned int * pTab_pred_succ = new unsigned int[uiVERnb_edges_in + uiVERnb_edges_out];
    unsigned int uiIndex_newtab = 0;

    //fill the table with the id of the successor
    for (unsigned int uiIndex_succ = 0; uiIndex_succ < uiVERnb_edges_out; uiIndex_succ++) {
        pTab_pred_succ[uiIndex_newtab] = ppVERlist_edges_out[uiIndex_succ]->EDGget_id_vertex_in();
        uiIndex_newtab++;
    }
    //fill the table with the id of the predecessor
    for (unsigned int uiIndex_pred = 0; uiIndex_pred < uiVERnb_edges_in; uiIndex_pred++) {
        pTab_pred_succ[uiIndex_newtab] = ppVERlist_edges_in[uiIndex_pred]->EDGget_id_vertex_in();
        uiIndex_newtab++;
    }

    //sort the table
    for (unsigned int uiIndex = 0; uiIndex < (uiVERnb_edges_in + uiVERnb_edges_out); uiIndex++) {
        unsigned int uiIndex2 = uiIndex;
        unsigned int * pVertex = &pTab_pred_succ[uiIndex];
        while (uiIndex2 > 0 && pTab_pred_succ[uiIndex2 - 1] > *pVertex) {
            pTab_pred_succ[uiIndex2] = pTab_pred_succ[uiIndex2 - 1];
            uiIndex2 = uiIndex2 - 1;
        }
        pTab_pred_succ[uiIndex2] = *pVertex;
    }

    return pTab_pred_succ;

}

bool Cvertex::VERis_vertex_equivalent(Cvertex * pVertexToCompare) {

    unsigned int * pTable_pred_succ_vertex = VERget_pred_succ();
    //get the id of the predecessor or successor of the current vertex
    unsigned int uiNbuiNb_edges_current_vertex = VERget_nb_edges_in() + VERget_nb_edges_out();

    //get the number of edges of this predecessor (or successor)
    unsigned int uiNb_edges_vertex_to_compare = pVertexToCompare->VERget_nb_edges_in() + pVertexToCompare->VERget_nb_edges_out();
    //if the number of edges of the current vertex and the number of edges of his predecessor (or successor) are the same
    if (uiNb_edges_vertex_to_compare == uiNbuiNb_edges_current_vertex) {

        unsigned int * pTab_pred_succ_of_vertex_to_compare = pVertexToCompare->VERget_pred_succ();

        for (unsigned int uiIndex = 0; uiIndex < uiNb_edges_vertex_to_compare; uiIndex++) {
            if (pTable_pred_succ_vertex[uiIndex] != pTab_pred_succ_of_vertex_to_compare[uiIndex]
                    && (pTable_pred_succ_vertex[uiIndex] != pVertexToCompare->VERget_id_vertex() || pTab_pred_succ_of_vertex_to_compare[uiIndex] != VERget_id_vertex())) {
                if (pTable_pred_succ_vertex[uiIndex] != pTab_pred_succ_of_vertex_to_compare[uiIndex + 1] && pTable_pred_succ_vertex[uiIndex] != pTab_pred_succ_of_vertex_to_compare[uiIndex - 1]) {
                    return false;
                }
            }
        }

    } else {
        return false;
    }

    return true;
}

/***
 * operator=(const Cvertex &vertex_to_copy) - equal operator
 *
 *Purpose:
 *       enable the affectation of a Cvertex by another.
 *
 *Entry:
 *		const Cvertex &	vertex_to_copy	- the Cvertex to copy
 *
 *Return:
 *		
 *		Cvertex  &	-	change the values of the object who call the operator
 *
 *******************************************************************************/
Cvertex & Cvertex::operator=(const Cvertex &vertex_to_copy) {
    if (&vertex_to_copy != NULL) {
        uiVERid_vertex = vertex_to_copy.uiVERid_vertex;
        uiVERnb_edges_in = vertex_to_copy.uiVERnb_edges_in;
        uiVERnb_edges_out = vertex_to_copy.uiVERnb_edges_out;

        ppVERlist_edges_in = new Cedges*[uiVERnb_edges_in];
        for (unsigned int indexOfEdgeIn = 0; indexOfEdgeIn < uiVERnb_edges_in; indexOfEdgeIn++) {

            ppVERlist_edges_in[indexOfEdgeIn] = new Cedges(*vertex_to_copy.ppVERlist_edges_in[indexOfEdgeIn]);
        }

        ppVERlist_edges_out = new Cedges*[uiVERnb_edges_out];
        for (unsigned int indexOfEdgeOut = 0; indexOfEdgeOut < uiVERnb_edges_out; indexOfEdgeOut++) {

            ppVERlist_edges_out[indexOfEdgeOut] = new Cedges(*vertex_to_copy.ppVERlist_edges_out[indexOfEdgeOut]);
        }


    } else {
        uiVERid_vertex = 0;
        uiVERnb_edges_in = 0;
        uiVERnb_edges_out = 0;
        ppVERlist_edges_in = NULL;
        ppVERlist_edges_out = NULL;

    }
    return *this;
}

/***
 * operator==(const Cvertex &vertex_to_copy) - compare two Cvertex
 *
 *Purpose:
 *       compare two Cvertex
 *
 *Entry:
 *		Cvertex &	vertexToCompare	- the Cvertex to compare
 *
 *Return:
 *
 *		bool	-	true if the two Cvertex are equal (in term of value not address), false if they are differents. 
 *
 *******************************************************************************/
bool Cvertex::operator==(Cvertex &vertexToCompare) {
    if (this == NULL && &vertexToCompare == NULL) {
        return true; //if both pointer are null they are equal
    } else if (this == NULL || &vertexToCompare == NULL) {
        return false; //if one pointer is null and other one not , they are different
    } else {
        //test if number of edge out and edge in are the same
        if (vertexToCompare.uiVERid_vertex == uiVERid_vertex && vertexToCompare.uiVERnb_edges_in == uiVERnb_edges_in && vertexToCompare.uiVERnb_edges_out == uiVERnb_edges_out) {
            //compare pointer on edges Array if the pointer are the same the vertex are equal (but that should not appear)
            if (vertexToCompare.ppVERlist_edges_in == ppVERlist_edges_in && vertexToCompare.ppVERlist_edges_out == ppVERlist_edges_out) {
                return true;
            } else {
                //test if content of edge array are the same 
                for (unsigned int uiIndexEdgesIn = 0; uiIndexEdgesIn < uiVERnb_edges_in; uiIndexEdgesIn++) {
                    if (ppVERlist_edges_in[uiIndexEdgesIn]->EDGget_id_vertex_in() != vertexToCompare.ppVERlist_edges_in[uiIndexEdgesIn]->EDGget_id_vertex_in()) {
                        return false; //one element is different so they are not equal
                    }
                }
                for (unsigned int uiIndexEdgesOut = 0; uiIndexEdgesOut < uiVERnb_edges_out; uiIndexEdgesOut++) {
                    if (ppVERlist_edges_out[uiIndexEdgesOut]->EDGget_id_vertex_in() != vertexToCompare.ppVERlist_edges_out[uiIndexEdgesOut]->EDGget_id_vertex_in()) {
                        return false; //one element is different so they are not equal
                    }
                }
                return true; //the edge array In/Out are the same in both vertex so they are equal
            }
        } else {
            return false; //if id , number of edge in/out are not the same
        }
    }
}

/***
 * operator!=(const Cvertex &vertex_to_copy) - compare two Cvertex
 *
 *Purpose:
 *       compare two Cvertex
 *
 *Entry:
 *		Cvertex &	vertexToCompare	- the Cvertex to compare
 *
 *Return:
 *
 *		bool	-	false if the two Cvertex are equal (in term of value not address), true if they are differents.
 *
 *******************************************************************************/
bool Cvertex::operator!=(Cvertex &vertexToCompare) {
    return !(*this == vertexToCompare);
}

