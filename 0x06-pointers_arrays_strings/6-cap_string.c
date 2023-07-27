#include "main.h"

/**
 * cap_string - capitalizes all words of a string.
 *
 * @str: The string to be capitalized.
 *
 * Return: a pointer to the capitalized string.
 */
char *cap_string(char *str)
{
	char *ptr = str;

	while (*str != '\0')
	{
		if (*(str - 1) == ' ' ||
		    *(str - 1) == '\t' ||
		    *(str - 1) == '\n' ||
		    *(str - 1) == ',' ||
		    *(str - 1) == ';' ||
		    *(str - 1) == '.' ||
		    *(str - 1) == '!' ||
		    *(str - 1) == '?' ||
		    *(str - 1) == '"' ||
		    *(str - 1) == '(' ||
		    *(str - 1) == ')' ||
		    *(str - 1) == '{' ||
		    *(str - 1) == '}' ||
		    str == ptr)
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
	
		str++;
	}

	return (ptr);
}
