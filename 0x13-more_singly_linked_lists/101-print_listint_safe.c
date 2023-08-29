#include "lists.h"
#include <stdio.h>

size_t unique_nodesint(const listint_t *head);

/**
 * print_listint_safe - Prints a listint_t list safely.
 *
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 *
 * Description: Can print lists containing loops.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes_count, i = 0;

	nodes_count = unique_nodesint(head);

	if (nodes_count == 0)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			nodes_count++;
			head = head->next;
		}
	}
	else
	{
		for (i = 0; i < nodes_count; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

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
