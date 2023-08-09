#include "main.h"
#include <stdlib.h>

unsigned int word_len(char *str, unsigned int start_index);
unsigned int count_words(char *str);

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
	unsigned int str_index, letter_index,
				 word_length, words_count = 0;
	int word_index;

	if (str == NULL || *str == '\0')
		return (NULL);

	words_count = count_words(str);

	words = malloc(sizeof(char *) * (words_count + 1));
	if (words == NULL)
		return (NULL);

	word_index = 0;
	for (str_index = 0; str[str_index]; str_index++)
	{
		if (str[str_index] == ' ')
			continue;

		word_length = word_len(str, str_index);
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
		word_index++;
	}

	words[words_count] = NULL;

	return (words);
}

/**
 * word_len - Calculates the length of a word inside a string.
 *			  (words are seperated by spaces)
 *
 * @str: The string to be searched.
 * @start_index: The starting position of the word inside @str.
 *
 * Return: The length of the word.
 */
unsigned int word_len(char *str, unsigned int start_index)
{
	unsigned int i, length = 0;

	i = start_index;
	while (str[i] != ' ' && str[i] != '\0')
	{
		length++;
		i++;
	}

	return (length);
}

/**
 * count_words - Counts the number of words, seperated by spaces,
 *				 inside a string.
 *
 * @str: The string containing the words.
 *
 * Return: The number of words contained within @str.
 */
unsigned int count_words(char *str)
{
	unsigned int i, words_count = 0;


	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			continue;

		i += word_len(str, i);
		words_count++;
	}

	return (words_count);
}
