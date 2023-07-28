#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer 10 bytes per line, starting
 *				  with the byte position, then showing the hex
 *				  content, then displaying printable charcaters
 *
 * @b: the buffer to be printed
 * @size: the number of bytes to be printed from the buffer
 */
void print_buffer(char *b, int size)
{
	int byte, i;
	unsigned int ascii_value;

	for (byte = 0; byte < size; byte += 10)
	{
		printf("%08x: ", byte);

		for (i = 0; i < 10; i++)
		{
			ascii_value = *(b + byte + i);

			if ((byte + i) >= size)
				printf("  ");
			else
				printf("%02x", ascii_value);

			if ((i % 2) != 0 && i != 0)
				printf(" ");
		}

		for (i = 0; i < 10; i++)
		{
			ascii_value = *(b + byte + i);

			if ((byte + i) >= size)
				break;

			else if (ascii_value >= 31 &&
					 ascii_value <= 126)
				printf("%c", ascii_value);

			else
				printf(".");
		}

		if (byte >= size)
			continue;

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
