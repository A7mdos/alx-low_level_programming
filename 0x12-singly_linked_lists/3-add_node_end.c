#include "lists.h"
#include <string.h>


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
	list_t *new_node, *tail_node;
	char *duplicate;
	unsigned int str_len;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	duplicate = strdup(str);
	if (str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	for (str_len = 0; str[str_len] != '\0';)
		str_len++;

	new_node->str = duplicate;
	new_node->len = str_len;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	tail_node = *head;
	while (tail_node->next != NULL)
		tail_node = tail_node->next;

	tail_node->next = new_node;

	return (new_node);
}
