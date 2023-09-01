#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 *
 * @b: A pointer to a string of 0 and 1 characters.
 *
 * Return: If b is NULL or contains chars other than 0's and 1's - 0.
 *         Otherwise - the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0, mult = 1;
	int l_idx, r_idx, bit, length = 0;

	if (b == NULL)
		return (0);

	while (b[length] != '\0')
		length++;

	for (l_idx = 0; l_idx < length; l_idx++)
	{
		r_idx = length - l_idx - 1;

		if (b[r_idx] != '0' && b[r_idx] != '1')
			return (0);

		bit = b[r_idx] - '0';
		number += bit * mult;
		mult *= 2;
	}

	return (number);
}
