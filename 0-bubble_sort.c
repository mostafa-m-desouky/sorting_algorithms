#include "sort.h"

/**
 * bubble_sort - Sorting Algorithm
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	int *prev, *next, temp;
	int swap_occurred;
	size_t index;

	if (array == NULL || size < 2)
	return;

	do {
		index = 1;
		prev = array;
		next = array + index;
		swap_occurred = false;

		while (index < size)
		{
			if (*prev > *next)
			{
				temp = *prev;
				*prev = *next;
				*next = temp;
				swap_occurred = true;
				print_array(array, size);
			}
			index++;
			prev = next;
			next = array + index;
		}
	} while (swap_occurred == true);
}
