#include "main.h"

/**
 * _atoi - convert a string to an integer
 *
 * @s: the string to be converted
 *
 * Return: the extracted integer from the string
 */
int _atoi(char *s)
{
	int sign = 1, digit;
	unsigned int number = 0;
	char chr = *s;

	while (chr != '\0')
	{
		if (chr == '-')
		{
			sign *= -1;
		}
		else if (chr >= '0' && chr <= '9')
		{
			digit = chr - '0';
			number = number * 10 + digit;
		}
		else if (number)
		{
			break;
		}

		s++;
		chr = *s;
	}

	return (sign * number);
}
