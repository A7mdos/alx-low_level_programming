#include "lists.h"

size_t unique_nodesint(const listint_t *head);

/**
 * free_listint_safe - Frees a listint_t list safely.
 *
 * @h: A pointer to the address of the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL. And
 *				it can free lists containing loops.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes_count, i;
	listint_t *temp;

	if (h == NULL)
		return (0);

	nodes_count = unique_nodesint(*h);

	if (nodes_count == 0)
	{
		while (*h != NULL)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			nodes_count++;
		}
	}
	else
	{
		for (i = 0; i < nodes_count; i++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodes_count);
}


/**
 * unique_nodesint - Counts the number of unique nodes
 *					 in a looped listint_t linked list.
 *
 * @head: A pointer to the head of the listint_t.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the linked list.
 */
size_t unique_nodesint(const listint_t *head)
{
	size_t nodes_count = 1;
	const listint_t *sl7f, *amjed;

	if (head == NULL || head->next == NULL)
		return (0);

	sl7f = head->next;
	amjed = (head->next)->next;
	while (amjed != NULL)
	{
		if (sl7f == amjed)
		{
			sl7f = head;
			while (sl7f != amjed)
			{
				amjed = amjed->next;
				sl7f = sl7f->next;
				nodes_count++;
			}

			sl7f = sl7f->next;
			while (sl7f != amjed)
			{
				sl7f = sl7f->next;
				nodes_count++;
			}

			return (nodes_count);
		}

		sl7f = sl7f->next;
		amjed = (amjed->next)->next;
	}

	return (0);
}
