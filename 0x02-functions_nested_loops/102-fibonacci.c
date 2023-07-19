#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 *
 * Return: 0
 */
int main(void)
{
	int i;
	long int first, second, next;

	first = 1;
	second = 2;

	printf("%ld, %ld", first, second);

	for (i = 3; i <= 50; i++)
	{
		next = first + second;
		printf(", %ld", next);
		first = second;
		second = next;
	}

	printf("\n");

	return (0);
}
