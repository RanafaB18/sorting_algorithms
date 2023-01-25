#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: Array of integers.
 * @size: Size of array.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (!array || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = &array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
			{
				min = (&array[j]);
			}
		}
		if ((&array[i]) != min)
		{
			swap(&array[i], min);
			print_array(array, size);
		}
	}
}
