#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 *
 * @head: A pointer to the list_t list.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		free(head->str);
		temp = head->next;
		free(head);
		head = temp;
	}
}
