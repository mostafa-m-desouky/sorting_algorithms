#include "sort.h"

/**
 * ls_Wap - swaping ele of list
 * @pt_one: pointer num one
 * @pt_tow: pointer num tow
 * @n: 0 or 1
 * Return: void
 *  amine mohamed and salma abzou
 */
void ls_Wap(listint_t **pt_one, listint_t **pt_tow, int n)
{
	listint_t *our_ax, *our_tp;

	our_ax = *pt_one;
	our_tp = *pt_tow;

	our_ax->next = our_tp->next;
	our_tp->prev = our_ax->prev;

	if (our_tp->next)
		our_tp->next->prev = our_ax;

	if (our_ax->prev)
		our_ax->prev->next = our_tp;

	our_ax->prev = our_tp;
	our_tp->next = our_ax;

	if (n == 0)
		*pt_one = our_tp;
	else
		*pt_tow = our_ax;
}

/**
 * srInc_rease - this to move the bg num to the start
 * @pt: bigger num is pointer
 * @lmt: ls limit
 * @ls: int list
 * Return: void
 */
void srInc_rease(listint_t **pt, listint_t **lmt, listint_t **ls)
{
	listint_t *our_ax;

	our_ax = *pt;

	while (our_ax != *lmt && our_ax->next != *lmt)
	{
		if (our_ax->n > our_ax->next->n)
		{
			ls_Wap(&our_ax, &(our_ax->next), 0);
			if (our_ax->prev == NULL)
				*ls = our_ax;
			print_list(*ls);
		}
		our_ax = our_ax->next;
	}

	*lmt = our_ax;
	*pt = our_ax;
}

/**
 * srDec_rease - func to move the sm num to the start
 * @pt: pointer to sm num
 * @lmt: ls limit
 * @ls: int list
 * Return: void
 */
void srDec_rease(listint_t **pt, listint_t **lmt, listint_t **ls)
{
	listint_t *our_ax;

	our_ax = *pt;

	while (our_ax != *lmt && our_ax->prev != *lmt)
	{
		if (our_ax->n < our_ax->prev->n)
		{
			ls_Wap(&(our_ax->prev), &our_ax, 1);
			if (our_ax->prev->prev == NULL)
				*ls = our_ax->prev;
			print_list(*ls);
		}
		our_ax = our_ax->prev;
	}

	*lmt = our_ax;
	*pt = our_ax;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: linked ls head
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *lmt1, *lmt2, *pt;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	lmt1 = lmt2 = NULL;
	pt = *list;

	do {
		srInc_rease(&pt, &lmt1, list);
		srDec_rease(&pt, &lmt2, list);
	} while (lmt1 != lmt2);
}
