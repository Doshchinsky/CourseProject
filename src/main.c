#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Missing input file name!\nHint: Please, try again!\n");
		exit(EXIT_FAILURE);
	}
	char filename[10] = "./";
	strcat(filename, argv[1]);

	FILE *input_file;
	input_file = fopen(filename, "r");
	if (input_file == NULL) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Program can't open file '%s' for reading!\nHint: Please, check your file!\n", filename);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}