#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

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

	int i, height = 1024, width = 1024, amount_of_strings = 0;
	
	char **strings = (char **)malloc(height * sizeof(char *));
	for (i = 0; i < height; i++)
		strings[i] = (char *)malloc(width * sizeof(char));

	while (!feof(input_file)) {
		fgets(strings[amount_of_strings], width, input_file);
		printf("String #%d -> %s\n", amount_of_strings + 1, strings[amount_of_strings]);
		amount_of_strings++;
	}
	fclose(input_file);

	free(strings);
	return EXIT_SUCCESS;
}