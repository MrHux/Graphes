#include "Cfile_UNIT.h"

void Cfile_UNIT::TEST_UNIT_parse_file()
{
	std::cout << " - Test : Parsing input file 1" << std::endl;

	char ** values1 = Cfile::FILparse_file(INPUT_FILE1);

	assert(strcmp(values1[0], "NBSommets") == 0);
	assert(strcmp(values1[1], "3") == 0);

	assert(strcmp(values1[2], "NBArcs") == 0);
	assert(strcmp(values1[3], "3") == 0);

	assert(strcmp(values1[4], "Sommets") == 0);
	assert(strcmp(values1[5], "[") == 0);

	assert(strcmp(values1[6], "Numero") == 0);
	assert(strcmp(values1[7], "1") == 0);
	assert(strcmp(values1[8], "Numero") == 0);
	assert(strcmp(values1[9], "2") == 0);
	assert(strcmp(values1[10], "Numero") == 0);
	assert(strcmp(values1[11], "3") == 0);

	assert(strcmp(values1[12], "]") == 0);

	assert(strcmp(values1[13], "Arcs") == 0);
	assert(strcmp(values1[14], "[") == 0);

	assert(strcmp(values1[15], "Debut") == 0);
	assert(strcmp(values1[16], "1") == 0);
	assert(strcmp(values1[17], "Fin") == 0);
	assert(strcmp(values1[18], "2") == 0);

	assert(strcmp(values1[19], "Debut") == 0);
	assert(strcmp(values1[20], "2") == 0);
	assert(strcmp(values1[21], "Fin") == 0);
	assert(strcmp(values1[22], "3") == 0);

	assert(strcmp(values1[23], "Debut") == 0);
	assert(strcmp(values1[24], "3") == 0);
	assert(strcmp(values1[25], "Fin") == 0);
	assert(strcmp(values1[26], "1") == 0);

	assert(strcmp(values1[27], "]") == 0);

	assert(values1[28] == NULL);

	std::cout << " - Test : Parsing input file 2" << std::endl << std::endl;

	char ** values2 = Cfile::FILparse_file(INPUT_FILE2);

	assert(strcmp(values2[0], "NBSommets") == 0);
	assert(strcmp(values2[1], "0") == 0);

	assert(strcmp(values2[2], "NBArcs") == 0);
	assert(strcmp(values2[3], "0") == 0);

	assert(strcmp(values2[4], "Sommets") == 0);
	assert(strcmp(values2[5], "[") == 0);
	assert(strcmp(values2[6], "]") == 0);

	assert(strcmp(values2[7], "Arcs") == 0);
	assert(strcmp(values2[8], "[") == 0);
	assert(strcmp(values2[9], "]") == 0);

	assert(values2[10] == NULL);
}