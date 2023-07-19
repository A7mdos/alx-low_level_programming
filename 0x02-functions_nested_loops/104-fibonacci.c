#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *        separated by a comma followed by a space.
 *
 * Return: 0
 */
int main(void)
{
	int i;
	unsigned long first, second, next,
				  first_left_half, first_right_half,
				  second_left_half, second_right_half,
				  left_half, right_half;

	first = 1;
	second = 2;
	printf("%lu, %lu, ", first, second);
	for (i = 0; i < 92; i++)
	{
		next = first + second;
		first = second;
		second = next;
		printf("%lu, ", next);
	}
	first_left_half = first / 10000000000;
	first_right_half = first % 10000000000;
	second_left_half = second / 10000000000;
	second_right_half = second % 10000000000;
	for (i = 93; i < 99; i++)
	{
		left_half = first_left_half + second_left_half;
		right_half = first_right_half + second_right_half;
		if (right_half > 9999999999)
		{
			right_half %= 10000000000;
			left_half += 1;
		}
		printf("%lu%lu", left_half, right_half);
		if (i == 98)
			break;
		printf(", ");
		first_left_half = second_left_half;
		first_right_half = second_right_half;
		second_left_half = left_half;
		second_right_half = right_half;
	}
	printf("\n");
	return (0);
}
