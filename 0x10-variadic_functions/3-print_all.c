#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

void print_char(va_list arg);
void print_int(va_list arg);
void print_float(va_list arg);
void print_string(va_list arg);

/**
 * print_all - Prints anything, followed by a new line.
 * @format: A string of characters representing the argument types.
 * @...: A variable number of arguments to be printed.
 *
 * Description: Any argument not of type char, int, float,
 *              or char * is ignored.
 *              If a string argument is NULL, (nil) is printed instead.
 */
void print_all(const char * const format, ...)
{
	int i, j;
	char *separator = "";
	va_list args;
	Printer printers[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};

	va_start(args, format);

	i = 0;
	while (format && format[i])
	{
		j = 0;

		while (j < 4 && (format[i] != *(printers[j].typeSpecifier)))
			j++;

		if (j < 4)
		{
			printf("%s", separator);
			printers[j].print(args);
			separator = ", ";
		}

		i++;
	}

	printf("\n");

	va_end(args);
}


/**
 * print_char - Prints a char.
 *
 * @arg: A pointer to the character to be printed.
 */
void print_char(va_list arg)
{
	char letter;

	letter = va_arg(arg, int);
	printf("%c", letter);
}


/**
 * print_int - Prints an int.
 *
 * @arg: A pointer to the integer to be printed.
 */
void print_int(va_list arg)
{
	int number;

	number = va_arg(arg, int);
	printf("%d", number);
}


/**
 * print_float - Prints a float.
 *
 * @arg: A pointer to the float to be printed.
 */
void print_float(va_list arg)
{
	float number;

	number = va_arg(arg, double);
	printf("%f", number);
}


/**
 * print_string - Prints a string.
 *
 * @arg: A pointer to the string to be printed.
 */
void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", str);
}
