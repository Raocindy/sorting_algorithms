#include "sort.h"

/**
 * counting_sort - Sorts array of integers in ascending order
 * using Counting sort
 * @array: Pointer to the array 
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count, o, maxValue;

	if (array == NULL || size < 2)
		return;

	count = malloc(sizeof(int) * size);

	if (count == NULL)
		return;

	maxValue = find_maximum(array, size);
	output = malloc(sizeof(int) * (maxValue + 1));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (o = 0; o < (maxValue + 1); o++)
		output[o] = 0;
	for (o = 0; o < (int)size; o++)
		output[array[o]] += 1;
	for (o = 0; o < (maxValue + 1); o++)
		output[o] += output[o - 1];
	print_array(output, maxValue + 1);

	for (o = 0; o < (int)size; o++)
	{
		count[output[array[o]] - 1] = array[o];
		output[array[o]] -= 1;
	}

	for (o = 0; o < (int)size; o++)
		array[o] = count[o];

	free(count);
	free(output);
}

/**
 * find_maximum - Finds the maximum value in an array.
 * @array: The array.
 * @size: size of  array.
 *
 * Return: The maximum value.
 */
int find_maximum(int *array, int size)
{
	int o, v;

	for (v = array[0], o = 1; o < size; o++)
	{
		if (array[o] > v)
			v = array[o];
	}
	return (v);
}
