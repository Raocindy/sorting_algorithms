#include "sort.h"

/**
 * _swap - Swap two integers in an array.
 * @first: First index element.
 * @second: Second index element.
 */
void _swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * bitonic_merge -  Merges two sorted halves of a bitonic sequence.
 * @arr: The array.
 * @arr_size: size of array.
 * @s: Starting index of sequence in array.
 * @seq: Size of the sequence to sort.
 * @asc: Direction to sort in array.
 */
void bitonic_merge(int *arr, size_t arr_size, size_t s, size_t seq, char asc)
{
	size_t o, mid;

	mid = seq / 2;

	if (seq > 1)
	{
		for (o = s; o < s + mid; o++)
		{
			if ((asc == OP && array[o] > array[o + mid]) ||
			    (asc == OS && array[o] < array[o + mid]))
				_swap(array + o, array + o + mid);
		}
		bitonic_merge(array, arr_size, s, mid, asc);
		bitonic_merge(array, arr_size, s + mid, mid, asc);
	}
}

/**
 * bitonic_recur - Convert an array of integers into a bitonic sequence.
 * @arr: The array.
 * @arr_size: Number of elements in the array
 * @s: Starting index of the bitonic sequence
 * @seq: Size of bitonic sequence.
 * @asc: Direction to sort the bitonic sequence.
 */
void bitonic_recur(int *arr, size_t arr_size, size_t s, size_t seq, char asc)
{
	size_t mid_index = seq / 2;
	char *q;

	q = (asc == OP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, p);
		print_array(arr + s, seq);

		bitonic_recur(arr, arr_size, s, mid_index, OP);
		bitonic_recur(arr, arr_size, s + mid_index, mid_index, OS);
		bitonic_merge(arr, arr_size, s, seq, asc);

		printf("Result [%lu/%lu] (%s):\n", seq, arr_size, q);
		print_array(arr + s, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the Bitonic sort algorithm.
 * @array: The array.
 * @size: size array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_recur(array, size, 0, size, OP);
}
