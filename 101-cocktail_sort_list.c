#include "sort.h"

/**
* cocktail_sort_list - Sorts  doubly linked list of integers.
* @list: Pointer to the pointer of the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	int isSwapped;
	listint_t *current, *leftmost = NULL, *rightmost = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		isSwapped = 0;
		current = leftmost = *list;

		while (current->next != rightmost)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				isSwapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
		rightmost = current;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				isSwapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		leftmost = current;
	} while (isSwapped);
}

/**
* swap - Swaps two nodes in a doubly linked list.
* @list: Pointer to the pointer of the head of the list.
* @node_a: Pointer to the first node.
* @node_b: Pointer to the second node.
*
* Return: no return.
*/
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node_a->prev)
		node_a->prev->next = node_b;
	else
		*list = node_b;

	if (node_b->next)
		node_b->next->prev = node1;

	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
	print_list((const listint_t *)*list);
}

