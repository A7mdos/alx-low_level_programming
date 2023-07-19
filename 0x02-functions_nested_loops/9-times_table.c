#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 */
void times_table(void)
{
	int number, multiple, product;

	for (number = 0; number <= 9; number++)
	{
		_putchar('0');
		_putchar(',');

		for (multiple = 1; multiple <= 9; multiple++)
		{
			_putchar(' ');

			product = number * multiple;

			if (product <= 9)
				_putchar(' ');
			else
				_putchar('0' + (product / 10));

			_putchar('0' + (product % 10));

			if (multiple != 9)
				_putchar(',');
		}

		_putchar('\n');
	}
}
