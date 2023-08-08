#include "main.h"
#include <stdlib.h>

int _strlen(char *s);

/**
 * str_concat - Concatenates two strings.
 *
 * @s1: The string to be concatenated upon.
 * @s2: The string to be concatenated to s1.
 *
 * Return: If concatenation fails, NULL.
 *         Otherwise, a pointer the newly-allocated space in memory
 *                     containing the concatenated strings.
 */
char *str_concat(char *s1, char *s2)
{
	char* concat;
	unsigned int length1, length2, total_length,
				 index, concat_index = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	length1 = _strlen(s1);
	length2 = _strlen(s2);
	total_length = length1 + length2;
	concat = (char*)malloc(sizeof(char) * (total_length + 1));

	if (concat == NULL)
		return (NULL);

	for (index = 0; index < length1; index++)
		concat[concat_index++] = s1[index];

	for (index = 0; index < length2; index++)
		concat[concat_index++] = s2[index];

	concat[total_length] = '\0';

	return (concat);
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