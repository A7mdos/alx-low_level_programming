#include "lists.h"
#include <string.h>

size_t _strlen(char *s);

/**
 * add_node_end - Adds a new node at the end
 *                of a list_t list.
 *
 * @head: The adderss of a pointer the head of the list_t list.
 * @str: The string to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *last_node;
	char *duplicate;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	duplicate = strdup(str);
	if (str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = duplicate;
	new_node->len = _strlen(duplicate);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}

	return (*head);
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
