#include "sort.h"


/**
 * swap -  swaps 2 numbers
 * @first: first number
 * @second: second number
 */
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * partition - Partition an integer array according to
 * the lomuto partition scheme
 * @array: Integer array
 * @size: Size of array.
 * @low: The starting index.
 * @high: The ending index
 * Return: Index of pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - Sorts the array with recursion
 * @array: Integer array
 * @size: The size of the array
 * @low: The starting index
 * @high: The ending index
 *
 * Return: void
 */
void sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, size, low, high);
		sort(array, size, low, part - 1);
		sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: Integer array
 * @size: size of array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	sort(array, size, 0, size - 1);
}
