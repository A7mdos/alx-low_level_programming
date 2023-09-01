#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be
 *             flipped to get from one number to another.
 *
 * @n: One number.
 * @m: The other number.
 *
 * Return: The necessary number of bits to flip
 *		   to get from n to m, or vice versa.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor, i, max_bits, mask = 0x01, bits_count = 0;

	xor = n ^ m;

	max_bits = sizeof(unsigned long int) * 8;
	for (i = 0; i < max_bits; i++)
	{
		if (xor & mask)
			bits_count++;

		mask <<= 1;
	}

	return (bits_count);
}
