#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 * @array: The array.
 * @size: size of array.
 */
void radix_sort(int *array, size_t size)
{
	int *tmp, max_val, exp;

	if (array == NULL || size < 2)
		return;

	/* allocate memory */
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	/* Find the maximum value */
	max_val = find_maximum(array, size);

	/* Perform counting sort for each significant digit */
	for (exp = 1; max_val / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, tmp);
		/* Print the array after each iteration */
		print_array(array, size);
	}
	free(tmp);
}

/**
 * count_sort - Helper function to perform Counting Sort.
 * @array: The array to be sorted.
 * @size: Number of element in the array.
 * @e: The current digit.
 * @out: Stores array.
 */
void count_sort(int *array, size_t size, int e, int *output)
{
	size_t o;
	int counts[10] = {0};

	/* Count the occurrences of each digit in the input array */
	for (o = 0; o < size; o++)
		counts[(array[o] / e) % 10]++;

	/* Update the counting array to store the correct positions */
	for (o = 1; o < 10; o++)
		counts[o] += counts[o - 1];

	/* Build the output array in sorted order */
	for (o = size - 1; (int) o >= 0; o--)
	{
		out[counts[(array[o] / e) % 10] - 1] = array[o];
		counts[(array[o] / e) % 10]--;
	}

	/* Copy the sorted elements back to the original array */
	for (o = 0; o < size; o++)
		array[o] = out[o];
}

/**
 * find_maximum - Finds the maximum value in an array.
 * @array: The array.
 * @size: size of array.
 *
 * Return: The maximum value.
 */
int find_maximum(int *array, int size)
{
	int o = 1, z;

	z = array[0];
	while (o < size)
	{
		if (array[o] > z)
			z  = array[o];
		o++;
	}
	return (z);
}
