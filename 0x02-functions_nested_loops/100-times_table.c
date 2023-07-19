#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0.
 *
 * @n: order of the time table
 */
void print_times_table(int n)
{
	int number, multiple, product;

	if ((n > 15) || (n < 0))
		return;


	for (number = 0; number <= n; number++)
	{
		_putchar('0');

		for (multiple = 1; multiple <= n; multiple++)
		{
			_putchar(',');
			_putchar(' ');

			product = number * multiple;

			if (product <= 99)
			{
				_putchar(' ');
			}
			else
			{
				_putchar('0' + (product / 100));
				_putchar('0' + ((product % 100) / 10));
			}

			if (product <= 9)
				_putchar(' ');
			else if (product <= 99)
				_putchar('0' + (product / 10));

			_putchar('0' + (product % 10));
		}

		_putchar('\n');
	}
}
