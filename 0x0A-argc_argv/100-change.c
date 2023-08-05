#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins
 *		  to make change for an amount of money.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If the number of arguments is not exactly one, 1.
 *         Otherwise, 0.
 */

int main(int argc, char *argv[])
{
	int cents;
	int	min_num_of_coins = 0;
	int coins[] = {25, 10, 5, 2, 1};
	int *coin = coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	while (cents > 0)
	{
		min_num_of_coins += (cents / *coin);
		cents = cents % *coin++;
	}

	printf("%d\n", min_num_of_coins);

	return (0);
}
