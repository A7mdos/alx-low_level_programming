#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int word_len(char *str);
int count_words(char *str);

/**
 * strtow - Splits a string into words.
 *
 * @str: The string to be split.
 *
 * Return: If str == NULL, str == "", or the function fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **words;
	int str_index = 0, words_count, word_index, word_length, letter_index;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words_count = count_words(str);
	if (words_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (words_count + 1));
	if (words == NULL)
		return (NULL);

	for (word_index = 0; word_index < words_count; word_index++)
	{
		while (str[str_index] == ' ')
			str_index++;

		word_length = word_len(str + str_index);

		words[word_index] = malloc(sizeof(char) * (word_length + 1));

		if (words[word_index] == NULL)
		{
			for (; word_index >= 0; word_index--)
				free(words[word_index]);

			free(words);
			return (NULL);
		}

		for (letter_index = 0; letter_index < word_length; letter_index++)
			words[word_index][letter_index] = str[str_index++];

		words[word_index][letter_index] = '\0';
	}
	words[word_index] = NULL;

	return (words);
}

/**
 * word_len - Locates the index marking the end of the
 *            first word contained within a string.
 *
 * @str: The string to be searched.
 *
 * Return: The index marking the end of the initial word pointed to by str.
 */
int word_len(char *str)
{
	int i = 0, length = 0;

	while (*(str + i) && *(str + i) != ' ')
	{
		length++;
		i++;
	}

	return (length);
}


/**
 * count_words - Counts the number of words contained within a string.
 *
 * @str: The string to be searched.
 *
 * Return: The number of words contained within str.
 */
int count_words(char *str)
{
	int i = 0, words_count = 0, length = 0;

	for (i = 0; *(str + i); i++)
		length++;

	for (i = 0; i < length; i++)
	{
		if (*(str + i) != ' ')
		{
			words_count++;
			i += word_len(str + i);
		}
	}

	return (words_count);
}
