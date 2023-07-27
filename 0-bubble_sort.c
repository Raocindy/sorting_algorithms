#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array.
 * @size: size of array.
 */
void bubble_sort(int *array, size_t size)
{
	int isSwapped = 1;
	size_t o, p;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (o = 0; o < size - 1 && isSwapped; o++)
	{
		isSwapped = 0;
		for (p = 0; n < (size - 1 - o); p++)
		{
			if (array[p] > array[p + 1])
			{
				tmp = array[p];
				array[p] = array[p + 1];
				array[p + 1] = tmp;
				isSwapped = 1;
				print_array(array, size);
			}
		}
		if (isSwapped == 0)
			break;
	}
}

