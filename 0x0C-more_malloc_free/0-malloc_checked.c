#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc. But if malloc fails,
 *					it causes normal process termination with a status
 *					value of 98.
 *
 * @b: The number of bytes to be allocated.
 *
 * Return: A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
