#include "sort.h"
#include <stdio.h>
/**
 * data_Pr - function tot print data
 * @message: message
 * @a: ary
 * @f_m: form
 * @to: to
 * Return: void
 * amine mohamed and salma abzou
 */
void data_Pr(char *message, int *a, int f_m, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", message);
	sep = "";

	for (i = f_m; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * fun_meg - aux prev func
 * @a: ar
 * @lwer: ind lwer
 * @mddl: mddl
 * @hger: hger index
 * @buff: bfr
 * Return: void
 */
void fun_meg(int *a, int lwer, int mddl, int hger, int *buff)
{
	int lo, lm, i;

	lo = i = lwer;
	lm = mddl + 1;

	printf("Merging...\n");
	data_Pr("left", a, lwer, mddl);
	data_Pr("right", a, mddl + 1, hger);

	while (lo <= mddl && lm <= hger)
	{
		if (a[lo] < a[lm])
			buff[i++] = a[lo++];
		else
			buff[i++] = a[lm++];
	}

	while (lo <= mddl)
		buff[i++] = a[lo++];

	while (lm <= hger)
		buff[i++] = a[lm++];

	for (i = lwer; i <= hger; i++)
		a[i] = buff[i];

	data_Pr("Done", a, lwer, hger);
}
/**
 * aux_merge - fun_meg Auxiliar
 * @ary: ary
 * @lwer: lwer index
 * @hger: hger index
 * @bfr: bfr
 * Return: void
 */
void aux_merge(int *ary, int lwer, int hger, int *bfr)
{
	int mdl;

	if (lwer < hger)
	{
		mdl = (lwer + hger - 1) / 2;
		aux_merge(ary, lwer, mdl, bfr);
		aux_merge(ary, mdl + 1, hger, bfr);
		fun_meg(ary, lwer, mdl, hger, bfr);
	}
}
/**
 * merge_sort -Sorts an aryof integers
 * in ascending order using the
 * fun_meg sort algorithm
 * @array: ary
 * @size: size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *bfr;

	bfr = malloc(sizeof(int) * size);
	if (!bfr)
		return;
	aux_merge(array, 0, size - 1, bfr);
	free(bfr);
}
