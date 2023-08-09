#include "main.h"
#include <stdlib.h>

int _strlen(char *s);

/**
 * argstostr - Concatenates all arguments of the program into a string.
 *             Arguments are separated by a new line in the string.
 *
 * @ac: The number of arguments passed to the program
 *		(including the program's name).
 * @av: An array of pointers to the arguments.
 *
 * Return: If ac == 0, av == NULL, or the function fails - NULL.
 *         Otherwise - a pointer to the new string.
 */
char *argstostr(int ac, char **av)
{
	char *concat;
	int arg_index, char_index, concat_index = 0,
		total_length = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (arg_index = 0; arg_index < ac; arg_index++)
		total_length += _strlen(av[arg_index]) + 1;

	concat = malloc(sizeof(char) * (total_length + 1));
	if (concat == NULL)
		return (NULL);

	for (arg_index = 0; arg_index < ac; arg_index++)
	{
		for (char_index = 0; av[arg_index][char_index]; char_index++)
			concat[concat_index++] = av[arg_index][char_index];

		concat[concat_index++] = '\n';
	}

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
int _strlen(char *s)
{
	unsigned int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}
