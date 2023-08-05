#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the addition of positive numbers,
 *        followed by a new line.
 *
 * @argc: The number of arguments supplied to the program
 *		  (the program's name is considered an argument).
 * @argv: An array of pointers to the arguments.
 *
 * Return: If one of the numbers contains symbols that are not digits, 1.
 *         Otherwise, 0.
 */

int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
