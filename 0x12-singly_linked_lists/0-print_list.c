#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t list.
 *
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes.
 */

size_t print_list(const list_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		nodes_count++;
		h = h->next;
	}

	return (nodes_count);
}
