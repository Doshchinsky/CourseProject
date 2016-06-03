#include "main.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Missing the instruction for the program!\nHint: Please, try again!\n-c   Compressing\n-d   Decompressing\n");
		exit(EXIT_FAILURE);
	} else if (argc < 3) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Missing input file name!\nHint: Please, try again!\n");
		exit(EXIT_FAILURE);
	} else if (argc < 4) {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Missing binary file name!\nHint: Please, look up *.sf file!\n");
		exit(EXIT_FAILURE);
	}
	
	if ((argv[1][1] != 'c' || argv[1][1] != 'd') && argv[1][0] != '-') {
		fprintf(stderr, "CourseProject: An error has occured!\nERROR: Wrong instruction!\nHint: Please, check your input value!\n-c   Compressing\n-d   Decompressing\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1][1] == 'c') {
		compress(argv[2], argv[3]);
		printf("\nCourseProject: Completed!\nSTATUS: Compressing completed successfully!\n");
	} else {
		decompress(argv[2], argv[3]);
		printf("CourseProject: Completed!\nSTATUS: Decompressing completed successfully!\n");
	}
	return EXIT_SUCCESS;
}