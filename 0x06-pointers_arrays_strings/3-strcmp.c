#include "main.h"

/**
 * _strcmp - compares two strings.
 *
 * @s1: a pointer to the first string to be compared.
 * @s2: a pointer to the second string to be compared.
 *
 * Return: If s1 < s2, the negative difference of the
 *		   first unmatched characters.
 *
 *		   If s1 == s2, 0.
 *
 *		   If s1 > s2, the positive difference of the
 *		   first unmatched characters.
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') && (*s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
