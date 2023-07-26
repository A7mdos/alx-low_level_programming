#include "main.h"

/**
 * leet - encodes a string to 1337.
 *
 * @str: the string to be encoded.
 *
 * Return: a pointer to the encoded string.
 */
char *leet(char *str)
{
	char *ptr = str;
	char *leet_chars = "aAeEoOtTlL";
	char *leet_nums = "4433007711";
	int i;

	while (*ptr != '\0')
	{
		for (i = 0; leet_chars[i] != '\0'; i++)
		{
			if (*ptr == leet_chars[i])
			{
				*ptr = leet_nums[i];
				break;
			}
		}
		ptr++;
	}

	return (str);
}
