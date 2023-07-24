#include "sort.h"

/**
 * bubble_sort - this func for sorting an array.
 * @array: input arrray
 * @size: array size
 * Return: void
 * amine mohamed & ABZOU Salma
 */
void bubble_sort(int *array, size_t size)
{
	int sp, tp;
	size_t j, n;

	for (n = size, sp = 1; n > 0 && sp; n--)
	{
		sp = 0;
		for (j = 0; (j + 1) < n; j++)
		{
			if (array[j] > array[j + 1])
			{
				tp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tp;
				print_array(array, size);
				sp = 1;
			}
		}
	}
}
