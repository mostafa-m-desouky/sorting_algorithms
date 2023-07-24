#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list -func that sort a dll
 * @list: db linked ls
 * Return: void
 * amine mohamed & salma abzou
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pt, *tp;

	if (!list)
		return;

	pt = *list;

	while (pt)
	{
		while (pt->next && (pt->n > pt->next->n))
		{
			tp = pt->next;
			pt->next = tp->next;
			tp->prev = pt->prev;

			if (pt->prev)
				pt->prev->next = tp;

			if (tp->next)
				tp->next->prev = pt;

			pt->prev = tp;
			tp->next = pt;

			if (tp->prev)
				pt = tp->prev;
			else
				*list = tp;

			print_list(*list);
		}
		pt = pt->next;
	}
}
