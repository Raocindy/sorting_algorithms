#include "sort.h"

/**
* heap_sort - Sorts array with heap sort algo
* @array: array to sort
* @size: Size of array to sort
*/
void heap_sort(int *array, size_t size)
{
	int o;

	if (array == NULL || size < 2)
		return;

	/* Bulild the max heap */
	for (o = (size / 2) - 1; o >= 0; o--)
		sift_down(array, size, size, o);

	for (o = size - 1; o > 0; o--)
	{
		heap_swap(array, array + o);
		print_array(array, size);
		sift_down(array, size, o, 0);
	}
}

/**
 * sift_down - Helper function to perform the sift-down operation in max heap.
 * @array: The array.
 * @size: size of  array.
 * @index: Index of the root node.
 * @pop: The index base.
 */
void sift_down(int *array, size_t size, size_t pop, size_t index)
{
	size_t left, ri, large;

	large = index;
	left = 2 * index + 1;
	ri = 2 * index + 2;

	if (left < pop && array[left] > array[large])
		large = left;

	if (right < pop && array[ri] > array[large])
		large = ri;

	if (large != index)
	{
		heap_swap(array + index, array + large);
		print_array(array, size);
		sift_down(array, size, pop, large);
	}
}

/**
 * heap_swap - Helper function that swap two element.
 * @first: first element.
 * @second: second element.
 */
void heap_swap(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}
