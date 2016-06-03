#include "main.h"

void clear(tree *root)
{
	if (root->left != NULL)
		clear(root->left);
	if (root->right != NULL)
		clear(root->right);
	
	free(root);
}

int gototree(char c, tree **t)
{
	if (c == '0')
		(*t) = (*t)->left;
	else
		(*t) = (*t)->right;
	return (*t)->data;
}

tree* addelement(int v)
{
	tree *node = (tree*) malloc(sizeof(tree));
	node->right = node->left = NULL;
	node->data = v;
	return node;
} 

int bittochar(char v[])
{
	int i, temp = 0;
	for (i = 0; i < 8; ++i)
		if (v[7 - i] == '1')
			temp += (1 << i);
	return temp;
}

void chartobit(int val, char v[])
{
	int i;
	for (i = 7; i > 0; --i)
		{
			v[i] = (val % 2 == 1) ? '1' : '0';
			val /= 2;
		}
	v[0] = (val % 2 == 1) ? '1' : '0';
}

void writebit(FILE *outfile, buffer *buff, char bit)
{
	if (buff->size == 8) {
			putc(buff->v, outfile);
			buff->v = buff->size = 0;
	}

	if (bit == '1')
		buff->v |= (1 << buff->size);
	else
		buff->v &= ~(1 << buff->size);
	++(buff->size);
}

int readbit(FILE *infile, buffer *buff)
{
	if (buff->size == 0) {
			buff->v = getc(infile);
			buff->size = 8;
	}
	
	--(buff->size);
	return (((buff->v & (1 << (7 - buff->size))) >> (7 - buff->size)) == 1) ? '1' : '0'; 
}

void quicksort(ptab v[],int first, int last)
{
		int i = first, j = last;
		ptab x = v[(first + last) / 2];

		do {
				while (v[i].p > x.p) i++;
				while (v[j].p < x.p) j--;

				if(i <= j)
					{
						if (i < j)
							swap(v, i, j);
						i++;
						j--;
					}
		} while (i <= j);

		if (i < last)
			quicksort(v, i, last);
		if (first < j)
				quicksort(v, first,j);
}

void swap(ptab v[], int i, int j)
{
	ptab temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}