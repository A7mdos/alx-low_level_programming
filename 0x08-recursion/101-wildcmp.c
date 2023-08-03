#include "main.h"

/**
 * wildcmp - Compares two strings and checkes if
 *			 they can be considered identical.
 *			 considering wildcards
 *
 * @s1: The first string to be compared.
 * @s2: The second string to be compared (may contain wildcard chars '*').
 *
 * Return: If the strings can be considered identical, 1.
 *         If the strings can't be considered identical, 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			return (1);
	}

	return (0);
}
