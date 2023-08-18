#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Prints numbers, followed by a new line.
 *
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: A variable number of numbers to be printed.
 *
 * Description: If separator is NULL, it is not printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	int num;
	va_list numbers;

	va_start(numbers, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(numbers, int);

		if (separator != NULL && i != n - 1)
			printf("%d%s", num, separator);
		else
			printf("%d", num);
	}

	printf("\n");

	va_end(numbers);
}
