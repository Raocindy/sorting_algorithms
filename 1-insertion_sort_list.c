#include "sort.h"

/**
 * insertion_sort_list - sort a list
 * @list: UnSorted Linked list.
 *
 * Returns: no return.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *key, *prev, *next_node, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		key = current;
		prev = current->prev;

		while (prev && key->n < prev->n)
		{
			next_node = key->next;
			prev_node = prev->prev;

			if (prev_node)
				prev_node->next = key;
			else
				*list = key;

			prev->prev = key;
			prev->next = next_node;

			if (next_node)
				next_node->prev = prev;

			key->prev = prev_node;
			key->next = prev;

			print_list(*list);

			prev = key->prev;
		}
		current = current->next;
	}
}
