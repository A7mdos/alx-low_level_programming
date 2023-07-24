#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 *
 * @str: the string to print
 */
void puts_half(char *str)
{
	int i = 0, length = 0, half_length;

	while (str[i++] != '\0')
		length++;

	if (length % 2 == 0)
		half_length = length / 2;
	else
		half_length = (length + 1) / 2;

	for (i = half_length; i < length; i++)
		_putchar(str[i]);

	_putchar('\n');
}
