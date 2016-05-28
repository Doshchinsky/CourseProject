#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct _symbols
{
	char symbol;
	int count;
} symbols;

typedef struct _array
{
	symbols *arr[100];
	int count;	
} array;

void array_init(array *element);
int search(array element, char character);
void addelement(array *element, char character);

#endif