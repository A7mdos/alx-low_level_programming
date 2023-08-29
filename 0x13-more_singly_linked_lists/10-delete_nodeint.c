#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given
 *                           index of a listint_t list.
 *
 * @head: A pointer to the address of the head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: On success - 1.
 *         On failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *node;
	unsigned int h;

	if (head == NULL)
		return (-1);

	node = *head;
	if (node == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(node);
		return (1);
	}

	for (h = 1; h < index; h++)
	{
		if (node->next == NULL)
			return (-1);

		node = node->next;
	}

	temp = node->next;
	node->next = (node->next)->next;
	free(temp);

	return (1);
}
