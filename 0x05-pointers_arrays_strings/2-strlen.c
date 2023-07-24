#include "main.h"
#include <stdio.h>


/**
 * _strlen - calculates the length of a string
 *
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}
