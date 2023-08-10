#include "main.h"
#include <stdlib.h>

unsigned int _strlen(char *s);

/**
 * string_nconcat - Concatenates two strings using at
 *                  most an inputted number of bytes.
 *
 * @s1: The first string to be concatenated upon.
 * @s2: The second string concatenate to s1.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the concatenated string in memory.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int s1_length, s2_length, i, concat_index = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	s1_length = _strlen(s1);
	s2_length = _strlen(s2);

	if (n >= s2_length)
		n = s2_length;

	concat = malloc(sizeof(char) * (s1_length + n + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < s1_length; i++)
		concat[concat_index++] = s1[i];

	for (i = 0; i < n; i++)
		concat[concat_index++] = s2[i];

	concat[concat_index] = '\0';

	return (concat);
}


/**
 * _strlen - calculates the length of a string
 *
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}
