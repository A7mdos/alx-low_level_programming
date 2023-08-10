#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array of a number
 *           of elements each of a given byte size. And
 *			 initializes it with zeros.
 *
 * @nmemb: The number of array elements.
 * @size: The byte size of each array element.
 *
 * Return: If nmemb = 0, size = 0, or the function fails - NULL.
 *         Otherwise - a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	char *initalizer;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	initalizer = ptr;
	for (i = 0; i < (nmemb * size); i++)
		initalizer[i] = '\0';

	return (ptr);
}
