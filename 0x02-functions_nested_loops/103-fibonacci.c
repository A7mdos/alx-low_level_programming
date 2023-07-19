#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms in the
 *        Fibonacci sequence whose values do not exceed 4,000,000
 *
 * Return: 0
 */
int main(void)
{
	long int first, second, next, sum;

	first = 1;
	second = 2;
	next = first + second;

	sum = 2;

	while (next < 4000000)
	{
		next = first + second;
		first = second;
		second = next;

		if (next % 2 == 0)
			sum += next;
	}

	printf("%ld\n", sum);

	return (0);
}
