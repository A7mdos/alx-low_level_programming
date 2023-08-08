#include "main.h"
#include <stdlib.h>

int _strlen(char *s);

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter.
 *
 * @str: The string to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 *         Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	unsigned int str_length, i;
	char *copy;

	if (str == NULL)
		return (NULL);

	str_length = _strlen(str);
	copy = (char*)malloc(sizeof(char) * (str_length + 1));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < str_length; i++)
		copy[i] = str[i];
	copy[str_length] = '\0';

	return (copy);
}


/**
 * _strlen - calculates the length of a string
 *
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	unsigned int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}
