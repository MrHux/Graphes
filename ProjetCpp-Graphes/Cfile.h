#ifndef PROJETCPP2_CFILE_H
#define PROJETCPP2_CFILE_H

#include "stdafx.h"

// String (char[]) buffer size
#define BUFFER_SIZE 1024

// Values of Cexception thrown
#define ERROR_INPUT_FILE_OPEN 10
#define ERROR_CHANGING_SIZE_TABLE_VALUES 11

// Path of test's files
#define INPUT_FILE1 ".\\Test_Files\\in\\graph1.txt"
#define INPUT_FILE2 ".\\Test_Files\\in\\graph2.txt"
#define INPUT_FILE3 ".\\Test_Files\\in\\graph3.txt"

// Important characters in the input files
#define CHARS_DELIMS_TOKENS "=, "

#define CHARS_VERTICES "Sommets"
#define CHARS_EDGES "Arcs"

#define CHARS_VALUE_VERTEX "Numero"

#define CHARS_VALUE_BEGIN_EDGE "Debut"
#define CHARS_VALUE_END_EDGE "Fin"

#define CHARS_BEGIN_NUMBERS "NB"

#define CHARS_BEGIN_NUMBER_VERTICES "NBSommets"
#define CHARS_BEGIN_NUMBER_EDGES    "NBArcs"

#define CHAR_BEGIN_TABLE "["
#define CHAR_END_TABLE "]"

class Cfile
{
public:

	/***
	* FILparse_file(const char * pcFile_to_parse) - parse the graph file (designated by pcFile_to_parse)
	*											   and construct a 2D table of cstring representing the file's contents
	*
	*Purpose:
	*       Parse a graph file to get its values. This method is used to construct a Cgraph
	*
	*Entry:
	*		const char * pcFile_to_parse - the graph file's path
	*
	*Return:
	*		char **	- All the values of the graph in the file.
	*
	*******************************************************************************/
	static char ** FILparse_file(const char* pcFile_to_parse) throw (Cexception);

};

#endif
