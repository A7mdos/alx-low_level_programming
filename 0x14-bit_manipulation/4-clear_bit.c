#include "main.h"

/**
 * clear_bit - Clears the bit at a given index (sets it to 0).
 *
 * @n: A pointer to the number to clear a bit of.
 * @index: The index to clear the bit at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
