#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including the
 *				 terminating null byte (\0), to the buffer pointed to by dest
 *
 * @src: pointer to the source string
 * @dest: pointer to the destination string
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	while (src[++i] != '\0')
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}
