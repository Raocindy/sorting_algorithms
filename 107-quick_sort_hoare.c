#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using Quick sort with Hoare partition scheme
 * @array: The array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursive(array, size, 0, size - 1);
}

/**
 * quick_recursive - Recursively performs Quick sort on the array
 * @array: The array
 * @size: size of array.
 * @l: The low index of the partition
 * @h: The high index of the partition
 */
void quick_recursive(int *array, size_t size, int l, int h)
{
	int center;

	if (h - l > 0)
	{
		pivot = hoare_partition(array, size, l, h);
		quick_recursive(array, size, l, center - 1);
		quick_recursive(array, size, center, h);
	}
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme.
 * @array: The array.
 * @size: size array.
 * @l: The low index.
 * @h: The high index.
 *
 * Return: The index of the pivot
 */
int hoare_partition(int *array, int size, int l, int h)
{
	int center = array[h];
	int c, k;

	c = l - 1;
	k = h + 1;
	while (c < k)
	{
		do {
			c++;
		} while (array[c] < center);

		do {
			k--;
		} while (array[k] > center);

		if (c < k)
		{
			_swap(array + c, array + k);
			print_array(array, size);
		}
	}
	return (c);
}

/**
 * _swap - Swap two integers in an array.
 * @first: First index.
 * @second: Second index.
 */
void _swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
