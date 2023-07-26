#include "main.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: the string to be concatenated upon.
 * @src: the source string to be appended to @dest.
 *
 * Return: a pointer to the resulting string @dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j, dest_length = 0;

	while (dest[i++] != '\0')
		dest_length++;

	i = dest_length;
	for (j = 0; src[j] != '\0'; j++)
		dest[i++] = src[j];

	return (dest);
}
