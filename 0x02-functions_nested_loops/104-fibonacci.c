#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *        separated by a comma followed by a space.
 *
 * Return: 0
 */
int main(void)
{
	int count;
	unsigned long first, second, next,
				  first_left_half, first_right_half,
				  second_left_half, second_right_half,
				  left_half, right_half;

	first = 0;
	second = 1;
	for (count = 0; count < 92; count++)
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
	for (count = 93; count < 99; count++)
	{
		left_half = first_left_half + second_left_half;
		right_half = first_right_half + second_right_half;
		if (right_half > 9999999999)
		{
			right_half %= 10000000000;
			left_half += 1;
		}
		printf("%lu%lu", left_half, right_half);
		if (count != 98)
			printf(", ");

		first_left_half = second_left_half;
		first_right_half = second_right_half;
		second_left_half = left_half;
		second_right_half = right_half;
	}
	printf("\n");
	return (0);
}
