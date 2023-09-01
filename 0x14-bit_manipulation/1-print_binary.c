#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	if (n == 0 || n == 1)
	{
		_putchar(n + '0');
		return;
	}

	print_binary(n >> 1);
	_putchar((n & 0x01) + '0');
}
