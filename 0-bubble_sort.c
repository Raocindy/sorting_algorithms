#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: size of array.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t o, p;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (o = 0; o < size - 1 && swapped; o++)
	{
		swapped = 0;
		for (p = 0; n < (size - 1 - o); p++)
		{
			if (array[p] > array[p + 1])
			{
				tmp = array[p];
				array[p] = array[p + 1];
				array[p + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}

