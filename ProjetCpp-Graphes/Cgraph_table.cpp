#include "stdafx.h"

/***
 * Cgraph_table() - create a new Cgraph_table with null value
 *
 *Purpose:
 *       create a new Cgraph_table with null value
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph_table::Cgraph_table() {
    ppGRTgraph_table = NULL;
    uiGRTnb_graph = 0;
}

/***
 * Cgraph_table(const Cgraph_table & Cgraph_table_to_copy) - create a new Cgraph_table with the value of the one in parameter
 *
 *Purpose:
 *        create a new Cgraph_table with the value of the one in parameter
 *
 *Entry:
 *       const Cgraph_table & Cgraph_table_to_copy	-	the graph to copy
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph_table::Cgraph_table(const Cgraph_table & Cgraph_table_to_copy) {
    ppGRTgraph_table = NULL;
    uiGRTnb_graph = 0;
    for (unsigned int uiIndex = 0; uiIndex < Cgraph_table_to_copy.uiGRTnb_graph; uiIndex++) {
        //made a copy of each graph of the Cgraph_table in param and fill the new Cgraph_table
        GRTadd_graph(new Cgraph(*Cgraph_table_to_copy.ppGRTgraph_table[uiIndex]));
    }

}

/***
 * ~Cgraph_table() - delete correctly a Cgraph_table
 *
 *Purpose:
 *       delete correctly a Cgraph_table
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
Cgraph_table::~Cgraph_table() {
    GRTempty_table();
}

/***
 * void GRTempty_table() - remove all the Graph in the Cgraph_table
 *
 *Purpose:
 *       remove all the Graph in the Cgraph_table
 *
 *Entry:
 *       none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cgraph_table::GRTempty_table() {
    unsigned int uiIndex_of_graph = 0;

    while (uiIndex_of_graph < uiGRTnb_graph) {
        delete ppGRTgraph_table[uiIndex_of_graph];
        uiIndex_of_graph++;
    }
    delete [] ppGRTgraph_table;

    this->ppGRTgraph_table = NULL;
    this->uiGRTnb_graph = 0;
}

/***
 * Cgraph ** GRTget_graph_table() - get the table of graph at the index
 *
 *Purpose:
 *		get the table of graph
 *
 *Entry:
 *       none
 *
 *Return:
 *		Cgraph **	-	a pointer on the table
 *
 *******************************************************************************/
Cgraph ** Cgraph_table::GRTget_graph_table() {
    return ppGRTgraph_table;
}

/***
 * Cgraph * GRTget_graph(unsigned int uiIndex) - get the graph at the index
 *
 *Purpose:
 *		get the graph at the index in the table
 *
 *Entry:
 *       unsigned int uiIndex	-	the index of the graph to get
 *
 *Return:
 *		Cgraph *	-	a pointer on the graph
 *
 *******************************************************************************/
Cgraph * Cgraph_table::GRTget_graph(unsigned int uiIndex) {
    if (uiIndex < uiGRTnb_graph) {
        return ppGRTgraph_table[uiIndex];
    } else {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    }
}

/***
 * unsigned int GRTget_nb_graph() -	get the number of graph in the table
 *
 *Purpose:
 *       get the number of graph in the table
 *
 *Entry:
 *       none
 *
 *Return:
 *		unsigned int	-	the number of graph
 *
 *******************************************************************************/
unsigned int Cgraph_table::GRTget_nb_graph() {
    return uiGRTnb_graph;
}

/***
 * void GRTadd_graph(Cgraph * pGraph) - add a graph to the table
 *
 *Purpose:
 *       add a graph to the table, beware it add a copy of the graph in parameter
 *
 *Entry:
 *       Cgraph * pGraph	-	the graph to add
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cgraph_table::GRTadd_graph(Cgraph * pGraph) {
    Cgraph ** ppNew_graph_table = NULL;

    //create a new table with + 1 graph
    unsigned int uiIndexGraph = 0;
    ppNew_graph_table = new Cgraph*[uiGRTnb_graph + 1];
    for (uiIndexGraph = 0; uiIndexGraph < uiGRTnb_graph; uiIndexGraph++) {
        ppNew_graph_table[uiIndexGraph] = new Cgraph(*ppGRTgraph_table[uiIndexGraph]);
    }

    //delete the old table
    GRTempty_table();
    uiGRTnb_graph = uiIndexGraph; //GRTempty_table set uiIndexGraph to 0 so we need to get back the old number of graph
    //set the new table
    ppGRTgraph_table = ppNew_graph_table;

    //add the graph to the table
    ppGRTgraph_table[uiGRTnb_graph] = new Cgraph(*pGraph);
    uiGRTnb_graph++; //increment number of graph


}

/*delete graph at index, insert graph, modify graph, etc are function not essential for the purpose of the project but are function who could be interesting to add for that class*/

/***
 * Cgraph * Cgraph_table::GRT_delete_graph_at_index(unsigned int uiIndex) - delete a graph at the specified position
 *
 *Purpose:
 *       delete a graph at the specified position
 *
 *Entry:
 *		unsigned int uiIndex	-	index of the graph to be removed
 *
 *Return:
 *		Cgraph *	-	the graph who will be removed
 *
 *Throw:
 *		Throw an exception if index is outofbound
 *
 *******************************************************************************/
void Cgraph_table::GRT_delete_graph_at_index(unsigned int uiIndex) {

    Cgraph_table * pNew_graph_table = NULL;

    if (uiIndex <= GRTget_nb_graph()) {

        if (uiGRTnb_graph > 0) {
            pNew_graph_table = new Cgraph_table();

            //made a copy of the first uiIndex-1  graphs of the current Cgraph_table and fill the new Cgraph_table
            if (uiIndex != 0) {
                for (unsigned int uiIndex_of_graph = 0; uiIndex_of_graph < uiIndex; uiIndex_of_graph++) {
                    pNew_graph_table->GRTadd_graph(this->ppGRTgraph_table[uiIndex_of_graph]);
                }
            }

            //made a copy of the last graphs uiIndex+1 graphs of the current Cgraph_table and fill the new Cgraph_table
            for (unsigned int uiIndex_of_graph = uiIndex + 1; uiIndex_of_graph < this->GRTget_nb_graph(); uiIndex_of_graph++) {
                pNew_graph_table->GRTadd_graph(this->ppGRTgraph_table[uiIndex_of_graph]);
            }

            //update current object
            this->GRTempty_table();

            this->ppGRTgraph_table = pNew_graph_table->ppGRTgraph_table;
            this->uiGRTnb_graph = pNew_graph_table->uiGRTnb_graph;

            pNew_graph_table->ppGRTgraph_table = NULL;
            pNew_graph_table->uiGRTnb_graph = 0;

            delete pNew_graph_table;
        }

    } else {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    }
}

/***
 * void Cgraph_table::GRT_insert_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add) - insert a graph at the position in parameter
 *
 *Purpose:
 *       insert a graph at the position in parameter
 *
 *Entry:
 *		unsigned int uiIndex	-	index of the graph to be inserted
 *		Cgraph * pGraph	-	graph to set
 *
 *Return:
 *		Cgraph *	-	the graph who will be removed
 *
 *Throw:
 *		Throw an exception if index is outofbound
 *
 *******************************************************************************/
void Cgraph_table::GRT_insert_graph_at_index(unsigned int uiIndex, Cgraph * pCgraph_to_add) {
    Cgraph_table * pNew_graph_table = NULL;

    if (uiIndex <= GRTget_nb_graph()) {

        pNew_graph_table = new Cgraph_table();

        if (uiIndex != 0) {
            //made a copy of the first uiIndex-1  graphs of the current Cgraph_table and fill the new Cgraph_table
            for (unsigned int uiIndex_of_graph = 0; uiIndex_of_graph < uiIndex; uiIndex_of_graph++) {
                Cgraph * pNew_graph = new Cgraph(*this->ppGRTgraph_table[uiIndex_of_graph]);//create a new graph (copy of graph of the list)
                pNew_graph_table->GRTadd_graph(pNew_graph);
                delete pNew_graph;//desallocate the graph
            }
        }
        pNew_graph_table->GRTadd_graph(pCgraph_to_add); //add the graph at the position in parameter
        //made a copy of the last graphs uiIndex graphs of the current Cgraph_table and fill the new Cgraph_table
        for (unsigned int uiIndex_of_graph = uiIndex; uiIndex_of_graph < this->GRTget_nb_graph(); uiIndex_of_graph++) {
            Cgraph * pNewGraph = new Cgraph(*this->ppGRTgraph_table[uiIndex_of_graph]); // allocation of a copy of the graph 
            pNew_graph_table->GRTadd_graph(pNewGraph);//here the copy pNewGraph wiil be copied again
            delete pNewGraph;//desallocation of the copy
        }

        //update the current object
        this->GRTempty_table();

        this->ppGRTgraph_table = pNew_graph_table->ppGRTgraph_table;
        this->uiGRTnb_graph = pNew_graph_table->uiGRTnb_graph;

        pNew_graph_table->ppGRTgraph_table = NULL;
        pNew_graph_table->uiGRTnb_graph = 0;

        delete pNew_graph_table;

    } else if (uiIndex == GRTget_nb_graph() + 1) {
        GRTadd_graph(pCgraph_to_add);
    } else {
        Cexception exc(ERROR_INDEX_OUT_OF_BOUND);
        throw exc;
    }
}

/***
 * Cgraph * Cgraph_table::GRT_replace_graph_at_index(unsigned int uiIndex, Cgraph * pGraph) - replace the graph at the index by the one in parameter 
 *
 *Purpose:
 *       replace the graph at the index by the one in parameter 
 *
 *Entry:
 *		unsigned int uiIndex	-	index of the graph to be replaced
 *		Cgraph * pGraph	-	graph to set
 *
 *Return:
 *		Cgraph *	-	the graph who will be removed, null if the index is outofbound
 *
 *******************************************************************************/
Cgraph * Cgraph_table::GRT_replace_graph_at_index(unsigned int uiIndex, Cgraph * pGraph) {
    Cgraph * pGraph_to_be_removed = NULL;

    if (uiIndex <= GRTget_nb_graph()) {
        pGraph_to_be_removed = GRTget_graph(uiIndex);

        ppGRTgraph_table[uiIndex] = pGraph;
    }

    return pGraph_to_be_removed;
}

/***
 * void MITprint() - print the independant sets
 *
 *Purpose:
 *       print the independant sets
 *
 *Entry:
 * none
 *
 *Return:
 *		nothing
 *
 *******************************************************************************/
void Cgraph_table::GRTprint() {
    for (unsigned int uiIndex = 0; uiIndex < GRTget_nb_graph(); uiIndex++) {
        printf("\n\n\n***	%d) *** \n\n", (uiIndex + 1));
        ppGRTgraph_table[uiIndex]->GRAprint("-id_ver");

    }
}

/***
 *Cgraph & Cgraph_table::operator=(const Cgraph &graph_to_copy) - set the value of a graph table with equal operator
 *
 *Purpose:
 *       set the value of a graph table with equal operator
 *
 *Entry:
 *		const Cgraph &	graph_table_to_copy	-	the graph table to copy (use to set the value)
 *
 *Return:
 *		none
 *
 *******************************************************************************/
Cgraph_table & Cgraph_table::operator=(const Cgraph_table &graph_table_to_copy) {
    if (&graph_table_to_copy != NULL) {

        for (unsigned int uiIndex = 0; uiIndex < graph_table_to_copy.uiGRTnb_graph; uiIndex++) {
            //made a copy of each graph of the Cgraph_table in param and fill the new Cgraph_table
            GRTadd_graph(new Cgraph(*graph_table_to_copy.ppGRTgraph_table[uiIndex]));
        }
    } else {
        uiGRTnb_graph = 0;
        ppGRTgraph_table = NULL;

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
bool Cgraph_table::operator==(Cgraph_table &graph_table_to_compare)const {
    if (this == NULL && &graph_table_to_compare == NULL) {
        return true; //if both pointer are null they are equal
    } else if (this == NULL || &graph_table_to_compare == NULL) {
        return false; //if one pointer is null and other one not , they are different
    } else {
        //test if number of graph are the same
        if (graph_table_to_compare.uiGRTnb_graph == uiGRTnb_graph) {
            //compare pointer on graph table if the pointer are the same the graph table are equal (but that should not appear)
            if (graph_table_to_compare.ppGRTgraph_table == ppGRTgraph_table) {
                return true;
            } else {
                //test if content of graph table are the same 
                for (unsigned int uiIndexGraph = 0; uiIndexGraph < uiGRTnb_graph; uiIndexGraph++) {
                    if (*ppGRTgraph_table[uiIndexGraph] != *graph_table_to_compare.ppGRTgraph_table[uiIndexGraph]) {
                        return false; //one element is different so they are not equal
                    }
                }
                return true; //the graph are the same in both graph table so they are equal
            }
        } else {
            return false; //if number of graphs are not the same
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
bool Cgraph_table::operator!=(Cgraph_table &graph_table_to_compare)const {
    return !(*this == graph_table_to_compare);
}