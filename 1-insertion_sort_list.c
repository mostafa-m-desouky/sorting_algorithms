#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Pointer to the doubly linked list to be sorted.
 * Return: currnt state of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	/* Validate if list = 0 or list = 1 */
	if (!list || !(*list) || !(*list)->next)
		return;

	/* Sorting from element 2 */
	current = (*list)->next;

	while (current)
	{
		temp = current;
		current = current->next;

		/* Iterate sorted list from the right to the left */
		while (temp->prev && (temp->prev->n > temp->n))
		{
			/* Join previous node with next node */
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;

			/* Move temp node one position to the left */
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			/* Update the links of the adjacent nodes */
			temp->next->prev = temp;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			/* Display list's current state. */
			print_list(*list);
		}
	}
}
