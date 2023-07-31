#define bool int
#define true 1
#define false 0

#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 *
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in @s which consist only of bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0, j = 0;
	bool acceptable;
	unsigned int bytes = 0;

	while (s[i] != '\0')
	{
		j = 0;
		acceptable = false;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j++])
			{
				acceptable = true;
				break;
			}
		}

		if (acceptable)
			bytes++;
		else
			return (bytes);

		i++;
	}

	return (bytes);
}
