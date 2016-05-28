#define _CRT_SECURE_NO_WARNINGS
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

	int height = 1024, length = 1024, amount_of_words = 0;
	
	char **strings = (char **)malloc(height * sizeof(char *));
	char *input_word = (char *)malloc(length * sizeof(char));

	while (!feof(input_file)) {
		fscanf(input_file, "%s", input_word);
		strings[amount_of_words] = malloc(sizeof(input_word));
		strings[amount_of_words] = strdup(input_word);
		printf("String #%d -> %s\n", amount_of_words + 1, strings[amount_of_words]);
		amount_of_words++;
	}
	fclose(input_file);
	free(strings);

	return EXIT_SUCCESS;
}