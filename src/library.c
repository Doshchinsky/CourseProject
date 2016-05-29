#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "sfcompress.h"

void array_init(array *element)
{
	int i;
	for (i = 0; i < 100; i++)
		element->arr[i] = NULL;
	element->count = 0;
}

int search(array element, char character)
{
	int i;
	for (i = 0; i < 100; i++) {
		if (element.arr[i] != NULL && element.arr[i]->symbol == character)
			return i;
	}
	return -1;
}

void addelement(array *element, char character)
{
	int tmp = search(*element, character);
	if (tmp >= 0) {
		element->arr[tmp]->count++;
	} else {
		element->arr[element->count] = malloc(sizeof(symbols));
		element->arr[element->count]->symbol = character;
		element->arr[element->count]->count = 1;
		element->count++;
	}
}