#include "sort.h"

/**
 * selection_sort - function that sorts an array
 *@size:  size of array
 * @array: list with numbers
 *
 * Returns: no return.
 */

void selection_sort(int *array, size_t size)
{
	size_t c, o, minIndex;
	int tmp;

	if (size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		minIndex = c;

		for (o = c + 1; o < size; o++)
		{
			if (array[o] < array[minIndex])
				minIndex = o;
		}

		if (minIndex != c)
		{
			tmp = array[c];
			array[c] = array[minIndex];
			array[minIndex] = tmp;

			print_array(array, size);
		}
	}
}
