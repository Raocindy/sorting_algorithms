#include "sort.h"

/**
 * shell_sort -Sorts an Array using shell sort algorithm
 * @array: The array
 * @size: size of array
 **/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int tmp;
	size_t z, o;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (o = gap; o < size; o++)
		{
			tmp = array[o];

			for (z = o; z >= gap && array[z - gap] > tmp; z -= gap)
			{
				array[z] = array[z - gap];
			}

			array[z] = tmp;
		}
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
