#include "main.h"

/**
 * _strncpy - Copies at most @n number
 *            of bytes from string @src into @dest.
 * @dest: a pointer to the buffer storing the string copy.
 * @src: a pointer to the source string.
 * @n: The maximum number of bytes to be copied from @src.
 *
 * Return: a pointer to the resulting string @dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, src_length = 0;

	while (src[i++] != '\0')
		src_length++;

	for (i = 0; (src[i] != '\0') && (i < n); i++)
		dest[i] = src[i];

	for (i = src_length; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
