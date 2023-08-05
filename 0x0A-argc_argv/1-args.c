#include <stdio.h>

/**
 * main - Prints the number of arguments passed into it.
 *
 * @argc: The number of arguments supplied to the program
 *		  (the program's name is considered an argument).
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);

	return (0);
}
