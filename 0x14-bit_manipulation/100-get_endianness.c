#include "main.h"

/**
 * get_endianness - Checks the endianness of a computer.
 *
 * Return: If big endian - 0.
 *         If little endian - 1.
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *little_endian = (char *) &n;

	if (*little_endian)
		return (1);
	else
		return (0);
}
