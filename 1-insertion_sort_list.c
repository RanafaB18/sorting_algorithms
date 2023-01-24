#include "sort.h"
/**
 * swap_nodes - Swap two nodes
 * @h: list of the linked list.
 * @n1: first node
 * @n2: second node
 * Return: void
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: A pointer to the list of a doubly-linked list of integers.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;
	listint_t *temp;

	if (!list || !(*list)->next || !*list)
	{
		return;
	}

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		prev = current->prev;
		while (prev != NULL && current->n < prev->n)
		{
			swap_nodes(list, &prev, current);
			print_list((const listint_t *)*list);
		}
	}
}
