#include "main.h"

/**
 * swap_int - swaps the values of two integers
 *
 * @a: the pointer to the first integer
 * @b: the pointer to the second integer
 */
void swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
