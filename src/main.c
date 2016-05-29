#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Missing the instruction for the program!\nHint: Please, try again!\n");
		exit(EXIT_FAILURE);
	}
	char instruction[2];
	strcpy(instruction, argv[1]);
	if (instruction[1] != 'c' && instruction[1] != 'd') {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Wrong instruction!\nHint: Please, check your input value!\n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", instruction);

	if (argc < 3) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Missing input file name!\nHint: Please, try again!\n");
		exit(EXIT_FAILURE);
	}
	char filename[10] = "./";
	strcat(filename, argv[2]);

	FILE *input_file;
	input_file = fopen(filename, "r");
	if (input_file == NULL) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Program can't open file '%s' for reading!\nHint: Please, check your file!\n", filename);
		exit(EXIT_FAILURE);
	}

	int i, j, height = 1024, width = 1024, amount_of_strings = 0;

	char **strings = (char **)malloc(height * sizeof(char *));
	for (i = 0; i < height; i++)
		strings[i] = (char *)malloc(width * sizeof(char));

	while (!feof(input_file)) {
		fgets(strings[amount_of_strings], width, input_file);
		amount_of_strings++;
	}
	fclose(input_file);

	array mass;
	array_init(&mass);
	for (i = 0; i < amount_of_strings; i++) {
		for ( j = 0; j < strlen(strings[i]); j++)
		{
			addelement(&mass, strings[i][j]);
		}
	}

	double probability[mass.count];
	for (i = 0; i < mass.count; i++) {
		probability[i] = mass.arr[i]->count;
		probability[i] /= mass.count;
	}

	printf("<------------------------------------------------------>\n");
	printf("\tSymbol:\tAmount:\tProbability:\tCode:\n");
	for (i = 0; i < mass.count; i++)
		if (mass.arr[i]->symbol != '\n')
			printf("\t%c\t%d\t%0.2f\n", mass.arr[i]->symbol, mass.arr[i]->count, probability[i]);
		else
			printf("\t \t%d\t%0.2f\n", mass.arr[i]->count, probability[i]);
	printf("\nTotal number of symbols: %d\n", mass.count);
	printf("<------------------------------------------------------>\n");
	free(strings);
	return EXIT_SUCCESS;
}