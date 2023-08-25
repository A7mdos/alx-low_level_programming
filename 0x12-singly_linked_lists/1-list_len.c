#include "lists.h"

/**
 * list_len - Finds the number of elements
 *            in a linked list_t list.
 *
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of elements in h.
 */
size_t list_len(const list_t *h)
{
	size_t elements_count = 0;

	while (h != NULL)
	{
		elements_count++;
		h = h->next;
	}

	return (elements_count);
}
