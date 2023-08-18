#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);


#include <stdarg.h>

/**
 * struct Printer - A struct type defining a printer.
 *
 * @typeSpecifier: A pointer to a character representing a data type.
 * @print: A function pointer to a function that prints
 *         a data type corresponding to typeSpecifier.
 */
struct Printer
{
	char *typeSpecifier;
	void (*print)(va_list arg);

};
typedef struct Printer Printer;

#endif
