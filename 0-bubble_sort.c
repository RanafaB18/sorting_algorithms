#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

    if (size < 2){
        return;
    }
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swap(&array[j - 1], &array[j]);
				print_array(array, size);
			}
		}
	}
}
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
