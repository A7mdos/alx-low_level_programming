#include "main.h"

/**
 * rot13 - encodes a string using rot13
 *
 * @str: a pointer to the string to be encoded
 *
 * Return: a pointer to the modified string
 */
char *rot13(char *str)
{
	int i = 0, letter_order;
	char encoded_letter;

	while (str[i] != '\0')
	{
		while ((str[i] >= 'a' && str[i] <= 'z') ||
			   (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if ((str[i] >= 'a' && str[i] <= 'z'))
			{
				letter_order = str[i] - 'a';
				encoded_letter = 'a' + ((letter_order + 13) % 26);
				str[i++] = encoded_letter;
			}
			else
			{
				letter_order = str[i] - 'A';
				encoded_letter = 'A' + ((letter_order + 13) % 26);
				str[i++] = encoded_letter;
			}
		}

		i++;
	}

	return (str);
}
