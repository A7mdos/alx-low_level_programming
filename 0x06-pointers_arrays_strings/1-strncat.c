#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from @src
 *
 * @dest: the string to be concatenated upon.
 * @src: the string to be appended to @dest.
 * @n: The number of bytes from src to be appended to @dest.
 *
 * Return: the resulting string @dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j, dest_length = 0;

	while (dest[i++] != '\0')
		dest_length++;

	i = dest_length;
	for (j = 0; (src[j] != '\0') && (j < n); j++)
		dest[i++] = src[j];

	return (dest);
}
