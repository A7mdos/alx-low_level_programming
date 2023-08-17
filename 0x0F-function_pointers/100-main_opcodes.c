#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints a specified number of opcodes of itself.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int offset, number_of_bytes;
	unsigned char *start_address = (unsigned char *)&main;
	unsigned char opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	number_of_bytes = atoi(argv[1]);

	if (number_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (offset = 0; offset < number_of_bytes; offset++)
	{
		opcode = start_address[offset];
		printf("%02x", opcode);

		if (offset != number_of_bytes - 1)
			printf(" ");
	}

	printf("\n");

	return (0);
}
