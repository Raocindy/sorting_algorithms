#include "sort.h"

/**
* swap - Swaps two elements.
* @array: The array.
* @x: First element.
* @y: Second element.
*
* Return: no return
*/
void swap(int *array, ssize_t x, ssize_t y)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
* lomuto_partition - Lomuto partition scheme for Quick Sort.
* @array: The array.
* @low: Starting index to be sorted.
* @high: Ending index to be sorted.
* @size: The size.
*
* Return: Index of the pivot.
*/
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t c = low, k;

	for (k = low; k < high; k++)
	{
		if (array[k] <= pivot)
		{
			if (array[c] != array[k])
			{
				swap(array, c, k);
				print_array(array, size);
			}
			c++;
		}
	}
	if (array[c] != array[high])
	{
		swap(array, c, high);
		print_array(array, size);
	}
	return (c);
}

/**
 * quick_sort_recursive - helper function for Quick sort
 * @array: Array to be sorted
 * @low: The starting index to be sorted
 * @high: The ending index to be sorted.
 * @size: the size.
 *
 * Return: no return.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t pivotIndex = 0;

	if (low < high)
	{
		pivotIndex = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivotIndex - 1, size);
		quick_sort_recursive(array, pivotIndex + 1, high, size);
	}
}

/**
 * quick_sort - Sorts array of integers in ascending order.
 * using Quick sort algorithm.
 * @array: The array.
 * @size: size of array.
 *
 * Return: no return.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
