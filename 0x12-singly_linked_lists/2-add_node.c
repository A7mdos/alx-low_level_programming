#include "lists.h"
#include <string.h>

size_t _strlen(char *s);

/**
 * add_node - Adds a new node at the beginning
 *            of a list_t list.
 *
 * @head: The address of a pointer to the head of the list_t list.
 * @str: The string to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *duplicate;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	duplicate = strdup(str);
	if (duplicate == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = duplicate;
	new_node->len = _strlen(duplicate);
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}


/**
 * _strlen - calculates the length of a string
 *
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
size_t _strlen(char *s)
{
	size_t i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}
