#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using Merge sort algorithm.
 * @array: The array.
 * @size: size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmpArr;

	if (array == NULL || size < 2)
		return;

	tmpArr = malloc(size * sizeof(int));
	if (tmpArr == NULL)
		return;

	merge_recursive(array, tmpArr, 0, size);

	free(tmpArr);
}

/**
 * merge_recursive - Recursive function for Merge sort
 * @array: The array.
 * @s: The starting index.
 * @e: The ending index.
 * @tmpArr: Temporary array.
 */
void merge_recursive(int *array, int *tmpArr, size_t s, size_t e)
{
	size_t mid;

	if (e - s > 1)
	{
		mid = s + (e - s) / 2;
		merge_recursive(array, tmpArr, s, mid);
		merge_recursive(array, tmpArr, mid, e);

		merge(array, tmpArr, s, mid, e);
	}
}

/**
 * merge - Merges two sorted sub-arrays into a single sorted array.
 * @array: The array
 * @s: The starting index.
 * @mid: The last index of sub-array
 * @e: The last index of sub-array
 * @tmpArr: Temporary array.
 */
void merge(int *array, int *tmpArr, size_t s, size_t mid, size_t e)
{
	size_t l, m, n = 0;

	printf("Merging...\n[left]: ");
	print_array(array + s, mid - s);
	printf("[right]: ");
	print_array(array + mid, e - mid);

	for (l = s, m = mid; l < mid && m < e; n++)
		tmpArr[n] = (array[l] < array[m]) ? array[l++] : array[m++];
	for (; l < mid; l++)
		tmpArr[c++] = array[l];
	for (; m < e; m++)
		tmpArr[n++] = array[m];
	for (l = s, n = 0; l < e; l++)
		array[l] = tmpArr[n++];

	printf("[Done]: ");
	print_array(array + s, e - s);
}
